// ---------------------------------------------------------------------------
//  Hyper Operating System V4  ����ե�����졼����                           
//    INCLUDE API �ν���                                                      
//                                                                            
//                                    Copyright (C) 1998-2002 by Project HOS  
//                                    http://sourceforge.jp/projects/hos/     
// ---------------------------------------------------------------------------


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "defercd.h"
#include "apiinc.h"
#include "analyze.h"



// ���󥹥ȥ饯��
CApiInclude::CApiInclude()
{
	// �ѥ�᡼������ʸ����
	m_iParamSyntax[0] = 0;		// ñ�ȥѥ�᡼����
	m_iParams         = 1;
}


// �ǥ��ȥ饯��
CApiInclude::~CApiInclude()
{
}



// API�β���
int CApiInclude::AnalyzeApi(const char* pszApiName, const char* pszParams)
{
	char szBuf[4096];
	int  iErr;
	
	// API̾�����å�
	if ( strcmp(pszApiName, "INCLUDE") != 0 )
	{
		return CFG_ERR_NOPROC;
	}

	// �ѥ�᡼�����ɲ�
	iErr = AddParams(pszParams);
	if ( iErr != CFG_ERR_OK )
	{
		return iErr;
	}

	// ʸ�����Ÿ��
	iErr = CAnalyze::DecodeText(szBuf, m_pParamPacks[m_iObjs - 1]->GetParam(0));
	if ( iErr != CFG_ERR_OK )
	{
		return iErr;
	}
	m_pParamPacks[m_iObjs - 1]->SetParam(0, szBuf);

	return CFG_ERR_OK;
}


// ʸ�����Ÿ��
int CApiInclude::AutoId(void)
{
	return CFG_ERR_OK;
}


// cfg�ե�����������񤭽Ф�
void  CApiInclude::WriteCfgDef(FILE* fp)
{
	int i;

	if ( m_iObjs == 0)
	{
		return;
	}

	fputs("\n", fp);

	for ( i = 0; i < m_iObjs; i++ )
	{
		fprintf(fp, "#include %s\n", m_pParamPacks[i]->GetParam(0));
	}
}


// ---------------------------------------------------------------------------
//  Copyright (C) 1998-2002 by Project HOS                                    
// ---------------------------------------------------------------------------
