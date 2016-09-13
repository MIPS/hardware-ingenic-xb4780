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
 *	  qipengzhen <aric.pzqi@ingenic.com>
 *    liuyang <king.lyang@ingenic.com>
 */

#ifndef _JZ_DMMU_H_
#define _JZ_DMMU_H_

__BEGIN_DECLS

#include <hardware/hardware.h>

#define DMMU_DEV_NAME "/dev/dmmu"
#define DMMU_PAGE_SIZE 4096

#define DMMU_IOCTL_MAGIC 'd'

#define DMMU_GET_PAGE_TABLE_BASE_PHYS		_IOW(DMMU_IOCTL_MAGIC, 0x01, unsigned int)
#define DMMU_GET_BASE_PHYS                  _IOR(DMMU_IOCTL_MAGIC, 0x02, unsigned int)
#define DMMU_MAP_USER_MEM		            _IOWR(DMMU_IOCTL_MAGIC, 0x11, struct dmmu_mem_info)
#define DMMU_UNMAP_USER_MEM		            _IOW(DMMU_IOCTL_MAGIC, 0x12, struct dmmu_mem_info)
#define DMMU_GET_TLB_PHYS                   _IOWR(DMMU_IOCTL_MAGIC, 0x13, struct dmmu_mem_info)
#define DMMU_SET_TABLE_FLAG 	            _IOW(DMMU_IOCTL_MAGIC, 0x34, int)

#define DMMU_DUMP_TLB_TABLE					_IOW(DMMU_IOCTL_MAGIC, 0x41, int)

#define VIDEO_TABLE_FLAGE 1

struct dmmu_mem_info {
	int size;
	int page_count;

	unsigned int paddr;

	void *vaddr;
	void *pages_phys_addr_table;

	unsigned int start_offset;
	unsigned int end_offset;
};

static inline void init_page_count(struct dmmu_mem_info *info)
{
	int page_count;
	unsigned int start;			/* page start */
	unsigned int end;			/* page end */

	start = ((unsigned int)info->vaddr) & (~(DMMU_PAGE_SIZE-1));
	end = ((unsigned int)info->vaddr + (info->size-1)) & (~(DMMU_PAGE_SIZE-1));
	page_count = (end - start)/(DMMU_PAGE_SIZE) + 1;

	info->page_count = page_count;
	info->start_offset = (unsigned int)info->vaddr - start;
	info->end_offset = ((unsigned int)info->vaddr + info->size) - end; 

	return;
}

static inline int dump_mem_info(struct dmmu_mem_info *mem, char * description)
{
	if (mem == NULL) {
		ALOGD("mem is NULL!\n");
		return -1;
	}
	ALOGD("mem: %p, \t%s", mem, description?description:"");
	ALOGD("\tvaddr= %p,", mem->vaddr);
	ALOGD("\tsize= %d (0x%x)", mem->size, mem->size);
	ALOGD("\tpaddr= 0x%08x", mem->paddr);
	ALOGD("\tpage_count= %d", mem->page_count);
	ALOGD("\tpages_phys_addr_table=%p", mem->pages_phys_addr_table);
	ALOGD("\tstart_offset= %d", mem->start_offset);
	ALOGD("\tend_offset= %d", mem->end_offset);

	return 0;
}

enum REQUIRE_ALLOC_PAGE_TABLE {
	NO_REQUIRED = 0,
	REQUIRED = 1,
};

extern int dmmu_init();
extern int dmmu_set_table_flag(void);
extern int dmmu_init_with_set_page_table(unsigned int * phys_addr, int size);
extern int dmmu_deinit();
extern int dmmu_get_page_table_base_phys(unsigned int * phys_addr);
extern int dmmu_set_page_table(unsigned int * phys_addr, int size);
extern int dmmu_map_user_memory(struct dmmu_mem_info* mem);
extern int dmmu_unmap_user_memory(struct dmmu_mem_info* mem);

extern int dmmu_map_user_mem(void * vaddr, int size);
extern int dmmu_unmap_user_mem(void * vaddr, int size);

extern int dmmu_match_user_mem_tlb(void * vaddr, int size);

extern int dmmu_get_memory_physical_address(struct dmmu_mem_info* mem);
extern int dmmu_release_memory_physical_address(struct dmmu_mem_info* mem);

__END_DECLS

#endif	/*  _JZ_DMMU_H_ */
