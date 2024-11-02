/* -------------------------------------------------------------------------*/
/*  Hyper Operating System V4                                               */
/*    割り込みハンドラ  Hitachi H8S 用                                      */
/*                                                                          */
/*                                  Copyright (C) 1998-2002 by Project HOS  */
/*                                  http://sourceforge.jp/projects/hos/     */
/* ------------------------------------------------------------------------ */

/* 割り込みモードの指定は、
                          H8S_INTMODE = 0 (割り込みモード0)
                                      = 1 (割り込みモード1) を#defineする。
   H8/2000シリーズは、__NO_S2600__を#defineする。    builtin_defineではない */

	.h8300s


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
	.global	_hos_vector026
	.global	_hos_vector027
	.global	_hos_vector028
	.global	_hos_vector029
	.global	_hos_vector030
	.global	_hos_vector031
	.global	_hos_vector032
	.global	_hos_vector033
	.global	_hos_vector034
	.global	_hos_vector035
	.global	_hos_vector036
	.global	_hos_vector037
	.global	_hos_vector038
	.global	_hos_vector039
	.global	_hos_vector040
	.global	_hos_vector041
	.global	_hos_vector042
	.global	_hos_vector043
	.global	_hos_vector044
	.global	_hos_vector045
	.global	_hos_vector046
	.global	_hos_vector047
	.global	_hos_vector048
	.global	_hos_vector049
	.global	_hos_vector050
	.global	_hos_vector051
	.global	_hos_vector052
	.global	_hos_vector053
	.global	_hos_vector054
	.global	_hos_vector055
	.global	_hos_vector056
	.global	_hos_vector057
	.global	_hos_vector058
	.global	_hos_vector059
	.global	_hos_vector060
	.global	_hos_vector061
	.global	_hos_vector062
	.global	_hos_vector063
	.global	_hos_vector064
	.global	_hos_vector065
	.global	_hos_vector066
	.global	_hos_vector067
	.global	_hos_vector068
	.global	_hos_vector069
	.global	_hos_vector070
	.global	_hos_vector071
	.global	_hos_vector072
	.global	_hos_vector073
	.global	_hos_vector074
	.global	_hos_vector075
	.global	_hos_vector076
	.global	_hos_vector077
	.global	_hos_vector078
	.global	_hos_vector079
	.global	_hos_vector080
	.global	_hos_vector081
	.global	_hos_vector082
	.global	_hos_vector083
	.global	_hos_vector084
	.global	_hos_vector085
	.global	_hos_vector086
	.global	_hos_vector087
	.global	_hos_vector088
	.global	_hos_vector089
	.global	_hos_vector090
	.global	_hos_vector091

/************************************************
  割り込みハンドラ
*************************************************/
_hos_vector001:	stm.l	er0-er3,@-sp
	mov.b	#1, r0l
	bra	int_handler:16

_hos_vector002:	stm.l	er0-er3,@-sp
	mov.b	#2, r0l
	bra	int_handler:16

_hos_vector003:	stm.l	er0-er3,@-sp
	mov.b	#3, r0l
	bra	int_handler:16

_hos_vector004:	stm.l	er0-er3,@-sp
	mov.b	#4, r0l
	bra	int_handler:16

_hos_vector005:	stm.l	er0-er3,@-sp
	mov.b	#5, r0l
	bra	int_handler:16

_hos_vector006:	stm.l	er0-er3,@-sp
	mov.b	#6, r0l
	bra	int_handler:16

_hos_vector007:	stm.l	er0-er3,@-sp
	mov.b	#7, r0l
	bra	int_handler:16

_hos_vector008:	stm.l	er0-er3,@-sp
	mov.b	#8, r0l
	bra	int_handler:16

_hos_vector009:	stm.l	er0-er3,@-sp
	mov.b	#9, r0l
	bra	int_handler:16

_hos_vector010:	stm.l	er0-er3,@-sp
	mov.b	#10, r0l
	bra	int_handler:16

_hos_vector011:	stm.l	er0-er3,@-sp
	mov.b	#11, r0l
	bra	int_handler:16

_hos_vector012:	stm.l	er0-er3,@-sp
	mov.b	#12, r0l
	bra	int_handler:16

_hos_vector013:	stm.l	er0-er3,@-sp
	mov.b	#13, r0l
	bra	int_handler:16

_hos_vector014:	stm.l	er0-er3,@-sp
	mov.b	#14, r0l
	bra	int_handler:16

