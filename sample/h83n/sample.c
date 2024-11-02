/* ------------------------------------------------------------------------ */
/*  Hyper Operating System V4 Tiny サンプルプログラム                       */
/*                                                                          */
/*                                  Copyright (C) 1998-2003 by Project HOS  */
/*                                  http://sourceforge.jp/projects/hos/     */
/* ------------------------------------------------------------------------ */


#include "kernel.h"
#include "kernel_id.h"
#include "h83664f.h"
#include "h8t_sci.h"


/* メイン関数 */
int main()
{
	char *p;

	/* SCIの初期化 */
	Sci_Initialize(SCI_19200);

	/* 開始メッセージ */
	for ( p="HOS V4 Tiny\r\ntest program start!\r\n"; *p!='\0'; p++)
		Sci_PutChar( *p);

	sta_hos();
	
	return 0;
}

/* 初期化ハンドラ */
void Initialize(VP_INT exinf)
{
	IO.PMR1.BYTE = 0x02; /* port1をTXD bit以外汎用入出力ポートに設定 */
	IO.PCR1      = 0xff; /* port1を出力ポートに設定 */
}

const char mes1[] = "Task: ID -> ";
const char mes2[] = " :EXINF -> ";

/* サンプルタスク
   「起動コードで与えられたタスクを起こし,自分は眠る」を繰り返す */
void Task(VP_INT exinf)
{
	char	*p;
	int	tid = KERNEL_GET_RUN_TSKID();

	/* TASK: ID -> tid : EXINF -> exinf ; 起動コードの確認 */
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
		/* TASK: ID -> X  ; 実行タスクのID確認 */
		for ( p=mes1; *p!='\0'; p++)
			Sci_PutChar( *p);
		Sci_PutChar( '0'+tid);
		Sci_PutChar( '\r');
		Sci_PutChar( '\n');
		sig_sem(SID_SCI);
		wup_tsk((ID)exinf);	/* 目的のタスクを起こす */
		slp_tsk();		/* 自分は寝る */
	}
}

const char chop[] = "*****\r\n";
/* SCIのセマフォを隙あらば取得して*****を出力するタスク */
void Chop(VP_INT exinf)
{
	char *p;

	for (;;)
	{
		wai_sem(SID_SCI);
		for ( p=chop; *p!='\0'; p++)
			Sci_PutChar( *p);
		sig_sem(SID_SCI);
		/* 周期的動作タスクに起こされるまで寝る */
		slp_tsk();
	}
}

/* タイマ割り込みでとフラグ連動して周期的動作をするタスク */
void Cycl(VP_INT exinf)
{
	int i;

	for (i=1;;i++)
	{
		wai_flg( FID_CYC, 1, TWF_ANDW, NULL);
		clr_flg( FID_CYC, 0);
		IO.PDR1.BYTE = ~(IO.PDR1.BYTE);
		/* 更に分周して寝ているChopタスクを起こす */
		if ((i&0x1) == 0) wup_tsk( exinf);
	}
}


/* ------------------------------------------------------------------------ */
/*  Copyright (C) 1998-2003 by Project HOS                                  */
/* ------------------------------------------------------------------------ */
