/* ------------------------------------------------------------------------ */
/*  Hyper Operating System V4 Tiny  μITRON4.0仕様 Real-Time OS             */
/*    カーネル依存情報定義ヘッダ                                            */
/*                                                                          */
/*                                  Copyright (C) 1998-2003 by Project HOS  */
/*                                  http://sourceforge.jp/projects/hos/     */
/* ------------------------------------------------------------------------ */


#ifndef __HOS_V4T__kernel_h__
#define __HOS_V4T__kernel_h__


#include "itron.h"



/* ------------------------------------------ */
/*                  定数定義                  */
/* ------------------------------------------ */

/* システムの状態 */
#define KERNEL_TSS_TSK		0x00				/* タスク部実行中 */
#define KERNEL_TSS_INDP		0x04				/* タスク独立部実行中 */
#define KERNEL_TSS_DDSP		0x01				/* ディスパッチ禁止 (dis_dsp 有効) */
#define KERNEL_TSS_DINT		0x02				/* 割り込み禁止(loc_cpu 有効) */


/* キューイング／ネスト回数の最大値 */
#define TMAX_ACTCNT			0					/* タスク起動要求キューイング数の最大値 */
#define TMAX_WUPCNT			127					/* タスク起床要求キューイング数の最大値 */
#define TMAX_SUSCNT			0					/* タスク強制待ち要求ネスト数の最大値 */



/* ------------------------------------------ */
/*                 型定義                     */
/* ------------------------------------------ */


/* コンテキスト情報保存ブロック */
typedef struct t_hos_pac_ctxinf
{
	VP sp;			/* スタックポインタ保存領域 */
} T_HOSPAC_CTXINF;


/* キュー管理ブロック */
typedef struct t_kernel_que
{
	ID    head;					/* キュー先頭のタスクID */
} T_KERNEL_QUE;


/* タスクコントロールブロック */
typedef struct t_kernel_tcb
{
	T_HOSPAC_CTXINF ctxinf;		/* コンテキスト情報保存ブロック */
	T_KERNEL_QUE    *que;		/* 接続されているキュー */
	PRI   tskpri;				/* 現在の優先度 */
	ID    next;					/* 次のタスク */
	ID    prev;					/* 前のタスク */
	UB    wupcnt;				/* 起床要求キューイング数 */
	FP    task;					/* タスクの起動番地 */
	VP    isp;					/* 初期スタックポインタ */
} T_KERNEL_TCB;


/* セマフォコントロールブロック */
typedef struct t_kernel_semcb
{
	T_KERNEL_QUE que;			/* セマフォ待ちタスクキュー */
	UB           semcnt;		/* セマフォの資源数 */
} T_KERNEL_SEMCB;


/* イベントフラグコントロールブロック */
typedef struct t_kernel_flgcb
{
	ID     tskid;		/* フラグ待ちのタスクID */
	FLGPTN flgptn;		/* イベントフラグのビットパターン */
	MODE   wfmode;		/* 待ちモード */
	FLGPTN waiptn;		/* 待ちビットパターン（解除時パターンと兼用) */
	FLGPTN *p_flgptn;	/* フラグパターン格納アドレス */
} T_KERNEL_FLGCB;


/* 割り込みハンドラ */
typedef struct t_kernel_intcb
{
	FP    	isr;		/* ハンドラの起動番地 */
	VP_INT	exinf;
} T_KERNEL_INTCB;


/* システム管理 */
typedef struct t_kernel_sys
{
    T_HOSPAC_CTXINF ctxinf_idle;	/* アイドルコンテキスト */
	T_KERNEL_QUE    rdyque;			/* レディーキュー */
	UB              tskid_run;		/* 実行中タスクのID */
	UB              stat;			/* システムのコンテキスト状態 */
	UB              dly_dsp;		/* 遅延しているディスパッチがあるか */
} T_KERNEL_SYS;



/* ---------------------------------- */
/*        グローバル変数宣言          */
/* ---------------------------------- */


extern FP             kernel_irq_tbl[];			/* 割り込みハンドラテーブル */
extern T_KERNEL_TCB   kernel_tcb_tbl[];			/* タスクコントロールブロックテーブル */
extern T_KERNEL_SEMCB kernel_semcb_tbl[];		/* セマフォコントロールブロックテーブル */
extern T_KERNEL_FLGCB kernel_flgcb_tbl[];		/* フラグコントロールブロックテーブル */
extern const T_KERNEL_INTCB kernel_intcb_tbl[];		/* 割り込みハンドラコントロールブロックテーブル */


/* ---------------------------------- */
/*            マクロ定義              */
/* ---------------------------------- */

/* タスクコントロールブロックテーブルの0番目の要素にシステム情報を重ねる */
#define kernel_sys		(*((T_KERNEL_SYS*)(&kernel_tcb_tbl[0])))		/* 0番目にidleが重なる */

