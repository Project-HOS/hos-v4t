/* ------------------------------------------------------------------------ */
/*  Hyper Operating System V4  μITRON4.0仕様 Real-Time OS                  */
/*    プロセッサ抽象化コンポーネント (日立 H8S/2000 用)                     */
/*    コンテキスト制御                                                      */
/*                                                                          */
/*                                  Copyright (C) 2003 by Project HOS       */
/*                                  http://sourceforge.jp/projects/hos/     */
/* ------------------------------------------------------------------------ */


	.h8300s

	.text
	.align 2

	.global	_hospac_dis_int		/* 割り込み禁止 */
	.global	_hospac_ena_int		/* 割り込み許可 */
	.global	_hospac_cre_ctx_asm	/* 実行コンテキストの作成 */
	.global	_hospac_swi_ctx		/* 実行コンテキストの切替 */
	.global	_hospac_set_tex		/* 例外処理実行設定 */

/************************************************
  割り込み禁止
  void hospac_dis_int(void)
*************************************************/
_hospac_dis_int:
#if	H8S_INTMODE == 0
	orc	#0xc0, ccr		/* 割り込みの禁止 */
#else // H8S_INTMODE == 1
        orc     #0x07, exr
#endif
	rts


/************************************************
  割り込み許可
  void hospac_ena_int(void)
*************************************************/
_hospac_ena_int:
	mov.b	@_kernel_h83_imsk, r0l
#if	H8S_INTMODE == 0
	ldc.b	r0l, ccr	/* 割り込みの許可 */
#else   // H8S_INTMODE == 1
        ldc.b   r0l, exr
#endif
	rts


/************************************************
  実行コンテキストエントリーアドレス
*************************************************/
ctx_entry:	
	mov.l	er4, er0	/* 実行時パラメータを第一引数に設定 */
	jmp	@er5		/* 実行アドレスにジャンプ */


/************************************************
  実行コンテキストの作成
  void hospac_cre_ctx_asm(
	T_HOSPAC_CTXINF *pk_ctxinf,		作成するコンテキスト
	VP              sp,			スタックポインタ
	void            (*task)(VP_INT),	実行アドレス
	VP_INT          exinf		実行時パラメータ
	)
*************************************************/
_hospac_cre_ctx_asm:
	mov.l   #ctx_entry, er3	/* 実行エントリーポイントの設定 */
	mov.l   er3, @-er1
	mov.l   @(4,er7), er3	/* 実行時パラメータの取り出し */
	mov.l   er3, @-er1	/* 実行時パラメータ格納 (er4の退避分) */
	mov.l   er2, @-er1	/* 実行ドレスを格納 (er5 の退避分) */
	sub.l   #4, er1		/* er6の退避分 */
	mov.l   er1, @(0, er0)	/* スタックポインタの格納 */
	rts


/************************************************
  実行コンテキストの切替
  void hospac_swi_ctx(
	T_HOSPAC_CTXINF *pk_pre_ctxinf,	現在のコンテキストの保存先
	T_HOSPAC_CTXINF *pk_nxt_ctxinf	切り替えるコンテキスト
	)
*************************************************/
_hospac_swi_ctx:
        stm.l   er4-er6, @-sp
        mov.l   er7,@(0, er0)   /* スタックポインタ保存 */
	mov.l	@(0, er1), er7	/* スタックポインタ復帰 */
        ldm.l   @sp+, er4-er6
	rts


	.end


/* -------------------------------------------------------------------------*/
/*  Copyright (C) 2003 by Project HOS                                       */
/* -------------------------------------------------------------------------*/
