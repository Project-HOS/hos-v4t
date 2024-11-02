/* ------------------------------------------------------------------------ */
/*  Hyper Operating System V4 Tiny  ��ITRON4.0���� Real-Time OS             */
/*    ITRON�����ͥ� ������������ǽ                                          */
/*                                                                          */
/*                                  Copyright (C) 1998-2003 by Project HOS  */
/*                                  http://sourceforge.jp/projects/hos/     */
/* ------------------------------------------------------------------------ */


#include "kernel.h"



/* ������ͥ���٤λ��� */
ER get_pri(
		ID  tskid,
		PRI *p_tskpri)
{
	T_KERNEL_TCB *tcb;

	kernel_loc_sys();	/* �����ƥ�Υ�å� */
	
	/* ������������ʤ� */
	if ( tskid == TSK_SELF )
	{
		tskid = KERNEL_GET_RUN_TSKID();		/* �¹��楿����ID�μ��� */
	}
	
	/* TCB���� */
	tcb = KERNEL_GET_TCB(tskid);
	
	/* ͥ���ټ��� */
	*p_tskpri = tcb->tskpri;
	
	kernel_unl_sys();	/* �����ƥ�Υ�å���� */
	
	return E_OK;
}


/* ------------------------------------------------------------------------ */
/*  Copyright (C) 1998-2003 by Project HOS                                  */
/* ------------------------------------------------------------------------ */
