/* ------------------------------------------------------------------------ */
/*  Hyper Operating System V4 Tiny  ��ITRON4.0���� Real-Time OS             */
/*    ITRON�����ͥ� ���ޥե�                                                */
/*                                                                          */
/*                                  Copyright (C) 1998-2003 by Project HOS  */
/*                                  http://sourceforge.jp/projects/hos/     */
/* ------------------------------------------------------------------------ */


#include "kernel.h"



/* ���ޥե��񸻤γ���(�ݡ����) */
ER pol_sem(
		ID semid)	/* �񸻳����оݤΥ��ޥե�ID�ֹ� */
{
	T_KERNEL_SEMCB *semcb;
	ER             ercd;

	kernel_loc_sys();		/* �����ƥ�Υ�å� */
	
	/* ���ޥե��񸻤������Ǥ�������� */
	if ( semcb->semcnt > 0 )
	{
		semcb->semcnt--;	/* ���ޥե��񸻤γ��� */
		ercd = E_OK;
	}
	else
	{
		ercd = E_TMOUT;		/* �����ॢ���� */
	}

	kernel_unl_sys();		/* �����ƥ�Υ�å���� */

	return ercd;
}


/* ------------------------------------------------------------------------ */
/*  Copyright (C) 1998-2003 by Project HOS                                  */
/* ------------------------------------------------------------------------ */
