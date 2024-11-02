/* ------------------------------------------------------------------------ */
/*  Hyper Operating System V4 Tiny  ��ITRON4.0���� Real-Time OS             */
/*    ITRON�����ͥ� ���ޥե�                                                */
/*                                                                          */
/*                                  Copyright (C) 1998-2003 by Project HOS  */
/*                                  http://sourceforge.jp/projects/hos/     */
/* ------------------------------------------------------------------------ */


#include "kernel.h"



/* ���ޥե��񸻤γ��� */
ER wai_sem(
		ID semid)	/* �񸻳����оݤΥ��ޥե�ID�ֹ� */
{
	T_KERNEL_SEMCB *semcb;
	ID             tskid;

	kernel_loc_sys();	/* �����ƥ�Υ�å� */
	
	semcb = KERNEL_GET_SEMCB(semid);
	
	/* ���ޥե��񸻤������Ǥ�������� */
	if ( semcb->semcnt > 0 )
	{
		semcb->semcnt--;	/* ���ޥե��񸻤γ��� */
	}
	else
	{
		/* �¹��楿����ID�μ��� */
		tskid = KERNEL_GET_RUN_TSKID();

		/* ���������Ԥ����֤ˤ��� */
		kernel_rmv_que(tskid);					/* ��ǥ������塼�����곰�� */
		kernel_add_que(&semcb->que, tskid);		/* ���ޥե��Ԥ�������ɲ� */
		
		/* �������ǥ����ѥå��μ¹� */
		kernel_exe_dsp();
	}
		
	kernel_unl_sys();		/* �����ƥ�Υ�å���� */

	return E_OK;
}


/* ------------------------------------------------------------------------ */
/*  Copyright (C) 1998-2003 by Project HOS                                  */
/* ------------------------------------------------------------------------ */
