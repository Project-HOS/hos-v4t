# -----------------------------------------------------------------------------
#  HOS-V4                                                                      
#   ����ե�����졼�����ᥤ���ե����� GCC��                       
#                                                                              
#                                       Copyright (C) 1998-2002 by Project HOS 
#                                       http://sourceforge.jp/projects/hos/    
# -----------------------------------------------------------------------------



# �ġ���
CC   = g++
LINK = g++


# ���ץ����
CFLAGS = -O2 -pipe -Wall
LFLAGS = 


# �������å�
TARGET  = hos4tcfg


# ���֥������ȥե�����
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



# �������å�����
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
