/* ------------------------------------------------------------------------ */
/*  Hyper Operating System V4 Tiny  μITRON4.0仕様 Real-Time OS             */
/*  μカーネル キュー操作                                                   */
/*                                                                          */
/*                                  Copyright (C) 1998-2003 by Project HOS  */
/*                                  http://sourceforge.jp/projects/hos/     */
/* ------------------------------------------------------------------------ */


#include "kernel.h"



/* タスク優先度順で追加 */
void kernel_add_que(
		T_KERNEL_QUE *que,		/* 追加するキュー */
		ID           tskid)		/* 追加するタスク */
{
	T_KERNEL_TCB *tcb;
	T_KERNEL_TCB *tcb_ptr;
	ID           tskid_ptr;
	
	tcb = KERNEL_GET_TCB(tskid);
	
	/* 接続したキューを登録 */
	tcb->que = que;
	
	if ( que->head == 0 )
	{
		/* キューにタスクが無ければ先頭に設定 */
		que->head  = tskid;
		tcb->next  = tskid;
		tcb->prev  = tskid;
	}
	else
	{
		/* キュー先頭から検索 */
		tskid_ptr = que->head;
		tcb_ptr   = KERNEL_GET_TCB(tskid_ptr);
		
		if ( tcb->tskpri < tcb_ptr->tskpri )	/* 最優先なら */
		{
			/* 先頭を更新 */
			que->head  = tskid;
		}
		else
		{
			/* 挿入位置検索 */
			do {
				tskid_ptr = tcb_ptr->next;
				tcb_ptr   = KERNEL_GET_TCB(tskid_ptr);
			} while ( tcb->tskpri >= tcb_ptr->tskpri && tskid_ptr != que->head );
		}
		
		/* 挿入処理 */
		tcb->next     = tskid_ptr;
		tcb->prev     = tcb_ptr->prev;
		tcb_ptr->prev = tskid;
		KERNEL_GET_TCB(tcb->prev)->next = tskid;
	}
}


/* ------------------------------------------------------------------------ */
/*  Copyright (C) 1998-2003 by Project HOS                                  */
/* ------------------------------------------------------------------------ */
