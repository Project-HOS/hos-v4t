/* ------------------------------------------------------------------------ */
/*  Hyper Operating System V4 Tiny  ��ITRON4.0���� Real-Time OS             */
/*    �����ͥ��¸��������إå�                                            */
/*                                                                          */
/*                                  Copyright (C) 1998-2003 by Project HOS  */
/*                                  http://sourceforge.jp/projects/hos/     */
/* ------------------------------------------------------------------------ */


#ifndef __HOS_V4T__kernel_h__
#define __HOS_V4T__kernel_h__


#include "itron.h"



/* ------------------------------------------ */
/*                  ������                  */
/* ------------------------------------------ */

/* �����ƥ�ξ��� */
#define KERNEL_TSS_TSK		0x00				/* ���������¹��� */
#define KERNEL_TSS_INDP		0x04				/* ��������Ω���¹��� */
#define KERNEL_TSS_DDSP		0x01				/* �ǥ����ѥå��ػ� (dis_dsp ͭ��) */
#define KERNEL_TSS_DINT		0x02				/* �����߶ػ�(loc_cpu ͭ��) */


/* ���塼���󥰡��ͥ��Ȳ���κ����� */
#define TMAX_ACTCNT			0					/* ��������ư�׵ᥭ�塼���󥰿��κ����� */
#define TMAX_WUPCNT			127					/* �����������׵ᥭ�塼���󥰿��κ����� */
#define TMAX_SUSCNT			0					/* �����������Ԥ��׵�ͥ��ȿ��κ����� */



/* ------------------------------------------ */
/*                 �����                     */
/* ------------------------------------------ */


/* ����ƥ����Ⱦ�����¸�֥�å� */
typedef struct t_hos_pac_ctxinf
{
	VP sp;			/* �����å��ݥ�����¸�ΰ� */
} T_HOSPAC_CTXINF;


/* ���塼�����֥�å� */
typedef struct t_kernel_que
{
	ID    head;					/* ���塼��Ƭ�Υ�����ID */
} T_KERNEL_QUE;


/* ����������ȥ���֥�å� */
typedef struct t_kernel_tcb
{
	T_HOSPAC_CTXINF ctxinf;		/* ����ƥ����Ⱦ�����¸�֥�å� */
	T_KERNEL_QUE    *que;		/* ��³����Ƥ��륭�塼 */
	PRI   tskpri;				/* ���ߤ�ͥ���� */
	ID    next;					/* ���Υ����� */
	ID    prev;					/* ���Υ����� */
	UB    wupcnt;				/* �����׵ᥭ�塼���󥰿� */
	FP    task;					/* �������ε�ư���� */
	VP    isp;					/* ��������å��ݥ��� */
} T_KERNEL_TCB;


/* ���ޥե�����ȥ���֥�å� */
typedef struct t_kernel_semcb
{
	T_KERNEL_QUE que;			/* ���ޥե��Ԥ����������塼 */
	UB           semcnt;		/* ���ޥե��λ񸻿� */
} T_KERNEL_SEMCB;


/* ���٥�ȥե饰����ȥ���֥�å� */
typedef struct t_kernel_flgcb
{
	ID     tskid;		/* �ե饰�Ԥ��Υ�����ID */
	FLGPTN flgptn;		/* ���٥�ȥե饰�Υӥåȥѥ����� */
	MODE   wfmode;		/* �Ԥ��⡼�� */
	FLGPTN waiptn;		/* �Ԥ��ӥåȥѥ�����ʲ�����ѥ�����ȷ���) */
	FLGPTN *p_flgptn;	/* �ե饰�ѥ������Ǽ���ɥ쥹 */
} T_KERNEL_FLGCB;


/* �����ߥϥ�ɥ� */
typedef struct t_kernel_intcb
{
	FP    	isr;		/* �ϥ�ɥ�ε�ư���� */
	VP_INT	exinf;
} T_KERNEL_INTCB;


/* �����ƥ���� */
typedef struct t_kernel_sys
{
    T_HOSPAC_CTXINF ctxinf_idle;	/* �����ɥ륳��ƥ����� */
	T_KERNEL_QUE    rdyque;			/* ��ǥ������塼 */
	UB              tskid_run;		/* �¹��楿������ID */
	UB              stat;			/* �����ƥ�Υ���ƥ����Ⱦ��� */
	UB              dly_dsp;		/* �ٱ䤷�Ƥ���ǥ����ѥå������뤫 */
} T_KERNEL_SYS;



/* ---------------------------------- */
/*        �����Х��ѿ����          */
/* ---------------------------------- */


extern FP             kernel_irq_tbl[];			/* �����ߥϥ�ɥ�ơ��֥� */
extern T_KERNEL_TCB   kernel_tcb_tbl[];			/* ����������ȥ���֥�å��ơ��֥� */
extern T_KERNEL_SEMCB kernel_semcb_tbl[];		/* ���ޥե�����ȥ���֥�å��ơ��֥� */
extern T_KERNEL_FLGCB kernel_flgcb_tbl[];		/* �ե饰����ȥ���֥�å��ơ��֥� */
extern const T_KERNEL_INTCB kernel_intcb_tbl[];		/* �����ߥϥ�ɥ饳��ȥ���֥�å��ơ��֥� */


/* ---------------------------------- */
/*            �ޥ������              */
/* ---------------------------------- */

