/* ------------------------------------------------------------------------ */
/*  Hyper Operating System V4 Tiny  ��ITRON4.0���� Real-Time OS             */
/*  �̥����ͥ� ���塼���                                                   */
/*                                                                          */
/*                                  Copyright (C) 1998-2003 by Project HOS  */
/*                                  http://sourceforge.jp/projects/hos/     */
/* ------------------------------------------------------------------------ */


#include "kernel.h"



/* ������ͥ���ٽ���ɲ� */
void kernel_add_que(
		T_KERNEL_QUE *que,		/* �ɲä��륭�塼 */
		ID           tskid)		/* �ɲä��륿���� */
{
	T_KERNEL_TCB *tcb;
	T_KERNEL_TCB *tcb_ptr;
	ID           tskid_ptr;
	
	tcb = KERNEL_GET_TCB(tskid);
	
	/* ��³�������塼����Ͽ */
	tcb->que = que;
	
	if ( que->head == 0 )
	{
		/* ���塼�˥�������̵�������Ƭ������ */
		que->head  = tskid;
		tcb->next  = tskid;
		tcb->prev  = tskid;
	}
	else
	{
		/* ���塼��Ƭ���鸡�� */
		tskid_ptr = que->head;
		tcb_ptr   = KERNEL_GET_TCB(tskid_ptr);
		
		if ( tcb->tskpri < tcb_ptr->tskpri )	/* ��ͥ��ʤ� */
		{
			/* ��Ƭ�򹹿� */
			que->head  = tskid;
		}
		else
		{
			/* �������ָ��� */
			do {
				tskid_ptr = tcb_ptr->next;
				tcb_ptr   = KERNEL_GET_TCB(tskid_ptr);
			} while ( tcb->tskpri >= tcb_ptr->tskpri && tskid_ptr != que->head );
		}
		
		/* �������� */
		tcb->next     = tskid_ptr;
		tcb->prev     = tcb_ptr->prev;
		tcb_ptr->prev = tskid;
		KERNEL_GET_TCB(tcb->prev)->next = tskid;
	}
}


/* ------------------------------------------------------------------------ */
/*  Copyright (C) 1998-2003 by Project HOS                                  */
/* ------------------------------------------------------------------------ */
