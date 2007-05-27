/* ------------------------------------------------------------------------ */
/*  Hyper Operating System V4  ��ITRON4.0���� Real-Time OS                  */
/*    ITRON�����ͥ� ����������                                            */
/*                                                                          */
/*                                  Copyright (C) 1998-2003 by Project HOS  */
/*                                  http://sourceforge.jp/projects/hos/     */
/* ------------------------------------------------------------------------ */


#include "kernel.h"



/* �����ߥ���ƥ����Ȥγ��� */
void kernel_sta_int(void)
{
	/* �󥿥�����(�����ߥ���ƥ����Ȥ˰ܹ�) */
	kernel_sys.stat = KERNEL_TSS_INDP;
}


/* �����ߥ���ƥ����Ȥν�λ */
void kernel_end_int(void)
{
	/* ���������˰ܹ� */
	kernel_sys.stat = KERNEL_TSS_TSK;

	/* �ٱ�ǥ����ѥå��¹� */
	kernel_exe_dsp();
}


/* �����߽����¹� */
void kernel_exe_int(
		INTNO intno)		/* �������ֹ� */
{
	const T_KERNEL_INTCB *intcb;
	
	intcb = KERNEL_GET_INTCB(intno);
	
	kernel_unl_sys();		/* ¿�ų����ߵ��� */
	
	if ( intcb->isr != NULL )
	{
		intcb->isr(intcb->exinf); /* �����ߥ����ӥ��롼����¹� */
	}
	
	kernel_loc_sys();		/* ¿�ų����߶ػ� */
}


/* ------------------------------------------------------------------------ */
/*  Copyright (C) 1998-2003 by Project HOS                                  */
/* ------------------------------------------------------------------------ */
