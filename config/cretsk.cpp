// ---------------------------------------------------------------------------
//  Hyper Operating System V4  コンフィギュレーター                           
//    CRE_TSK API の処理                                                      
//                                                                            
//                                    Copyright (C) 1998-2002 by Project HOS  
//                                    http://sourceforge.jp/projects/hos/     
// ---------------------------------------------------------------------------


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "defercd.h"
#include "cretsk.h"
#include "analyze.h"


#define CRETSK_TSKID		0
#define CRETSK_TSKATR		1
#define CRETSK_EXINF		2
#define CRETSK_TASK			3
#define CRETSK_ITSKPRI		4
#define CRETSK_STKSZ		5
#define CRETSK_STK			6



// コンストラクタ
CApiCreTsk::CApiCreTsk()
{
	// パラメーター構文設定
	m_iParamSyntax[0] = 0;		// 単独パラメーター
	m_iParamSyntax[1] = 6;		// 6パラメーターのブロック
	m_iParams = 2;
}

// デストラクタ
CApiCreTsk::~CApiCreTsk()
{
}



// APIの解析
int CApiCreTsk::AnalyzeApi(const char* pszApiName, const char* pszParams)
{
	if ( strcmp(pszApiName, "CRE_TSK") == 0 )
	{
		return AddParams(pszParams);
	}

	return CFG_ERR_NOPROC;
}


// ID 定義ファイル書き出し
void CApiCreTsk::WriteId(FILE* fp)
{
	int i;

	// ID 直接指定でないオブジェクトが在るかどうかサーチ
	for ( i = 0; i < m_iObjs; i++ )
	{
		if ( atoi(m_pParamPacks[i]->GetParam(CRETSK_TSKID)) == 0 )
		{
			break;
		}
	}
	if ( i == m_iObjs )
	{
		return;
	}

	fputs("\n\n/* task ID definetion */\n", fp);
	for ( i = 0; i < m_iObjs; i++ )
	{
		if ( atoi(m_pParamPacks[i]->GetParam(CRETSK_TSKID)) == 0 )
		{
			fprintf(
				fp,
				"#define %s\t\t%d\n",
				m_pParamPacks[i]->GetParam(CRETSK_TSKID),
				m_iId[i]);
		}
	}

	fprintf( fp,"\n#define TMAX_TSKID\t\t%d\n", m_iMaxId );
}


// cfgファイル定義部書き出し
void  CApiCreTsk::WriteCfgDef(FILE* fp)
{
	const char* pszParam;
	bool blOutput;
	int  i;

	// コメント出力
	fputs(
		"\n\n\n"
		"/* ------------------------------------------ */\n"
		"/*          create task objects               */\n"
		"/* ------------------------------------------ */\n"
		, fp);

	// スタック領域出力
	blOutput = false;
	for ( i = 0; i < m_iObjs; i++ )
	{
		pszParam = m_pParamPacks[i]->GetParam(CRETSK_STK);
		if ( strcmp(pszParam, "NULL") == 0 )
		{
			if ( !blOutput )
			{
				fputs("\n/* stack area */\n", fp);
				blOutput = true;
			}

			fprintf(
				fp,
				"static VP kernel_tsk%d_stk[((%s) + sizeof(VP) - 1) / sizeof(VP)];\n",
				m_iId[i],
				m_pParamPacks[i]->GetParam(CRETSK_STKSZ));
		}
	}

	if ( m_iObjs > 0 )
	{
		fprintf(
			fp,
			"\n/* task control block table */\n"
			"T_KERNEL_TCB kernel_tcb_tbl[%d] =\n"
			"{\n"
			"\t{{}, NULL,(PRI)0,(ID)0,(ID)0,(UB)0,NULL,NULL}, /* system */\n",
			m_iObjs+1);

		// タスクコントロールブロック出力
		for ( i = 0; i < m_iObjs; i++ )
		{
			fprintf(
				fp,
				"\t{{}, NULL,(PRI)(%s),(ID)0,(ID)0,(UB)0,(FP)(%s),",
				m_pParamPacks[i]->GetParam(CRETSK_ITSKPRI),
				m_pParamPacks[i]->GetParam(CRETSK_TASK)
				);

			pszParam = m_pParamPacks[i]->GetParam(CRETSK_STK);
			if ( strcmp(pszParam, "NULL") == 0 )
			{
				fprintf(
					fp,
					"(VP)kernel_tsk%d_stk+sizeof(kernel_tsk%d_stk)},\n",
					m_iId[i], m_iId[i]);
			}
			else
			{
				fprintf(
					fp,
					"(VP)(%s)},\n",
					m_pParamPacks[i]->GetParam(CRETSK_STK));
			}
		}
		fprintf(fp, "};\n");
	}

	// タスク情報出力
	fprintf(
		fp,
		"\n/* task control block count */\n"
		"const INT kernel_tcb_cnt = %d;\n",
		m_iMaxId);
}


// cfgファイル初期化部書き出し
void  CApiCreTsk::WriteCfgIni(FILE* fp)
{
	int	i;

	// オブジェクト存在チェック
	if ( m_iObjs == 0 )
	{
		return;
	}

	// 初期化部出力
	fputs( "\t\n\t\n\t/* start tasks assigned TA_ACT */\n",	fp);

	for ( i=0; i<m_iObjs; i++)
	{
		if ( strstr(m_pParamPacks[i]->GetParam(CRETSK_TSKATR), "TA_ACT") != NULL)
		{
			fprintf(
				fp,
				"\tsta_tsk(%s,%s);\n",
				m_pParamPacks[i]->GetParam(CRETSK_TSKID),
				m_pParamPacks[i]->GetParam(CRETSK_EXINF));
		}
	}

}


// cfgファイル起動部書き出し
void  CApiCreTsk::WriteCfgStart(FILE* fp)
{
}


// ---------------------------------------------------------------------------
//  Copyright (C) 1998-2002 by Project HOS                                    
// ---------------------------------------------------------------------------
