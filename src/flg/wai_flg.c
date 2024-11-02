/* ------------------------------------------------------------------------ */
/*  Hyper Operating System V4 Tiny  μITRON4.0仕様 Real-Time OS             */
/*    ITRONカーネル イベントフラグ                                          */
/*                                                                          */
/*                                  Copyright (C) 1998-2003 by Project HOS  */
/*                                  http://sourceforge.jp/projects/hos/     */
/* ------------------------------------------------------------------------ */


#include "kernel.h"



/* イベントフラグ待ち */
ER wai_flg(
		ID     flgid,		/* 待ち対象のイベントフラグのID番号 */
		FLGPTN waiptn,		/* 待ちビットパターン */
		MODE   wfmode,		/* 待ちモード */
		FLGPTN *p_flgptn)	/* 待ち解除時のビットパターン格納アドレス */
{
	T_KERNEL_FLGCB *flgcb;
	ID             tskid;

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
	}
	else
	{
		/* 条件を満たしていなければ待ちに入る */
		tskid           = KERNEL_GET_RUN_TSKID();	/* 実行中タスクIDの取得 */
		flgcb->tskid    = tskid;					/* 待ちタスクの登録 */
		flgcb->p_flgptn = p_flgptn;					/*  待ち解除時のビットパターン格納アドレス保存 */
		kernel_rmv_que(tskid);						/* レディーキューから取り外し */
		
		/* タスクディスパッチ実行 */
		kernel_exe_dsp();
	}
	
	kernel_unl_sys();	/* システムのロック解除 */
	
	return E_OK;
}


/* ------------------------------------------------------------------------ */
/*  Copyright (C) 1998-2003 by Project HOS                                  */
/* ------------------------------------------------------------------------ */
