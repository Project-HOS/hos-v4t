/* ------------------------------------------------------------------------ */
/*  Hyper Operating System V4 Tiny  ��ITRON4.0���� Real-Time OS             */
/*    ITRON�����ͥ� ������������ǽ                                          */
/*                                                                          */
/*                                  Copyright (C) 1998-2003 by Project HOS  */
/*                                  http://sourceforge.jp/projects/hos/     */
/* ------------------------------------------------------------------------ */


#include "kernel.h"



/* �������ε�ư(��ư�����ɻ���) */
ER sta_tsk(
		ID     tskid,	/* ��ư�оݤΥ�����ID�ֹ� */
		VP_INT stacd)	/* �������ε�ư������ */
{
	T_KERNEL_TCB *tcb;
	
	kernel_loc_sys();	/* �����ƥ�Υ�å� */
	
	/* ID���饿��������ȥ���֥�å�RAM������ */
	tcb = KERNEL_GET_TCB(tskid);
	
	/* �¹ԥ���ƥ�������Ͽ */
	hospac_cre_ctx(&tcb->ctxinf, tcb->isp, tcb->task, stacd);
	
	/* ����� */
	tcb->wupcnt = 1;
	
	/* �¹��Ԥ����塼����Ͽ */
	kernel_add_que(KERNEL_GET_RDYQUE(), tskid);
	
	/* �������ǥ����ѥå��μ¹� */
	kernel_exe_dsp();
	
	kernel_unl_sys();	/* �����ƥ�Υ�å���� */
	
	return E_OK;
}


/* ------------------------------------------------------------------------ */
/*  Copyright (C) 1998-2003 by Project HOS                                  */
/* ------------------------------------------------------------------------ */
