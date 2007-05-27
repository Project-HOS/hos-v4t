// ---------------------------------------------------------------------------
//  Hyper Operating System V4  コンフィギュレーター                           
//    ATT_ISR API の処理                                                      
//                                                                            
//                                    Copyright (C) 1998-2002 by Project HOS  
//                                    http://sourceforge.jp/projects/hos/     
// ---------------------------------------------------------------------------


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "defercd.h"
#include "attisr.h"
#include "analyze.h"


#define ATTISR_ISRATR		0
#define ATTISR_EXINF		1
#define ATTISR_INTNO		2
#define ATTISR_ISR		3


// コンストラクタ
CApiAttIsr::CApiAttIsr()
{
	// パラメーター構文設定
	m_iParamSyntax[0] = 4;		// 4つのパラメーターブロック
	m_iParams = 1;

	m_iMaxIntNo = 0;
	m_iMinIntNo = 0;
	m_iMaxIsrId = 0;
}

// デストラクタ
CApiAttIsr::~CApiAttIsr()
{
}


// 自動ID番号割り当て
int CApiAttIsr::AutoId(void)
{
	return CFG_ERR_OK;
}


// APIの解析
int CApiAttIsr::AnalyzeApi(const char* pszApiName, const char* pszParams)
{
	if ( strcmp(pszApiName, "ATT_ISR") == 0 )
	{
		return AddParams(pszParams);
	}

	return CFG_ERR_NOPROC;
}


// cfgファイル定義部書き出し
void  CApiAttIsr::WriteCfgDef(FILE* fp)
{
	int	i,j,max;

	// オブジェクト存在チェック
	if ( m_iObjs == 0 )
	{
		return;
	}

	// 割り込み番号の最大値を探す
	for ( i = max = 0; i < m_iObjs; i++ )
	{
		if (( j = atoi(m_pParamPacks[i]->GetParam(ATTISR_INTNO))) > max)
		{
			max = j;
		}
	} 

	// コメント出力
	fputs(
		"\n\n\n"
		"/* ------------------------------------------ */\n"
		"/*        interrupt control objects           */\n"
		"/* ------------------------------------------ */\n"
		, fp);

	// 割り込み管理テーブル生成
	fputs(
		"\n"
		"/* interrupt control block table */\n"
		"const T_KERNEL_INTCB kernel_intcb_tbl[] = {\n",
		fp);

	for ( i=0; i<=max; i++ )
	{
		for ( j=0; j<m_iObjs; j++ )
		{
			if ( i == atoi(m_pParamPacks[j]->GetParam(ATTISR_INTNO)))
			{
				fprintf( fp,
					 "\t{(FP)%s,(VP_INT)%s},\n",
				 	m_pParamPacks[j]->GetParam(ATTISR_ISR),
				 	m_pParamPacks[j]->GetParam(ATTISR_EXINF));
				break;
			}
		}

		if ( j == m_iObjs )
		{
			fputs( "\t{(FP)NULL,(VP_INT)~0},\n", fp);
		}
	}

	fputs(	"};\n", fp);
}


// cfgファイル初期化部書き出し
void  CApiAttIsr::WriteCfgIni(FILE* fp)
{
}



// ---------------------------------------------------------------------------
//  Copyright (C) 1998-2002 by Project HOS                                    
// ---------------------------------------------------------------------------
