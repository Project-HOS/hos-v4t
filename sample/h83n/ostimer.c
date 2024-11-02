/* ------------------------------------------------------------------------ */
/*  Hyper Operating System V4 Tiny サンプルプログラム                       */
/*    H8/3664 用 タイマ (Timer Aを利用)                                     */
/*                                                                          */
/*                                  Copyright (C) 1998-2003 by Project HOS  */
/*                                  http://sourceforge.jp/projects/hos/     */
/* ------------------------------------------------------------------------ */
#include "kernel.h"
#include "kernel_id.h"
#include "h83664f.h"
#include "ostimer.h"



/* OSタイマの初期化 */
void OsTimer_Initialize(VP_INT exinf)
{
	/* TMA初期化
	   16MHzで8.192msecのインターバルタイマとして設定 */
	IO.PMR1.BYTE = 0x02;
	IO.PCR1 = 0xff;
	TA.TMA.BYTE =  0x03;    /* 00000011 */
	IENR1.BIT.IENTA = 1;	/* タイマ割り込み許可 */
}

static int time_counter = 0;

/* タイマ用割り込みハンドラ */
void OsTimer_TimerHandler(VP_INT exinf)
{
	/* 割り込み要因クリア */
	IRR1.BYTE &= 0xbf; /* 10111111 */

	/* 適当に分周してフラグを立てる */
	if (((++time_counter)&0x7f) == 0)
		iset_flg( FID_CYC, 1);
}

/* ------------------------------------------------------------------------ */
/*  Copyright (C) 1998-2003 by Project HOS                                  */
/* ------------------------------------------------------------------------ */