_hos_vector015:	stm.l	er0-er3,@-sp
	mov.b	#15, r0l
	bra	int_handler:16

_hos_vector016:	stm.l	er0-er3,@-sp
	mov.b	#16, r0l
	bra	int_handler:16

_hos_vector017:	stm.l	er0-er3,@-sp
	mov.b	#17, r0l
	bra	int_handler:16:16

_hos_vector018:	stm.l	er0-er3,@-sp
	mov.b	#18, r0l
	bra	int_handler:16

_hos_vector019:	stm.l	er0-er3,@-sp
	mov.b	#19, r0l
	bra	int_handler:16

_hos_vector020:	stm.l	er0-er3,@-sp
	mov.b	#20, r0l
	bra	int_handler:16

_hos_vector021:	stm.l	er0-er3,@-sp
	mov.b	#21, r0l
	bra	int_handler:16

_hos_vector022:	stm.l	er0-er3,@-sp
	mov.b	#22, r0l
	bra	int_handler:16

_hos_vector023:	stm.l	er0-er3,@-sp
	mov.b	#23, r0l
	bra	int_handler:16

_hos_vector024:	stm.l	er0-er3,@-sp
	mov.b	#24, r0l
	bra	int_handler:16

_hos_vector025:	stm.l	er0-er3,@-sp
	mov.b	#25, r0l
	bra	int_handler:16

_hos_vector026:	stm.l	er0-er3,@-sp
	mov.b	#26, r0l
	bra	int_handler:16

_hos_vector027:	stm.l	er0-er3,@-sp
	mov.b	#27, r0l
	bra	int_handler:16

_hos_vector028:	stm.l	er0-er3,@-sp
	mov.b	#28, r0l
	bra	int_handler:16

_hos_vector029:	stm.l	er0-er3,@-sp
	mov.b	#29, r0l
	bra	int_handler:16

_hos_vector030:	stm.l	er0-er3,@-sp
	mov.b	#30, r0l
	bra	int_handler:16

_hos_vector031:	stm.l	er0-er3,@-sp
	mov.b	#31, r0l
	bra	int_handler:16

_hos_vector032:	stm.l	er0-er3,@-sp
	mov.b	#32, r0l
	bra	int_handler:16

_hos_vector033:	stm.l	er0-er3,@-sp
	mov.b	#33, r0l
	bra	int_handler:16

_hos_vector034:	stm.l	er0-er3,@-sp
	mov.b	#34, r0l
	bra	int_handler:16

_hos_vector035:	stm.l	er0-er3,@-sp
	mov.b	#35, r0l
	bra	int_handler:16

_hos_vector036:	stm.l	er0-er3,@-sp
	mov.b	#36, r0l
	bra	int_handler:16

_hos_vector037:	stm.l	er0-er3,@-sp
	mov.b	#37, r0l
	bra	int_handler:16

_hos_vector038:	stm.l	er0-er3,@-sp
	mov.b	#38, r0l
	bra	int_handler:16

_hos_vector039:	stm.l	er0-er3,@-sp
	mov.b	#39, r0l
	bra	int_handler:16

_hos_vector040:	stm.l	er0-er3,@-sp
	mov.b	#40, r0l
	bra	int_handler:16

_hos_vector041:	stm.l	er0-er3,@-sp
	mov.b	#41, r0l
	bra	int_handler:16

_hos_vector042:	stm.l	er0-er3,@-sp
	mov.b	#42, r0l
	bra	int_handler:16

_hos_vector043:	stm.l	er0-er3,@-sp
	mov.b	#43, r0l
	bra	int_handler:16

_hos_vector044:	stm.l	er0-er3,@-sp
	mov.b	#44, r0l
	bra	int_handler:16

_hos_vector045:	stm.l	er0-er3,@-sp
	mov.b	#45, r0l
	bra	int_handler:16

_hos_vector046:	stm.l	er0-er3,@-sp
	mov.b	#46, r0l
	bra	int_handler:16

_hos_vector047:	stm.l	er0-er3,@-sp
	mov.b	#47, r0l
	bra	int_handler:16

_hos_vector048:	stm.l	er0-er3,@-sp
	mov.b	#48, r0l
	bra	int_handler:16

_hos_vector049:	stm.l	er0-er3,@-sp
	mov.b	#49, r0l
	bra	int_handler:16

_hos_vector050:	stm.l	er0-er3,@-sp
	mov.b	#50, r0l
	bra	int_handler:16

_hos_vector051:	stm.l	er0-er3,@-sp
	mov.b	#51, r0l
	bra	int_handler:16

