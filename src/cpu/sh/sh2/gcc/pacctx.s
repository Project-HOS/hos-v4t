/* ------------------------------------------------------------------------ */
/*  Hyper Operating System V4  ��ITRON4.0���� Real-Time OS                  */
/*    �ץ��å���ݲ�����ݡ��ͥ�� (��Ω SH2��)                           */
/*                                                                          */
/*                                  Copyright (C) 1998-2002 by Project HOS  */
/*                                  http://sourceforge.jp/projects/hos/     */
/* ------------------------------------------------------------------------ */



				.global	_hospac_dis_int			/* �����߶ػ� */
				.global	_hospac_ena_int			/* �����ߵ��� */
				.global	_hospac_cre_ctx_asm		/* �¹ԥ���ƥ����Ȥκ��� */
				.global	_hospac_swi_ctx			/* �¹ԥ���ƥ����Ȥ����� */



/************************************************
  �����߶ػ�
  void hospac_dis_int(void)
************************************************/
				.text
				.align	2
_hospac_dis_int:
				stc		sr, r0
				or		#0xf0, r0		/* �������ߥޥ��� */
				rts
				ldc		r0, sr



/************************************************
  �����ߵ���
  void hospac_ena_int(void)
************************************************/
				.text
				.align	2
_hospac_ena_int:
				mov		#0xf0, r1		/* 0x00f0 ��ȿž������ 0xff0f ����� */
				not		r1, r1
				stc		sr, r0
				and		r1, r0			/* �����ߥޥ����Ͱʳ������ */
				mov.l	imsk_addr, r1
				mov.l	@r1, r1
				or		r1, r0			/* �����ߥޥ������ͤ����� */
				rts
				ldc		r0, sr

				.align	2
imsk_addr:
				.long	_hospac_sh_imsk			/* �����ߥޥ��� */



/************************************************
  �¹ԥ���ƥ����ȥ���ȥ꡼���ɥ쥹
************************************************/
				.text
				.align 2
ctx_entry:	 	
				jmp		@r14			/* �¹ԥ��ɥ쥹�˥����� */
				mov		r13, r4			/* �¹Ի��ѥ�᡼���������������� */


/************************************************
  �¹ԥ���ƥ����Ȥκ���
  void hospac_cre_ctx_asm(
		 T_HOSPAC_CTXINF *pk_ctxinf,	�������륳��ƥ�����
		 VP 	sp, 					�����å��ݥ���
		 void	(*task)(VP_INT),		�¹ԥ��ɥ쥹
		 VP_INT exinf)					�¹Ի��ѥ�᡼��
************************************************/
				.text
				.align 2
_hospac_cre_ctx_asm:
				add 	#-20, r5				/* r14-10ʬ����ƥ����Ȥ�stack�򿭤Ф� */
				mov.l	r7, @-r5				/* �¹ԥѥ�᡼���γ�Ǽ(r9) */
				mov.l	r6, @-r5				/* �¹ԥ��ɥ쥹�γ�Ǽ(r8) */
				mov.l	ctx_entry_addr, r0		/* �¹ԥ���ȥ�ݥ���Ȥ򥳥�ƥ����Ȥ� */
				mov.l	r0, @-r5				/* �����å�����¸ */
				rts
				mov.l	r5, @(0,r4) 			/* ����ƥ����ȤΥ����å��ݥ�����¸ */

				.align	2
ctx_entry_addr:
				.long	ctx_entry



/************************************************
  �¹ԥ���ƥ����Ȥ�����
  void hospac_swi_ctx(
		T_HOSPAC_CTXINF *pk_pre_ctxinf,	���ߤΥ���ƥ����Ȥ���¸��
		T_HOSPAC_CTXINF *pk_nxt_ctxinf)	�ڤ��ؤ��륳��ƥ�����
************************************************/
				.text
				.align 2
_hospac_swi_ctx:
				mov.l	 r8, @-r15		/* 8-r14,pr������ */
				mov.l	 r9, @-r15
				mov.l	 r10, @-r15
				mov.l	 r11, @-r15
				mov.l	 r12, @-r15
				mov.l	 r13, @-r15
				mov.l	 r14, @-r15
				sts.l	 pr, @-r15

				mov.l	 r15, @(0, r4)	/* �����å��ݥ�����¸ */
				mov.l	 @(0, r5), r15	/* �����å��ݥ������� */

				lds.l	 @r15+, pr		/* r8-r14,pr������ */
				mov.l	 @r15+, r14
				mov.l	 @r15+, r13
				mov.l	 @r15+, r12
				mov.l	 @r15+, r11
				mov.l	 @r15+, r10
				mov.l	 @r15+, r9
				rts
				mov.l	 @r15+, r8



				.end


/* ------------------------------------------------------------------------ */
/*  Copyright (C) 1998-2002 by Project HOS                                  */
/* ------------------------------------------------------------------------ */
