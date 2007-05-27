/* ------------------------------------------------------------------------ */
/*  Hyper Operating System V4 Tiny  μITRON4.0仕様 Real-Time OS             */
/*    ITRONカーネル イベントフラグ                                          */
/*                                                                          */
/*                                  Copyright (C) 1998-2003 by Project HOS  */
/*                                  http://sourceforge.jp/projects/hos/     */
/* ------------------------------------------------------------------------ */


#include "kernel.h"



/* イベントフラグ待ち(ポーリング) */
ER pol_flg(
		ID     flgid,
		FLGPTN waiptn,
		MODE   wfmode,
		FLGPTN *p_flgptn)
{
	T_KERNEL_FLGCB *flgcb;
	ER             ercd;

	kernel_loc_sys();	/* システムのロック */

	flgcb = KERNEL_GET_FLGCB(flgid);

	/* 待ち条件設定 */
	flgcb->waiptn = waiptn;
	flgcb->wfmode = wfmode;
	
	/* フラグチェック */
	if ( kernel_chk_flg(flgcb) )
	{
		/* 既に条件を満たしているなら */
		if ( p_flgptn != NULL )
		{
			*p_flgptn = flgcb->flgptn;		/* 解除時のフラグパターンを格納 */
		}
		ercd = E_OK;
	}
	else
	{
		/* 既に条件を満たしていなければタイムアウト */
		ercd = E_TMOUT;
	}
	
	kernel_unl_sys();	/* システムのロック解除 */

	return ercd;
}


/* ------------------------------------------------------------------------ */
/*  Copyright (C) 1998-2003 by Project HOS                                  */
/* ------------------------------------------------------------------------ */
