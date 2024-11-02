/* ------------------------------------------------------------------------ */
/*  Hyper Operating System V4 Tiny  ��ITRON4.0���� Real-Time OS             */
/*    ITRON�����ͥ� ������������ǽ                                          */
/*                                                                          */
/*                                  Copyright (C) 1998-2003 by Project HOS  */
/*                                  http://sourceforge.jp/projects/hos/     */
/* ------------------------------------------------------------------------ */


#include "kernel.h"




/* ������ͥ���٤��ѹ� */
ER chg_pri(
		ID  tskid,		/* �ѹ��оݤΥ�����ID�ֹ� */
		PRI tskpri)		/* �ѹ���Υ١���ͥ���� */
{
	T_KERNEL_TCB *tcb;
	T_KERNEL_QUE *que;

	kernel_loc_sys();	/* �����ƥ�Υ�å� */
	
	/* ������������ʤ� */
	if ( tskid == TSK_SELF )
	{
		tskid = KERNEL_GET_RUN_TSKID();		/* �¹��楿����ID�μ��� */
	}
	
	/* TCB���� */
	tcb = KERNEL_GET_TCB(tskid);

	/* ���塼���� */
	que = tcb->que;
	
	/* ͥ�����ѹ� */
	tcb->tskpri = tskpri;
	if ( que != NULL )		/* ���塼�˷Ҥ��äƤ����ʤ� */
	{
		kernel_rmv_que(tskid);			/* ���塼�����ö��� */
		kernel_add_que(que, tskid);		/* ���塼�˷Ҥ�ľ�� */
	}
		
	/* �������ǥ����ѥå��μ¹� */
	kernel_exe_dsp();
	
	kernel_unl_sys();	/* �����ƥ�Υ�å���� */
	
	return E_OK;
}


/* ------------------------------------------------------------------------ */
/*  Copyright (C) 1998-2003 by Project HOS                                  */
/* ------------------------------------------------------------------------ */
