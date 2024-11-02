/* ------------------------------------------------------------------------ */
/*  Hyper Operating System V4 Tiny ����ץ�ץ����                       */
/*                                                                          */
/*                                  Copyright (C) 1998-2003 by Project HOS  */
/*                                  http://sourceforge.jp/projects/hos/     */
/* ------------------------------------------------------------------------ */


#include "kernel.h"
#include "kernel_id.h"
#include "h83664f.h"
#include "h8t_sci.h"


/* �ᥤ��ؿ� */
int main()
{
	char *p;

	/* SCI�ν���� */
	Sci_Initialize(SCI_19200);

	/* ���ϥ�å����� */
	for ( p="HOS V4 Tiny\r\ntest program start!\r\n"; *p!='\0'; p++)
		Sci_PutChar( *p);

	sta_hos();
	
	return 0;
}

/* ������ϥ�ɥ� */
void Initialize(VP_INT exinf)
{
	IO.PMR1.BYTE = 0x02; /* port1��TXD bit�ʳ����������ϥݡ��Ȥ����� */
	IO.PCR1      = 0xff; /* port1����ϥݡ��Ȥ����� */
}

const char mes1[] = "Task: ID -> ";
const char mes2[] = " :EXINF -> ";

/* ����ץ륿����
   �ֵ�ư�����ɤ�Ϳ����줿�������򵯤���,��ʬ��̲��פ򷫤��֤� */
void Task(VP_INT exinf)
{
	char	*p;
	int	tid = KERNEL_GET_RUN_TSKID();

	/* TASK: ID -> tid : EXINF -> exinf ; ��ư�����ɤγ�ǧ */
	wai_sem(SID_SCI);
	for ( p=mes1; *p!='\0'; p++)
			Sci_PutChar( *p);
	Sci_PutChar( '0'+tid);
	for ( p=mes2; *p!='\0'; p++)
			Sci_PutChar( *p);
	Sci_PutChar( '0'+exinf);
	Sci_PutChar( '\r');
	Sci_PutChar( '\n');
	sig_sem(SID_SCI);

	for ( ; ; )
	{
		wai_sem(SID_SCI);
		/* TASK: ID -> X  ; �¹ԥ�������ID��ǧ */
		for ( p=mes1; *p!='\0'; p++)
			Sci_PutChar( *p);
		Sci_PutChar( '0'+tid);
		Sci_PutChar( '\r');
		Sci_PutChar( '\n');
		sig_sem(SID_SCI);
		wup_tsk((ID)exinf);	/* ��Ū�Υ������򵯤��� */
		slp_tsk();		/* ��ʬ�Ͽ��� */
	}
}

const char chop[] = "*****\r\n";
/* SCI�Υ��ޥե���䤢��м�������*****����Ϥ��륿���� */
void Chop(VP_INT exinf)
{
	char *p;

	for (;;)
	{
		wai_sem(SID_SCI);
		for ( p=chop; *p!='\0'; p++)
			Sci_PutChar( *p);
		sig_sem(SID_SCI);
		/* ����Ūư������˵��������ޤǿ��� */
		slp_tsk();
	}
}

/* �����޳����ߤǤȥե饰Ϣư���Ƽ���Ūư��򤹤륿���� */
void Cycl(VP_INT exinf)
{
	int i;

	for (i=1;;i++)
	{
		wai_flg( FID_CYC, 1, TWF_ANDW, NULL);
		clr_flg( FID_CYC, 0);
		IO.PDR1.BYTE = ~(IO.PDR1.BYTE);
		/* ����ʬ�����ƿ��Ƥ���Chop�������򵯤��� */
		if ((i&0x1) == 0) wup_tsk( exinf);
	}
}


/* ------------------------------------------------------------------------ */
/*  Copyright (C) 1998-2003 by Project HOS                                  */
/* ------------------------------------------------------------------------ */
