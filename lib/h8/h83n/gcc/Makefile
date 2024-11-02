# ---------------------------------------------------------------------------
#  Hyper Operating System V4 Tiny μITRON4.0仕様 Real-Time OS
#   ライブラリメイクファイル SH2 gcc用
#
#                                     Copyright (C) 1998-2003 by Project HOS
#                                     http://sourceforge.jp/projects/hos/
# ---------------------------------------------------------------------------



# パス定義
HOSROOT	= ../../../..
INCDIR	= $(HOSROOT)/include
SRCDIR	= $(HOSROOT)/src
CPUDIR	= $(SRCDIR)/cpu/h8/h83n/gcc
DSPDIR	= $(SRCDIR)/dsp
FLGDIR	= $(SRCDIR)/flg
QUEDIR	= $(SRCDIR)/que
SEMDIR	= $(SRCDIR)/sem
SYSDIR	= $(SRCDIR)/sys
TSKDIR	= $(SRCDIR)/tsk


# ツール
CC	= h8300-hms-gcc
AS	= h8300-hms-gcc
LIBR	= h8300-hms-ar
RANLIB	= h8300-hms-ranlib


# オプション
CFLAGS = -c -O2 -mh -mn -I$(INCDIR)
AFLAGS = -c -x assembler-with-cpp -mh -mn


# ターゲット
TARGET  = libh4th83n.a


#インクルードファイル
INCS = $(INCDIR)/itron.h \
       $(INCDIR)/kernel.h


# オブジェクトファイル
OBJS =	pacctx.o pacint.o \
	exe_dsp.o \
	chk_flg.o clr_flg.o pol_flg.o set_flg.o wai_flg.o \
	add_que.o rmv_que.o \
	pol_sem.o sig_sem.o wai_sem.o \
	sta_hos.o exe_int.o \
	chg_pri.o ext_tsk.o get_pri.o slp_tsk.o sta_tsk.o wup_tsk.o


# ライブラリ生成
$(TARGET): $(OBJS)
	$(LIBR) rc $(TARGET) $(OBJS)
	$(RANLIB) $(TARGET)
	rm -f $(OBJS)


# プロセッサ依存
pacctx.o: $(CPUDIR)/pacctx.s $(INCS)
	$(AS) $(AFLAGS) $(CPUDIR)/pacctx.s

pacint.o: $(CPUDIR)/pacint.s $(INCS)
	$(AS) $(AFLAGS) $(CPUDIR)/pacint.s


# カーネル固有
sta_hos.o: $(SYSDIR)/sta_hos.c $(INCS)
	$(CC) $(CFLAGS) $(SYSDIR)/sta_hos.c

exe_int.o: $(SYSDIR)/exe_int.c $(INCS)
	$(CC) $(CFLAGS) $(SYSDIR)/exe_int.c


# タスク
chg_pri.o: $(TSKDIR)/chg_pri.c $(INCS)
	$(CC) $(CFLAGS) $(TSKDIR)/chg_pri.c

ext_tsk.o: $(TSKDIR)/ext_tsk.c $(INCS)
	$(CC) $(CFLAGS) $(TSKDIR)/ext_tsk.c

get_pri.o: $(TSKDIR)/get_pri.c $(INCS)
	$(CC) $(CFLAGS) $(TSKDIR)/get_pri.c

slp_tsk.o: $(TSKDIR)/slp_tsk.c $(INCS)
	$(CC) $(CFLAGS) $(TSKDIR)/slp_tsk.c

sta_tsk.o: $(TSKDIR)/sta_tsk.c $(INCS)
	$(CC) $(CFLAGS) $(TSKDIR)/sta_tsk.c

wup_tsk.o: $(TSKDIR)/wup_tsk.c $(INCS)
	$(CC) $(CFLAGS) $(TSKDIR)/wup_tsk.c


# セマフォ
pol_sem.o: $(SEMDIR)/pol_sem.c $(INCS)
	$(CC) $(CFLAGS) $(SEMDIR)/pol_sem.c

sig_sem.o: $(SEMDIR)/sig_sem.c $(INCS)
	$(CC) $(CFLAGS) $(SEMDIR)/sig_sem.c

wai_sem.o: $(SEMDIR)/wai_sem.c $(INCS)
	$(CC) $(CFLAGS) $(SEMDIR)/wai_sem.c


# イベントフラグ
chk_flg.o: $(FLGDIR)/chk_flg.c $(INCS)
	$(CC) $(CFLAGS) $(FLGDIR)/chk_flg.c

clr_flg.o: $(FLGDIR)/clr_flg.c $(INCS)
	$(CC) $(CFLAGS) $(FLGDIR)/clr_flg.c

pol_flg.o: $(FLGDIR)/pol_flg.c $(INCS)
	$(CC) $(CFLAGS) $(FLGDIR)/pol_flg.c

set_flg.o: $(FLGDIR)/set_flg.c $(INCS)
	$(CC) $(CFLAGS) $(FLGDIR)/set_flg.c

wai_flg.o: $(FLGDIR)/wai_flg.c $(INCS)
	$(CC) $(CFLAGS) $(FLGDIR)/wai_flg.c



# キュー
add_que.o: $(QUEDIR)/add_que.c
	$(CC) $(CFLAGS) $(QUEDIR)/add_que.c

rmv_que.o: $(QUEDIR)/rmv_que.c
	$(CC) $(CFLAGS) $(QUEDIR)/rmv_que.c

# ディスパッチャ
exe_dsp.o: $(DSPDIR)/exe_dsp.c
	$(CC) $(CFLAGS) $(DSPDIR)/exe_dsp.c


clean:
	rm -f $(OBJS)
	rm -f $(TARGET)


# -----------------------------------------------------------------------------
#  Copyright (C) 1998-2003 by Project HOS
# -----------------------------------------------------------------------------
