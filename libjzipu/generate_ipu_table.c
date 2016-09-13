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
#include <stdio.h>
#include <malloc.h>

struct Ration2m
{
  float ratio;
  int n, m;
};

#define IPU_LUT_LEN (32)
struct host_ipu_table
{
	int cnt;
	struct Ration2m ipu_ratio_table[IPU_LUT_LEN*IPU_LUT_LEN];
};

int main(int argc, char *argv[])
{
	unsigned int i, j, cnt;
	float diff;
	struct Ration2m *ipu_ratio_table;


	ipu_ratio_table = (struct Ration2m *)malloc(sizeof(struct Ration2m) * IPU_LUT_LEN*IPU_LUT_LEN);

	if (ipu_ratio_table == 0) {
		printf("too small memory!\n");
		return (-1);
	}
	// orig table, first calculate
	for (i = 1; i <= (IPU_LUT_LEN); i++) {
		for (j = 1; j <= (IPU_LUT_LEN); j++) {
			ipu_ratio_table[(i - 1) * IPU_LUT_LEN + j - 1].ratio = i / (float)j;
			ipu_ratio_table[(i - 1) * IPU_LUT_LEN + j - 1].n = i;
			ipu_ratio_table[(i - 1) * IPU_LUT_LEN + j - 1].m = j;
		}
	}
	// Eliminate the ratio greater than 1:2
	for (i = 0; i < (IPU_LUT_LEN) * (IPU_LUT_LEN); i++) {
		if (ipu_ratio_table[i].ratio < 0.031249) {
			ipu_ratio_table[i].n = ipu_ratio_table[i].m = -1;
		}
	}
	// eliminate the same ratio
	for (i = 0; i < (IPU_LUT_LEN) * (IPU_LUT_LEN); i++) {
		for (j = i + 1; j < (IPU_LUT_LEN) * (IPU_LUT_LEN); j++) {
			diff =
			    ipu_ratio_table[i].ratio - ipu_ratio_table[j].ratio;
			if (diff > -0.001 && diff < 0.001) {
				ipu_ratio_table[j].n = -1;
				ipu_ratio_table[j].m = -1;
			}
		}
	}

	// reorder ipu_ratio_table
	cnt = 0;
	for (i = 0; i < (IPU_LUT_LEN) * (IPU_LUT_LEN); i++) {
		if (ipu_ratio_table[i].n != -1) {
			if (cnt != i) {
				ipu_ratio_table[cnt] = ipu_ratio_table[i];
			}
			cnt++;
		}
	}
	printf("#include <android_jz_ipu.h>\n");
	printf("struct host_ipu_table hostiputable = {");
	printf("{%d},{\n\t",cnt);	
	int n = 0;
	for (i = 1; i <= (IPU_LUT_LEN); i++) {
		for (j = 1; j <= (IPU_LUT_LEN); j++) {
			printf("{%06f, %2d, %2d}",
			       ipu_ratio_table[(i - 1) * IPU_LUT_LEN + j - 1].ratio,
			       ipu_ratio_table[(i - 1) * IPU_LUT_LEN + j - 1].n,
			       ipu_ratio_table[(i - 1) * IPU_LUT_LEN + j - 1].m);
			n++;
			if((n != IPU_LUT_LEN * IPU_LUT_LEN))
			{
				if((n % 4 == 0))
				{
					printf(",\n\t");
				}else
					printf(",");
			}else
				printf("\n\t");
		}
	}
	printf("}};");
	return (0);
}

