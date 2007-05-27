/* ------------------------------------------------------------------------ */
/*  HOS-V4  kernel configuration                                            */
/*    kernel object create and initialize                                   */
/*                                                                          */
/* ------------------------------------------------------------------------ */


#include "kernel.h"
#include "kernel_id.h"

#include "user_id.h"
#include "sample.h"
#include "sh7045.h"
#include "ostimer.h"
#include "sci.h"



/* ------------------------------------------ */
/*                 idle stack                 */
/* ------------------------------------------ */

VP         mknl_idl_stkblk[((128) + sizeof(VP) - 1) / sizeof(VP)];	/* idle stack block*/
const VP   mknl_idl_stk   = (VP)(mknl_idl_stkblk);	/* idle stack */
const SIZE mknl_idl_stksz = (SIZE)sizeof(mknl_idl_stkblk);	/* idle stack size */



/* ------------------------------------------ */
/*                kernel heap                 */
/* ------------------------------------------ */

VP kernel_heap_mem[((4096) + sizeof(VP) - 1) / sizeof(VP)];	/* kernel heap */



/* ------------------------------------------ */
/*          create task objects               */
/* ------------------------------------------ */

/* stack area */
static VP kernel_tsk1_stk[((512) + sizeof(VP) - 1) / sizeof(VP)];
static VP kernel_tsk2_stk[((512) + sizeof(VP) - 1) / sizeof(VP)];
static VP kernel_tsk3_stk[((512) + sizeof(VP) - 1) / sizeof(VP)];
static VP kernel_tsk4_stk[((512) + sizeof(VP) - 1) / sizeof(VP)];
static VP kernel_tsk5_stk[((512) + sizeof(VP) - 1) / sizeof(VP)];

/* task control block table */
const T_KERNEL_TCB kernel_tcb_tbl[6] =
	{
{{}, NULL,(PRI)0,(ID)0,(ID)0,(UB)0,NULL,NULL}, /* system */
{{}, NULL,(PRI)(1),(ID)0,(ID)1,(UB)0,(FP)(PhilosopherTask),(VP)kernel_tsk1_stk},
{{}, NULL,(PRI)(1),(ID)0,(ID)1,(UB)0,(FP)(PhilosopherTask),(VP)kernel_tsk2_stk},
{{}, NULL,(PRI)(1),(ID)0,(ID)1,(UB)0,(FP)(PhilosopherTask),(VP)kernel_tsk3_stk},
{{}, NULL,(PRI)(1),(ID)0,(ID)1,(UB)0,(FP)(PhilosopherTask),(VP)kernel_tsk4_stk},
{{}, NULL,(PRI)(1),(ID)0,(ID)1,(UB)0,(FP)(PhilosopherTask),(VP)kernel_tsk5_stk},
	};

/* task control block count */
const INT kernel_tcb_cnt = 5;



/* ------------------------------------------ */
/*         create semaphore objects           */
/* ------------------------------------------ */

/* semaphore control block for rom area */
const T_KERNEL_SEMCB_ROM kernel_semcb_rom[8] =
	{
		{(ATR)(TA_TFIFO), (UINT)(1), (UINT)(1)},
		{(ATR)(TA_TFIFO), (UINT)(1), (UINT)(1)},
		{(ATR)(TA_TFIFO), (UINT)(1), (UINT)(1)},
		{(ATR)(TA_TFIFO), (UINT)(1), (UINT)(1)},
		{(ATR)(TA_TFIFO), (UINT)(1), (UINT)(1)},
		{(ATR)(TA_TFIFO), (UINT)(1), (UINT)(1)},
		{(ATR)(TA_TFIFO), (UINT)(0), (UINT)(SCI_RCV_BUFSZ)},
		{(ATR)(TA_TFIFO), (UINT)(0), (UINT)(SCI_RCV_BUFSZ)},
	};

/* semaphore control block for ram area */
T_KERNEL_SEMCB_RAM kernel_semcb_ram[8];

/* semaphore control block table */
T_KERNEL_SEMCB_RAM *kernel_semcb_ram_tbl[8] =
	{
		&kernel_semcb_ram[0],
		&kernel_semcb_ram[1],
		&kernel_semcb_ram[2],
		&kernel_semcb_ram[3],
		&kernel_semcb_ram[4],
		&kernel_semcb_ram[5],
		&kernel_semcb_ram[6],
		&kernel_semcb_ram[7],
	};

