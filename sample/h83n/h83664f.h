/* ------------------------------------------------------------------------- */
/*  H8/3664F �� �إå��ե�����                                               */
/*  ���ƤΥǥХ����Ǹ��ڤ򤷤Ƥ������Ǥ�̵���Τǡ����Ѥˤ����äƤϽ�ʬ���   */
/*  ��ɬ�פǤ���                                                             */
/*  �����դ��Ŀͤθ³��ȸ������ǡ��Х�����ԤäƤޤ���                       */
/*                                                                           */
/*  ��Ω����إå����ե����� �С�����󣲤Ȥΰ㤤                            */
/*  ��Ω�Υإå����ե�����Ǥ�16bitĹ�Υե�����ɤ� int��ɽ���Ƥ��ޤ���      */
/*  ���Υإå����ե�����⤽����浪�����Ȥ�פ��ޤ�������short��ɽ������    */
/*  ���ޤ������ȸ����Τ� SH�ʤ󤫤�빽 H8�Ǻ������������ǥ��󥰤��Τޤ�ư   */
/*  �����㤦����¿���ΤǤ���(�ä� SCI��)���㤨�� AD�Ϥ�Ϥ�10bit�Ǥ���Ĺ��   */
/*  �� H8�� SH���Ѥ�餺���쥸������16bit�ǥ����������ޤ������ä��� int��    */
/*  ���ä��� short�Ȥʤ�Τ����ޥ������ʤΤǡ�ξ���Ȥ�·����٤� short����   */
/*  �����Ƥ��ޤ���                                                           */
/*  �ޤ�����Ω����ѥ��顼 �С�����󣳰ʾ�Ǥ�����Ȥʤ�ʤ��ӥåȥե���    */
/*  ��ɤξ�ά�Ǥ����������ѥ��顢�Ĥޤ���Ω����ѥ��� �С�����󣲤�    */
/*  ���֥��åȤǤϥ���ѥ��륨�顼�Ȥʤ�Τǡ�Ŭ���ʥե������̾�򽼤ƤƤ�   */
/*  �ޤ���                                                                   */
/*                                                                           */
/*                                   Copyright (C) 1998-2003 by Project HOS  */
/* ------------------------------------------------------------------------- */


#ifndef __PROJECT_HOS__H8_3664_H_
#define __PROJECT_HOS__H8_3664_H_

/* IO �ǥХ������ɥ쥹��� */
#define	__EKR_ADD__		0xFF10		/* EKR�쥸�����������ȥ��ɥ쥹 */
#define	__TIMER_W_ADD__	0xFF80		/* TW�쥸�����������ȥ��ɥ쥹 */
#define	__FLASH_ADD__	0xFF90		/* FLASH�쥸�����������ȥ��ɥ쥹 */
#define	__TIMER_V_ADD__	0xFFA0		/* TV�쥸�����������ȥ��ɥ쥹 */
#define	__TIMER_A_ADD__	0xFFA6		/* TA�쥸�����������ȥ��ɥ쥹 */
#define	__SCI3_ADD__	0xFFA8		/* SCI3�쥸�����������ȥ��ɥ쥹 */
#define	__AD_ADD__		0xFFB0		/* A/D�쥸�����������ȥ��ɥ쥹 */
#define	__WDT_ADD__		0xFFC0		/* WDT�쥸�����������ȥ��ɥ쥹 */
#define	__IIC_ADD__		0xFFC4		/* IIC�쥸�����������ȥ��ɥ쥹 */
#define	__ADDRESS_BREAK_ADD__	0xFFC8		/* ���ɥ쥹�֥쥤���쥸�����������ȥ��ɥ쥹 */
#define	__IO_PORT_ADD__		0xFFD0	/* IO�ݡ��ȥ쥸�����������ȥ��ɥ쥹 */
#define	__SYSCR1_ADD__	0xFFF0		/* SYSCR1�쥸�����������ȥ��ɥ쥹 */
#define	__SYSCR2_ADD__	0xFFF1		/* SYSCR2�쥸�����������ȥ��ɥ쥹 */
#define	__IEGR1_ADD__	0xFFF2		/* IEGR1�쥸�����������ȥ��ɥ쥹 */
#define	__IEGR2_ADD__	0xFFF3		/* IEGR2�쥸�����������ȥ��ɥ쥹 */
#define	__IENR1_ADD__	0xFFF4		/* IENR1�쥸�����������ȥ��ɥ쥹 */
#define	__IRR1_ADD__	0xFFF6		/* IRR1�쥸�����������ȥ��ɥ쥹 */
#define	__IWPR_ADD__	0xFFF8		/* IWPR�쥸�����������ȥ��ɥ쥹 */
#define	__MSTCR1_ADD__	0xFFF9		/* MSTCR1�쥸�����������ȥ��ɥ쥹 */
#define	__TSCR_ADD__	0xFFFC		/* TSCR�쥸�����������ȥ��ɥ쥹 */

