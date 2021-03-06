#include <cstdio>
#include <cstring>
#include <fstream>

#include "vtr_assert.h"
#include "vtr_util.h"
#include "vtr_log.h"
#include "vtr_digest.h"

#include "vpr_types.h"
#include "vpr_error.h"

#include "globals.h"
#include "hash.h"
#include "read_place.h"
#include "read_xml_arch_file.h"

t_block* find_block(t_block* blocks, int num_blocks, std::string name);

void read_place(const char* net_file, 
                const char* place_file,
                const int L_nx, const int L_ny,
		        const int L_num_blocks, struct s_block block_list[]) {
    std::ifstream fstream(place_file); 
    if (!fstream) {
        vpr_throw(VPR_ERROR_PLACE_F, __FILE__, __LINE__, 
                        "'%s' - Cannot open place file.\n", 
                        place_file);
    }

    std::string line;
    int lineno = 0;
    bool seen_netlist_id = false;
    bool seen_grid_dimensions = false;
    while (std::getline(fstream, line)) { //Parse line-by-line
        ++lineno;

        std::vector<std::string> tokens = vtr::split(line);

        if (tokens.empty()) {
            continue; //Skip blank lines

        } else if (tokens[0][0] == '#') {
            continue; //Skip commented lines

        } else if (tokens.size() == 4 
                   && tokens[0] == "Netlist_File:" 
                   && tokens[2] == "Netlist_ID:") {
            //Check that the netlist used to generate this placement matches the one loaded
            //
            //NOTE: this is an optional check which causes no errors if this line is missing.
            //      This ensures other tools can still generate placement files which can be loaded 
            //      by VPR.

            if (seen_netlist_id) {
                vpr_throw(VPR_ERROR_PLACE_F, place_file, lineno, 
                          "Duplicate Netlist_File/Netlist_ID specification");
            }
            
            std::string place_netlist_id = tokens[3];
            std::string place_netlist_file = tokens[1];

            if (place_netlist_id != g_clbs_nlist.netlist_id) {
                vpr_throw(VPR_ERROR_PLACE_F, place_file, lineno, 
                          "The packed netlist file that generated placement (File: '%s' ID: '%s')"
                          " does not match current netlist (File: '%s' ID: '%s')", 
                          place_netlist_file.c_str(), place_netlist_id.c_str(), 
                          net_file, g_clbs_nlist.netlist_id.c_str());
            }

            seen_netlist_id = true;

        } else if (tokens.size() == 7 
                   && tokens[0] == "Array"
                   && tokens[1] == "size:"
                   && tokens[3] == "x"
                   && tokens[5] == "logic"
                   && tokens[6] == "blocks") {
            //Load the device grid dimensions

            if (seen_grid_dimensions) {
                vpr_throw(VPR_ERROR_PLACE_F, place_file, lineno, 
                          "Duplicate device grid dimensions specification");
            }

            int place_file_nx = vtr::atoi(tokens[2]);
            int place_file_ny = vtr::atoi(tokens[4]);
            if (L_nx != place_file_nx || L_ny != place_file_ny) {
                vpr_throw(VPR_ERROR_PLACE_F, place_file, lineno, 
                        "Current FPGA size (%d x %d) is different from size when placement generated (%d x %d)", 
                        L_nx, L_ny, place_file_nx, place_file_ny);
            }

            seen_grid_dimensions = true;

        } else if (tokens.size() == 4 || (tokens.size() == 5 && tokens[4][0] == '#')) {
            //Load the block location
            //
            //We should have 4 tokens of actual data, with an optional 5th (commented) token indicating VPR's
            //internal block number

            //Grid dimensions are required by this point
            if (!seen_grid_dimensions) {
                vpr_throw(VPR_ERROR_PLACE_F, place_file, lineno, 
                        "Missing device grid size specification");
            }

            std::string block_name = tokens[0];
            int block_x = vtr::atoi(tokens[1]);
            int block_y = vtr::atoi(tokens[2]);
            int block_z = vtr::atoi(tokens[3]);

            t_block* blk = find_block(block_list, L_num_blocks, block_name);

            if (!blk) {
                vpr_throw(VPR_ERROR_PLACE_F, place_file, lineno, 
                          "Block '%s' in placement file does not exist in netlist.",
                          block_name.c_str());
            }

            //Set the location
            blk->x = block_x;
            blk->y = block_y;
            blk->z = block_z;

        } else {
            //Unrecognized
            vpr_throw(VPR_ERROR_PLACE_F, place_file, lineno, 
                      "Invalid line '%s' in placement file",
                      line.c_str());
        }
    }

    g_placement_id = vtr::secure_digest_file(place_file);
}

