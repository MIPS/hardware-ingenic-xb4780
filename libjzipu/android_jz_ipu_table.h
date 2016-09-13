/*
 * Copyright (c) 2015 Ingenic Semiconductor Co.,Ltd. All Rights Reserved.
 *
 * Website:www.ingenic.com
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sub license, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice (including the
 * next paragraph) shall be included in all copies or substantial portions
 * of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT.
 * IN NO EVENT SHALL PRECISION INSIGHT AND/OR ITS SUPPLIERS BE LIABLE FOR
 * ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * Authors:
 *    liuyang <king.lyang@ingenic.com>
 */
#ifndef __ANDROID_JZ_IPU_TABLE_H__
#define __ANDROID_JZ_IPU_TABLE_H__

#include <linux/fb.h>
//#include "jz4750_android_ipu.h"

#ifdef __cplusplus
extern "C" {
#endif
	int dump_ipu_ratio_table(struct ipu_native_info *ipu);
	int init_ipu_ratio_table(struct ipu_native_info *ipu);
	int find_ipu_ratio_factor(struct ipu_native_info *ipu, float ratio, unsigned int up);
	int resize_out_cal(int insize, int outsize, int srcN, int dstM, int upScale, int *diff);
	int resize_lut_cal(int srcN, int dstM, int upScale, rsz_lut lut[]);
	void caculate_h_lut(struct ipu_native_info *ipu, int H_MAX_LUT);
	void caculate_v_lut(struct ipu_native_info *ipu, int V_MAX_LUT);
	void _inti_sinxdivx_table(struct ipu_native_info * ipu, double CUBE_LEVEL);
	int caculate_cube_coef_table(struct ipu_native_info *ipu, int way_sel);
	int jz47_dump_ipu_resize_table(struct ipu_native_info *ipu, int num);
	void gen_pic_enhance_table(struct ipu_native_info *ipu, int mid);

#ifdef __cplusplus
}
#endif

#endif /* __ANDROID_JZ_IPU_TABLE_H__ */ 