/*TIMER W*/
struct __TIMER_W_REGISTER__
{
	union								/*TMRW*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct							/*Bit Access*/
		{
			unsigned char CTS:1;		/*�����󥿥�������*/
			unsigned char rsv1:1;		/*ͽ��*/
			unsigned char BUFEB:1;		/*�Хåե�ư�� B*/
			unsigned char BUFEA:1;		/*�Хåե�ư�� A*/
			unsigned char rsv2:1;		/*ͽ��*/
			unsigned char PWMD:1;		/*PWM�⡼�� D*/
			unsigned char PWMC:1;		/*PWM�⡼�� C*/
			unsigned char PWMB:1;		/*PWM�⡼�� B*/
		} BIT;
	} TMRW;
	union								/*TCRW*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct							/*Bit Access*/
		{
			unsigned char CCLR:1;		/*�����󥿥��ꥢ*/
			unsigned char CKS:3;		/*����å����쥯��*/
			unsigned char TOD:1;		/*�����޽��ϥ�٥륻�å� D*/
			unsigned char TOC:1;		/*�����޽��ϥ�٥륻�å� C*/
			unsigned char TOB:1;		/*�����޽��ϥ�٥륻�å� B*/
			unsigned char TOA:1;		/*�����޽��ϥ�٥륻�å� A*/
		} BIT;
	} TCRW;
	union								/*TIERW*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct							/*Bit Access*/
		{
			unsigned char OVIE:1;		/*�����ޥ����С��ե�����ߥ��͡��֥�*/
			unsigned char rsv1:3;		/*ͽ��*/
			unsigned char IMIED:1;		/*����ץåȥ���ץ���/����ڥ��ޥå�����ߥ��͡��֥� D*/
			unsigned char IMIEC:1;		/*����ץåȥ���ץ���/����ڥ��ޥå�����ߥ��͡��֥� C*/
			unsigned char IMIEB:1;		/*����ץåȥ���ץ���/����ڥ��ޥå�����ߥ��͡��֥� B*/
			unsigned char IMIEA:1;		/*����ץåȥ���ץ���/����ڥ��ޥå�����ߥ��͡��֥� A*/
		} BIT;
	} TIERW;
	union								/*TSRW*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct							/*Bit Access*/
		{
			unsigned char OVF:1;		/*�����ޥ����С��ե�*/
			unsigned char rsv1:3;		/*ͽ��*/
			unsigned char IMFD:1;		/*����ץåȥ���ץ���/����ڥ��ޥå��ե饰 D*/
			unsigned char IMFC:1;		/*����ץåȥ���ץ���/����ڥ��ޥå��ե饰 C*/
			unsigned char IMFB:1;		/*����ץåȥ���ץ���/����ڥ��ޥå��ե饰 B*/
			unsigned char IMFA:1;		/*����ץåȥ���ץ���/����ڥ��ޥå��ե饰 A*/
		} BIT;
	} TSRW;
	union								/*TIOR0*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct							/*Bit Access*/
		{
			unsigned char rsv1:1;		/*ͽ��*/
			unsigned char IOB:3;		/*IO����ȥ��� B*/
			unsigned char rsv2:1;		/*ͽ��*/
			unsigned char IOA:3;		/*IO����ȥ��� A*/
		} BIT;
	} TIOR0;
	union								/*TIOR1*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct							/*Bit Access*/
		{
			unsigned char rsv1:1;		/*ͽ��*/
			unsigned char IOD:3;		/*IO����ȥ��� D*/
			unsigned char rsv2:1;		/*ͽ��*/
			unsigned char IOC:3;		/*IO����ȥ��� C*/
		} BIT;
	} TIOR1;
	unsigned short	TCNT;				/*�����ޥ�����*/
	unsigned short	GRA;				/*�����ͥ��쥸���� A*/
	unsigned short	GRB;				/*�����ͥ��쥸���� B*/
	unsigned short	GRC;				/*�����ͥ��쥸���� C*/
	unsigned short	GRD;				/*�����ͥ��쥸���� D*/
};

#define	TW	(*(volatile struct __TIMER_W_REGISTER__ *)__TIMER_W_ADD__)