_hos_vector052:	stm.l	er0-er3,@-sp
	mov.b	#52, r0l
	bra	int_handler:16

_hos_vector053:	stm.l	er0-er3,@-sp
	mov.b	#53, r0l
	bra	int_handler:16

_hos_vector054:	stm.l	er0-er3,@-sp
	mov.b	#54, r0l
	bra	int_handler:16

_hos_vector055:	stm.l	er0-er3,@-sp
	mov.b	#55, r0l
	bra	int_handler:16

_hos_vector056:	stm.l	er0-er3,@-sp
	mov.b	#56, r0l
	bra	int_handler:16

_hos_vector057:	stm.l	er0-er3,@-sp
	mov.b	#57, r0l
	bra	int_handler:16

_hos_vector058:	stm.l	er0-er3,@-sp
	mov.b	#58, r0l
	bra	int_handler:16

_hos_vector059:	stm.l	er0-er3,@-sp
	mov.b	#59, r0l
	bra	int_handler1:8

_hos_vector060:	stm.l	er0-er3,@-sp
	mov.b	#60, r0l
	bra	int_handler1:8

_hos_vector061:	stm.l	er0-er3,@-sp
	mov.b	#61, r0l
	bra	int_handler1:8

_hos_vector062:	stm.l	er0-er3,@-sp
	mov.b	#62, r0l
	bra	int_handler1:8

_hos_vector063:	stm.l	er0-er3,@-sp
	mov.b	#63, r0l
	bra	int_handler1:8

_hos_vector064:	stm.l	er0-er3,@-sp
	mov.b	#64, r0l
	bra	int_handler1:8

_hos_vector065:	stm.l	er0-er3,@-sp
	mov.b	#65, r0l
	bra	int_handler1:8

_hos_vector066:	stm.l	er0-er3,@-sp
	mov.b	#66, r0l
	bra	int_handler1:8

_hos_vector067:	stm.l	er0-er3,@-sp
	mov.b	#67, r0l
	bra	int_handler1:8

_hos_vector068:	stm.l	er0-er3,@-sp
	mov.b	#68, r0l
	bra	int_handler1:8

_hos_vector069:	stm.l	er0-er3,@-sp
	mov.b	#69, r0l
	bra	int_handler1:8

_hos_vector070:	stm.l	er0-er3,@-sp
	mov.b	#70, r0l
	bra	int_handler1:8

_hos_vector071:	stm.l	er0-er3,@-sp
	mov.b	#71, r0l
	bra	int_handler1:8

_hos_vector072:	stm.l	er0-er3,@-sp
	mov.b	#72, r0l
	bra	int_handler1:8

_hos_vector073:	stm.l	er0-er3,@-sp
	mov.b	#73, r0l
	bra	int_handler1:8

_hos_vector074:	stm.l	er0-er3,@-sp
	mov.b	#74, r0l
	bra	int_handler1:8

_hos_vector075:	stm.l	er0-er3,@-sp
	mov.b	#75, r0l

int_handler1:
	bra	int_handler:8

_hos_vector076:	stm.l	er0-er3,@-sp
	mov.b	#76, r0l
	bra	int_handler:8

_hos_vector077:	stm.l	er0-er3,@-sp
	mov.b	#77, r0l
	bra	int_handler:8

_hos_vector078:	stm.l	er0-er3,@-sp
	mov.b	#78, r0l
	bra	int_handler:8

_hos_vector079:	stm.l	er0-er3,@-sp
	mov.b	#79, r0l
	bra	int_handler:8

_hos_vector080:	stm.l	er0-er3,@-sp
	mov.b	#80, r0l
	bra	int_handler:8

_hos_vector081:	stm.l	er0-er3,@-sp
	mov.b	#81, r0l
	bra	int_handler:8

_hos_vector082:	stm.l	er0-er3,@-sp
	mov.b	#82, r0l
	bra	int_handler:8

_hos_vector083:	stm.l	er0-er3,@-sp
	mov.b	#83, r0l
	bra	int_handler:8

_hos_vector084:	stm.l	er0-er3,@-sp
	mov.b	#84, r0l
	bra	int_handler:8

_hos_vector085:	stm.l	er0-er3,@-sp
	mov.b	#85, r0l
	bra	int_handler:8

_hos_vector086:	stm.l	er0-er3,@-sp
	mov.b	#86, r0l
	bra	int_handler:8

_hos_vector087:	stm.l	er0-er3,@-sp
	mov.b	#87, r0l
	bra	int_handler:8

