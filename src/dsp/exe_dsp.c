/* ------------------------------------------------------------------------ */
/*  Hyper Operating System V4 Tiny  μITRON4.0仕様 Real-Time OS             */
/*    μカーネル タスク制御                                                 */
/*                                                                          */
/*                                  Copyright (C) 1998-2003 by Project HOS  */
/*                                  http://sourceforge.jp/projects/hos/     */
/* ------------------------------------------------------------------------ */


#include "kernel.h"



/* タスクディスパッチの実行 */
void kernel_exe_dsp(void)
{
	T_HOSPAC_CTXINF *ctxinf_top;
	T_HOSPAC_CTXINF *ctxinf_run;
	ID              tskid_top;
	ID              tskid_run;

	/* 切り替えが必要かどうかチェック */
	if ( KERNEL_GET_RUN_TSKID() == kernel_ref_qhd(KERNEL_GET_RDYQUE()) )
	{
		return;
	}

	/* コンテキストチェック */
	if ( kernel_sys.stat != KERNEL_TSS_TSK )
	{
		kernel_sys.dly_dsp = TRUE;	/* ディスパッチ可能でなければ予約して終了 */
		return;
	}

	/* 最高優先度の実行可能タスクを取得 */
	tskid_top  = kernel_ref_qhd(KERNEL_GET_RDYQUE());
	ctxinf_top = &KERNEL_GET_TCB(tskid_top)->ctxinf;
	
	/* 実行中タスクIDの取得 */
	tskid_run  = KERNEL_GET_RUN_TSKID();
	ctxinf_run = &KERNEL_GET_TCB(tskid_run)->ctxinf;
	
	/* 実行タスクの登録 */
	KERNEL_SET_RUN_TSKID(tskid_top);
	
	/* タスクコンテキストスイッチ実行 */
	hospac_swi_ctx(ctxinf_run, ctxinf_top);
}


/* ------------------------------------------------------------------------ */
/*  Copyright (C) 1998-2003 by Project HOS                                  */
/* ------------------------------------------------------------------------ */