/*FLASH ROM*/
struct __FLASH_ROM_REGISTER__
{
	union								/*FLMCR1*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct							/*Bit Access*/
		{
			unsigned char rsv1:1;		/*ͽ��*/
			unsigned char SWE:1;		/*���եȥ������饤�ȥ��͡��֥�*/
			unsigned char ESU:1;		/*���졼�����åȥ��å�*/
			unsigned char PSU:1;		/*�ץ���ॻ�åȥ��å�*/
			unsigned char EV:1;			/*���졼���٥�ե���*/
			unsigned char PV:1;			/*�ץ����٥�ե���*/
			unsigned char E:1;			/*�����졼��*/
			unsigned char P:1;			/*�ץ����*/
		} BIT;
	} FLMCR1;
	union								/*FLMCR2*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct							/*Bit Access*/
		{
			unsigned char FLER:1;		/*FLASH ROM �񤭹��ߥ��顼*/
			unsigned char rsv1:7;		/*ͽ��*/
		} BIT;
	} FLMCR2;
	union								/*FLPWCR*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct							/*Bit Access*/
		{
			unsigned char PDWND:1;		/*�ѥ������ǥ��������֥�*/
			unsigned char rsv1:7;		/*ͽ��*/
		} BIT;
	} FLPWCR;
	union								/*EBR1*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct							/*Bit Access*/
		{
			unsigned char rsv1:3;		/*ͽ��*/
			unsigned char EB4:1;		/*���졼���֥�å� 4*/
			unsigned char EB3:1;		/*���졼���֥�å� 3*/
			unsigned char EB2:1;		/*���졼���֥�å� 2*/
			unsigned char EB1:1;		/*���졼���֥�å� 1*/
			unsigned char EB0:1;		/*���졼���֥�å� 0*/
		} BIT;
	} EBR1;
	char	rsv1[ 0xff9b - 0xff93 - 1 ];	/*����*/
	union								/*FENR*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct							/*Bit Access*/
		{
			unsigned char FLSHE:1;		/*�ե�å�����ꥳ��ȥ���쥸�������͡��֥�*/
			unsigned char rsv1:7;		/*ͽ��*/
		} BIT;
	} FENR;
};

#define	FLASH	(*(volatile struct __FLASH_ROM_REGISTER__ *)__FLASH_ADD__)

/*TIMER V*/
struct __TIMER_V_REGISTER__
{
	union								/*TCRV0*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct							/*Bit Access*/
		{
			unsigned char CMIEB:1;		/*����ڥ��ޥå����󥿥�ץȥ��͡��֥� B*/
			unsigned char CMIEA:1;		/*����ڥ��ޥå����󥿥�ץȥ��͡��֥� A*/
			unsigned char OVIE:1;		/*�����ޥ����С��ե����󥿥�ץȥ��͡��֥� B*/
			unsigned char CCLR:2;		/*�����󥿥��ꥢ*/
			unsigned char CKS:3;		/*����å����쥯��*/
		} BIT;
	} TCRV0;
	union								/*TCSRV*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct							/*Bit Access*/
		{
			unsigned char CMFB:1;		/*����ڥ��ޥå��ե饰 B*/
			unsigned char CMFA:1;		/*����ڥ��ޥå��ե饰 A*/
			unsigned char OVF:1;		/*�����ޥ����С��ե��ե饰*/
			unsigned char rsv1:1;		/*ͽ��*/
			unsigned char OS:4;			/*�����ȥץåȥ��쥯��*/
		} BIT;
	} TCSRV;
	unsigned char TCORA;				/*�����ॳ�󥹥���ȥ쥸���� A*/
	unsigned char TCORB;				/*�����ॳ�󥹥���ȥ쥸���� B*/
	unsigned char TCNTV;				/*�����ޥ�����ȥ� V*/
	union								/*TCRV1*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct							/*Bit Access*/
		{
			unsigned char rsv1:3;		/*ͽ��*/
			unsigned char TVEG:2;		/*TRGV ���ϥ��å����쥯��*/
			unsigned char TRGE:1;		/*������ȥ��åפγ��Ϥȥ�����ȥ��åפ���ߤζػߤ�*/
			unsigned char rsv2:1;		/*ͽ��*/
			unsigned char ICKS:1;		/*���󥿡��ʥ륯��å����쥯�� 0*/
		} BIT;
	} TCRV1;
};

#define	TV	(*(volatile struct __TIMER_V_REGISTER__ *)__TIMER_V_ADD__)

/*TIMER A*/
struct __TIMER_A_REGISTER__
{
	union								/*TMA*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct							/*Bit Access*/
		{
			unsigned char CKSO:3;		/*TMOWü�Ҥ�����Ϥ��륯��å�������*/
			unsigned char rsv1:1;		/*ͽ��*/
			unsigned char CKSI:4;		/*������A��ư��⡼�ɤ�����*/
		} BIT;
	} TMA;
	unsigned char TCA;					/*�����ޥ����� A*/
};

#define	TA	(*(volatile struct __TIMER_A_REGISTER__ *)__TIMER_A_ADD__)

