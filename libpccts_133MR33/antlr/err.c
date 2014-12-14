/*
 * A n t l r  S e t s / E r r o r  F i l e  H e a d e r
 *
 * Generated from: antlr.g
 *
 * Terence Parr, Russell Quong, Will Cohen, and Hank Dietz: 1989-1997
 * Parr Research Corporation
 * with Purdue University Electrical Engineering
 * With AHPCRC, University of Minnesota
 * ANTLR Version 1.33MR7
 */

#include <stdio.h>
#define ANTLR_VERSION	133MR7

#include "config.h"
#include "set.h"
#include <ctype.h>
#include "syn.h"
#include "hash.h"
#include "generic.h"
#define zzcr_attr(attr,tok,t)
#define zzSET_SIZE 20
#include "antlr.h"
#include "tokens.h"
#include "dlgdef.h"
#include "err.h"

ANTLRChar *zztokens[148]={
	/* 00 */	"Invalid",
	/* 01 */	"Eof",
	/* 02 */	"QuotedTerm",
	/* 03 */	"[\\n\\r]",
	/* 04 */	"\\[\\n\\r]",
	/* 05 */	"\\~[]",
	/* 06 */	"~[\\n\\r\"\\]+",
	/* 07 */	"\"",
	/* 08 */	"[\\n\\r]",
	/* 09 */	"\\[\\n\\r]",
	/* 10 */	"\\~[]",
	/* 11 */	"~[\\n\\r\"\\]+",
	/* 12 */	"'",
	/* 13 */	"[\\n\\r]",
	/* 14 */	"\\~[]",
	/* 15 */	"~[\\n\\r'\\]+",
	/* 16 */	"\\*/",
	/* 17 */	"\\*",
	/* 18 */	"[\\n\\r]",
	/* 19 */	"~[\\n\\r\\*]+",
	/* 20 */	"\\*/",
	/* 21 */	"\\*",
	/* 22 */	"[\\n\\r]",
	/* 23 */	"~[\\n\\r\\*]+",
	/* 24 */	"[\\n\\r]",
	/* 25 */	"~[\\n\\r]+",
	/* 26 */	"[\\n\\r]",
	/* 27 */	"~[\\n\\r]+",
	/* 28 */	"[\\n\\r]",
	/* 29 */	"~[\\n\\r]+",
	/* 30 */	"\\*/",
	/* 31 */	"\\*",
	/* 32 */	"[\\n\\r]",
	/* 33 */	"~[\\n\\r\\*]+",
	/* 34 */	"Action",
	/* 35 */	"Pred",
	/* 36 */	"PassAction",
	/* 37 */	"consumeUntil\\( [\\ \\t]* \\{~[\\}]+\\} [\\ \\t]* \\)",
	/* 38 */	"consumeUntil\\( ~[\\)]+ \\)",
	/* 39 */	"[\\n\\r]",
	/* 40 */	"\\>",
	/* 41 */	"$",
	/* 42 */	"$$",
	/* 43 */	"$\\[\\]",
	/* 44 */	"$\\[",
	/* 45 */	"$[0-9]+",
	/* 46 */	"$[0-9]+.",
	/* 47 */	"$[0-9]+.[0-9]+",
	/* 48 */	"$[_a-zA-Z][_a-zA-Z0-9]*",
	/* 49 */	"#0",
	/* 50 */	"#\\[\\]",
	/* 51 */	"#\\(\\)",
	/* 52 */	"#[0-9]+",
	/* 53 */	"#[_a-zA-Z][_a-zA-Z0-9]*",
	/* 54 */	"#\\[",
	/* 55 */	"#\\(",
	/* 56 */	"#",
	/* 57 */	"\\)",
	/* 58 */	"\\[",
	/* 59 */	"\\(",
	/* 60 */	"\\\\]",
	/* 61 */	"\\\\)",
	/* 62 */	"\\>",
	/* 63 */	"'",
	/* 64 */	"\"",
	/* 65 */	"\\$",
	/* 66 */	"\\#",
	/* 67 */	"\\[\\n\\r]",
	/* 68 */	"\\~[\\]\\)>$#]",
	/* 69 */	"/",
	/* 70 */	"/\\*",
	/* 71 */	"\\*/",
	/* 72 */	"//",
	/* 73 */	"~[\\n\\r\\)\\(\\$#\\>\\]\\[\"'/]+",
	/* 74 */	"[\\t\\ ]+",
	/* 75 */	"[\\n\\r]",
	/* 76 */	"\\[",
	/* 77 */	"\\<\\<",
	/* 78 */	"\"",
	/* 79 */	"/\\*",
	/* 80 */	"\\*/",
	/* 81 */	"//",
	/* 82 */	"\\>\\>",
	/* 83 */	"WildCard",
	/* 84 */	"\\@",
	/* 85 */	"LABEL",
	/* 86 */	"grammar-element",
	/* 87 */	"meta-symbol",
	/* 88 */	"#header",
	/* 89 */	"#parser",
	/* 90 */	"#tokdefs",
	/* 91 */	"\\}",
	/* 92 */	"class",
	/* 93 */	"NonTerminal",
	/* 94 */	"TokenTerm",
	/* 95 */	"\\{",
	/* 96 */	"!",
	/* 97 */	"\\<",
	/* 98 */	"\\>",
	/* 99 */	":",
	/* 100 */	";",
	/* 101 */	"#lexaction",
	/* 102 */	"#lexmember",
	/* 103 */	"#lexprefix",
	/* 104 */	"#lexclass",
	/* 105 */	"#errclass",
	/* 106 */	"#tokclass",
	/* 107 */	"#token",
	/* 108 */	"=",
	/* 109 */	"[0-9]+",
	/* 110 */	"\\|",
	/* 111 */	"\\~",
	/* 112 */	"..",
	/* 113 */	"^",
	/* 114 */	"#pragma",
	/* 115 */	"approx",
	/* 116 */	"LL(1)",
	/* 117 */	"LL(2)",
	/* 118 */	"\\(",
	/* 119 */	"\\)",
	/* 120 */	"\\*",
	/* 121 */	"\\+",
	/* 122 */	"?",
	/* 123 */	"=>",
	/* 124 */	"exception",
	/* 125 */	"default",
	/* 126 */	"catch",
	/* 127 */	"#[A-Za-z0-9_]*",
	/* 128 */	"[\\t\\ ]+",
	/* 129 */	"[\\n\\r]",
	/* 130 */	"//",
	/* 131 */	"/\\*",
	/* 132 */	"#ifdef",
	/* 133 */	"#if",
	/* 134 */	"#ifndef",
	/* 135 */	"#else",
	/* 136 */	"#endif",
	/* 137 */	"#undef",
	/* 138 */	"#import",
	/* 139 */	"ID",
	/* 140 */	"#define",
	/* 141 */	"INT",
	/* 142 */	"enum",
	/* 143 */	"\\{",
	/* 144 */	"=",
	/* 145 */	",",
	/* 146 */	"\\}",
	/* 147 */	";"
};
SetWordType zzerr1[20] = {0x0,0x0,0x0,0x0, 0x0,0x0,0x0,0x0, 0x0,0x0,0x0,0x60,
	0x0,0x0,0x0,0x0, 0x0,0x0,0x0,0x0};
