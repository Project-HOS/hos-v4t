/* ------------------------------------------------------------------------ */
/*  Hyper Operating System V4 Tiny  μITRON4.0仕様 Real-Time OS             */
/*    ITRONカーネル タスク管理機能                                          */
/*                                                                          */
/*                                  Copyright (C) 1998-2003 by Project HOS  */
/*                                  http://sourceforge.jp/projects/hos/     */
/* ------------------------------------------------------------------------ */


#include "kernel.h"




/* タスク優先度の変更 */
ER chg_pri(
		ID  tskid,		/* 変更対象のタスクID番号 */
		PRI tskpri)		/* 変更後のベース優先度 */
{
	T_KERNEL_TCB *tcb;
	T_KERNEL_QUE *que;

	kernel_loc_sys();	/* システムのロック */
	
	/* 自タスク指定なら */
	if ( tskid == TSK_SELF )
	{
		tskid = KERNEL_GET_RUN_TSKID();		/* 実行中タスクIDの取得 */
	}
	
	/* TCB取得 */
	tcb = KERNEL_GET_TCB(tskid);

	/* キュー取得 */
	que = tcb->que;
	
	/* 優先度変更 */
	tcb->tskpri = tskpri;
	if ( que != NULL )		/* キューに繋がっていたなら */
	{
		kernel_rmv_que(tskid);			/* キューから一旦削除 */
		kernel_add_que(que, tskid);		/* キューに繋ぎ直し */
	}
		
	/* タスクディスパッチの実行 */
	kernel_exe_dsp();
	
	kernel_unl_sys();	/* システムのロック解除 */
	
	return E_OK;
}


/* ------------------------------------------------------------------------ */
/*  Copyright (C) 1998-2003 by Project HOS                                  */
/* ------------------------------------------------------------------------ */