/* semaphore control block count */
const INT kernel_semcb_cnt = 8;



/* ------------------------------------------ */
/*        create event flag objects           */
/* ------------------------------------------ */

/* event flag control block for rom area */
const T_KERNEL_FLGCB_ROM kernel_flgcb_rom[2] =
	{
		{(ATR)(TA_TFIFO | TA_WSGL | TA_CLR), (FLGPTN)(0)},
		{(ATR)(TA_TFIFO | TA_WSGL | TA_CLR), (FLGPTN)(0)},
	};

/* event flag control block for ram area */
T_KERNEL_FLGCB_RAM kernel_flgcb_ram[2];

/* event flag control block table */
T_KERNEL_FLGCB_RAM *kernel_flgcb_ram_tbl[2] =
	{
		&kernel_flgcb_ram[0],
		&kernel_flgcb_ram[1],
	};

/* event flag control block count */
const INT kernel_flgcb_cnt = 2;



/* ------------------------------------------ */
/*        interrupt control objects           */
/* ------------------------------------------ */

/* interrupt control */
T_KERNEL_INTCB kernel_intcb_tbl[257];		/* interrupt control block table */
const INT      kernel_intcb_cnt = 257;		/* interrupt control block count */
const INTNO    kernel_min_intno = 0;		/* minimum intrrupt number */

/* interrupt service routine control */
const INT      kernel_isrcb_cnt = 0;		/* ISR control block count */



/* ------------------------------------------ */
/*          initialize functions              */
/* ------------------------------------------ */

/* object initialize */
void hoscfg_ini(void)
{
	int i;
	
	
	/* initialize task control block */
	for ( i = 0; i < 5; i++ )
	{
		kernel_tcb_ram[i].tcb_rom = &kernel_tcb_rom[i];
	}
	
	
	/* initialize semaphore control block */
	for ( i = 0; i < 8; i++ )
	{
		kernel_semcb_ram[i].semcb_rom = &kernel_semcb_rom[i];
	}
	
	
	/* initialize event flag control block */
	for ( i = 0; i < 2; i++ )
	{
		kernel_flgcb_ram[i].flgcb_rom = &kernel_flgcb_rom[i];
	}

	/* initialize interrupt table */
	kernel_intcb_tbl[SH_INTNUM_CMI0].exinf = (VP_INT)(0);
	kernel_intcb_tbl[SH_INTNUM_CMI0].isr   = (FP)(ostim_hdr);
	kernel_intcb_tbl[SH_INTNUM_TXI0].exinf = (VP_INT)(1);
	kernel_intcb_tbl[SH_INTNUM_TXI0].isr   = (FP)(sci_snd_hdr);
	kernel_intcb_tbl[SH_INTNUM_RXI0].exinf = (VP_INT)(1);
	kernel_intcb_tbl[SH_INTNUM_RXI0].isr   = (FP)(sci_rcv_hdr);
	kernel_intcb_tbl[SH_INTNUM_TXI1].exinf = (VP_INT)(2);
	kernel_intcb_tbl[SH_INTNUM_TXI1].isr   = (FP)(sci_snd_hdr);
	kernel_intcb_tbl[SH_INTNUM_RXI1].exinf = (VP_INT)(2);
	kernel_intcb_tbl[SH_INTNUM_RXI1].isr   = (FP)(sci_rcv_hdr);
}

/* start up */
void kernel_cfg_start(void)
{
	kernel_ini_mem(kernel_heap_mem, sizeof(kernel_heap_mem));		/* initialize kernel heap */

	kernel_ini_tsk();		/* initialize task */
	kernel_ini_sem();		/* initialize semaphore */
	kernel_ini_flg();		/* initialize event flag */

	/* call initialize routine*/
	((FP)(ostim_init))((VP_INT)(30720 - 1));
	((FP)(SampleInitialize))((VP_INT)(0));
}


/* ------------------------------------------------------------------------ */
/*  End of file                                                             */
/* ------------------------------------------------------------------------ */