SetWordType setwd1[148] = {0x0,0xb0,0x0,0x0,0x0,0x0,0x0,
	0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
	0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
	0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
	0x0,0x0,0x0,0xaa,0x0,0x40,0x0,0x0,
	0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
	0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
	0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
	0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
	0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
	0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
	0x0,0x1,0x1,0x1,0xae,0xae,0xa4,0x0,
	0x0,0x0,0x40,0x0,0x0,0x0,0xaa,0xaa,
	0xaa,0xa6,0xae,0xae,0xa6,0x0,0x0,0x0,
	0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
	0x0,0x0,0x0,0x0,0x0,0x22,0x0,0x0,
	0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
	0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
	0x0,0x0,0x0,0x0,0x0};
SetWordType zzerr2[20] = {0x4,0x0,0x0,0x0, 0x0,0x0,0x0,0x0, 0x0,0x0,0x0,0x40,
	0x0,0x0,0x0,0x0, 0x0,0x0,0x0,0x0};
SetWordType zzerr3[20] = {0x4,0x0,0x0,0x0, 0x0,0x0,0x0,0x0, 0x0,0x0,0x0,0x60,
	0x0,0x0,0x0,0x0, 0x0,0x0,0x0,0x0};
SetWordType zzerr4[20] = {0x4,0x0,0x0,0x0, 0x0,0x0,0x0,0x0, 0x0,0x0,0x0,0x60,
	0x0,0x0,0x0,0x0, 0x0,0x0,0x0,0x0};
