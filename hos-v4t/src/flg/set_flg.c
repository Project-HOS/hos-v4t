/* ------------------------------------------------------------------------ */
/*  Hyper Operating System V4 Tiny  μITRON4.0仕様 Real-Time OS             */
/*    ITRONカーネル イベントフラグ                                          */
/*                                                                          */
/*                                  Copyright (C) 1998-2003 by Project HOS  */
/*                                  http://sourceforge.jp/projects/hos/     */
/* ------------------------------------------------------------------------ */


#include "kernel.h"



/* イベントフラグのセット */
ER set_flg(
		ID     flgid,		/* セット対象のイベントフラグのID番号 */
		FLGPTN setptn)		/* セットするビットパターン */
{
	T_KERNEL_FLGCB *flgcb;

	kernel_loc_sys();	/* システムのロック */

	flgcb = KERNEL_GET_FLGCB(flgid);
	
	/* フラグのセット */
	flgcb->flgptn = (FLGPTN)(flgcb->flgptn | setptn);
	
	/* 待ちタスクがあれば起床チェック */
	if ( flgcb->tskid != 0 )
	{
		/* フラグチェック */
		if ( kernel_chk_flg(flgcb) )
		{
			/* 起床条件を満たしているなら */
			if ( flgcb->p_flgptn != NULL )
			{
				*flgcb->p_flgptn = flgcb->flgptn;	/* 現在のフラグパターンを格納 */
			}
			
			/* 待ち解除 */
			kernel_add_que(KERNEL_GET_RDYQUE(), flgcb->tskid);		/* レディーキューに登録 */

			kernel_exe_dsp();		/* タスクディスパッチの実行 */
		}
	}
	
	kernel_unl_sys();	/* システムのロック解除 */
	
	return E_OK;	/* 正常終了 */
}


/* ------------------------------------------------------------------------ */
/*  Copyright (C) 1998-2003 by Project HOS                                  */
/* ------------------------------------------------------------------------ */