/* システム制御 */
#define KERNEL_SET_RUN_TSKID(tskid)	(kernel_sys.tskid_run = tskid)		/* 実行中タスクIDの設定 */
#define KERNEL_GET_RUN_TSKID()		(kernel_sys.tskid_run)				/* 実行中タスクIDの取得 */
#define KERNEL_GET_RDYQUE()			(&kernel_sys.rdyque)				/* レディキューの取得 */


#define KERNEL_GET_TCB(tskid)		(&kernel_tcb_tbl[tskid])			/* タスクIDからTCBアドレスを取得 */
#define KERNEL_GET_SEMCB(semid)		(&kernel_semcb_tbl[(semid) - 1])	/* セマフォIDからSEMCBアドレスを取得 */
#define KERNEL_GET_FLGCB(flgid)		(&kernel_flgcb_tbl[(flgid) - 1])	/* セマフォIDからFLGCBアドレスを取得 */
#define KERNEL_GET_INTCB(intno)		(&kernel_intcb_tbl[(intno)])	/* 割り込み番号からINTCBアドレスを取得 */

/* ------------------------------------------ */
/*                関数宣言                    */
/* ------------------------------------------ */

#ifdef __cplusplus
extern "C" {
#endif

/* プロセッサ抽象化層 */
void    hospac_dis_int(void);								/* 割り込み禁止 */
void    hospac_ena_int(void);								/* 割り込み許可 */
void    hospac_cre_ctx(T_HOSPAC_CTXINF *pk_ctxinf,
						VP sp, FP task, VP_INT exinf);		/* 実行コンテキストの作成 */
void    hospac_swi_ctx(T_HOSPAC_CTXINF *pk_pre_ctxinf,
						T_HOSPAC_CTXINF *pk_nxt_ctxinf);	/* 実行コンテキストの切替 */
#define hospac_idle()										/* アイドル時処理 */


/* キュー操作 */
void    kernel_add_que(T_KERNEL_QUE *que, ID tskid);		/* タスクを優先度順でキューに追加 */
void    kernel_rmv_que(ID tskid);							/* タスクをキューから取り除く */
#define kernel_ref_qhd(que)	((que)->head)					/* キューの先頭タスクの参照(マクロ関数) */

void    kernel_exe_dsp(void);								/* タスクディスパッチの実行 */

/* システム制御 */
#define kernel_loc_sys()	hospac_dis_int()				/* システムのロック */
#define kernel_unl_sys()	hospac_ena_int()				/* システムのロック */


/* コンフィギュレータ */
void    hoscfg_ini(void);


/* カーネルシステム管理 */
ER      sta_hos(void);										/* カーネル動作開始 */


/* タスク管理機能 */
ER      sta_tsk(ID tskid, VP_INT stacd);					/* タスクの起動(起動コード指定) */
void    ext_tsk(void);										/* 自タスクの終了 */
ER      chg_pri(ID tskid, ID tskpri);						/* タスク優先度の変更 */
ER      get_pri(ID tskid, PRI *p_tskpri);					/* タスク優先度の参照 */


/* タスク付属同期機能 */
ER      slp_tsk(void);										/* タスクの起床待ち */
ER      wup_tsk(ID tskid);									/* タスクの起床 */
#define	iwup_tsk	wup_tsk									/* タスクの起床(非タスクコンテキスト用マクロ) */
ER_UINT can_wup(ID tskid);									/* タスク起床要求のキャンセル */

/* セマフォ */
ER      sig_sem(ID semid);									/* セマフォ資源の返却 */
#define isig_sem sig_sem									/* セマフォ資源の返却(非タスクコンテキスト用マクロ) */
ER      wai_sem(ID semid);									/* セマフォ資源の獲得 */
ER      pol_sem(ID semid);									/* セマフォ資源の獲得(ポーリング) */

/* イベントフラグ */
ER      set_flg(ID flgid, FLGPTN setptn);					/* イベントフラグのセット */
#define iset_flg	set_flg									/* イベントフラグのセット(非タスクコンテキスト用マクロ) */
ER      clr_flg(ID flgid, FLGPTN clrptn);					/* イベントフラグのクリア */
ER      wai_flg(ID flgid, FLGPTN waiptn, MODE wfmode, FLGPTN *p_flgptn);
															/* イベントフラグ待ち */
ER      pol_flg(ID flgid, FLGPTN waiptn, MODE wfmode, FLGPTN *p_flgptn);
															/* イベントフラグ待ち(ポーリング) */
BOOL    kernel_chk_flg(T_KERNEL_FLGCB *flgcb);


#ifdef __cplusplus
}
#endif



#endif /* __HOS_V4T__kernel_h__ */


/* ------------------------------------------------------------------------ */
/*  Copyright (C) 1998-2003 by Project HOS                                  */
/* ------------------------------------------------------------------------ */
