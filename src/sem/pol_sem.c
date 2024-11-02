/* ------------------------------------------------------------------------ */
/*  Hyper Operating System V4 Tiny  μITRON4.0仕様 Real-Time OS             */
/*    ITRONカーネル セマフォ                                                */
/*                                                                          */
/*                                  Copyright (C) 1998-2003 by Project HOS  */
/*                                  http://sourceforge.jp/projects/hos/     */
/* ------------------------------------------------------------------------ */


#include "kernel.h"



/* セマフォ資源の獲得(ポーリング) */
ER pol_sem(
		ID semid)	/* 資源獲得対象のセマフォID番号 */
{
	T_KERNEL_SEMCB *semcb;
	ER             ercd;

	kernel_loc_sys();		/* システムのロック */
	
	/* セマフォ資源が獲得できれば成功 */
	if ( semcb->semcnt > 0 )
	{
		semcb->semcnt--;	/* セマフォ資源の獲得 */
		ercd = E_OK;
	}
	else
	{
		ercd = E_TMOUT;		/* タイムアウト */
	}

	kernel_unl_sys();		/* システムのロック解除 */

	return ercd;
}


/* ------------------------------------------------------------------------ */
/*  Copyright (C) 1998-2003 by Project HOS                                  */
/* ------------------------------------------------------------------------ */
