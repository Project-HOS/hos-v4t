/* ------------------------------------------------------------------------ */
/*  Hyper Operating System V4 Tiny  ��ITRON4.0���� Real-Time OS             */
/*    �̥����ͥ� ����������                                                 */
/*                                                                          */
/*                                  Copyright (C) 1998-2003 by Project HOS  */
/*                                  http://sourceforge.jp/projects/hos/     */
/* ------------------------------------------------------------------------ */


#include "kernel.h"



/* ���������Ԥ���� */
ER wup_tsk(
		ID tskid)	/* ���꡼�ײ�����륿���� */
{
	T_KERNEL_TCB *tcb;
	
	kernel_loc_sys();	/* �����ƥ�Υ�å� */

	tcb = KERNEL_GET_TCB(tskid);
	
	if ( tcb->wupcnt++ == 0 )
	{
		/* ��ǥ������塼���ɲ� */
		kernel_add_que(KERNEL_GET_RDYQUE(), tskid);

		/* �ǥ����ѥå��¹� */
		kernel_exe_dsp();
	}

	kernel_unl_sys();	/* �����ƥ�Υ�å���� */
	
	return E_OK;
}


/* ------------------------------------------------------------------------ */
/*  Copyright (C) 1998-2003 by Project HOS                                  */
/* ------------------------------------------------------------------------ */