/*SCI3*/
struct __SCI3_REGISTER__
{
	union								/*SMR*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct							/*Bit Access*/
		{
			unsigned char COM:1;		/*���ߥ�˥��������⡼��*/
			unsigned char CHR:1;		/*����饯����󥰥�*/
			unsigned char PE:1;			/*�ѥ�ƥ����͡��֥�*/
			unsigned char PM:1;			/*�ѥ�ƥ��⡼��*/
			unsigned char STOP:1;		/*���ȥåץӥåȥ�󥰥�*/
			unsigned char MP:1;			/*�ޥ���ץ��å��⡼��*/
			unsigned char CKS:2;		/*����å����쥯��*/
		} BIT;
	} SMR;
	unsigned char BRR;					/*�ӥåȥ졼�ȥ쥸����*/
	union								/*SCR3*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct							/*Bit Access*/
		{
			unsigned char TIE:1;		/*�ȥ�󥹥ߥåȥ��󥿥�ץȥ��͡��֥�*/
			unsigned char RIE:1;		/*�쥷���֥��󥿥�ץȥ��͡��֥�*/
			unsigned char TE:1;			/*�ȥ�󥹥ߥåȥ��͡��֥�*/
			unsigned char RE:1;			/*�쥷���֥��͡��֥�*/
			unsigned char MPIE:1;		/*�ޥ���ץ��å����󥿥�ץȥ��͡��֥�*/
			unsigned char TEIE:1;		/*�ȥ�󥹥ߥåȥ���ɥ��󥿥�ץȥ��͡��֥�*/
			unsigned char CKE:2;		/*����å����͡��֥�*/
		} BIT;
	} SCR3;
	unsigned char TDR;					/**/
	union								/*SSR*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct							/*Bit Access*/
		{
			unsigned char TDRE:1;		/*�ȥ�󥹥ߥåȥǡ����쥸��������ץƥ�*/
			unsigned char RDRF:1;		/*�쥷���֥ǡ����쥸�����ե�*/
			unsigned char OER:1;		/*�����С���󥨥顼*/
			unsigned char FER:1;		/*�ե졼�ߥ󥰥��顼*/
			unsigned char PER:1;		/*�ѥ�ƥ����顼*/
			unsigned char TEND:1;		/*�ȥ�󥹥ߥåȥ����*/
			unsigned char MPBR:1;		/*�ޥ���ץ��å��ӥåȥ쥷����*/
			unsigned char MPBT:1;		/*�ޥ���ץ��å��ӥåȥȥ�󥹥ե�*/
		} BIT;
	} SSR;
	unsigned char RDR;					/*�쥷���֥ǡ����쥸����*/
};

#define	SCI3	(*(volatile struct __SCI3_REGISTER__ *)__SCI3_ADD__)

/*AD*/
struct __AD_REGISTER__
{
	unsigned short ADDRA;				/*A/D �ǡ����쥸���� A*/
	unsigned short ADDRB;				/*A/D �ǡ����쥸���� B*/
	unsigned short ADDRC;				/*A/D �ǡ����쥸���� C*/
	unsigned short ADDRD;				/*A/D �ǡ����쥸���� D*/
	union								/*ADCSR*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct							/*Bit Access*/
		{
			unsigned char ADF:1;		/*A/D ����ɥե饰*/
			unsigned char ADIE:1;		/*A/D ���󥿥�ץȥ��͡��֥�*/
			unsigned char ADST:1;		/*A/D ��������*/
			unsigned char SCAN:1;		/*�������⡼��*/
			unsigned char CKS:1;		/*����å����쥯��*/
			unsigned char CH:3;			/*����ͥ륻�쥯��*/
		} BIT;
	} ADCSR;
	union								/*ADCR*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct							/*Bit Access*/
		{
			unsigned char TRGE:1;		/*�ȥꥬ���͡��֥�*/
			unsigned char rsv1:7;		/*ͽ��*/
		} BIT;
	} ADCR;
};

#define	AD	(*(volatile struct __AD_REGISTER__ *)__AD_ADD__)

/*WDT*/
struct __WDT_REGISTER__
{
	union								/*TCSRWD*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct							/*Bit Access*/
		{
			unsigned char B6WI:1;		/*�ӥå� 6 ����߶ػ�*/
			unsigned char TCWE:1;		/*�����ޥ����� W �񤭹��ߵ���*/
			unsigned char B4WI:1;		/*�ӥå� 4 ����߶ػ�*/
			unsigned char TCSRWE:1;		/*�����ޥ���ȥ���/���ơ������쥸���� W �񤭹��ߵ���*/
			unsigned char B2WI:1;		/*�ӥå� 2 ����߶ػ�*/
			unsigned char WDON:1;		/*�����å��ɥå������ޥ���*/
			unsigned char B0WI:1;		/*�ӥå� 0 ����߶ػ�*/
			unsigned char WRST:1;		/*�����å��ɥå������ޥꥻ�å�*/
		} BIT;
	} TCSRWD;
	unsigned char	TCWD;				/*�����ޥ�����*/
	union								/*TMWD*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct							/*Bit Access*/
		{
			unsigned char rsv1:4;		/*ͽ��*/
			unsigned char CKS:4;		/*����å����쥯��*/
		} BIT;
	} TMWD;
};

#define	WDT	(*(volatile struct __WDT_REGISTER__ *)__WDT_ADD__)

