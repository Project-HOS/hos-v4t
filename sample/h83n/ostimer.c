/* ------------------------------------------------------------------------ */
/*  Hyper Operating System V4 Tiny ����ץ�ץ����                       */
/*    H8/3664 �� ������ (Timer A������)                                     */
/*                                                                          */
/*                                  Copyright (C) 1998-2003 by Project HOS  */
/*                                  http://sourceforge.jp/projects/hos/     */
/* ------------------------------------------------------------------------ */
#include "kernel.h"
#include "kernel_id.h"
#include "h83664f.h"
#include "ostimer.h"



/* OS�����ޤν���� */
void OsTimer_Initialize(VP_INT exinf)
{
	/* TMA�����
	   16MHz��8.192msec�Υ��󥿡��Х륿���ޤȤ������� */
	IO.PMR1.BYTE = 0x02;
	IO.PCR1 = 0xff;
	TA.TMA.BYTE =  0x03;    /* 00000011 */
	IENR1.BIT.IENTA = 1;	/* �����޳����ߵ��� */
}

static int time_counter = 0;

/* �������ѳ����ߥϥ�ɥ� */
void OsTimer_TimerHandler(VP_INT exinf)
{
	/* �������װ����ꥢ */
	IRR1.BYTE &= 0xbf; /* 10111111 */

	/* Ŭ����ʬ�����ƥե饰��Ω�Ƥ� */
	if (((++time_counter)&0x7f) == 0)
		iset_flg( FID_CYC, 1);
}

/* ------------------------------------------------------------------------ */
/*  Copyright (C) 1998-2003 by Project HOS                                  */
/* ------------------------------------------------------------------------ */
