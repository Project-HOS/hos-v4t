/* ------------------------------------------------------------------------ */
/*  Hyper Operating System V4 Tiny  μITRON4.0仕様 Real-Time OS             */
/*    ITRONカーネル イベントフラグ                                          */
/*                                                                          */
/*                                  Copyright (C) 1998-2003 by Project HOS  */
/*                                  http://sourceforge.jp/projects/hos/     */
/* ------------------------------------------------------------------------ */


#include "kernel.h"



/* イベントフラグのクリア */
ER clr_flg(
		ID     flgid,	/* クリア対象のイベントフラグのID番号 */
		FLGPTN clrptn)	/* クリアするビットパターン(ビット毎の反転値) */
{
	T_KERNEL_FLGCB *flgcb;

	kernel_loc_sys();	/* システムのロック */

	flgcb = KERNEL_GET_FLGCB(flgid);

	/* フラグのクリア */
	flgcb->flgptn = (FLGPTN)(flgcb->flgptn & clrptn);

	kernel_unl_sys();	/* システムのロック解除 */

	return E_OK;
}


/* ------------------------------------------------------------------------ */
/*  Copyright (C) 1998-2003 by Project HOS                                  */
/* ------------------------------------------------------------------------ */
