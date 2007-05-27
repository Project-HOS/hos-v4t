# -----------------------------------------------------------------------------
#  HOS-V4                                                                      
#   コンフィギュレーターメイクファイル GCC用                       
#                                                                              
#                                       Copyright (C) 1998-2002 by Project HOS 
#                                       http://sourceforge.jp/projects/hos/    
# -----------------------------------------------------------------------------



# ツール
CC   = g++
LINK = g++


# オプション
CFLAGS = -O2 -pipe -Wall
LFLAGS = 


# ターゲット
TARGET  = hos4tcfg


# オブジェクトファイル
OBJS = hos4cfg.o \
       analyze.o \
       parpack.o \
       read.o \
       defercd.o \
       intstk.o \
       idlstk.o \
       knlheap.o \
       apidef.o \
       apiinc.o \
       cretsk.o \
       cresem.o \
       creflg.o \
       attini.o \
       attisr.o



# ターゲット生成
$(TARGET): $(OBJS)
	$(LINK) $(OBJS) -o $(TARGET)

clean:
	rm -f $(TARGET) $(TARGET).exe $(OBJS)

.cpp.o:
	$(CC) $(CFLAGS) -c $<

.c.o:
	$(CC) $(CFLAGS) -c $<


# -----------------------------------------------------------------------------
#  Copyright (C) 1998-2002 by Project HOS                                      
# -----------------------------------------------------------------------------
