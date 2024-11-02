// ---------------------------------------------------------------------------
//  Hyper Operating System V4  コンフィギュレーター                           
//    CRE_SEM API の処理                                                      
//                                                                            
//                                    Copyright (C) 1998-2002 by Project HOS  
//                                    http://sourceforge.jp/projects/hos/     
// ---------------------------------------------------------------------------


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "defercd.h"
#include "cresem.h"
#include "analyze.h"


#define CRESEM_SEMID		0
#define CRESEM_SEMATR		1
#define CRESEM_SEMCNT		2
#define CRESEM_MAXSEM		3



// コンストラクタ
CApiCreSem::CApiCreSem()
{
	// パラメーター構文設定
	m_iParamSyntax[0] = 0;		// 単独パラメーター
	m_iParamSyntax[1] = 3;		// 3パラメーターのブロック
	m_iParams = 2;
}

// デストラクタ
CApiCreSem::~CApiCreSem()
{
}


// APIの解析
int CApiCreSem::AnalyzeApi(const char* pszApiName, const char* pszParams)
{
	static bool blExMid = false;

	if ( strcmp(pszApiName, "CRE_SEM") == 0 )
	{
		return AddParams(pszParams);
	}
	else if ( strcmp(pszApiName, "HOS_MAX_SEMID") == 0 )
	{
		int iId;

		if ( blExMid == true )
		{
			return CFG_ERR_MULTIDEF;
		}

		blExMid = true;

		if ( (iId = atoi(pszParams)) <= 0 )
		{
			return CFG_ERR_PARAM;
		}
		if ( pszParams[0] == '+' )
		{
			m_iMaxId = -iId;
		} else {
			m_iMaxId = iId;
		}
		return CFG_ERR_OK;
	}

	return CFG_ERR_NOPROC;
}


// ID 定義ファイル書き出し
void CApiCreSem::WriteId(FILE* fp)
{
	int i;

	// ID 直接指定でないオブジェクトが在るかどうかサーチ
	for ( i = 0; i < m_iObjs; i++ )
	{
		if ( atoi(m_pParamPacks[i]->GetParam(CRESEM_SEMID)) == 0 )
		{
			break;
		}
	}
	if ( i == m_iObjs )
	{
		return;
	}

	fputs("\n\n/* semaphore ID definetion */\n", fp);
	for ( i = 0; i < m_iObjs; i++ )
	{
		if ( atoi(m_pParamPacks[i]->GetParam(CRESEM_SEMID)) == 0 )
		{
			fprintf(
				fp,
				"#define %s\t\t%d\n",
				m_pParamPacks[i]->GetParam(CRESEM_SEMID),
				m_iId[i]);
		}
	}

	fprintf( fp,"\n#define TMAX_SEMID\t\t%d\n", m_iMaxId );
}


// cfgファイル定義部書き出し
void  CApiCreSem::WriteCfgDef(FILE* fp)
{
	int  i, j;

	// コメント出力
	fputs(
		"\n\n\n"
		"/* ------------------------------------------ */\n"
		"/*         create semaphore objects           */\n"
		"/* ------------------------------------------ */\n"
		, fp);

	if ( m_iObjs > 0 )
	{
		fputs(
			"\n/* semaphore control block */\n"
			"T_KERNEL_SEMCB kernel_semcb_tbl[] =\n"
			"\t{\n",
			fp);

		// コントロールブロック出力
		for ( i = 0; i < m_iObjs; i++ )
		{
			fprintf(
				fp,
				"\t\t{{(ID)0}, (UB)(%s)},\n",
				m_pParamPacks[i]->GetParam(CRESEM_SEMCNT));
		}
		fprintf(fp, "\t};\n");
	}

	// テーブルサイズ情報出力
	fprintf(
		fp,
		"\n/* semaphore control block count */\n"
		"const INT kernel_semcb_cnt = %d;\n",
		m_iMaxId);
}


// cfgファイル初期化部書き出し
void  CApiCreSem::WriteCfgIni(FILE* fp)
{
}


// cfgファイル起動部書き出し
void  CApiCreSem::WriteCfgStart(FILE* fp)
{
}


// ---------------------------------------------------------------------------
//  Copyright (C) 1998-2002 by Project HOS                                    
// ---------------------------------------------------------------------------
