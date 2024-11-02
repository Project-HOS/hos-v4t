/* ------------------------------------------------------------------------ */
/*  Hyper Operating System V4 Tiny  μITRON4.0仕様 Real-Time OS             */
/*    μカーネル タスク制御                                                 */
/*                                                                          */
/*                                  Copyright (C) 1998-2003 by Project HOS  */
/*                                  http://sourceforge.jp/projects/hos/     */
/* ------------------------------------------------------------------------ */


#include "kernel.h"



/* タスクのスリープ */
ER slp_tsk(void)
{
	T_KERNEL_TCB *tcb;
	ID           tskid;

	kernel_loc_sys();	/* システムのロック */
	
	/* 実行中タスクIDの取得 */
	tskid = KERNEL_GET_RUN_TSKID();
	
	tcb = KERNEL_GET_TCB(tskid);
	
	if ( --tcb->wupcnt == 0 )
	{
		/* レディーキューから削除 */
		kernel_rmv_que(tskid);

		/* ディスパッチ実行 */
		kernel_exe_dsp();
	}
	
	kernel_unl_sys();	/* システムのロック解除 */
	
	return E_OK;
}


/* ------------------------------------------------------------------------ */
/*  Copyright (C) 1998-2003 by Project HOS                                  */
/* ------------------------------------------------------------------------ */