SetWordType zzerr5[20] = {0x4,0x0,0x0,0x0, 0x0,0x0,0x0,0x0, 0x0,0x0,0x0,0x40,
	0x0,0x0,0x0,0x0, 0x0,0x0,0x0,0x0};
SetWordType setwd2[148] = {0x0,0xaf,0x50,0x0,0x0,0x0,0x0,
	0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
	0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
	0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
	0x0,0x0,0x0,0xaf,0x0,0x0,0x0,0x0,
	0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
	0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
	0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
	0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
	0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
	0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
	0x0,0x0,0x0,0x0,0xaf,0xaf,0xbf,0x50,
	0x0,0x0,0x0,0x0,0x0,0x0,0xaf,0xaf,
	0xaf,0xaf,0xaf,0xaf,0xaf,0x0,0x0,0x0,
	0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
	0x0,0x0,0x0,0x0,0x0,0xaf,0x0,0x0,
	0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
	0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
	0x0,0x0,0x0,0x0,0x0};
SetWordType zzerr6[20] = {0x4,0x0,0x0,0x0, 0x0,0x0,0x0,0x0, 0x0,0x0,0x0,0x40,
	0x0,0x0,0x0,0x0, 0x0,0x0,0x0,0x0};
SetWordType zzerr7[20] = {0x0,0x0,0x0,0x0, 0x0,0x0,0x0,0x0, 0x0,0x0,0xd0,0x0,
	0x0,0x0,0x0,0x10, 0x0,0x0,0x0,0x0};
SetWordType zzerr8[20] = {0x4,0x0,0x0,0x0, 0x0,0x0,0x0,0x0, 0x0,0x0,0x0,0x40,
	0x0,0x0,0x0,0x0, 0x0,0x0,0x0,0x0};
SetWordType zzerr9[20] = {0x0,0x0,0x0,0x0, 0x0,0x0,0x0,0x0, 0x0,0x0,0xd0,0x0,
	0x0,0x0,0x0,0x10, 0x0,0x0,0x0,0x0};
SetWordType setwd3[148] = {0x0,0x1,0xf4,0x0,0x0,0x0,0x0,
	0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
	0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
	0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
	0x0,0x0,0x0,0xc5,0xc4,0xc4,0x0,0x0,
	0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
	0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
	0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
	0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
	0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
	0x0,0x0,0x0,0x0,0xf4,0xc0,0xe4,0x0,
	0x0,0x0,0x0,0x0,0xcb,0x1,0xf5,0xf4,
	0xc4,0x0,0x0,0xc4,0x0,0xca,0x1,0x1,
	0x1,0x1,0x1,0x1,0x1,0x0,0x0,0xc8,
	0xc4,0x0,0x0,0xc4,0x0,0x0,0x0,0xc4,
	0xca,0xc4,0xc4,0x0,0x0,0xc9,0x0,0x0,
	0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
	0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
	0x0,0x0,0x0,0x0,0x0};
SetWordType zzerr10[20] = {0x0,0x0,0x0,0x0, 0x0,0x0,0x0,0x0, 0x0,0x0,0xc0,0x0,
	0x0,0x0,0x0,0x10, 0x0,0x0,0x0,0x0};
SetWordType zzerr11[20] = {0x4,0x0,0x0,0x0, 0x0,0x0,0x0,0x0, 0x0,0x0,0x8,0x60,
	0x0,0x0,0x0,0x0, 0x0,0x0,0x0,0x0};
