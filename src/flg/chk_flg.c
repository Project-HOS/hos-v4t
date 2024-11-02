/* ------------------------------------------------------------------------ */
/*  Hyper Operating System V4 Tiny  ��ITRON4.0���� Real-Time OS             */
/*    ITRON�����ͥ� ���٥�ȥե饰                                          */
/*                                                                          */
/*                                  Copyright (C) 1998-2003 by Project HOS  */
/*                                  http://sourceforge.jp/projects/hos/     */
/* ------------------------------------------------------------------------ */


#include "kernel.h"



/* �ե饰�����������������Ƥ��뤫�����å� */
BOOL kernel_chk_flg(
		T_KERNEL_FLGCB *flgcb)	/* ����ȥ���֥�å� */
{
	if ( flgcb->wfmode == TWF_ANDW )
	{
		/* AND�Ԥ�Ƚ�� */
		return ((flgcb->flgptn & flgcb->waiptn) == flgcb->waiptn);
	}
	else
	{
		/* OR�Ԥ�Ƚ�� */
		return ((flgcb->flgptn & flgcb->waiptn) != 0);
	}
}


/* ------------------------------------------------------------------------ */
/*  Copyright (C) 1998-2003 by Project HOS                                  */
/* ------------------------------------------------------------------------ */
