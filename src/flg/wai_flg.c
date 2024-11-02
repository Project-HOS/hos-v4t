/* ------------------------------------------------------------------------ */
/*  Hyper Operating System V4 Tiny  ��ITRON4.0���� Real-Time OS             */
/*    ITRON�����ͥ� ���٥�ȥե饰                                          */
/*                                                                          */
/*                                  Copyright (C) 1998-2003 by Project HOS  */
/*                                  http://sourceforge.jp/projects/hos/     */
/* ------------------------------------------------------------------------ */


#include "kernel.h"



/* ���٥�ȥե饰�Ԥ� */
ER wai_flg(
		ID     flgid,		/* �Ԥ��оݤΥ��٥�ȥե饰��ID�ֹ� */
		FLGPTN waiptn,		/* �Ԥ��ӥåȥѥ����� */
		MODE   wfmode,		/* �Ԥ��⡼�� */
		FLGPTN *p_flgptn)	/* �Ԥ�������Υӥåȥѥ������Ǽ���ɥ쥹 */
{
	T_KERNEL_FLGCB *flgcb;
	ID             tskid;

	kernel_loc_sys();	/* �����ƥ�Υ�å� */
	
	flgcb = KERNEL_GET_FLGCB(flgid);
	
	/* �Ԥ�������� */
	flgcb->waiptn = waiptn;
	flgcb->wfmode = wfmode;
	
	/* �ե饰�����å� */
	if ( kernel_chk_flg(flgcb) )
	{
		/* ���˾����������Ƥ���ʤ� */
		if ( p_flgptn != NULL )
		{
			*p_flgptn = flgcb->flgptn;		/* ������Υե饰�ѥ�������Ǽ */
		}
	}
	else
	{
		/* �����������Ƥ��ʤ�����Ԥ������� */
		tskid           = KERNEL_GET_RUN_TSKID();	/* �¹��楿����ID�μ��� */
		flgcb->tskid    = tskid;					/* �Ԥ�����������Ͽ */
		flgcb->p_flgptn = p_flgptn;					/*  �Ԥ�������Υӥåȥѥ������Ǽ���ɥ쥹��¸ */
		kernel_rmv_que(tskid);						/* ��ǥ������塼�����곰�� */
		
		/* �������ǥ����ѥå��¹� */
		kernel_exe_dsp();
	}
	
	kernel_unl_sys();	/* �����ƥ�Υ�å���� */
	
	return E_OK;
}


/* ------------------------------------------------------------------------ */
/*  Copyright (C) 1998-2003 by Project HOS                                  */
/* ------------------------------------------------------------------------ */
