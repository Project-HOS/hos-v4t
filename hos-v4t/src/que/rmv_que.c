/* ------------------------------------------------------------------------ */
/*  Hyper Operating System V4 Tiny  ��ITRON4.0���� Real-Time OS             */
/*  �̥����ͥ� ���塼���                                                   */
/*                                                                          */
/*                                  Copyright (C) 1998-2003 by Project HOS  */
/*                                  http://sourceforge.jp/projects/hos/     */
/* ------------------------------------------------------------------------ */


#include "kernel.h"



/* �������򥭥塼���鳰�� */
void kernel_rmv_que(
		ID           tskid)
{
	T_KERNEL_QUE *que;
	T_KERNEL_TCB *tcb;
	T_KERNEL_TCB *tcb_next;
	T_KERNEL_TCB *tcb_prev;
	ID           tskid_next;
	ID           tskid_prev;
	
	tcb = KERNEL_GET_TCB(tskid);

	/* ���塼����� */
	que = tcb->que;

	if ( tcb->next == tskid )
	{
		que->head = 0;
	}
	else
	{
		tskid_next = tcb->next;
		tskid_prev = tcb->prev;
		tcb_next = KERNEL_GET_TCB(tskid_next);
		tcb_prev = KERNEL_GET_TCB(tskid_prev);
		tcb_next->prev = tskid_prev;
		tcb_prev->next = tskid_next;
		if ( que->head == tskid )
		{
			que->head = tskid_next;
		}
	}
	
	/* ���塼����Ͽ��� */
	tcb->que = NULL;
}


/* ------------------------------------------------------------------------ */
/*  Copyright (C) 1998-2003 by Project HOS                                  */
/* ------------------------------------------------------------------------ */
