/* ------------------------------------------------------------------------ */
/*  Hyper Operating System V4 Tiny  ��ITRON4.0���� Real-Time OS             */
/*    ITRON�����ͥ� ������������ǽ                                          */
/*                                                                          */
/*                                  Copyright (C) 1998-2003 by Project HOS  */
/*                                  http://sourceforge.jp/projects/hos/     */
/* ------------------------------------------------------------------------ */


#include "kernel.h"



/* ���������ν�λ */
void ext_tsk(void)
{
	ID tskid;

	kernel_loc_sys();	/* �����ƥ�Υ��å� */
	
	/* �¹��楿����ID�μ��� */
	tskid = KERNEL_GET_RUN_TSKID();
	
	/* ��ǥ������塼������ */
	kernel_rmv_que(tskid);
	
	/* �������ǥ����ѥå��μ¹� */
	kernel_exe_dsp();
}


/* ------------------------------------------------------------------------ */
/*  Copyright (C) 1998-2003 by Project HOS                                  */
/* ------------------------------------------------------------------------ */