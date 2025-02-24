// ---------------------------------------------------------------------------
//  Hyper Operating System V4  コンフィギュレーター                           
//    API定義クラス                                                           
//                                                                            
//                                    Copyright (C) 1998-2002 by Project HOS  
//                                    http://sourceforge.jp/projects/hos/     
// ---------------------------------------------------------------------------


#include <stdio.h>
#include <stdlib.h>
#include "defercd.h"
#include "apidef.h"
#include "analyze.h"



// コンストラクタ
CApiDef::CApiDef()
{
	int i;

	m_iMaxId = 0;
	m_iObjs  = 0;
	for ( i = 0; i < API_MAX_OBJS; i++ )
	{
		m_pParamPacks[i] = NULL;
		m_iId[i]         = 0;
	}
}


// デストラクタ
CApiDef::~CApiDef()
{
	int i;

	for ( i = 0; i < API_MAX_OBJS; i++ )
	{
		delete m_pParamPacks[i];
	}
}


// パラメーター追加（超手抜き）
int CApiDef::AddParams(const char* pszParams)
{
	char szParamBlock[API_MAX_PARAM];
	char szParam[API_MAX_PARAM];
	int  iErr;
	int  iIndex = 0;
	int  i, j;

	// パラメータ格納用オブジェクト生成
	m_pParamPacks[m_iObjs] = new CParamPack();

	for ( i = 0; i < m_iParams; i++ )
	{
		if ( m_iParamSyntax[i] == 0 )
		{
			// 単独パラメーター切り出し
			iErr = CAnalyze::GetParameter(szParam, pszParams);
			if ( iErr != CFG_ERR_OK )
			{
				break;
			}

			// パラメーター追加
			CAnalyze::SpaceCut(szParam);
			m_pParamPacks[m_iObjs]->SetParam(iIndex++, szParam);
		}
		else
		{
			// 空白読み飛ばし
			while ( *pszParams == ' ' )
			{
				pszParams++;
			}

			// ブロック開始チェック
			if ( *pszParams++ != '{' )
			{
				iErr = CFG_ERR_SYNTAX;
				break;
			}
			
			// ブロック切り出し
			iErr = CAnalyze::SearchChar(szParamBlock, pszParams, '}');
			if ( iErr != CFG_ERR_OK )
			{
				break;
			}

			// ブロック内読み出し
			const char* pszParamBlock = szParamBlock;
			for ( j = 0; j < m_iParamSyntax[i] + 1; j++ )
			{
				// 単独パラメーター切り出し
				iErr = CAnalyze::GetParameter(szParam, pszParamBlock);
				if ( iErr != CFG_ERR_OK )
				{
					break;
				}

				// パラメーター追加
				CAnalyze::SpaceCut(szParam);
				if ( szParam[0] == '\0')
				{
					break;
				}
				m_pParamPacks[m_iObjs]->SetParam(iIndex++, szParam);
			}
			if ( iErr != CFG_ERR_OK )
			{
				iErr = CFG_ERR_SYNTAX;
				break;
			}
			if ( j != m_iParamSyntax[i] )
			{
				iErr = CFG_ERR_PARAM;
				break;
			}
		}
	}

	if ( iErr == CFG_ERR_OK )
	{
		m_iObjs++;
	}

	return iErr;
}


// 自動ID番号割り当て
int CApiDef::AutoId(void)
{
	bool blUsedId[255];
	int iId;
	int i;

	// 変数初期化
	for ( i = 0; i < 255; i++ )
	{
		blUsedId[i] = false;
	}

	// 固定値指定のIDをサーチ
	for ( i = 0; i < m_iObjs; i++ )
	{
		iId = atoi(m_pParamPacks[i]->GetParam(0));
		if ( iId > 0 )
		{
			if ( m_iId[i] != 0 )
			{
				return CFG_ERR_ID_CONFLICT;		// ID衝突
			}
			m_iId[i] = iId;
			blUsedId[iId - 1] = true;
			if ( iId > m_iMaxId )
			{
				m_iMaxId = iId;
			}
		}
	}

	// ID 自動割当
	iId = 1;
	for ( i = 0; i < m_iObjs; i++ )
	{
		if ( m_iId[i] == 0 )
		{
			// 使用済みIDのスキップ
			while ( blUsedId[iId - 1] )
			{
				iId++;
			}
			m_iId[i] = iId++;
		}
	}
	iId--;

	if ( m_iMaxId < 0 )
	{
		m_iMaxId = iId - m_iMaxId;
	}

	if ( iId > m_iMaxId )
	{
		m_iMaxId = iId;
	}

	return 0;
}


// ID 定義ファイル書き出し
void CApiDef::WriteId(FILE* fpId)
{
}


// cfgファイル定義部書き出し
void CApiDef::WriteCfgDef(FILE* fpCfg)
{
}

// cfgファイル初期化部書き出し
void CApiDef::WriteCfgIni(FILE* fpCfg)
{
}

// cfgファイル起動部書き出し
void CApiDef::WriteCfgStart(FILE* fpCfg)
{
}


// ---------------------------------------------------------------------------
//  Copyright (C) 1998-2002 by Project HOS                                    
// ---------------------------------------------------------------------------