void read_user_pad_loc(const char *pad_loc_file) {

	/* Reads in the locations of the IO pads from a file. */

	struct s_hash **hash_table, *h_ptr;
	int iblk, i, j, xtmp, ytmp, bnum, k;
	FILE *fp;
	char buf[vtr::BUFSIZE], bname[vtr::BUFSIZE], *ptr;

	vtr::printf_info("\n");
	vtr::printf_info("Reading locations of IO pads from '%s'.\n", pad_loc_file);
	fp = fopen(pad_loc_file, "r");
	if (!fp) vpr_throw(VPR_ERROR_PLACE_F, __FILE__, __LINE__, 
				"'%s' - Cannot find IO pads location file.\n", 
				pad_loc_file);
		
	hash_table = alloc_hash_table();
	for (iblk = 0; iblk < g_num_blocks; iblk++) {
		if (g_blocks[iblk].type == IO_TYPE) {
			insert_in_hash_table(hash_table, g_blocks[iblk].name, iblk);
			g_blocks[iblk].x = OPEN; /* Mark as not seen yet. */
		}
	}

	for (i = 0; i <= g_nx + 1; i++) {
		for (j = 0; j <= g_ny + 1; j++) {
			if (g_grid[i][j].type == IO_TYPE) {
				for (k = 0; k < IO_TYPE->capacity; k++) {
					if (g_grid[i][j].blocks[k] != INVALID_BLOCK) {
						g_grid[i][j].blocks[k] = EMPTY_BLOCK; /* Flag for err. check */
					}
				}
			}
		}
	}

	ptr = vtr::fgets(buf, vtr::BUFSIZE, fp);

	while (ptr != NULL) {
		ptr = vtr::strtok(buf, TOKENS, fp, buf);
		if (ptr == NULL) {
			ptr = vtr::fgets(buf, vtr::BUFSIZE, fp);
			continue; /* Skip blank or comment lines. */
		}

        if(strlen(ptr) + 1 < vtr::BUFSIZE) {
            strcpy(bname, ptr);
        } else {
			vpr_throw(VPR_ERROR_PLACE_F, pad_loc_file, vtr::get_file_line_number_of_last_opened_file(), 
					"Block name exceeded buffer size of %zu characters", vtr::BUFSIZE);
        }

		ptr = vtr::strtok(NULL, TOKENS, fp, buf);
		if (ptr == NULL) {
			vpr_throw(VPR_ERROR_PLACE_F, pad_loc_file, vtr::get_file_line_number_of_last_opened_file(), 
					"Incomplete.\n");
		}
		sscanf(ptr, "%d", &xtmp);

		ptr = vtr::strtok(NULL, TOKENS, fp, buf);
		if (ptr == NULL) {
			vpr_throw(VPR_ERROR_PLACE_F, pad_loc_file, vtr::get_file_line_number_of_last_opened_file(), 
					"Incomplete.\n");
		}
		sscanf(ptr, "%d", &ytmp);

		ptr = vtr::strtok(NULL, TOKENS, fp, buf);
		if (ptr == NULL) {
			vpr_throw(VPR_ERROR_PLACE_F, pad_loc_file, vtr::get_file_line_number_of_last_opened_file(), 
					"Incomplete.\n");
		}
		sscanf(ptr, "%d", &k);

		ptr = vtr::strtok(NULL, TOKENS, fp, buf);
		if (ptr != NULL) {
			vpr_throw(VPR_ERROR_PLACE_F, pad_loc_file, vtr::get_file_line_number_of_last_opened_file(), 
					"Extra characters at end of line.\n");
		}

		h_ptr = get_hash_entry(hash_table, bname);
		if (h_ptr == NULL) {
			vtr::printf_warning(__FILE__, __LINE__, 
					"[Line %d] Block %s invalid, no such IO pad.\n", vtr::get_file_line_number_of_last_opened_file(), bname);
			ptr = vtr::fgets(buf, vtr::BUFSIZE, fp);
			continue;
		}
		bnum = h_ptr->index;
		i = xtmp;
		j = ytmp;

		if (g_blocks[bnum].x != OPEN) {
			vpr_throw(VPR_ERROR_PLACE_F, pad_loc_file, vtr::get_file_line_number_of_last_opened_file(), 
					"Block %s is listed twice in pad file.\n", bname);
		}

		if (i < 0 || i > g_nx + 1 || j < 0 || j > g_ny + 1) {
			vpr_throw(VPR_ERROR_PLACE_F, pad_loc_file, 0, 
					"Block #%d (%s) location, (%d,%d) is out of range.\n", bnum, bname, i, j);
		}

		g_blocks[bnum].x = i; /* Will be reloaded by initial_placement anyway. */
		g_blocks[bnum].y = j; /* I need to set .x only as a done flag.         */
		g_blocks[bnum].z = k;
		g_blocks[bnum].is_fixed = true;

		if (g_grid[i][j].type != IO_TYPE) {
			vpr_throw(VPR_ERROR_PLACE_F, pad_loc_file, 0, 
					"Attempt to place IO g_blocks %s at illegal location (%d, %d).\n", bname, i, j);
		}

		if (k >= IO_TYPE->capacity || k < 0) {
			vpr_throw(VPR_ERROR_PLACE_F, pad_loc_file, vtr::get_file_line_number_of_last_opened_file(), 
					"Block %s subblock number (%d) is out of range.\n", bname, k);
		}
		g_grid[i][j].blocks[k] = bnum;
		g_grid[i][j].usage++;

		ptr = vtr::fgets(buf, vtr::BUFSIZE, fp);
	}

	for (iblk = 0; iblk < g_num_blocks; iblk++) {
		if (g_blocks[iblk].type == IO_TYPE && g_blocks[iblk].x == OPEN) {
			vpr_throw(VPR_ERROR_PLACE_F, pad_loc_file, 0, 
					"IO g_blocks %s location was not specified in the pad file.\n", g_blocks[iblk].name);
		}
	}

	fclose(fp);
	free_hash_table(hash_table);
	vtr::printf_info("Successfully read %s.\n", pad_loc_file);
	vtr::printf_info("\n");
}

