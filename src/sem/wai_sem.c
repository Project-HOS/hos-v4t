/* ------------------------------------------------------------------------ */
/*  Hyper Operating System V4 Tiny  μITRON4.0仕様 Real-Time OS             */
/*    ITRONカーネル セマフォ                                                */
/*                                                                          */
/*                                  Copyright (C) 1998-2003 by Project HOS  */
/*                                  http://sourceforge.jp/projects/hos/     */
/* ------------------------------------------------------------------------ */


#include "kernel.h"



/* セマフォ資源の獲得 */
ER wai_sem(
		ID semid)	/* 資源獲得対象のセマフォID番号 */
{
	T_KERNEL_SEMCB *semcb;
	ID             tskid;

	kernel_loc_sys();	/* システムのロック */
	
	semcb = KERNEL_GET_SEMCB(semid);
	
	/* セマフォ資源が獲得できれば成功 */
	if ( semcb->semcnt > 0 )
	{
		semcb->semcnt--;	/* セマフォ資源の獲得 */
	}
	else
	{
		/* 実行中タスクIDの取得 */
		tskid = KERNEL_GET_RUN_TSKID();

		/* タスクを待ち状態にする */
		kernel_rmv_que(tskid);					/* レディーキューから取り外し */
		kernel_add_que(&semcb->que, tskid);		/* セマフォ待ち行列に追加 */
		
		/* タスクディスパッチの実行 */
		kernel_exe_dsp();
	}
		
	kernel_unl_sys();		/* システムのロック解除 */

	return E_OK;
}


/* ------------------------------------------------------------------------ */
/*  Copyright (C) 1998-2003 by Project HOS                                  */
/* ------------------------------------------------------------------------ */
