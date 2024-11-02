/* ------------------------------------------------------------------------ */
/*  Hyper Operating System V4 Tiny  ��ITRON4.0���� Real-Time OS             */
/*    ��ITRON4.0 ɸ��إå�                                                 */
/*                                                                          */
/*                                  Copyright (C) 1998-2003 by Project HOS  */
/*                                  http://sourceforge.jp/projects/hos/     */
/* ------------------------------------------------------------------------ */



#ifndef __HOS_V4T__itron_h__
#define __HOS_V4T__itron_h__



/* ------------------------------------ */
/*          �ǡ��������                */
/* ------------------------------------ */

typedef signed char		B;			/* ����դ�8�ӥå����� */
typedef signed short	H;			/* ����դ�16�ӥå����� */
typedef signed long		W;			/* ����դ�32�ӥå����� */

typedef unsigned char	UB;			/* ���̵��8�ӥå����� */
typedef unsigned short 	UH;			/* ���̵��16�ӥå����� */
typedef unsigned long	UW;			/* ���̵��32�ӥå����� */

typedef signed char		VB;			/* �ǡ��������פ���ޤ�ʤ�8�ӥåȤ��� */
typedef signed short	VH;			/* �ǡ��������פ���ޤ�ʤ�16�ӥåȤ��� */
typedef signed long		VW;			/* �ǡ��������פ���ޤ�ʤ�32�ӥåȤ��� */

typedef void			*VP;		/* �ǡ��������פ���ޤ�ʤ���ΤؤΥݥ��� */
typedef void			(*FP)();	/* �ץ����ε�ư���ϡʥݥ��󥿡� */

typedef signed   int	INT;		/* �ץ��å��˼����ʥ�����������դ�����(16bit�ʾ�) */
typedef unsigned int	UINT;		/* �ץ��å��˼����ʥ����������̵������(16bit�ʾ�) */

typedef INT		BOOL;		/* ������ */

typedef INT		FN;			/* ��ǽ������ */
typedef INT		ER;			/* ���顼������ */
typedef UB		ID;			/* ���֥������Ȥ�ID�ֹ� */
typedef UB		ATR;		/* ���֥������Ȥ�°�� */
typedef UB		STAT;		/* ���֥������Ȥξ��� */
typedef UB		MODE;		/* �����ӥ��������ư��⡼�� */
typedef UB		PRI;		/* ͥ���� */
typedef UW		SIZE;		/* �����ΰ�Υ����� */
typedef W		TMO;		/* �����ॢ���Ȼ��� */
typedef UW		RELTIM;		/* ���л��� */

typedef struct t_systim		/* �����ƥ���� */
{
	UW ltime;				/* ���� 32bit */
	UH utime;				/* ��� 16bit */
} SYSTIM;

typedef long	VP_INT;		/* VP �ޤ��� INT */

typedef ER		ER_BOOL;	/* ER �ޤ��� BOOL */

typedef W		ER_UINT;	/* ER �ޤ��� UINT */

typedef INT		ER_ID;		/* ER �ޤ��� ID */

typedef UH		TEXPTN;		/* �������㳰�װ��Υѥ����� */

typedef UH		FLGPTN;		/* �ե饰�ѥ����� */

typedef INT     EXCNO;		/* CPU�㳰�ϥ�ɥ��ֹ� */

typedef INT		INHNO;		/* �����ߥϥ�ɥ��ֹ� */
typedef INT		INTNO;		/* �������ֹ� */



/* ------------------------------------ */
/*             ������                 */
/* ------------------------------------ */

/* ���� */
#ifdef NULL		/* C����ɸ��إå��Ȥζ������ */
#undef NULL
#endif

#ifdef __cplusplus
#define NULL		0			/* ̵���ݥ��� */
#else
#define NULL		((void *)0)	/* ̵���ݥ��� */
#endif

#define TRUE		1			/* �� */
#define FALSE		0			/* �� */
#define E_OK		0			/* ���ｪλ */


/* ���֥�������°�� */
#define TA_NULL		0			/* ���֥�������°������ꤷ�ʤ� */
#define TA_HLNG		0x00		/* �������ѤΥ��󥿡��ե������ǽ���ñ�̤�ư */
#define TA_ASM		0x01		/* ������֥�����ѤΥ��󥿡��ե������ǽ���ñ�̤�ư */

