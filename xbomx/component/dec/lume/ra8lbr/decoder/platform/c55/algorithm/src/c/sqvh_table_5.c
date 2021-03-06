/* ***** BEGIN LICENSE BLOCK *****   
 * Source last modified: $Id: sqvh_table_5.c,v 1.1.1.1 2007/12/07 08:11:47 zpxu Exp $ 
 * 
 * REALNETWORKS CONFIDENTIAL--NOT FOR DISTRIBUTION IN SOURCE CODE FORM   
 * Portions Copyright (c) 1995-2005 RealNetworks, Inc.   
 * All Rights Reserved.   
 *   
 * The contents of this file, and the files included with this file, 
 * are subject to the current version of the RealNetworks Community 
 * Source License (the "RCSL"), including Attachment G and any 
 * applicable attachments, all available at 
 * http://www.helixcommunity.org/content/rcsl.  You may also obtain 
 * the license terms directly from RealNetworks.  You may not use this 
 * file except in compliance with the RCSL and its Attachments. There 
 * are no redistribution rights for the source code of this 
 * file. Please see the applicable RCSL for the rights, obligations 
 * and limitations governing use of the contents of the file. 
 *   
 * This file is part of the Helix DNA Technology. RealNetworks is the 
 * developer of the Original Code and owns the copyrights in the 
 * portions it created. 
 *   
 * This file, and the files included with this file, is distributed 
 * and made available on an 'AS IS' basis, WITHOUT WARRANTY OF ANY 
 * KIND, EITHER EXPRESS OR IMPLIED, AND REALNETWORKS HEREBY DISCLAIMS 
 * ALL SUCH WARRANTIES, INCLUDING WITHOUT LIMITATION, ANY WARRANTIES 
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, QUIET 
 * ENJOYMENT OR NON-INFRINGEMENT. 
 *   
 * Technology Compatibility Kit Test Suite(s) Location:   
 * https://rarvcode-tck.helixcommunity.org   
 *   
 * Contributor(s):   
 *   
 * ***** END LICENSE BLOCK ***** */   

/*-------------------------------------------------------------------------*
 *	FileName : sqvh_table_5.c												   *
 *																		   *
 *	Huffman lookup table(s) generated by utility for huffman tree(s) 	   *
 *		sqvh_table_5 of real audio decoder.									   *
 *																		   *
 *																		   *
 *  NOTE : SQVH_TABLE_5_BIT_COUNT no. of bits should be read in the			   *
 *			DecodeNextSymbolFromTree() function for the table			   *
 *																		   *
 *-------------------------------------------------------------------------*/


#ifdef _HUFFMAN_TABLES_

#include "sqvh_table_5.h"

#pragma DATA_ALIGN( RA_TNI_sqvh_table_5, 2 )	 // align on 32-bit boundary
 
