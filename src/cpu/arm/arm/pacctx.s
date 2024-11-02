; --------------------------------------------------------------------------- 
;  Hyper Operating System V4 Tiny μITRON4.0仕様 Real-Time OS                 
;    プロセッサ抽象化コンポーネント (ARM Thumbモード用)                       
;    コンテキスト制御                                                         
;                                                                             
;                                     Copyright (C) 1998-2003 by Project HOS  
;                                     http://sourceforge.jp/projects/hos/     
; --------------------------------------------------------------------------- 


				INCLUDE	pacarm.inc

				EXPORT	hospac_dis_int		; 割り込み禁止
				EXPORT	hospac_ena_int		; 割り込み許可
				EXPORT	hospac_cre_ctx		; 実行コンテキストの作成
				EXPORT	hospac_swi_ctx		; 実行コンテキストの切替

				CODE16

				AREA	code, CODE, READONLY


; -----------------------------------------------
;  割り込み禁止
;  void hospac_dis_int(void)
; -----------------------------------------------
hospac_dis_int
				mov		r0, #1			; Zフラグを倒す
				adr		r0, ctl_int_32
				bx		r0

; -----------------------------------------------
;  割り込み許可
;  void hospac_ena_int(void)
; -----------------------------------------------
hospac_ena_int
				mov		r0, #0			; Zフラグを立てる
				adr		r0, ctl_int_32
				bx		r0


				ALIGN
				CODE32
ctl_int_32
				mrs		r0, cpsr
				biceq	r0, r0, #I_Bit
				orrne	r0, r0, #I_Bit
				msr 	cpsr_cf, r0
				bx		lr
				CODE16


; -----------------------------------------------
;  実行コンテキストエントリーアドレス
; -----------------------------------------------
				IMPORT	ext_tsk
ctx_entry	
				bl		hospac_ena_int	; 割り込み許可
				mov		a1, v2			; 実行時パラメータを第一引数に設定
				ldr		r0, =ext_tsk	; リターンアドレス設定
				mov		lr, r0
				bx		v1				; 実行アドレスに分岐


; -----------------------------------------------
;  実行コンテキストの作成
;  void hospac_cre_ctx(
;		T_HOSPAC_CTXINF *pk_ctxinf,	/* 作成するコンテキスト */
;		VP     sp,					/* スタックポインタ */
;		void   (*task)(VP_INT),		/* 実行アドレス */
;		VP_INT exinf				/* 実行時パラメータ */
;		)
; -----------------------------------------------
hospac_cre_ctx
				sub		a2, #20			; スタックを確保
				str		a3, [a2, #0]	; v1 部分に実行アドレスを設定
				str		a4, [a2, #4]	; v2 部分に実行時パラメータを設定
				ldr		a3, =ctx_entry
				str		a3, [a2, #16]	; lr 部分にエントリーアドレスを設定
				str		a2, [a1]		; コンテキストとして sp を保存
				bx		lr				; リターン


; -----------------------------------------------
;  実行コンテキストの切替
;  void hospac_swi_ctx(
;		T_HOSPAC_CTXINF *pk_pre_ctxinf,	/* 現在のコンテキストの保存先 */
;		T_HOSPAC_CTXINF *pk_nxt_ctxinf	/* 切り替えるコンテキスト */
;		)
; -----------------------------------------------
hospac_swi_ctx
				push	{v1-v4, lr}			; レジスタ保存
				mov		v1, sp
				str		v1, [a1]			; スタックポインタ保存
				ldr		v1, [a2]			; スタックポインタ復帰
				mov		sp, v1
				pop		{v1-v4, pc}			; レジスタ復帰＆リターン

				END



; --------------------------------------------------------------------------- 
;  Copyright (C) 1998-2003 by Project HOS                                     
; --------------------------------------------------------------------------- 