#define TA_TFIFO	0x00		/* ���������Ԥ������FIFO��� */
#define TA_TPRI		0x01		/* ���������Ԥ�����򥿥�����ͥ���ٽ�� */

#define TA_MFIFO	0x00		/* ��å��������Ԥ������FIFO��� */
#define TA_MPRI		0x02		/* ��å��������Ԥ�������å�������ͥ���ٽ�� */

#define TA_ACT		0x02		/* ��������ư���줿���֤����� */
#define TA_RSTR		0x04		/* ���󥿥��� */

#define TA_WSGL		0x00		/* ���٥�ȥե饰��ʣ���Υ��������ԤĤ��Ȥ�����ʤ� */
#define TA_WMUL		0x02		/* ���٥�ȥե饰��ʣ���Υ��������ԤĤ��Ȥ���� */
#define TA_CLR		0x04		/* �Ԥ�������˥��٥�ȥե饰�򥯥ꥢ */

#define TA_INHERIT	0x02		/* �ߥ塼�ƥå�����ͥ���ٷѾ��ץ�ȥ���򥵥ݡ��� */
#define TA_CEILING	0x03		/* �ߥ塼�ƥå�����ͥ���پ�¥ץ�ȥ���򥵥ݡ��� */

#define TA_STA		0x02		/* �����ϥ�ɥ��ư��Ƥ�����֤����� */
#define TA_PHS		0x04		/* �����ϥ�ɥ�ΰ������¸ */


/* �����ॢ���Ȼ��� */
#define TMO_POL		0			/* �ݡ���� */
#define TMO_FEVR	(-1)		/* �ʵ��Ԥ� */
#define TMO_NBLK	(-2)		/* �Υ�֥�å��� */


/* �����ӥ��������ư��⡼�� */
#define TWF_ANDW	0x00		/* ���٥�ȥե饰��AND�Ԥ� */
#define TWF_ORW		0x01		/* ���٥�ȥե饰��OR�Ԥ� */


/* ���֥������Ȥξ��� */
#define TTS_RUN		0x01		/* �¹Ծ��� */
#define TTS_RDY		0x02		/* �¹Բ�ǽ���� */
#define TTS_WAI		0x04		/* �Ԥ����� */
#define TTS_SUS		0x08		/* �����Ԥ����� */
#define TTS_WAS		0x0c		/* ����Ԥ����� */
#define TTS_DMT		0x10		/* �ٻ߾��� */

#define TTW_SLP		0x0001		/* �����Ԥ����� */
#define TTW_DLY		0x0002		/* ���ַв��Ԥ����� */
#define TTW_SEM		0x0004		/* ���ޥե��񸻤γ����Ԥ����� */
#define TTW_FLG		0x0008		/* ���٥�ȥե饰�Ԥ����� */
#define TTW_SDTQ	0x0010		/* �ǡ������塼�ؤ������Ԥ����� */
#define TTW_RDTQ	0x0020		/* �ǡ������塼����μ����Ԥ����� */
#define TTW_MBX		0x0040		/* �᡼��ܥå�������μ����Ԥ����� */
#define TTW_MTX		0x0080		/* �ߥ塼�ƥå����Υ�å��Ԥ����� */
#define TTW_SMBF	0x0100		/* ��å������Хåե��ؤ������Ԥ����� */
#define TTW_RMBF	0x0200		/* ��å������Хåե�����μ����Ԥ����� */
#define TTW_CAL		0x0400		/* ���ǥ֤θƤӽФ��Ԥ����� */
#define TTW_ACP		0x0800		/* ���ǥ֤μ����Ԥ����� */
#define TTW_RDV		0x1000		/* ���ǥ֤ν�λ�Ԥ����� */
#define TTW_MPF		0x2000		/* ����Ĺ����֥�å��γ����Ԥ����� */
#define TTW_MPL		0x4000		/* ����Ĺ����֥�å��γ����Ԥ����� */

#define TTEX_ENA	0x00		/* ���������㳰�������ľ��� */
#define TTEX_DIS	0x01		/* �������㳰�����ػ߾��� */

#define TCYC_STP	0x00		/* �����ϥ�ɥ餬ư��Ƥ��ʤ� */
#define TCYC_STA	0x01		/* �����ϥ�ɥ餬ư��Ƥ��� */

