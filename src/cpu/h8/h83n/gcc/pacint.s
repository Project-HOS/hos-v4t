/* -------------------------------------------------------------------------*/
/*  Hyper Operating System V4                                               */
/*    �����ߥϥ�ɥ�  Hitachi H8/300H ��                                  */
/*                                                                          */
/*                                  Copyright (C) 1998-2003 by Project HOS  */
/*                                  http://sourceforge.jp/projects/hos/     */
/* ------------------------------------------------------------------------ */


				.h8300h


				.text
				.align 2


				.global	_hos_vector001
				.global	_hos_vector002
				.global	_hos_vector003
				.global	_hos_vector004
				.global	_hos_vector005
				.global	_hos_vector006
				.global	_hos_vector007
				.global	_hos_vector008
				.global	_hos_vector009
				.global	_hos_vector010
				.global	_hos_vector011
				.global	_hos_vector012
				.global	_hos_vector013
				.global	_hos_vector014
				.global	_hos_vector015
				.global	_hos_vector016
				.global	_hos_vector017
				.global	_hos_vector018
				.global	_hos_vector019
				.global	_hos_vector020
				.global	_hos_vector021
				.global	_hos_vector022
				.global	_hos_vector023
				.global	_hos_vector024
				.global	_hos_vector025


/************************************************
  �����ߥϥ�ɥ�
*************************************************/
_hos_vector001:	push.w	r0
				mov.b	#1, r0l
				bra		int_handler1:8

_hos_vector002:	push.w	r0
				mov.b	#2, r0l
				bra		int_handler1:8

_hos_vector003:	push.w	r0
				mov.b	#3, r0l
				bra		int_handler1:8

_hos_vector004:	push.w	r0
				mov.b	#4, r0l

int_handler1:
				bra		int_handler:8

_hos_vector005:	push.w	r0
				mov.b	#5, r0l
				bra		int_handler:8

_hos_vector006:	push.w	r0
				mov.b	#6, r0l
				bra		int_handler:8

_hos_vector007:	push.w	r0
				mov.b	#7, r0l
				bra		int_handler:8

_hos_vector008:	push.w	r0
				mov.b	#8, r0l
				bra		int_handler:8

_hos_vector009:	push.w	r0
				mov.b	#9, r0l
				bra		int_handler:8

_hos_vector010:	push.w	r0
				mov.b	#10, r0l
				bra		int_handler:8

_hos_vector011:	push.w	r0
				mov.b	#11, r0l
				bra		int_handler:8

_hos_vector012:	push.w	r0
				mov.b	#12, r0l
				bra		int_handler:8

_hos_vector013:	push.w	r0
				mov.b	#13, r0l
				bra		int_handler:8

_hos_vector014:	push.w	r0
				mov.b	#14, r0l
				bra		int_handler:8

_hos_vector015:	push.w	r0
				mov.b	#15, r0l
				bra		int_handler:8

_hos_vector016:	push.w	r0
				mov.b	#16, r0l
				bra		int_handler:8

_hos_vector017:	push.w	r0
				mov.b	#17, r0l
				bra		int_handler:8

_hos_vector018:	push.w	r0
				mov.b	#18, r0l
				bra		int_handler:8

_hos_vector019:	push.w	r0
				mov.b	#19, r0l
				bra		int_handler:8

_hos_vector020:	push.w	r0
				mov.b	#20, r0l
				bra		int_handler:8

_hos_vector021:	push.w	r0
				mov.b	#21, r0l
				bra		int_handler:8

_hos_vector022:	push.w	r0
				mov.b	#22, r0l
				bra		int_handler:8

_hos_vector023:	push.w	r0
				mov.b	#23, r0l
				bra		int_handler:8

_hos_vector024:	push.w	r0
				mov.b	#24, r0l
				bra		int_handler

_hos_vector025:	push.w	r0
				mov.b	#25, r0l


/************************************************
          �����߽���

  ������ȯ������ r0 �� push �����塢r0l ��
  �������ֹ�򥻥åȤ��ơ������˥����פ���
*************************************************/

int_handler:
				/* �쥸������¸ */
				push.w	e0
				push.l	er1
				push.l	er2
				push.l	er3

				/* �������ֹ�Υޥ��� */
				extu.w	r0

				/* �����ߥޥ������� */
				stc.b	ccr, r1l
				and.b	#0xc0, r1l
				mov.b	r1l, @_kernel_h83_imsk:16

				/* ¿�ų����ߤ�Ƚ�� */
				mov.w	@_kernel_int_cnt:16, r1
				bne		mul_int

		/* ======== �ǽ�γ����� ======== */
				/* �����ߥͥ��ȥ��������� */
				mov.w	#1, r1
				mov.w	r1, @_kernel_int_cnt:16

				/* �����å��ݥ��󥿤������ؤ� */
				mov.w	r7, @_kernel_int_ssp:16
				mov.w	@_kernel_int_sp:16, r7

				/* �����߽����γ��� */
				push.w	r0
				jsr		@_kernel_sta_int:16
				pop.w	r0

				/* �����ߥϥ�ɥ�ν��� */
				jsr		@_kernel_exe_int:16

				/* �����å��ݥ������� */
				mov.w	@_kernel_int_ssp:16, r7

				/* �����ߥͥ��ȥ����󥿥��ꥢ */
				xor.w	r1, r1
				mov.w	r1, @_kernel_int_cnt:16

				/* �����ߥޥ����ͤ����� */
				mov.b	@_kernel_h83_ibmsk:16, r0l
				mov.b	r0l, @_kernel_h83_imsk:16		/* �����ߥޥ����ͤ�١����ͤ��᤹ */

				/* ����������ƥ����Ȥ˰ܹ� */
				jsr		@_kernel_end_int:16

				/* ������Υޥ����ͤ����� */
				mov.b	@_kernel_h83_ibmsk:16, r0l		/* �١����ޥ����ͼ��Ф� */
				mov.b	@(16:16, er7), r1l
				and.b	#0x3f,r1l					/* �����å����CCR����I��U�ʳ�����Ф� */
				or.b	r0l, r1l					/* �١����ޥ����ͤ����� */
				mov.b	r1l, @(16:16, er7)				/* �����å����CCR�򹹿� */

				/* ���� */
				pop.l	er3
				pop.l	er2
				pop.l	er1
				pop.w	e0
				pop.w	r0
				rte


		/* ======== ¿�ų����� ======== */
mul_int:
				/* �����ߥͥ��ȥ����󥿲û� */
				inc.w	#1, r1
				mov.w	r1, @_kernel_int_cnt:16

				/* �����ߥϥ�ɥ�ƤӽФ� */
				jsr		@_kernel_exe_int:16

				/* �����ߥͥ��ȥ����󥿸��� */
				mov.w	@_kernel_int_cnt:16, r0
				dec.w	#1, r0
				mov.w	r0, @_kernel_int_cnt:16

				/* ���� */
				pop.l	er3
				pop.l	er2
				pop.l	er1
				pop.w	e0
				pop.w	r0
				rte


				.global		_kernel_h83_imsk
				.global		_kernel_h83_ibmsk
				.section	.bss
_kernel_int_cnt:
		.space	2
_kernel_int_ssp:
		.space	2
_kernel_h83_imsk:
		.space	1
_kernel_h83_ibmsk:
		.space	1



/* -------------------------------------------------------------------------*/
/*  Copyright (C) 1998-2003 by Project HOS                                  */
/* -------------------------------------------------------------------------*/