_hos_vector088:	stm.l	er0-er3,@-sp
	mov.b	#88, r0l
	bra	int_handler:8

_hos_vector089:	stm.l	er0-er3,@-sp
	mov.b	#89, r0l
	bra	int_handler:8

_hos_vector090:	stm.l	er0-er3,@-sp
	mov.b	#90, r0l
	bra	int_handler:8

_hos_vector091:	stm.l	er0-er3,@-sp
	mov.b	#91, r0l

/************************************************
          割り込み処理

  割り込み発生時は er0-er3 を push した後、r0l に
  割り込み番号をセットして、ここにジャンプする
*************************************************/
int_handler:
#ifndef	__NO_S2600__
	/* 2600の場合、MACレジスタも保存する */
	stmac.l	mach,er2
	stmac.l	macl,er3
	stm.l	er2-er3,@-sp
#endif

	/* 割り込み番号のマスク */
	extu.w	r0

	/* 割り込みマスク設定 */
#if	H8S_INTMODE == 0
	stc.b	ccr, r1l
	and.b	#0xc0, r1l
#else	// H8S_INTMODE == 1
	stc.b	exr, r1l
#endif
	mov.b	r1l, @_kernel_h83_imsk

	/* 多重割り込みの判別 */
	mov.w	@_kernel_int_cnt, r1
	bne	mul_int

	/* ======== 最初の割り込み ======== */
	/* 割り込みネストカウンタ設定 */
	mov.w	#1, r1
	mov.w	r1, @_kernel_int_cnt

	/* スタックポインタの入れ替え */
	mov.l	er7, @_kernel_int_ssp
	mov.l	@_kernel_int_sp, er7

	/* 割り込み処理の開始 */
	push.w	r0
	jsr	@_kernel_sta_int
	pop.w	r0

	/* 割り込みハンドラの処理 */
	jsr	@_kernel_exe_int

	/* スタックポインタ復帰 */
	mov.l	@_kernel_int_ssp, er7

	/* 割り込みネストカウンタクリア */
	xor.w	r1, r1
	mov.w	r1, @_kernel_int_cnt

	/* 割り込みマスク値の復帰 */
	mov.b	@_kernel_h83_ibmsk, r0l
	mov.b	r0l, @_kernel_h83_imsk	/* 割り込みマスク値をベース値に戻す */

	/* タスクコンテキストに移行 */
	jsr	@_kernel_end_int

	/* 復帰後のマスク値を設定 */
	mov.b	@_kernel_h83_ibmsk, r0l	/* ベースマスク値取り出し */

#ifndef	__NO_S2600__
	/* 2600の場合、MACレジスタ保存分がある */
	#define MAC_OFFSET	8
#else
	#define MAC_OFFSET	0
#endif

	mov.b	@(16+MAC_OFFSET, er7), r1l
#if	H8S_INTMODE == 0
	and.b	#0x3f,r1l	/* スタック上のCCRからIとU以外を取り出し */
	or.b	r0l, r1l	/* ベースマスク値を設定 */
	mov.b	r1l, @(16+MAC_OFFSET, er7) /* スタック上のCCRを更新 */
#else	/* H8S_INTMODE == 1 */
	mov.b	r0l, @(16+MAC_OFFSET, er7) /* スタック上のEXRを更新 */
#endif

	/* 復帰 */
#ifndef	__NO_S2600__
	/* MACレジスタ復帰 */
	ldm.l	@sp+,er0-er1
	ldmac.l	er1,macl
	ldmac.l	er0,mach
#endif
	ldm.l	@sp+,er0-er3
	rte


	/* ======== 多重割り込み ======== */
mul_int:
	/* 割り込みネストカウンタ加算 */
	inc.w	#1, r1
	mov.w	r1, @_kernel_int_cnt

	/* 割り込みハンドラ呼び出し */
	jsr	@_kernel_exe_int

	/* 割り込みネストカウンタ減算 */
	mov.w	@_kernel_int_cnt, r0
	dec.w	#1, r0
	mov.w	r0, @_kernel_int_cnt

	/* 復帰 */
#ifndef __NO_S2600__
	/* 2600の場合、MACレジスタ復帰 */
	ldm.l	@sp+,er0-er1
	ldmac.l	er1,macl
	ldmac.l	er0,mach
#endif
	ldm.l	@sp+,er0-er3
	rte


	.end


/* -------------------------------------------------------------------------*/
/*  Copyright (C) 2003 by Project HOS                                       */
/* -------------------------------------------------------------------------*/

