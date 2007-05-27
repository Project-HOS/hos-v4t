; --------------------------------------------------------------------------- 
;  Hyper Operating System V4  ��Ω H8 �� ����ץ�ץ����                   
;    �������ȥ��åץ롼����                                                   
;                                                                             
;                                   Copyright (C) 2003 by Project HOS    
;                                   http://sourceforge.jp/projects/hos/       
; --------------------------------------------------------------------------- 



				.h8300h

; -------------------------------------
;  �������ȥ��åץ롼����
; -------------------------------------
				.text
				.align 2
				.global _startup
_startup:
		; ----- �����å������
				mov.w	#_stack,r7

		; ----- .data ��������󥳥ԡ�
				mov.w	#___dtors_end,r5
				mov.w	#___data,r6
				mov.w	#data_size,r4
copy_dsec:	eepmov.w
				mov.w	r4,r4
				bne	copy_dsec
				
		; ----- .bss ��������󥯥ꥢ
				mov.w	#_bss_start,r5
				mov.w	#_bss_start+1,r6
				mov.w	#bss_size,r4
				mov.b	#0,r0l
				mov.b	r0l,@er5
clr_bsec:		eepmov.w
				mov.w	r4,r4
				bne	clr_bsec

		; ----- ������롼����ƤӽФ�
				jsr	@_main
idle_loop:
				bra	idle_loop


				.global	_kernel_int_sp
				.section .rodata
				.align 2
_kernel_int_sp:
				.word	_stack		/* �����߻��� er7 ��¸�� */


				.end


; --------------------------------------------------------------------------- 
;  Copyright (C) 2003 by Project HOS                                     
; --------------------------------------------------------------------------- 
