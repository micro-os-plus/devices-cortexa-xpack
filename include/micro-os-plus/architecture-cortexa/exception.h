/*
 * This file is part of the µOS++ distribution.
 *   (https://github.com/micro-os-plus/)
 * Copyright (c) 2014 Takeharu KATO.
 * Copyright (c) 2022 Liviu Ionescu.
 *
 * Permission to use, copy, modify, and/or distribute this software
 * for any purpose is hereby granted, under the terms of the MIT license.
 *
 * If a copy of the license was not distributed with this file, it can
 * be obtained from https://opensource.org/licenses/MIT/.
 */

#if !defined(MICRO_OS_PLUS_ARCHITECTURE_CORTEXA_EXCEPTION_H_)
#define MICRO_OS_PLUS_ARCHITECTURE_CORTEXA_EXCEPTION_H_

/* Vector Table
 * see 5.1.1 Setting up a vector table in
 * Application Note Bare-metal Boot Code for ARMv8-A Processors Version 1.0
 */

/*
 * AArch64 exception types
 */
/* Current EL with SP0 */
#define AARCH64_EXC_SYNC_SP0      (0x1)   /* Synchronous */
#define AARCH64_EXC_IRQ_SP0       (0x2)   /* IRQ/vIRQ */
#define AARCH64_EXC_FIQ_SP0       (0x3)   /* FIQ/vFIQ */
#define AARCH64_EXC_SERR_SP0      (0x4)   /* SError/vSError */
/* Current EL with SPx */
#define AARCH64_EXC_SYNC_SPX      (0x11)
#define AARCH64_EXC_IRQ_SPX       (0x12)
#define AARCH64_EXC_FIQ_SPX       (0x13)
#define AARCH64_EXC_SERR_SPX      (0x14)
/* Lower EL using AArch64 */
#define AARCH64_EXC_SYNC_AARCH64  (0x21)
#define AARCH64_EXC_IRQ_AARCH64   (0x22)
#define AARCH64_EXC_FIQ_AARCH64   (0x23)
#define AARCH64_EXC_SERR_AARCH64  (0x24)
/* Lower EL using AArch32 */
#define AARCH64_EXC_SYNC_AARCH32  (0x31)
#define AARCH64_EXC_IRQ_AARCH32   (0x32)
#define AARCH64_EXC_FIQ_AARCH32   (0x33)
#define AARCH64_EXC_SERR_AARCH32  (0x34)

#if defined(__ASSEMBLY__)
#define vector_table_align .align 11    /* Vector tables must be placed at a 2KB-aligned address */
#define vector_entry_align .align 7     /* Each entry is 128B in size*/
#define text_align .align  2            /* Text alignment */
#endif /* __ASSEMBLY__ */


/*
 * exception_frame offset definitions
 */
#define EXC_FRAME_SIZE (288)	/* sizeof(struct _exception_frame) */
#define EXC_EXC_TYPE_OFFSET (0)	/* __asm_offsetof(struct _exception_frame, exc_type) */
#define EXC_EXC_ESR_OFFSET (8)	/* __asm_offsetof(struct _exception_frame, exc_esr) */
#define EXC_EXC_SP_OFFSET (16)	/* __asm_offsetof(struct _exception_frame, exc_sp) */
#define EXC_EXC_ELR_OFFSET (24)	/* __asm_offsetof(struct _exception_frame, exc_elr) */
#define EXC_EXC_SPSR_OFFSET (32)/* __asm_offsetof(struct _exception_frame, exc_spsr) */

/*
 * IRQ
 */
#define IRQ_FOUND          (0)
#define IRQ_NOT_FOUND      (1)

#endif // MICRO_OS_PLUS_ARCHITECTURE_CORTEXA_EXCEPTION_H_
