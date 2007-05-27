/* ------------------------------------------------------------------------ */
/*  H8/3664�� SCI3����饤�֥��                                            */
/*                                                                          */
/*                                  Copyright (C) 1998-2002 by Project HOS  */
/*                                  http://sourceforge.jp/projects/hos/     */
/* ------------------------------------------------------------------------ */
#include "kernel.h"
#include "h83664f.h"
#include "h8t_sci.h"

#define RECV_BUFSIZE	32		/* �����Хåե��Υ����� */

static unsigned char recv_buf[RECV_BUFSIZE];
static int head;
static int tail;

/* SCI3����� */
void SCI3_Initialize(unsigned char rate)
{
	volatile int i;
	
	/* SCI3����� */
	SCI3.SCR3.BYTE = 0x00;
	SCI3.SMR.BYTE = 0x00;
	SCI3.BRR = rate;
	for ( i = 0; i < 280; i++ )
		;
	SCI3.SCR3.BYTE = 0x30; /* ������|������ */
	IO.PMR1.BIT.TXD = 1;
}

/* ��ʸ������ */
void SCI3_PutChar(char c)
{
	while ( !(SCI3.SSR.BYTE & 0x80) )
		;

	SCI3.TDR  = c;

	while ( !(SCI3.SSR.BYTE & 0x04) )
		;
}

/* ��ʸ������ */
int SCI3_GetChar(void)
{
	int c;

	if ( head == tail )
	{
		return -1;
	}

	c = recv_buf[head++];
	if ( head == RECV_BUFSIZE )
	{
		head = 0;
	}
	
	return c;
}

/* SCI���������� */
void SCI3_RxiHandler(VP_INT exinf)
{
	unsigned char c;
	int next;
	
	/* 1ʸ������ */
	c = SCI3.RDR;
	SCI3.SSR.BYTE &= 0xbf;
	
	/* �����������֤�׻� */
	next = tail + 1;
	if ( next == RECV_BUFSIZE )
	{
		next = 0;
	}
	
	/* �����С��ե������å� */
	if ( next == head )
	{
		return;
	}
	
	/* �����Хåե��˳�Ǽ */
	recv_buf[tail] = c;
	tail = next;
}

/* ------------------------------------------------------------------------ */
/*                                  Copyright (C) 1998-2002 by Project HOS  */
/*                                  http://sourceforge.jp/projects/hos/     */
/* ------------------------------------------------------------------------ */
