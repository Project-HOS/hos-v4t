/* ------------------------------------------------------------------------ */
/*  Hyper Operating System V4 Tiny  ��ITRON4.0���� Real-Time OS             */
/*    ITRON�����ͥ� ���٥�ȥե饰                                          */
/*                                                                          */
/*                                  Copyright (C) 1998-2003 by Project HOS  */
/*                                  http://sourceforge.jp/projects/hos/     */
/* ------------------------------------------------------------------------ */


#include "kernel.h"



/* ���٥�ȥե饰�Ԥ�(�ݡ����) */
ER pol_flg(
		ID     flgid,
		FLGPTN waiptn,
		MODE   wfmode,
		FLGPTN *p_flgptn)
{
	T_KERNEL_FLGCB *flgcb;
	ER             ercd;

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
		ercd = E_OK;
	}
	else
	{
		/* ���˾����������Ƥ��ʤ���Х����ॢ���� */
		ercd = E_TMOUT;
	}
	
	kernel_unl_sys();	/* �����ƥ�Υ�å���� */

	return ercd;
}


/* ------------------------------------------------------------------------ */
/*  Copyright (C) 1998-2003 by Project HOS                                  */
/* ------------------------------------------------------------------------ */
