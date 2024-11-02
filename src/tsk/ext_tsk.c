/* ------------------------------------------------------------------------ */
/*  Hyper Operating System V4 Tiny  μITRON4.0仕様 Real-Time OS             */
/*    ITRONカーネル タスク管理機能                                          */
/*                                                                          */
/*                                  Copyright (C) 1998-2003 by Project HOS  */
/*                                  http://sourceforge.jp/projects/hos/     */
/* ------------------------------------------------------------------------ */


#include "kernel.h"



/* 自タスクの終了 */
void ext_tsk(void)
{
	ID tskid;

	kernel_loc_sys();	/* システムのロック */
	
	/* 実行中タスクIDの取得 */
	tskid = KERNEL_GET_RUN_TSKID();
	
	/* レディーキューから削除 */
	kernel_rmv_que(tskid);
	
	/* タスクディスパッチの実行 */
	kernel_exe_dsp();
}


/* ------------------------------------------------------------------------ */
/*  Copyright (C) 1998-2003 by Project HOS                                  */
/* ------------------------------------------------------------------------ */
