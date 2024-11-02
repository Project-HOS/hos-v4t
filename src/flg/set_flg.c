/* ------------------------------------------------------------------------ */
/*  Hyper Operating System V4 Tiny  ��ITRON4.0���� Real-Time OS             */
/*    ITRON�����ͥ� ���٥�ȥե饰                                          */
/*                                                                          */
/*                                  Copyright (C) 1998-2003 by Project HOS  */
/*                                  http://sourceforge.jp/projects/hos/     */
/* ------------------------------------------------------------------------ */


#include "kernel.h"



/* ���٥�ȥե饰�Υ��å� */
ER set_flg(
		ID     flgid,		/* ���å��оݤΥ��٥�ȥե饰��ID�ֹ� */
		FLGPTN setptn)		/* ���åȤ���ӥåȥѥ����� */
{
	T_KERNEL_FLGCB *flgcb;

	kernel_loc_sys();	/* �����ƥ�Υ�å� */

	flgcb = KERNEL_GET_FLGCB(flgid);
	
	/* �ե饰�Υ��å� */
	flgcb->flgptn = (FLGPTN)(flgcb->flgptn | setptn);
	
	/* �Ԥ�������������е��������å� */
	if ( flgcb->tskid != 0 )
	{
		/* �ե饰�����å� */
		if ( kernel_chk_flg(flgcb) )
		{
			/* ���������������Ƥ���ʤ� */
			if ( flgcb->p_flgptn != NULL )
			{
				*flgcb->p_flgptn = flgcb->flgptn;	/* ���ߤΥե饰�ѥ�������Ǽ */
			}
			
			/* �Ԥ���� */
			kernel_add_que(KERNEL_GET_RDYQUE(), flgcb->tskid);		/* ��ǥ������塼����Ͽ */

			kernel_exe_dsp();		/* �������ǥ����ѥå��μ¹� */
		}
	}
	
	kernel_unl_sys();	/* �����ƥ�Υ�å���� */
	
	return E_OK;	/* ���ｪλ */
}


/* ------------------------------------------------------------------------ */
/*  Copyright (C) 1998-2003 by Project HOS                                  */
/* ------------------------------------------------------------------------ */