SetWordType zzerr12[20] = {0x0,0x0,0x0,0x0, 0x0,0x0,0x0,0x0, 0x0,0x0,0x0,0x0,
	0x0,0x0,0x38,0x0, 0x0,0x0,0x0,0x0};
SetWordType zzerr13[20] = {0x0,0x0,0x0,0x0, 0x0,0x0,0x0,0x0, 0x0,0x0,0x40,0x8,
	0x10,0xc0,0x80,0x18, 0x0,0x0,0x0,0x0};
SetWordType zzerr14[20] = {0x0,0x0,0x0,0x0, 0x0,0x0,0x0,0x0, 0x0,0x0,0x40,0x8,
	0x10,0xc0,0x80,0x14, 0x0,0x0,0x0,0x0};
SetWordType zzerr15[20] = {0x0,0x0,0x0,0x0, 0x0,0x0,0x0,0x0, 0x0,0x0,0x0,0x80,
	0x0,0x0,0x40,0x0, 0x0,0x0,0x0,0x0};
SetWordType zzerr16[20] = {0x0,0x0,0x0,0x0, 0x0,0x0,0x0,0x0, 0x0,0x0,0x40,0x0,
	0x0,0x0,0x0,0x0, 0x0,0x0,0x0,0x0};
SetWordType zzerr17[20] = {0x0,0x0,0x0,0x0, 0x0,0x0,0x0,0x0, 0x0,0x0,0x0,0x60,
	0x0,0x0,0x0,0x0, 0x0,0x0,0x0,0x0};
SetWordType setwd4[148] = {0x0,0x80,0x39,0x0,0x0,0x0,0x0,
	0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
	0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
	0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
	0x0,0x0,0x0,0xf9,0x39,0x3b,0x0,0x0,
	0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
	0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
	0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
	0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
	0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
	0x0,0x0,0x0,0x0,0x39,0x0,0x39,0x0,
	0x0,0x0,0x0,0x0,0xf9,0xc0,0xf9,0x39,
	0x3d,0x0,0x2,0x39,0x0,0xb9,0xc0,0xc0,
	0xc0,0xc0,0xc0,0xc0,0xc0,0x0,0x0,0xb9,
	0x39,0x0,0x0,0x3d,0x0,0x0,0x0,0x3d,
	0xb9,0x39,0x39,0x0,0x0,0xf9,0x0,0x0,
	0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
	0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
	0x0,0x0,0x0,0x0,0x0};
SetWordType zzerr18[20] = {0x0,0x0,0x0,0x0, 0x0,0x0,0x0,0x0, 0x0,0x0,0x0,0x0,
	0x0,0x0,0x0,0x0, 0x0,0x50,0x0,0x0};
SetWordType zzerr19[20] = {0x2,0x0,0x0,0x0, 0x0,0x0,0x0,0x0, 0x0,0x0,0x0,0x0,
	0x0,0x0,0x0,0x0, 0x40,0x50,0x0,0x0};
SetWordType zzerr20[20] = {0x0,0x0,0x0,0x0, 0x0,0x0,0x0,0x0, 0x0,0x0,0x0,0x0,
	0x0,0x0,0x0,0x0, 0x0,0x0,0x7,0x0};
SetWordType zzerr21[20] = {0x0,0x0,0x0,0x0, 0x0,0x0,0x0,0x0, 0x0,0x0,0x0,0x0,
	0x0,0x0,0x0,0x0, 0x0,0x0,0x7,0x0};
SetWordType setwd5[148] = {0x0,0x4d,0x0,0x0,0x0,0x0,0x0,
	0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
	0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
	0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
	0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x0,
	0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
	0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
	0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
	0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
	0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
	0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
	0x0,0x0,0x0,0x0,0x1,0x1,0x1,0x0,
	0x0,0x0,0x0,0x0,0x0,0x1,0x1,0x1,
	0x1,0x1,0x1,0x1,0x1,0x0,0x0,0x1,
	0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
	0x1,0x0,0x0,0x0,0x0,0x1,0x1,0x1,
	0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x2,
	0x0,0x0,0x0,0x0,0x0,0x2,0x0,0x42,
	0x0,0x0,0x30,0x30,0x0};