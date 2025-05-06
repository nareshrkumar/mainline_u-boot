// SPDX-License-Identifier: GPL-2.0
/*
 * Copyright (C) 2025 Altera Corporation <www.altera.com>
 */

#include <asm/system.h>
#include <cpu_func.h>
#include <linux/sizes.h>
#include "sdram_soc32.h"

DECLARE_GLOBAL_DATA_PTR;

#define PGTABLE_OFF	0x4000

/* Initialize SDRAM ECC bits to avoid false DBE */
void sdram_init_ecc_bits(u32 size)
{
	icache_enable();

	memset(0, 0, 0x8000);
	gd->arch.tlb_addr = 0x4000;
	gd->arch.tlb_size = PGTABLE_SIZE;

	dcache_enable();

	printf("DDRCAL: Scrubbing ECC RAM (%i MiB).\n", size >> 20);
	memset((void *)0x8000, 0, size - 0x8000);
	flush_dcache_all();
	printf("DDRCAL: Scrubbing ECC RAM done.\n");
	dcache_disable();
}
