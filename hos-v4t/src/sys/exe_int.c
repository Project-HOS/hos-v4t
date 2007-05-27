/* ------------------------------------------------------------------------ */
/*  Hyper Operating System V4  μITRON4.0仕様 Real-Time OS                  */
/*    ITRONカーネル 割り込み制御                                            */
/*                                                                          */
/*                                  Copyright (C) 1998-2003 by Project HOS  */
/*                                  http://sourceforge.jp/projects/hos/     */
/* ------------------------------------------------------------------------ */


#include "kernel.h"



/* 割り込みコンテキストの開始 */
void kernel_sta_int(void)
{
	/* 非タスク部(割り込みコンテキストに移行) */
	kernel_sys.stat = KERNEL_TSS_INDP;
}


/* 割り込みコンテキストの終了 */
void kernel_end_int(void)
{
	/* タスク部に移行 */
	kernel_sys.stat = KERNEL_TSS_TSK;

	/* 遅延ディスパッチ実行 */
	kernel_exe_dsp();
}


/* 割り込み処理実行 */
void kernel_exe_int(
		INTNO intno)		/* 割り込み番号 */
{
	const T_KERNEL_INTCB *intcb;
	
	intcb = KERNEL_GET_INTCB(intno);
	
	kernel_unl_sys();		/* 多重割り込み許可 */
	
	if ( intcb->isr != NULL )
	{
		intcb->isr(intcb->exinf); /* 割り込みサービスルーチン実行 */
	}
	
	kernel_loc_sys();		/* 多重割り込み禁止 */
}


/* ------------------------------------------------------------------------ */
/*  Copyright (C) 1998-2003 by Project HOS                                  */
/* ------------------------------------------------------------------------ */
