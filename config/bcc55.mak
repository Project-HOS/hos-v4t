# -----------------------------------------------------------------------------
#  HOS-V4
#   コンフィギュレーターメイクファイル Borland C++ V5.5 用
#
#                                     Copyright (C) 1998-2003 by Project HOS
#                                     http://sourceforge.jp/projects/hos/
# -----------------------------------------------------------------------------



# ツール
CC   = bcc32
LINK = bcc32


# オプション
CFLAGS = -c -O2
LFLAGS =


# ターゲット
TARGET  = hos4tcfg


# オブジェクトファイル
OBJS =  hos4cfg.obj \
	analyze.obj \
	parpack.obj \
	read.obj \
	defercd.obj \
	intstk.obj \
	idlstk.obj \
	knlheap.obj \
	apidef.obj \
	apiinc.obj \
	cretsk.obj \
	cresem.obj \
	creflg.obj \
	attini.obj \
	attisr.obj


.suffixes:
.suffixes: .cpp


# ターゲット生成
$(TARGET).exe: $(OBJS)
	$(LINK) -e$(TARGET).exe $(OBJS)

# クリーンアップ
clean:
	del *.obj
	del $(TARGET).tds
	del $(TARGET).exe

# 推論規則
.cpp.obj:
	$(CC) $(CFLAGS) $<


# -----------------------------------------------------------------------------
#  Copyright (C) 1998-2003 by Project HOS
# -----------------------------------------------------------------------------
