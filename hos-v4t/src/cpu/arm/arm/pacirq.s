; --------------------------------------------------------------------------- 
;  Hyper Operating System V4 Tiny ��ITRON4.0���� Real-Time OS                 
;    �ץ��å���ݲ�����ݡ��ͥ�� (ARM Thumb�⡼����)                       
;    IRQ�㳰�ϥ�ɥ�                                                          
;                                                                             
;                                     Copyright (C) 1998-2003 by Project HOS  
;                                     http://sourceforge.jp/projects/hos/     
; --------------------------------------------------------------------------- 


				INCLUDE	pacarm.inc


; T_KERNEL_SYS ��¤�ΤΥ��ե��å�
SYS_STAT		EQU		6
SYS_DLYDSP		EQU		7
SYS_INTCNT		EQU		8


				AREA	inthdr_code, CODE, READONLY

				EXPORT	_HOS_IrqHandler

; ----------------------------------------------
;  IRQ �ϥ�ɥ�
; ----------------------------------------------
				IMPORT	hosarm_exe_irq				; IRQ�����߽����μ¹�
				IMPORT	hosarm_chk_mpi				; ¿�ų����ߤΥ����å�
				IMPORT	kernel_exe_dsp				; �ǥ����ѥå��μ¹�
				IMPORT	kernel_tcb_tbl				; �����ƥ����

				CODE32
				
_HOS_IrqHandler
			; ---- �쥸��������
				sub		lr, lr, #4					; �꥿���󥢥ɥ쥹����
				stmfd	sp!, {a1-a4, lr}			; �쥸��������
			
			; ---- Thumb�⡼�ɤ˰ܹ�
				adr		r0, ToThumb1 + 1
				bx		r0
				CODE16
ToThumb1		

			; ---- ¿�ų����ߥ����å�
				bl		hosarm_chk_mpi
				cmp		r0, #0
				bne		MultipleInt					; ¿�ų����ߤʤ�ʬ��
				
			; ---- �����߽����γ�������
				ldr		r0, =kernel_tcb_tbl
				ldrb	r1, [r0, #SYS_STAT]
				add		r1, #0x04
				strb	r1, [r0, #SYS_STAT]
				
			; ---- �����߽���
				bl		hosarm_exe_irq				; �����߽����¹�
				
			; ---- �ٱ�ǥ����ѥå���ɬ�פ��ɤ���Ƚ��
				ldrb	r0, [r0, #SYS_DLYDSP]		
				sub		r0, #1
				bneq	IrqReturn					; �ǥ����ѥå����פʤ�꥿����

				strb	r0, [r0, #SYS_DLYDSP]		; �ٱ�ǥ����ѥå��ե饰���ꥢ
				ldr		r2, [sp, #20]				; �������lr_irq����Ф�
				ldr		r0, =pac_irq_data

			; ---- ARM�⡼�ɤ˰ܹ�
				adr		r1, ToArm1
				bx		r1
				ALIGN
				CODE32
ToArm1
				mrs		r1, spsr					; spsr_irq ���Ф�
				stmia	r0, {r1, r2}				; spsr_irq, lr_irq ��¸
				ldmfd	sp!, {a1-a4, lr}			; �쥸��������
				
			; ---- System�⡼�ɤ˰ܹ�
				msr		cpsr_csxf, #I_Bit:OR:Mode_SYS
				
			; ---- Thumb �⡼�ɤ˰ܹ�
				adr		r0, ToThumb2
				bx		r0
				CODE16
ToThumb2		
				
				push	{a1-a4}						; �˲��쥸��������
				ldr		r0, =pac_irq_data
				ldmia	r0!, {r1, r2}				; spsr_irq, lr_irq ���Ф�
				push	{r1, r2}					; spsr_irq, lr_irq ����
				
			; ---- �ٱ�ǥ����ѥå�����
				bl		kernel_exe_dsp
				
			; ---- ��������
				pop		{r1, r2}					; spsr_irq, lr_irq ���Ф�
				ldr		r0, =pac_irq_data
				stmia	r0!, {r1, r2}
				
			; ---- ARM�⡼�ɤذܹ�
				adr		r0, ToArm2
				bx		r0
				ALIGN
				CODE32
ToArm2

				ldmfd	sp!, {a1-a4}				; �˲��쥸��������
				
			; ---- IRQ�⡼�ɤ���äƥ꥿�������
				msr		cpsr_csxf, #I_Bit:OR:Mode_IRQ
				stmfd	sp!, {a1-a2}
				ldr		r0, =pac_irq_data
				ldmia	r0, {r1, lr}
				msr		spsr_csxf, r1
				ldmfd	sp!, {a1-a2}
				subs	pc, lr, #0
				CODE16


			;---- ¿�ų����߽���
MultipleInt		
				bl		hosarm_exe_irq			; �����߽����¹�
				
IrqReturn
				adr		r0, ToArm3
				bx		r0
				
				ALIGN
				CODE32
ToArm3
			; ---- ��������
				ldmfd	sp!, {a1-a4, pc}^		; �쥸��������



; ----------------------------------------------
;  �����Х��ѿ�
; ----------------------------------------------
				AREA	irqhdr_bss, NOINIT

pac_irq_data	%		8		; lr, cpsr �����Ϥ���


				END



; --------------------------------------------------------------------------- 
;  Copyright (C) 1998-2003 by Project HOS                                     
; --------------------------------------------------------------------------- 
