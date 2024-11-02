; --------------------------------------------------------------------------- 
;  Hyper Operating System V4 Tiny μITRON4.0仕様 Real-Time OS                 
;    プロセッサ抽象化コンポーネント (ARM Thumbモード用)                       
;    IRQ例外ハンドラ                                                          
;                                                                             
;                                     Copyright (C) 1998-2003 by Project HOS  
;                                     http://sourceforge.jp/projects/hos/     
; --------------------------------------------------------------------------- 


				INCLUDE	pacarm.inc


; T_KERNEL_SYS 構造体のオフセット
SYS_STAT		EQU		6
SYS_DLYDSP		EQU		7
SYS_INTCNT		EQU		8


				AREA	inthdr_code, CODE, READONLY

				EXPORT	_HOS_IrqHandler

; ----------------------------------------------
;  IRQ ハンドラ
; ----------------------------------------------
				IMPORT	hosarm_exe_irq				; IRQ割り込み処理の実行
				IMPORT	hosarm_chk_mpi				; 多重割り込みのチェック
				IMPORT	kernel_exe_dsp				; ディスパッチの実行
				IMPORT	kernel_tcb_tbl				; システム情報

				CODE32
				
_HOS_IrqHandler
			; ---- レジスタ退避
				sub		lr, lr, #4					; リターンアドレス算出
				stmfd	sp!, {a1-a4, lr}			; レジスタ退避
			
			; ---- Thumbモードに移行
				adr		r0, ToThumb1 + 1
				bx		r0
				CODE16
ToThumb1		

			; ---- 多重割り込みチェック
				bl		hosarm_chk_mpi
				cmp		r0, #0
				bne		MultipleInt					; 多重割り込みなら分岐
				
			; ---- 割り込み処理の開始設定
				ldr		r0, =kernel_tcb_tbl
				ldrb	r1, [r0, #SYS_STAT]
				add		r1, #0x04
				strb	r1, [r0, #SYS_STAT]
				
			; ---- 割り込み処理
				bl		hosarm_exe_irq				; 割り込み処理実行
				
			; ---- 遅延ディスパッチが必要かどうか判定
				ldrb	r0, [r0, #SYS_DLYDSP]		
				sub		r0, #1
				bneq	IrqReturn					; ディスパッチ不要ならリターン

				strb	r0, [r0, #SYS_DLYDSP]		; 遅延ディスパッチフラグクリア
				ldr		r2, [sp, #20]				; 退避中のlr_irqを取り出し
				ldr		r0, =pac_irq_data

			; ---- ARMモードに移行
				adr		r1, ToArm1
				bx		r1
				ALIGN
				CODE32
ToArm1
				mrs		r1, spsr					; spsr_irq 取り出し
				stmia	r0, {r1, r2}				; spsr_irq, lr_irq 保存
				ldmfd	sp!, {a1-a4, lr}			; レジスタ復帰
				
			; ---- Systemモードに移行
				msr		cpsr_csxf, #I_Bit:OR:Mode_SYS
				
			; ---- Thumb モードに移行
				adr		r0, ToThumb2
				bx		r0
				CODE16
ToThumb2		
				
				push	{a1-a4}						; 破壊レジスタ退避
				ldr		r0, =pac_irq_data
				ldmia	r0!, {r1, r2}				; spsr_irq, lr_irq 取り出し
				push	{r1, r2}					; spsr_irq, lr_irq 退避
				
			; ---- 遅延ディスパッチ処理
				bl		kernel_exe_dsp
				
			; ---- 復帰処理
				pop		{r1, r2}					; spsr_irq, lr_irq 取り出し
				ldr		r0, =pac_irq_data
				stmia	r0!, {r1, r2}
				
			; ---- ARMモードへ移行
				adr		r0, ToArm2
				bx		r0
				ALIGN
				CODE32
ToArm2

				ldmfd	sp!, {a1-a4}				; 破壊レジスタ復帰
				
			; ---- IRQモードへ戻ってリターン処理
				msr		cpsr_csxf, #I_Bit:OR:Mode_IRQ
				stmfd	sp!, {a1-a2}
				ldr		r0, =pac_irq_data
				ldmia	r0, {r1, lr}
				msr		spsr_csxf, r1
				ldmfd	sp!, {a1-a2}
				subs	pc, lr, #0
				CODE16


			;---- 多重割り込み処理
MultipleInt		
				bl		hosarm_exe_irq			; 割り込み処理実行
				
IrqReturn
				adr		r0, ToArm3
				bx		r0
				
				ALIGN
				CODE32
ToArm3
			; ---- 復帰処理
				ldmfd	sp!, {a1-a4, pc}^		; レジスタ復帰



; ----------------------------------------------
;  グローバル変数
; ----------------------------------------------
				AREA	irqhdr_bss, NOINIT

pac_irq_data	%		8		; lr, cpsr の値渡し用


				END



; --------------------------------------------------------------------------- 
;  Copyright (C) 1998-2003 by Project HOS                                     
; --------------------------------------------------------------------------- 