/* ����������ȥ���֥�å��ơ��֥��0���ܤ����Ǥ˥����ƥ�����Ťͤ� */
#define kernel_sys		(*((T_KERNEL_SYS*)(&kernel_tcb_tbl[0])))		/* 0���ܤ�idle���Ťʤ� */

/* �����ƥ����� */
#define KERNEL_SET_RUN_TSKID(tskid)	(kernel_sys.tskid_run = tskid)		/* �¹��楿����ID������ */
#define KERNEL_GET_RUN_TSKID()		(kernel_sys.tskid_run)				/* �¹��楿����ID�μ��� */
#define KERNEL_GET_RDYQUE()			(&kernel_sys.rdyque)				/* ��ǥ����塼�μ��� */


#define KERNEL_GET_TCB(tskid)		(&kernel_tcb_tbl[tskid])			/* ������ID����TCB���ɥ쥹����� */
#define KERNEL_GET_SEMCB(semid)		(&kernel_semcb_tbl[(semid) - 1])	/* ���ޥե�ID����SEMCB���ɥ쥹����� */
#define KERNEL_GET_FLGCB(flgid)		(&kernel_flgcb_tbl[(flgid) - 1])	/* ���ޥե�ID����FLGCB���ɥ쥹����� */
#define KERNEL_GET_INTCB(intno)		(&kernel_intcb_tbl[(intno)])	/* �������ֹ椫��INTCB���ɥ쥹����� */

/* ------------------------------------------ */
/*                �ؿ����                    */
/* ------------------------------------------ */

#ifdef __cplusplus
extern "C" {
#endif

/* �ץ��å���ݲ��� */
void    hospac_dis_int(void);								/* �����߶ػ� */
void    hospac_ena_int(void);								/* �����ߵ��� */
void    hospac_cre_ctx(T_HOSPAC_CTXINF *pk_ctxinf,
						VP sp, FP task, VP_INT exinf);		/* �¹ԥ���ƥ����Ȥκ��� */
void    hospac_swi_ctx(T_HOSPAC_CTXINF *pk_pre_ctxinf,
						T_HOSPAC_CTXINF *pk_nxt_ctxinf);	/* �¹ԥ���ƥ����Ȥ����� */
#define hospac_idle()										/* �����ɥ������ */


/* ���塼��� */
void    kernel_add_que(T_KERNEL_QUE *que, ID tskid);		/* ��������ͥ���ٽ�ǥ��塼���ɲ� */
void    kernel_rmv_que(ID tskid);							/* �������򥭥塼��������� */
#define kernel_ref_qhd(que)	((que)->head)					/* ���塼����Ƭ�������λ���(�ޥ���ؿ�) */

void    kernel_exe_dsp(void);								/* �������ǥ����ѥå��μ¹� */

/* �����ƥ����� */
#define kernel_loc_sys()	hospac_dis_int()				/* �����ƥ�Υ�å� */
#define kernel_unl_sys()	hospac_ena_int()				/* �����ƥ�Υ�å� */


/* ����ե�����졼�� */
void    hoscfg_ini(void);


/* �����ͥ륷���ƥ���� */
ER      sta_hos(void);										/* �����ͥ�ư��� */


/* ������������ǽ */
ER      sta_tsk(ID tskid, VP_INT stacd);					/* �������ε�ư(��ư�����ɻ���) */
void    ext_tsk(void);										/* ���������ν�λ */
ER      chg_pri(ID tskid, ID tskpri);						/* ������ͥ���٤��ѹ� */
ER      get_pri(ID tskid, PRI *p_tskpri);					/* ������ͥ���٤λ��� */


/* ��������°Ʊ����ǽ */
ER      slp_tsk(void);										/* �������ε����Ԥ� */
ER      wup_tsk(ID tskid);									/* �������ε��� */
#define	iwup_tsk	wup_tsk									/* �������ε���(�󥿥�������ƥ������ѥޥ���) */
ER_UINT can_wup(ID tskid);									/* �����������׵�Υ���󥻥� */

/* ���ޥե� */
ER      sig_sem(ID semid);									/* ���ޥե��񸻤��ֵ� */
#define isig_sem sig_sem									/* ���ޥե��񸻤��ֵ�(�󥿥�������ƥ������ѥޥ���) */
ER      wai_sem(ID semid);									/* ���ޥե��񸻤γ��� */
ER      pol_sem(ID semid);									/* ���ޥե��񸻤γ���(�ݡ����) */

/* ���٥�ȥե饰 */
ER      set_flg(ID flgid, FLGPTN setptn);					/* ���٥�ȥե饰�Υ��å� */
#define iset_flg	set_flg									/* ���٥�ȥե饰�Υ��å�(�󥿥�������ƥ������ѥޥ���) */
ER      clr_flg(ID flgid, FLGPTN clrptn);					/* ���٥�ȥե饰�Υ��ꥢ */
ER      wai_flg(ID flgid, FLGPTN waiptn, MODE wfmode, FLGPTN *p_flgptn);
															/* ���٥�ȥե饰�Ԥ� */
ER      pol_flg(ID flgid, FLGPTN waiptn, MODE wfmode, FLGPTN *p_flgptn);
															/* ���٥�ȥե饰�Ԥ�(�ݡ����) */
BOOL    kernel_chk_flg(T_KERNEL_FLGCB *flgcb);


#ifdef __cplusplus
}
#endif



#endif /* __HOS_V4T__kernel_h__ */


/* ------------------------------------------------------------------------ */
/*  Copyright (C) 1998-2003 by Project HOS                                  */
/* ------------------------------------------------------------------------ */
