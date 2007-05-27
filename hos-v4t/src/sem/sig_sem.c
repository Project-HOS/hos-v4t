/* ------------------------------------------------------------------------ */
/*  Hyper Operating System V4 Tiny  ��ITRON4.0���� Real-Time OS             */
/*    ITRON�����ͥ� ���ޥե�                                                */
/*                                                                          */
/*                                  Copyright (C) 1998-2003 by Project HOS  */
/*                                  http://sourceforge.jp/projects/hos/     */
/* ------------------------------------------------------------------------ */


#include "kernel.h"



/* ���ޥե��񸻤��ֵ� */
ER sig_sem(
		ID semid)		/* ���ޥե����ֵ��оݤΥ��ޥե���ID�ֹ� */
{
	T_KERNEL_SEMCB *semcb;
	ID             tskid;
	
	kernel_loc_sys();	/* �����ƥ�Υ�å� */
	
	semcb = KERNEL_GET_SEMCB(semid);

#if 0
	/* ���塼���󥰥����С��ե������å� */
#ifdef HOS_ERCHK_E_QOVR
	if ( semcb_ram->semcnt >= semcb_rom->maxsem )
	{
		mknl_unl_sys();	/* �����ƥ�Υ�å���� */
		return E_QOVR;
	}
#endif
#endif
	
	tskid = kernel_ref_qhd(&semcb->que);	/* �Ԥ�������Ƭ���饿�������Ф� */
	if ( tskid != 0 )
	{
		/* �Ԥ���������������Ԥ���� */
		kernel_rmv_que(tskid);							/* ���ޥե����Ԥ����󤫤��� */
		kernel_add_que(KERNEL_GET_RDYQUE(), tskid);		/* ��ǥ������塼���ɲ� */
		
		kernel_exe_dsp();						/* �������ǥ����ѥå��μ¹� */
	}
	else
	{
		semcb->semcnt++;	/* ���ޥե����ֵ� */
	}

	kernel_unl_sys();	/* �����ƥ�Υ�å���� */

	return E_OK;	/* ���� */
}


/* ------------------------------------------------------------------------ */
/*  Copyright (C) 1998-2003 by Project HOS                                  */
/* ------------------------------------------------------------------------ */