/*IIC*/
struct __IIC_REGISTER__
{
	union								/*ICCR*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct							/*Bit Access*/
		{
			unsigned char ICE:1;		/*I2C�Х����󥿥ե��������͡��֥�*/
			unsigned char IEIC:1;		/*I2C�Х����󥿥ե���������ߥ��͡��֥�*/
			unsigned char MST:1;		/*�ޥ�����/���졼������*/
			unsigned char TRS:1;		/*��������*/
			unsigned char ACKE:1;		/*�����Υ�å��ӥå�Ƚ������*/
			unsigned char BBSY:1;		/*�Х��ӥ���*/
			unsigned char IRIC:1;		/*I2C�Х����󥿥ե�����������׵�ե饰*/
			unsigned char SCP:1;		/*���Ͼ��/��߾��ȯ�Զػߥӥå�*/
		} BIT;
	} ICCR;
	union								/*ICSR*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct							/*Bit Access*/
		{
			unsigned char ESTP:1;		/*���顼��߾�︡�Хե饰*/
			unsigned char STOP:1;		/*������߾�︡�Хե饰*/
			unsigned char IRTR:1;		/*I2C�Х����󥿥ե�����Ϣ³������������׵�ե饰*/
			unsigned char AASX:1;		/*���󥹥졼�֥��ɥ쥹ǧ���ե饰*/
			unsigned char AL:1;			/*�����ӥȥ졼�������ȥե饰*/
			unsigned char AAS:1;		/*���졼�֥��ɥ쥹ǧ���ե饰*/
			unsigned char ADZ:1;		/*���ͥ�륳���륢�ɥ쥹ǧ���ե饰*/
			unsigned char ACKB:1;		/*�����Υ�å��ӥå�*/
		} BIT;
	} ICSR;
	union
	{
		struct
		{
			union
			{
				unsigned char	BYTE;	/*Byte Access*/
				struct					/*Bit Access*/
				{
					unsigned char SVAX:7;	/*���󥹥졼�֥��ɥ쥹*/
					unsigned char FSX:1;	/*SAR��FS�Ȥ��Ȥ߹�碌��ž���ե����ޥåȤ�����*/
				} BIT;
			} UN_SARX;
			union
			{
				unsigned char	BYTE;	/*Byte Access*/
				struct					/*Bit Access*/
				{
					unsigned char SVA:7;	/*���졼�֥��ɥ쥹*/
					unsigned char FS:1;		/*SARX��FSX�Ȥ��Ȥ߹�碌��ž���ե����ޥåȤ�����*/
				} BIT;
			} UN_SAR;
		} ICE0;
		struct
		{
			unsigned char	UN_ICDR;	/* I2C�Х� �ǡ����쥸����*/
			union
			{
				unsigned char	BYTE;	/*Byte Access*/
				struct					/*Bit Access*/
				{
					unsigned char MLS:1;	/*MSB�ե�������/LSB�ե�����������*/
					unsigned char WAIT:1;	/*�������������ӥå�*/
					unsigned char CKS:3;	/*ž������å�����*/
					unsigned char BC:3;		/*�ӥåȥ����󥿡�*/
				} BIT;
			} UN_ICMR;
		} ICE1;
	} EQU;
};

#define	IIC	(*(volatile struct __IIC_REGISTER__ *)__IIC_ADD__)
#define	ICDR	EQU.ICE1.UN_ICDR		/* ICDR */
#define	ICMR	EQU.ICE1.UN_ICMR		/* ICDR */
#define	SAR		EQU.ICE0.UN_SAR			/* SAR  */
#define	SARX	EQU.ICE0.UN_SARX		/* SARX */

/*ADDRESS BREAK*/
struct __ADDRESS_BREAK_REGISTER__
{
	union								/*ABRKCR*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct							/*Bit Access*/
		{
			unsigned char RTINTE:1;		/*RTE����ߥ��͡��֥�*/
			unsigned char CSEL:2;		/*����ǥ�����󥻥쥯��*/
			unsigned char ACMP:3;		/*���ɥ쥹����ڥ�*/
			unsigned char DCMP:2;		/*�ǡ�������ڥ�*/
		} BIT;
	} CR;
	union								/*ABRKSR*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct							/*Bit Access*/
		{
			unsigned char ABIF:1;		/*ABRKCR�����ꤵ�줿��郎��Ω������*/
			unsigned char ABIE:1;		/* 1�λ����ɥ쥹�֥졼��������׵�򥤥͡��֥�ˤ��ޤ�*/
			unsigned char rsv1:6;		/*ͽ��*/
		} BIT;
	} SR;
	void			*BAR;				/*�֥졼�����ɥ쥹�쥸����*/
	unsigned short	BDR;				/*�֥졼���ǡ����쥸����*/
};

#define	ABRK	(*(volatile struct __ADDRESS_BREAK_REGISTER__ *)__ADDRESS_BREAK_ADD__)

