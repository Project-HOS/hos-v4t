/* ------------------------------------------------------------------------ */
/*  Hyper Operating System V4 Tiny  ��ITRON4.0���� Real-Time OS             */
/*    �̥����ͥ� ����������                                                 */
/*                                                                          */
/*                                  Copyright (C) 1998-2003 by Project HOS  */
/*                                  http://sourceforge.jp/projects/hos/     */
/* ------------------------------------------------------------------------ */


#include "kernel.h"



/* �������Υ��꡼�� */
ER slp_tsk(void)
{
	T_KERNEL_TCB *tcb;
	ID           tskid;

	kernel_loc_sys();	/* �����ƥ�Υ�å� */
	
	/* �¹��楿����ID�μ��� */
	tskid = KERNEL_GET_RUN_TSKID();
	
	tcb = KERNEL_GET_TCB(tskid);
	
	if ( --tcb->wupcnt == 0 )
	{
		/* ��ǥ������塼������ */
		kernel_rmv_que(tskid);

		/* �ǥ����ѥå��¹� */
		kernel_exe_dsp();
	}
	
	kernel_unl_sys();	/* �����ƥ�Υ�å���� */
	
	return E_OK;
}


/* ------------------------------------------------------------------------ */
/*  Copyright (C) 1998-2003 by Project HOS                                  */
/* ------------------------------------------------------------------------ */