#define TALM_STP	0x00		/* ���顼��ϥ�ɥ餬ư��Ƥ��ʤ� */
#define TALM_STA	0x00		/* ���顼��ϥ�ɥ餬ư��Ƥ��� */

#define TOVR_STP	0x00		/* ��¥ץ��å����֤����ꤵ��Ƥ��ʤ� */
#define TOVR_STA	0x01		/* ��¥ץ��å����֤����ꤵ��Ƥ��� */

/* ����¾����� */
#define TSK_SELF	0			/* ������������ */
#define TSK_NONE	0			/* �������륿������̵�� */

#define TPRI_SELF	0			/* ���������Υ١���ͥ���٤λ��� */
#define TPRI_INI	0			/* �������ε�ư��ͥ���٤λ��� */


/* ���顼������ */
#define E_SYS		(-5)		/* �����ƥ२�顼 */
#define E_NOSPT		(-9)		/* ̤���ݡ��ȵ�ǽ */
#define E_RSFN		(-10)		/* ͽ��ǽ������ */
#define E_RSATR		(-11)		/* ͽ��°�� */
#define E_PAR		(-17)		/* �ѥ�᡼�����顼 */
#define E_ID		(-18)		/* ����ID�ֹ� */
#define E_CTX		(-25)		/* ����ƥ����ȥ��顼 */
#define E_MACV		(-26)		/* ���ꥢ��������ȿ */
#define E_OACV		(-27)		/* ���֥������ȥ���������ȿ */
#define E_ILUSE		(-28)		/* �����ӥ��������������� */
#define E_NOMEM		(-33)		/* ������­ */
#define E_NOID		(-34)		/* ID�ֹ���­ */
#define E_OBJ		(-41)		/* ���֥������Ⱦ��֥��顼 */
#define E_NOEXS		(-42)		/* ���֥�������̤���� */
#define E_QOVR		(-43)		/* ���塼���󥰥����С��ե� */
#define E_RLWAI		(-49)		/* �Ԥ����֤ζ������ */
#define E_TMOUT		(-50)		/* �ݡ���󥰼��Ԥޤ��ϥ����ॢ���� */
#define E_DLT		(-51)		/* �Ԥ����֥������Ȥκ�� */
#define E_CLS		(-52)		/* �Ԥ����֥������Ȥξ����Ѳ� */
#define E_WBLK		(-57)		/* �Υ�֥�å��󥰼��դ� */
#define E_BOVR		(-58)		/* �Хåե������С��ե� */


/* ID���ϰ�(HOS�ȼ�) */
#define TMIN_TSKID	1			/* ��������ID�ֹ�κǾ��� */
#define TMIN_SEMID	1			/* ���ޥե���ID�ֹ�κǾ��� */
#define TMIN_FLGID	1			/* ���٥�ȥե饰��ID�ֹ�κǾ��� */
#define TMIN_DTQID	1			/* �ǡ������塼��ID�ֹ�κǾ��� */
#define TMIN_MBXID	1			/* �᡼��ܥå�����������ID�ֹ�κǾ��� */
#define TMIN_MBFID	1			/* ��å������Хåե���ID�ֹ�κǾ��� */
#define TMIN_MPFID	1			/* ����Ĺ����ס����ID�ֹ�κǾ��� */
#define TMIN_CYCID	1			/* �����ϥ�ɥ��ID�ֹ�κǾ��� */
#define TMIN_ALMID	1			/* ���顼��ϥ�ɥ��ID�ֹ�κǾ��� */
#define TMIN_ISRID	1			/* �����ߥ����ӥ��롼�����ID�ֹ�κǾ��� */



/* ------------------------------------ */
/*           �ޥ������                 */
/* ------------------------------------ */


/* ���顼�����ɼ��Ф� */
#define	MERCD(ercd)		((ER)((B)(ercd)))		/* ���顼�����ɤ���ᥤ�󥨥顼�����ɤ���Ф� */
#define	SERCD(ercd)		((ercd) >> 8)			/* ���顼�����ɤ��饵�֥��顼�����ɤ���Ф� */



#endif /* __HOS_V4T__itron_h__ */



/* ------------------------------------------------------------------------ */
/*  Copyright (C) 1998-2003 by Project HOS                                  */
/* ------------------------------------------------------------------------ */