#ifdef CONST_TABLE_DMA
#pragma DATA_SECTION( RA_TNI_sqvh_table_5, "CONST_TABLE_DMA_SECTION") 
#endif 
 
 
const HuffmanTableNode RA_TNI_sqvh_table_5[] = { 
	{  0 , 2  },
	{  0 , 2  },
	{  0 , 2  },
	{  0 , 2  },
	{  0 , 2  },
	{  0 , 2  },
	{  0 , 2  },
	{  0 , 2  },
	{  0 , 2  },
	{  0 , 2  },
	{  0 , 2  },
	{  0 , 2  },
	{  0 , 2  },
	{  0 , 2  },
	{  0 , 2  },
	{  0 , 2  },
	{  0 , 2  },
	{  0 , 2  },
	{  0 , 2  },
	{  0 , 2  },
	{  0 , 2  },
	{  0 , 2  },
	{  0 , 2  },
	{  0 , 2  },
	{  0 , 2  },
	{  0 , 2  },
	{  0 , 2  },
	{  0 , 2  },
	{  0 , 2  },
	{  0 , 2  },
	{  0 , 2  },
	{  0 , 2  },
	{  1 , 4  },
	{  1 , 4  },
	{  1 , 4  },
	{  1 , 4  },
	{  1 , 4  },
	{  1 , 4  },
	{  1 , 4  },
	{  1 , 4  },
	{  3 , 4  },
	{  3 , 4  },
	{  3 , 4  },
	{  3 , 4  },
	{  3 , 4  },
	{  3 , 4  },
	{  3 , 4  },
	{  3 , 4  },
	{  9 , 4  },
	{  9 , 4  },
	{  9 , 4  },
	{  9 , 4  },
	{  9 , 4  },
	{  9 , 4  },
	{  9 , 4  },
	{  9 , 4  },
	{  27 , 4  },
	{  27 , 4  },
	{  27 , 4  },
	{  27 , 4  },
	{  27 , 4  },
	{  27 , 4  },
	{  27 , 4  },
	{  27 , 4  },
	{  81 , 4  },
	{  81 , 4  },
	{  81 , 4  },
	{  81 , 4  },
	{  81 , 4  },
	{  81 , 4  },
	{  81 , 4  },
	{  81 , 4  },
	{  4 , 5  },
	{  4 , 5  },
	{  4 , 5  },
	{  4 , 5  },
	{  12 , 5  },
	{  12 , 5  },
	{  12 , 5  },
	{  12 , 5  },
	{  36 , 5  },
	{  36 , 5  },
	{  36 , 5  },
	{  36 , 5  },
	{  82 , 5  },
	{  82 , 5  },
	{  82 , 5  },
	{  82 , 5  },
	{  84 , 5  },
	{  84 , 5  },
	{  84 , 5  },
	{  84 , 5  },
	{  108 , 5  },
	{  108 , 5  },
	{  108 , 5  },
	{  108 , 5  },
	{  10 , 6  },
	{  10 , 6  },
	{  13 , 6  },
	{  13 , 6  },
	{  28 , 6  },
	{  28 , 6  },
	{  30 , 6  },
	{  30 , 6  },
	{  39 , 6  },
	{  39 , 6  },
	{  90 , 6  },
	{  90 , 6  },
	{  109 , 6  },
	{  109 , 6  },
	{  117 , 6  },
	{  117 , 6  },
	{  31 , 7  },
	{  37 , 7  },
	{  40 , 7  },
	{  85 , 7  },
	{  91 , 7  },
	{  93 , 7  },
	{  111 , 7  },
	{  120 , 7  },
	{  128 , -7 },
	{  136 , -7 },
	{  144 , -7 },
	{  152 , -7 },
	{  160 , -7 },
	{  168 , -7 },
	{  176 , -7 },
	{  184 , -7 },

	{  2 , 1  },
	{  2 , 1  },
	{  2 , 1  },
	{  2 , 1  },
	{  54 , 1  },
	{  54 , 1  },
	{  54 , 1  },
	{  54 , 1  },

	{  94 , 1  },
	{  94 , 1  },
	{  94 , 1  },
	{  94 , 1  },
	{  112 , 1  },
	{  112 , 1  },
	{  112 , 1  },
	{  112 , 1  },

	{  118 , 1  },
	{  118 , 1  },
	{  118 , 1  },
	{  118 , 1  },
	{  121 , 1  },
	{  121 , 1  },
	{  121 , 1  },
	{  121 , 1  },

	{  162 , 1  },
	{  162 , 1  },
	{  162 , 1  },
	{  162 , 1  },
	{  189 , 1  },
	{  189 , 1  },
	{  189 , 1  },
	{  189 , 1  },

	{  5 , 2  },
	{  5 , 2  },
	{  6 , 2  },
	{  6 , 2  },
	{  18 , 2  },
	{  18 , 2  },
	{  135 , 2  },
	{  135 , 2  },

	{  7 , 3  },
	{  15 , 3  },
	{  21 , 3  },
	{  45 , 3  },
	{  63 , 3  },
	{  163 , 3  },
	{  171 , 3  },
	{  24 , -3 },

	{  24 , -3 },
	{  32 , -3 },
	{  40 , -3 },
	{  48 , -3 },
	{  56 , -3 },
	{  64 , -3 },
	{  72 , -3 },
	{  80 , -3 },

	{  80 , -3 },
	{  88 , -3 },
	{  96 , -3 },
	{  104 , -3 },
	{  112 , -3 },
	{  120 , -3 },
	{  128 , -3 },
	{  136 , -3 },

	{  11 , 1  },
	{  11 , 1  },
	{  11 , 1  },
	{  11 , 1  },
	{  16 , 1  },
	{  16 , 1  },
	{  16 , 1  },
	{  16 , 1  },

	{  19 , 1  },
	{  19 , 1  },
	{  19 , 1  },
	{  19 , 1  },
	{  48 , 1  },
	{  48 , 1  },
	{  48 , 1  },
	{  48 , 1  },

	{  57 , 1  },
	{  57 , 1  },
	{  57 , 1  },
	{  57 , 1  },
	{  83 , 1  },
	{  83 , 1  },
	{  83 , 1  },
	{  83 , 1  },

	{  87 , 1  },
	{  87 , 1  },
	{  87 , 1  },
	{  87 , 1  },
	{  99 , 1  },
	{  99 , 1  },
	{  99 , 1  },
	{  99 , 1  },

	{  144 , 1  },
	{  144 , 1  },
	{  144 , 1  },
	{  144 , 1  },
	{  165 , 1  },
	{  165 , 1  },
	{  165 , 1  },
	{  165 , 1  },

	{  198 , 1  },
	{  198 , 1  },
	{  198 , 1  },
	{  198 , 1  },
	{  14 , 2  },
	{  14 , 2  },
	{  29 , 2  },
	{  29 , 2  },

	{  32 , 2  },
	{  32 , 2  },
	{  33 , 2  },
	{  33 , 2  },
	{  34 , 2  },
	{  34 , 2  },
	{  42 , 2  },
	{  42 , 2  },

	{  46 , 2  },
	{  46 , 2  },
	{  58 , 2  },
	{  58 , 2  },
	{  66 , 2  },
	{  66 , 2  },
	{  86 , 2  },
	{  86 , 2  },

	{  88 , 2  },
	{  88 , 2  },
	{  96 , 2  },
	{  96 , 2  },
	{  102 , 2  },
	{  102 , 2  },
	{  114 , 2  },
	{  114 , 2  },

	{  126 , 2  },
	{  126 , 2  },
	{  127 , 2  },
	{  127 , 2  },
	{  129 , 2  },
	{  129 , 2  },
	{  138 , 2  },
	{  138 , 2  },

	{  166 , 2  },
	{  166 , 2  },
	{  172 , 2  },
	{  172 , 2  },
	{  174 , 2  },
	{  174 , 2  },
	{  190 , 2  },
	{  190 , 2  },

	{  192 , 2  },
	{  192 , 2  },
	{  22 , 3  },
	{  38 , 3  },
	{  41 , 3  },
	{  43 , 3  },
	{  49 , 3  },
	{  55 , 3  },

	{  64 , 3  },
	{  92 , 3  },
	{  100 , 3  },
	{  103 , 3  },
	{  110 , 3  },
	{  130 , 3  },
	{  136 , 3  },
	{  139 , 3  },

	{  145 , 3  },
	{  147 , 3  },
	{  148 , 3  },
	{  175 , 3  },
	{  193 , 3  },
	{  199 , 3  },
	{  201 , 3  },
	{  32 , -3 },

	{  32 , -3 },
	{  40 , -3 },
	{  48 , -3 },
	{  56 , -3 },
	{  64 , -3 },
	{  72 , -3 },
	{  80 , -3 },
	{  88 , -3 },

	{  88 , -3 },
	{  96 , -3 },
	{  104 , -3 },
	{  112 , -3 },
	{  120 , -3 },
	{  128 , -3 },
	{  136 , -3 },
	{  144 , -3 },

	{  144 , -3 },
	{  152 , -3 },
	{  160 , -3 },
	{  168 , -3 },
	{  176 , -3 },
	{  184 , -3 },
	{  192 , -3 },
	{  200 , -3 },

	{  8 , 1  },
	{  8 , 1  },
	{  8 , 1  },
	{  8 , 1  },
	{  24 , 1  },
	{  24 , 1  },
	{  24 , 1  },
	{  24 , 1  },

	{  95 , 1  },
	{  95 , 1  },
	{  95 , 1  },
	{  95 , 1  },
	{  97 , 1  },
	{  97 , 1  },
	{  97 , 1  },
	{  97 , 1  },

	{  115 , 1  },
	{  115 , 1  },
	{  115 , 1  },
	{  115 , 1  },
	{  119 , 1  },
	{  119 , 1  },
	{  119 , 1  },
	{  119 , 1  },

	{  123 , 1  },
	{  123 , 1  },
	{  123 , 1  },
	{  123 , 1  },
	{  153 , 1  },
	{  153 , 1  },
	{  153 , 1  },
	{  153 , 1  },

	{  180 , 1  },
	{  180 , 1  },
	{  180 , 1  },
	{  180 , 1  },
	{  216 , 1  },
	{  216 , 1  },
	{  216 , 1  },
	{  216 , 1  },

	{  17 , 2  },
	{  17 , 2  },
	{  20 , 2  },
	{  20 , 2  },
	{  23 , 2  },
	{  23 , 2  },
	{  25 , 2  },
	{  25 , 2  },

	{  35 , 2  },
	{  35 , 2  },
	{  44 , 2  },
	{  44 , 2  },
	{  47 , 2  },
	{  47 , 2  },
	{  50 , 2  },
	{  50 , 2  },

	{  51 , 2  },
	{  51 , 2  },
	{  52 , 2  },
	{  52 , 2  },
	{  56 , 2  },
	{  56 , 2  },
	{  59 , 2  },
	{  59 , 2  },

	{  60 , 2  },
	{  60 , 2  },
	{  61 , 2  },
	{  61 , 2  },
	{  65 , 2  },
	{  65 , 2  },
	{  67 , 2  },
	{  67 , 2  },

	{  68 , 2  },
	{  68 , 2  },
	{  69 , 2  },
	{  69 , 2  },
	{  70 , 2  },
	{  70 , 2  },
	{  72 , 2  },
	{  72 , 2  },

	{  73 , 2  },
	{  73 , 2  },
	{  75 , 2  },
	{  75 , 2  },
	{  76 , 2  },
	{  76 , 2  },
	{  89 , 2  },
	{  89 , 2  },

	{  98 , 2  },
	{  98 , 2  },
	{  101 , 2  },
	{  101 , 2  },
	{  104 , 2  },
	{  104 , 2  },
	{  105 , 2  },
	{  105 , 2  },

	{  106 , 2  },
	{  106 , 2  },
	{  113 , 2  },
	{  113 , 2  },
	{  116 , 2  },
	{  116 , 2  },
	{  122 , 2  },
	{  122 , 2  },

	{  124 , 2  },
	{  124 , 2  },
	{  125 , 2  },
	{  125 , 2  },
	{  128 , 2  },
	{  128 , 2  },
	{  131 , 2  },
	{  131 , 2  },

	{  132 , 2  },
	{  132 , 2  },
	{  133 , 2  },
	{  133 , 2  },
	{  137 , 2  },
	{  137 , 2  },
	{  140 , 2  },
	{  140 , 2  },

	{  141 , 2  },
	{  141 , 2  },
	{  142 , 2  },
	{  142 , 2  },
	{  146 , 2  },
	{  146 , 2  },
	{  149 , 2  },
	{  149 , 2  },

	{  150 , 2  },
	{  150 , 2  },
	{  151 , 2  },
	{  151 , 2  },
	{  154 , 2  },
	{  154 , 2  },
	{  156 , 2  },
	{  156 , 2  },

	{  157 , 2  },
	{  157 , 2  },
	{  164 , 2  },
	{  164 , 2  },
	{  167 , 2  },
	{  167 , 2  },
	{  168 , 2  },
	{  168 , 2  },

	{  169 , 2  },
	{  169 , 2  },
	{  173 , 2  },
	{  173 , 2  },
	{  176 , 2  },
	{  176 , 2  },
	{  177 , 2  },
	{  177 , 2  },

	{  178 , 2  },
	{  178 , 2  },
	{  181 , 2  },
	{  181 , 2  },
	{  183 , 2  },
	{  183 , 2  },
	{  184 , 2  },
	{  184 , 2  },

	{  191 , 2  },
	{  191 , 2  },
	{  194 , 2  },
	{  194 , 2  },
	{  195 , 2  },
	{  195 , 2  },
	{  196 , 2  },
	{  196 , 2  },

	{  200 , 2  },
	{  200 , 2  },
	{  202 , 2  },
	{  202 , 2  },
	{  203 , 2  },
	{  203 , 2  },
	{  204 , 2  },
	{  204 , 2  },

	{  205 , 2  },
	{  205 , 2  },
	{  207 , 2  },
	{  207 , 2  },
	{  208 , 2  },
	{  208 , 2  },
	{  210 , 2  },
	{  210 , 2  },

	{  211 , 2  },
	{  211 , 2  },
	{  217 , 2  },
	{  217 , 2  },
	{  219 , 2  },
	{  219 , 2  },
	{  220 , 2  },
	{  220 , 2  },

	{  225 , 2  },
	{  225 , 2  },
	{  226 , 2  },
	{  226 , 2  },
	{  228 , 2  },
	{  228 , 2  },
	{  229 , 2  },
	{  229 , 2  }

};

#endif // _HUFFMAN_TABLES_