/*IO PORT*/
struct __IO_PORT_REGISTER__
{
	union								/*PUCR1*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct							/*Bit Access*/
		{
			unsigned char B7:1;			/* Bit 7 */
			unsigned char B6:1;			/* Bit 6 */
			unsigned char B5:1;			/* Bit 5 */
			unsigned char B4:1;			/* Bit 4 */
			unsigned char rsv1:1;		/*ͽ��*/
			unsigned char B2:1;			/* Bit 2 */
			unsigned char B1:1;			/* Bit 1 */
			unsigned char B0:1;			/* Bit 0 */
		} BIT;
	} PUCR1;
	union								/*PUCR5*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct							/*Bit Access*/
		{
			unsigned char rsv1:2;		/*ͽ��*/
			unsigned char B5:1;			/* Bit 5 */
			unsigned char B4:1;			/* Bit 4 */
			unsigned char B3:1;			/* Bit 3 */
			unsigned char B2:1;			/* Bit 2 */
			unsigned char B1:1;			/* Bit 1 */
			unsigned char B0:1;			/* Bit 0 */
		} BIT;
	} PUCR5;
	char	rsv1[ 0xffd4 - 0xffd1 - 1 ];	/*����*/
	union								/*PDR1*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct							/*Bit Access*/
		{
			unsigned char B7:1;			/* Bit 7 */
			unsigned char B6:1;			/* Bit 6 */
			unsigned char B5:1;			/* Bit 5 */
			unsigned char B4:1;			/* Bit 4 */
			unsigned char rsv1:1;		/*ͽ��*/
			unsigned char B2:1;			/* Bit 2 */
			unsigned char B1:1;			/* Bit 1 */
			unsigned char B0:1;			/* Bit 0 */
		} BIT;
	} PDR1;
	union								/*PDR2*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct							/*Bit Access*/
		{
			unsigned char rsv1:5;		/*ͽ��*/
			unsigned char B2:1;			/* Bit 2 */
			unsigned char B1:1;			/* Bit 1 */
			unsigned char B0:1;			/* Bit 0 */
		} BIT;
	} PDR2;
	char	rsv2[ 0xffd8 - 0xffd5 - 1 ];	/*����*/
	union								/*PDR5*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct							/*Bit Access*/
		{
			unsigned char B7:1;			/* Bit 7 */
			unsigned char B6:1;			/* Bit 6 */
			unsigned char B5:1;			/* Bit 5 */
			unsigned char B4:1;			/* Bit 4 */
			unsigned char B3:1;			/* Bit 3 */
			unsigned char B2:1;			/* Bit 2 */
			unsigned char B1:1;			/* Bit 1 */
			unsigned char B0:1;			/* Bit 0 */
		} BIT;
	} PDR5;
	char	rsv3[ 0xffda - 0xffd8 - 1 ];	/*����*/
	union								/*PDR7*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct							/*Bit Access*/
		{
			unsigned char rsv1:1;		/*ͽ��*/
			unsigned char B6:1;			/* Bit 6 */
			unsigned char B5:1;			/* Bit 5 */
			unsigned char B4:1;			/* Bit 4 */
			unsigned char rsv2:4;		/*ͽ��*/
		} BIT;
	} PDR7;
	union								/*PDR8*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct							/*Bit Access*/
		{
			unsigned char B7:1;			/* Bit 7 */
			unsigned char B6:1;			/* Bit 6 */
			unsigned char B5:1;			/* Bit 5 */
			unsigned char B4:1;			/* Bit 4 */
			unsigned char B3:1;			/* Bit 3 */
			unsigned char B2:1;			/* Bit 2 */
			unsigned char B1:1;			/* Bit 1 */
			unsigned char B0:1;			/* Bit 0 */
		} BIT;
	} PDR8;
	char	rsv4[ 0xffdd - 0xffdb - 1 ];	/*����*/
	union								/*PDRB*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct							/*Bit Access*/
		{
			unsigned char B7:1;			/* Bit 7 */
			unsigned char B6:1;			/* Bit 6 */
			unsigned char B5:1;			/* Bit 5 */
			unsigned char B4:1;			/* Bit 4 */
			unsigned char B3:1;			/* Bit 3 */
			unsigned char B2:1;			/* Bit 2 */
			unsigned char B1:1;			/* Bit 1 */
			unsigned char B0:1;			/* Bit 0 */
		} BIT;
	} PDRB;
	char	rsv5[ 0xffe0 - 0xffdd - 1 ];	/*����*/
	union								/*PMR1*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct							/*Bit Access*/
		{
			unsigned char IRQ3:1;		/*P17/IRQ3/TRGVü�Ҥε�ǽ������򤷤ޤ�*/
			unsigned char IRQ2:1;		/*P16/IRQ2ü�Ҥε�ǽ������򤷤ޤ�*/
			unsigned char IRQ1:1;		/*P15/IRQ1ü�Ҥε�ǽ������򤷤ޤ�*/
			unsigned char IRQ0:1;		/*P14/IRQ0ü�Ҥε�ǽ������򤷤ޤ�*/
			unsigned char rsv1:2;		/*ͽ��*/
			unsigned char TXD:1;		/*P22/TXDü�Ҥε�ǽ������򤷤ޤ�*/
			unsigned char TMOW:1;		/*P10/TMOWü�Ҥε�ǽ������򤷤ޤ�*/
		} BIT;
	} PMR1;
	union								/*PMR5*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct							/*Bit Access*/
		{
			unsigned char rsv1:2;		/*ͽ��*/
			unsigned char WKP5:1;		/*P55/WKP5ü�Ҥε�ǽ������򤷤ޤ�*/
			unsigned char WKP4:1;		/*P54/WKP4ü�Ҥε�ǽ������򤷤ޤ�*/
			unsigned char WKP3:1;		/*P53/WKP3ü�Ҥε�ǽ������򤷤ޤ�*/
			unsigned char WKP2:1;		/*P52/WKP2ü�Ҥε�ǽ������򤷤ޤ�*/
			unsigned char WKP1:1;		/*P51/WKP1ü�Ҥε�ǽ������򤷤ޤ�*/
			unsigned char WKP0:1;		/*P50/WKP0ü�Ҥε�ǽ������򤷤ޤ�*/
		} BIT;
	} PMR5;
	char	rsv6[ 0xffe4 - 0xffe1 - 1 ];	/*����*/
	unsigned char	PCR1;				/**/
	unsigned char	PCR2;				/**/
	char	rsv7[ 0xffe8 - 0xffe5 - 1 ];	/*����*/
	unsigned char	PCR5;				/**/
	char	rsv8[ 0xffea - 0xffe8 - 1 ];	/*����*/
	unsigned char	PCR7;				/**/
	unsigned char	PCR8;				/**/
};

