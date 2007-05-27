/* ------------------------------------------------------------------------ */
/*  Hyper Operating System V4 Tiny  ��ITRON4.0���� Real-Time OS             */
/*    �̥����ͥ� ����������                                                 */
/*                                                                          */
/*                                  Copyright (C) 1998-2003 by Project HOS  */
/*                                  http://sourceforge.jp/projects/hos/     */
/* ------------------------------------------------------------------------ */


#include "kernel.h"



/* �������ǥ����ѥå��μ¹� */
void kernel_exe_dsp(void)
{
	T_HOSPAC_CTXINF *ctxinf_top;
	T_HOSPAC_CTXINF *ctxinf_run;
	ID              tskid_top;
	ID              tskid_run;

	/* �ڤ��ؤ���ɬ�פ��ɤ��������å� */
	if ( KERNEL_GET_RUN_TSKID() == kernel_ref_qhd(KERNEL_GET_RDYQUE()) )
	{
		return;
	}

	/* ����ƥ����ȥ����å� */
	if ( kernel_sys.stat != KERNEL_TSS_TSK )
	{
		kernel_sys.dly_dsp = TRUE;	/* �ǥ����ѥå���ǽ�Ǥʤ����ͽ�󤷤ƽ�λ */
		return;
	}

	/* �ǹ�ͥ���٤μ¹Բ�ǽ����������� */
	tskid_top  = kernel_ref_qhd(KERNEL_GET_RDYQUE());
	ctxinf_top = &KERNEL_GET_TCB(tskid_top)->ctxinf;
	
	/* �¹��楿����ID�μ��� */
	tskid_run  = KERNEL_GET_RUN_TSKID();
	ctxinf_run = &KERNEL_GET_TCB(tskid_run)->ctxinf;
	
	/* �¹ԥ���������Ͽ */
	KERNEL_SET_RUN_TSKID(tskid_top);
	
	/* ����������ƥ����ȥ����å��¹� */
	hospac_swi_ctx(ctxinf_run, ctxinf_top);
}


/* ------------------------------------------------------------------------ */
/*  Copyright (C) 1998-2003 by Project HOS                                  */
/* ------------------------------------------------------------------------ */
