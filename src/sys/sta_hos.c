/* ------------------------------------------------------------------------ */
/*  Hyper Operating System V4 Tiny  μITRON4.0仕様 Real-Time OS             */
/*    システム                                                              */
/*                                                                          */
/*                                  Copyright (C) 1998-2003 by Project HOS  */
/*                                  http://sourceforge.jp/projects/hos/     */
/* ------------------------------------------------------------------------ */


#include "kernel.h"


/*T_KERNEL_SYS kernel_sys;	*/		/* システム状態 */
UW           kernel_idl_stk[16];	


static void kernel_idle(VP_INT exinf);


/* HOS カーネル動作開始 */
ER sta_hos(void)
{
	T_HOSPAC_CTXINF ctxinf_dmy;
	T_HOSPAC_CTXINF *ctxinf_top;
	ID              tskid_top;
	
	/* ディスパッチを禁止 */
	kernel_sys.stat = KERNEL_TSS_DDSP;
	
	/* アイドルタスク生成 */
	hospac_cre_ctx(&kernel_sys.ctxinf_idle,  &kernel_idl_stk[16], kernel_idle, 0);
	
	/* コンフィギュレータの初期化呼び出し */
	hoscfg_ini();

	/* ディスパッチを許可 */
	kernel_sys.stat = KERNEL_TSS_TSK;

	/* 最高優先度の実行可能タスクを取得 */
	tskid_top  = kernel_ref_qhd(KERNEL_GET_RDYQUE());
	ctxinf_top = &KERNEL_GET_TCB(tskid_top)->ctxinf;

	/* 実行タスクの登録 */
	KERNEL_SET_RUN_TSKID(tskid_top);

	/* タスク切り替え */
	hospac_swi_ctx(&ctxinf_dmy, ctxinf_top);
	
	return E_OK;
}


/* アイドルタスク */
void kernel_idle(VP_INT exinf)
{
	for ( ; ; )
	{
		hospac_idle();
	}
}


/* ------------------------------------------------------------------------ */
/*  Copyright (C) 1998-2003 by Project HOS                                  */
/* ------------------------------------------------------------------------ */