#define	IO	(*(volatile struct __IO_PORT_REGISTER__ *)__IO_PORT_ADD__)

/*SYSCR1*/
union __SYSCR1_REGISTER__
{
	unsigned char BYTE;					/*Byte Access*/
	struct								/*Bit Access*/
	{
		unsigned char SSBY:1;			/*���եȥ�����������Х�*/
		unsigned char STS:3;			/*������Х������ޥ��쥯��*/
		unsigned char NESEL:1;			/*�Υ��������ץ�󥰼��ȿ�����*/
		unsigned char rsv1:3;			/*ͽ��*/
	} BIT;
};

#define	SYSCR1	(*(volatile union __SYSCR1_REGISTER__ *)__SYSCR1_ADD__)

/*SYSCR2*/
union __SYSCR2_REGISTER__
{
	unsigned char BYTE;					/*Byte Access*/
	struct								/*Bit Access*/
	{
		unsigned char SMSEL:1;			/*���꡼�ץ⡼������*/
		unsigned char LSON:1;			/*�����ԡ��ɥ���ե饰*/
		unsigned char DTON:1;			/*�����쥯�ȥȥ�󥹥ե�����ե饰*/
		unsigned char MA:3;				/*�����ƥ��֥⡼�ɥ���å����쥯��*/
		unsigned char SA:2;				/*���֥����ƥ��֥⡼�ɥ���å����쥯��*/
	} BIT;
};

#define	SYSCR2	(*(volatile union __SYSCR2_REGISTER__ *)__SYSCR2_ADD__)

/*IEGR1*/
union __IEGR1_REGISTER__
{
	unsigned char BYTE;					/*Byte Access*/
	struct								/*Bit Access*/
	{
		unsigned char NMIEG:1;			/*NMI���å����쥯��*/
		unsigned char rsv1:3;			/*ͽ��*/
		unsigned char IEG3:1;			/*IRQ3���å����쥯��*/
		unsigned char IEG2:1;			/*IRQ2���å����쥯��*/
		unsigned char IEG1:1;			/*IRQ1���å����쥯��*/
		unsigned char IEG0:1;			/*IRQ0���å����쥯��*/
	} BIT;
};

#define	IEGR1	(*(volatile union __IEGR1_REGISTER__ *)__IEGR1_ADD__)

/*IEGR2*/
union __IEGR2_REGISTER__
{
	unsigned char BYTE;					/*Byte Access*/
	struct								/*Bit Access*/
	{
		unsigned char rsv1:2;			/*ͽ��*/
		unsigned char WPEG5:1;			/*WKOP5���å����쥯��*/
		unsigned char WPEG4:1;			/*WKOP4���å����쥯��*/
		unsigned char WPEG3:1;			/*WKOP3���å����쥯��*/
		unsigned char WPEG2:1;			/*WKOP2���å����쥯��*/
		unsigned char WPEG1:1;			/*WKOP1���å����쥯��*/
		unsigned char WPEG0:1;			/*WKOP0���å����쥯��*/
	} BIT;
};

#define	IEGR2	(*(volatile union __IEGR2_REGISTER__ *)__IEGR2_ADD__)

