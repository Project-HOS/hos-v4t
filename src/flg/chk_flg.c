/* ------------------------------------------------------------------------ */
/*  Hyper Operating System V4 Tiny  μITRON4.0仕様 Real-Time OS             */
/*    ITRONカーネル イベントフラグ                                          */
/*                                                                          */
/*                                  Copyright (C) 1998-2003 by Project HOS  */
/*                                  http://sourceforge.jp/projects/hos/     */
/* ------------------------------------------------------------------------ */


#include "kernel.h"



/* フラグが起床条件を満たしているかチェック */
BOOL kernel_chk_flg(
		T_KERNEL_FLGCB *flgcb)	/* コントロールブロック */
{
	if ( flgcb->wfmode == TWF_ANDW )
	{
		/* AND待ち判定 */
		return ((flgcb->flgptn & flgcb->waiptn) == flgcb->waiptn);
	}
	else
	{
		/* OR待ち判定 */
		return ((flgcb->flgptn & flgcb->waiptn) != 0);
	}
}


/* ------------------------------------------------------------------------ */
/*  Copyright (C) 1998-2003 by Project HOS                                  */
/* ------------------------------------------------------------------------ */
