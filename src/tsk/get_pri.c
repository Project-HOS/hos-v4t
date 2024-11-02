/* ------------------------------------------------------------------------ */
/*  Hyper Operating System V4 Tiny  μITRON4.0仕様 Real-Time OS             */
/*    ITRONカーネル タスク管理機能                                          */
/*                                                                          */
/*                                  Copyright (C) 1998-2003 by Project HOS  */
/*                                  http://sourceforge.jp/projects/hos/     */
/* ------------------------------------------------------------------------ */


#include "kernel.h"



/* タスク優先度の参照 */
ER get_pri(
		ID  tskid,
		PRI *p_tskpri)
{
	T_KERNEL_TCB *tcb;

	kernel_loc_sys();	/* システムのロック */
	
	/* 自タスク指定なら */
	if ( tskid == TSK_SELF )
	{
		tskid = KERNEL_GET_RUN_TSKID();		/* 実行中タスクIDの取得 */
	}
	
	/* TCB取得 */
	tcb = KERNEL_GET_TCB(tskid);
	
	/* 優先度取得 */
	*p_tskpri = tcb->tskpri;
	
	kernel_unl_sys();	/* システムのロック解除 */
	
	return E_OK;
}


/* ------------------------------------------------------------------------ */
/*  Copyright (C) 1998-2003 by Project HOS                                  */
/* ------------------------------------------------------------------------ */
