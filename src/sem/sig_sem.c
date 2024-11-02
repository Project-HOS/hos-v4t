/* ------------------------------------------------------------------------ */
/*  Hyper Operating System V4 Tiny  μITRON4.0仕様 Real-Time OS             */
/*    ITRONカーネル セマフォ                                                */
/*                                                                          */
/*                                  Copyright (C) 1998-2003 by Project HOS  */
/*                                  http://sourceforge.jp/projects/hos/     */
/* ------------------------------------------------------------------------ */


#include "kernel.h"



/* セマフォ資源の返却 */
ER sig_sem(
		ID semid)		/* セマフォ資源返却対象のセマフォのID番号 */
{
	T_KERNEL_SEMCB *semcb;
	ID             tskid;
	
	kernel_loc_sys();	/* システムのロック */
	
	semcb = KERNEL_GET_SEMCB(semid);

#if 0
	/* キューイングオーバーフローチェック */
#ifdef HOS_ERCHK_E_QOVR
	if ( semcb_ram->semcnt >= semcb_rom->maxsem )
	{
		mknl_unl_sys();	/* システムのロック解除 */
		return E_QOVR;
	}
#endif
#endif
	
	tskid = kernel_ref_qhd(&semcb->que);	/* 待ち行列先頭からタスク取り出し */
	if ( tskid != 0 )
	{
		/* 待ちタスクがあれば待ち解除 */
		kernel_rmv_que(tskid);							/* セマフォの待ち行列から削除 */
		kernel_add_que(KERNEL_GET_RDYQUE(), tskid);		/* レディーキューに追加 */
		
		kernel_exe_dsp();						/* タスクディスパッチの実行 */
	}
	else
	{
		semcb->semcnt++;	/* セマフォ資源返却 */
	}

	kernel_unl_sys();	/* システムのロック解除 */

	return E_OK;	/* 成功 */
}


/* ------------------------------------------------------------------------ */
/*  Copyright (C) 1998-2003 by Project HOS                                  */
/* ------------------------------------------------------------------------ */
