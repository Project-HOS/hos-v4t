; --------------------------------------------------------------------------- 
;  Hyper Operating System V4 Tiny ��ITRON4.0���� Real-Time OS                 
;    �ץ��å���ݲ�����ݡ��ͥ�� (ARM Thumb�⡼����)                       
;    ����ƥ���������                                                         
;                                                                             
;                                     Copyright (C) 1998-2003 by Project HOS  
;                                     http://sourceforge.jp/projects/hos/     
; --------------------------------------------------------------------------- 


				INCLUDE	pacarm.inc

				EXPORT	hospac_dis_int		; �����߶ػ�
				EXPORT	hospac_ena_int		; �����ߵ���
				EXPORT	hospac_cre_ctx		; �¹ԥ���ƥ����Ȥκ���
				EXPORT	hospac_swi_ctx		; �¹ԥ���ƥ����Ȥ�����

				CODE16

				AREA	code, CODE, READONLY


; -----------------------------------------------
;  �����߶ػ�
;  void hospac_dis_int(void)
; -----------------------------------------------
hospac_dis_int
				mov		r0, #1			; Z�ե饰���ݤ�
				adr		r0, ctl_int_32
				bx		r0

; -----------------------------------------------
;  �����ߵ���
;  void hospac_ena_int(void)
; -----------------------------------------------
hospac_ena_int
				mov		r0, #0			; Z�ե饰��Ω�Ƥ�
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
;  �¹ԥ���ƥ����ȥ���ȥ꡼���ɥ쥹
; -----------------------------------------------
				IMPORT	ext_tsk
ctx_entry	
				bl		hospac_ena_int	; �����ߵ���
				mov		a1, v2			; �¹Ի��ѥ�᡼����������������
				ldr		r0, =ext_tsk	; �꥿���󥢥ɥ쥹����
				mov		lr, r0
				bx		v1				; �¹ԥ��ɥ쥹��ʬ��


; -----------------------------------------------
;  �¹ԥ���ƥ����Ȥκ���
;  void hospac_cre_ctx(
;		T_HOSPAC_CTXINF *pk_ctxinf,	/* �������륳��ƥ����� */
;		VP     sp,					/* �����å��ݥ��� */
;		void   (*task)(VP_INT),		/* �¹ԥ��ɥ쥹 */
;		VP_INT exinf				/* �¹Ի��ѥ�᡼�� */
;		)
; -----------------------------------------------
hospac_cre_ctx
				sub		a2, #20			; �����å������
				str		a3, [a2, #0]	; v1 ��ʬ�˼¹ԥ��ɥ쥹������
				str		a4, [a2, #4]	; v2 ��ʬ�˼¹Ի��ѥ�᡼��������
				ldr		a3, =ctx_entry
				str		a3, [a2, #16]	; lr ��ʬ�˥���ȥ꡼���ɥ쥹������
				str		a2, [a1]		; ����ƥ����ȤȤ��� sp ����¸
				bx		lr				; �꥿����


; -----------------------------------------------
;  �¹ԥ���ƥ����Ȥ�����
;  void hospac_swi_ctx(
;		T_HOSPAC_CTXINF *pk_pre_ctxinf,	/* ���ߤΥ���ƥ����Ȥ���¸�� */
;		T_HOSPAC_CTXINF *pk_nxt_ctxinf	/* �ڤ��ؤ��륳��ƥ����� */
;		)
; -----------------------------------------------
hospac_swi_ctx
				push	{v1-v4, lr}			; �쥸������¸
				mov		v1, sp
				str		v1, [a1]			; �����å��ݥ�����¸
				ldr		v1, [a2]			; �����å��ݥ�������
				mov		sp, v1
				pop		{v1-v4, pc}			; �쥸�����������꥿����

				END



; --------------------------------------------------------------------------- 
;  Copyright (C) 1998-2003 by Project HOS                                     
; --------------------------------------------------------------------------- 
