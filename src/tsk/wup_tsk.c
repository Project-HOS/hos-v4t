/* ------------------------------------------------------------------------ */
/*  Hyper Operating System V4 Tiny  μITRON4.0仕様 Real-Time OS             */
/*    μカーネル タスク制御                                                 */
/*                                                                          */
/*                                  Copyright (C) 1998-2003 by Project HOS  */
/*                                  http://sourceforge.jp/projects/hos/     */
/* ------------------------------------------------------------------------ */


#include "kernel.h"



/* タスクの待ち解除 */
ER wup_tsk(
		ID tskid)	/* スリープ解除するタスク */
{
	T_KERNEL_TCB *tcb;
	
	kernel_loc_sys();	/* システムのロック */

	tcb = KERNEL_GET_TCB(tskid);
	
	if ( tcb->wupcnt++ == 0 )
	{
		/* レディーキューへ追加 */
		kernel_add_que(KERNEL_GET_RDYQUE(), tskid);

		/* ディスパッチ実行 */
		kernel_exe_dsp();
	}

	kernel_unl_sys();	/* システムのロック解除 */
	
	return E_OK;
}


/* ------------------------------------------------------------------------ */
/*  Copyright (C) 1998-2003 by Project HOS                                  */
/* ------------------------------------------------------------------------ */
