/* ------------------------------------------------------------------------ */
/*  Hyper Operating System V4 Tiny  μITRON4.0仕様 Real-Time OS             */
/*    ITRONカーネル タスク管理機能                                          */
/*                                                                          */
/*                                  Copyright (C) 1998-2003 by Project HOS  */
/*                                  http://sourceforge.jp/projects/hos/     */
/* ------------------------------------------------------------------------ */


#include "kernel.h"



/* タスクの起動(起動コード指定) */
ER sta_tsk(
		ID     tskid,	/* 起動対象のタスクID番号 */
		VP_INT stacd)	/* タスクの起動コード */
{
	T_KERNEL_TCB *tcb;
	
	kernel_loc_sys();	/* システムのロック */
	
	/* IDからタスクコントロールブロックRAM部取得 */
	tcb = KERNEL_GET_TCB(tskid);
	
	/* 実行コンテキスト登録 */
	hospac_cre_ctx(&tcb->ctxinf, tcb->isp, tcb->task, stacd);
	
	/* 初期化 */
	tcb->wupcnt = 1;
	
	/* 実行待ちキューに登録 */
	kernel_add_que(KERNEL_GET_RDYQUE(), tskid);
	
	/* タスクディスパッチの実行 */
	kernel_exe_dsp();
	
	kernel_unl_sys();	/* システムのロック解除 */
	
	return E_OK;
}


/* ------------------------------------------------------------------------ */
/*  Copyright (C) 1998-2003 by Project HOS                                  */
/* ------------------------------------------------------------------------ */
