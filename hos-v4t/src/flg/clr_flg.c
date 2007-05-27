/* ------------------------------------------------------------------------ */
/*  Hyper Operating System V4 Tiny  ��ITRON4.0���� Real-Time OS             */
/*    ITRON�����ͥ� ���٥�ȥե饰                                          */
/*                                                                          */
/*                                  Copyright (C) 1998-2003 by Project HOS  */
/*                                  http://sourceforge.jp/projects/hos/     */
/* ------------------------------------------------------------------------ */


#include "kernel.h"



/* ���٥�ȥե饰�Υ��ꥢ */
ER clr_flg(
		ID     flgid,	/* ���ꥢ�оݤΥ��٥�ȥե饰��ID�ֹ� */
		FLGPTN clrptn)	/* ���ꥢ����ӥåȥѥ�����(�ӥå����ȿž��) */
{
	T_KERNEL_FLGCB *flgcb;

	kernel_loc_sys();	/* �����ƥ�Υ�å� */

	flgcb = KERNEL_GET_FLGCB(flgid);

	/* �ե饰�Υ��ꥢ */
	flgcb->flgptn = (FLGPTN)(flgcb->flgptn & clrptn);

	kernel_unl_sys();	/* �����ƥ�Υ�å���� */

	return E_OK;
}


/* ------------------------------------------------------------------------ */
/*  Copyright (C) 1998-2003 by Project HOS                                  */
/* ------------------------------------------------------------------------ */
