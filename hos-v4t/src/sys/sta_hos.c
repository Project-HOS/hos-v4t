/* ------------------------------------------------------------------------ */
/*  Hyper Operating System V4 Tiny  ��ITRON4.0���� Real-Time OS             */
/*    �����ƥ�                                                              */
/*                                                                          */
/*                                  Copyright (C) 1998-2003 by Project HOS  */
/*                                  http://sourceforge.jp/projects/hos/     */
/* ------------------------------------------------------------------------ */


#include "kernel.h"


/*T_KERNEL_SYS kernel_sys;	*/		/* �����ƥ���� */
UW           kernel_idl_stk[16];	


static void kernel_idle(VP_INT exinf);


/* HOS �����ͥ�ư��� */
ER sta_hos(void)
{
	T_HOSPAC_CTXINF ctxinf_dmy;
	T_HOSPAC_CTXINF *ctxinf_top;
	ID              tskid_top;
	
	/* �ǥ����ѥå���ػ� */
	kernel_sys.stat = KERNEL_TSS_DDSP;
	
	/* �����ɥ륿�������� */
	hospac_cre_ctx(&kernel_sys.ctxinf_idle,  &kernel_idl_stk[16], kernel_idle, 0);
	
	/* ����ե�����졼���ν�����ƤӽФ� */
	hoscfg_ini();

	/* �ǥ����ѥå������ */
	kernel_sys.stat = KERNEL_TSS_TSK;

	/* �ǹ�ͥ���٤μ¹Բ�ǽ����������� */
	tskid_top  = kernel_ref_qhd(KERNEL_GET_RDYQUE());
	ctxinf_top = &KERNEL_GET_TCB(tskid_top)->ctxinf;

	/* �¹ԥ���������Ͽ */
	KERNEL_SET_RUN_TSKID(tskid_top);

	/* �������ڤ��ؤ� */
	hospac_swi_ctx(&ctxinf_dmy, ctxinf_top);
	
	return E_OK;
}


/* �����ɥ륿���� */
void kernel_idle(VP_INT exinf)
{
	for ( ; ; )
	{
		hospac_idle();
	}
}


/* ------------------------------------------------------------------------ */
/*  Copyright (C) 1998-2003 by Project HOS                                  */
/* ------------------------------------------------------------------------ */