void print_place(const char* net_file, 
                 const char* net_id, 
                 const char* place_file) {

	/* Prints out the placement of the circuit. The architecture and     *
	 * netlist files used to generate this placement are recorded in the *
	 * file to avoid loading a placement with the wrong support files    *
	 * later.                                                            */

	FILE *fp;
	int i;

	fp = fopen(place_file, "w");

	fprintf(fp, "Netlist_File: %s Netlist_ID: %s\n", 
            net_file,
            net_id);
	fprintf(fp, "Array size: %d x %d logic blocks\n\n", g_nx, g_ny);
	fprintf(fp, "#block name\tx\ty\tsubblk\tblock number\n");
	fprintf(fp, "#----------\t--\t--\t------\t------------\n");

	for (i = 0; i < g_num_blocks; i++) {
		fprintf(fp, "%s\t", g_blocks[i].name);
		if (strlen(g_blocks[i].name) < 8)
			fprintf(fp, "\t");

		fprintf(fp, "%d\t%d\t%d", g_blocks[i].x, g_blocks[i].y, g_blocks[i].z);
		fprintf(fp, "\t#%d\n", i);
	}
	fclose(fp);

    //Calculate the ID of the placement
    g_placement_id = vtr::secure_digest_file(place_file);
}

t_block* find_block(t_block* blocks, int nblocks, std::string name) {
    t_block* blk = NULL;
    for (int i = 0; i < nblocks; ++i) {
        if (blocks[i].name == name) {
            blk = (blocks + i);
            break;
        }
    }
    return blk;
}
