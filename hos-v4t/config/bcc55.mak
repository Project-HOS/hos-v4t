# -----------------------------------------------------------------------------
#  HOS-V4
#   ����ե�����졼�����ᥤ���ե����� Borland C++ V5.5 ��
#
#                                     Copyright (C) 1998-2003 by Project HOS
#                                     http://sourceforge.jp/projects/hos/
# -----------------------------------------------------------------------------



# �ġ���
CC   = bcc32
LINK = bcc32


# ���ץ����
CFLAGS = -c -O2
LFLAGS =


# �������å�
TARGET  = hos4tcfg


# ���֥������ȥե�����
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


# �������å�����
$(TARGET).exe: $(OBJS)
	$(LINK) -e$(TARGET).exe $(OBJS)

# ���꡼�󥢥å�
clean:
	del *.obj
	del $(TARGET).tds
	del $(TARGET).exe

# ������§
.cpp.obj:
	$(CC) $(CFLAGS) $<


# -----------------------------------------------------------------------------
#  Copyright (C) 1998-2003 by Project HOS
# -----------------------------------------------------------------------------