/*IENR1*/
union __IENR1_REGISTER__
{
	unsigned char BYTE;					/*Byte Access*/
	struct								/*Bit Access*/
	{
		unsigned char IENDT:1;			/*ľ�����ܳ�����׵ᥤ�͡��֥�*/
		unsigned char IENTA:1;			/*������ A ������׵ᥤ�͡��֥�*/
		unsigned char IENWP:1;			/* WAKE UP ������׵ᥤ�͡��֥�*/
		unsigned char rsv1:1;			/*ͽ��*/
		unsigned char IEN3:1;			/*IRQ3 ������׵ᥤ�͡��֥�*/
		unsigned char IEN2:1;			/*IRQ2 ������׵ᥤ�͡��֥�*/
		unsigned char IEN1:1;			/*IRQ1 ������׵ᥤ�͡��֥�*/
		unsigned char IEN0:1;			/*IRQ0 ������׵ᥤ�͡��֥�*/
	} BIT;
};

#define	IENR1	(*(volatile union __IENR1_REGISTER__ *)__IENR1_ADD__)

/*IRR1*/
union __IRR1_REGISTER__
{
	unsigned char BYTE;					/*Byte Access*/
	struct								/*Bit Access*/
	{
		unsigned char IRRDT:1;			/*ľ�����ܳ�����׵�ե饰*/
		unsigned char IRRTA:1;			/*������ A ������׵�ե饰*/
		unsigned char rsv1:2;			/*ͽ��*/
		unsigned char IRRI3:1;			/*IRQ3 ������׵�ե饰*/
		unsigned char IRRI2:1;			/*IRQ2 ������׵�ե饰*/
		unsigned char IRRI1:1;			/*IRQ1 ������׵�ե饰*/
		unsigned char IRRI0:1;			/*IRQ0 ������׵�ե饰*/
	} BIT;
};

#define	IRR1	(*(volatile union __IRR1_REGISTER__ *)__IRR1_ADD__)

/*IWPR*/
union __IWPR_REGISTER__
{
	unsigned char BYTE;					/*Byte Access*/
	struct								/*Bit Access*/
	{
		unsigned char rsv1:2;			/*ͽ��*/
		unsigned char IWPF5:1;			/*WKP5 ������׵�ե饰*/
		unsigned char IWPF4:1;			/*WKP4 ������׵�ե饰*/
		unsigned char IWPF3:1;			/*WKP3 ������׵�ե饰*/
		unsigned char IWPF2:1;			/*WKP2 ������׵�ե饰*/
		unsigned char IWPF1:1;			/*WKP1 ������׵�ե饰*/
		unsigned char IWPF0:1;			/*WKP0 ������׵�ե饰*/
	} BIT;
};

#define	IWPR	(*(volatile union __IWPR_REGISTER__ *)__IWPR_ADD__)

/*MSTCR1*/
union __MSTCR1_REGISTER__
{
	unsigned char BYTE;					/*Byte Access*/
	struct								/*Bit Access*/
	{
		unsigned char rsv1:1;			/*ͽ��*/
		unsigned char MSTIIC:1;			/*IIC�⥸�塼�륹����Х�*/
		unsigned char MSTS3:1;			/*SCI3�⥸�塼�륹����Х�*/
		unsigned char MSTAD:1;			/*A/D�Ѵ��⥸�塼�륹����Х�*/
		unsigned char MSTWD:1;			/*�����å��ɥå������ޡ��⥸�塼�륹����Х�*/
		unsigned char MSTTW:1;			/*������ W �⥸�塼�륹����Х�*/
		unsigned char MSTTV:1;			/*������ V �⥸�塼�륹����Х�*/
		unsigned char MSTTA:1;			/*������ A �⥸�塼�륹����Х�*/
	} BIT;
};

#define	MSTCR1	(*(volatile union __MSTCR1_REGISTER__ *)__MSTCR1_ADD__)

/*TSCR*/
union __TSCR_REGISTER__
{
	unsigned char BYTE;					/*Byte Access*/
	struct								/*Bit Access*/
	{
		unsigned char rsv1:6;			/*ͽ��*/
		unsigned char IICRST:1;			/*IICRST�ϡ�I2C�쥸�������������ȥ�������RESET���ޤ���*/
		unsigned char IICX:1;			/*ICMR��CKS2��0�Ȥ��Ȥ߹�碌�ǡ��ޥ������⡼�ɤ�ž���졼�Ȥ����򤷤ޤ���*/
	} BIT;
};

#define	TSCR	(*(volatile union __TSCR_REGISTER__ *)__TSCR_ADD__)

/*EKR*/
union __EKR_REGISTER__
{
	unsigned char BYTE;					/*Byte Access*/
	struct								/*Bit Access*/
	{
		unsigned char B7:1;				/* Bit 7 */
		unsigned char B6:1;				/* Bit 6 */
		unsigned char B5:1;				/* Bit 5 */
		unsigned char B4:1;				/* Bit 4 */
		unsigned char B3:1;				/* Bit 3 */
		unsigned char B2:1;				/* Bit 2 */
		unsigned char B1:1;				/* Bit 1 */
		unsigned char B0:1;				/* Bit 0 */
	} BIT;
};

#define	EKR	(*(volatile union __EKR_REGISTER__ *)__EKR_ADD__)

#endif /* __PROJECT_HOS__H8_3664_H_ */
