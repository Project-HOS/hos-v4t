// ---------------------------------------------------------------------------
//  Hyper Operating System V4  ����ե�����졼����                           
//    HOS_INT_STK API �ν���                                                  
//                                                                            
//                                    Copyright (C) 1998-2002 by Project HOS  
//                                    http://sourceforge.jp/projects/hos/     
// ---------------------------------------------------------------------------


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "defercd.h"
#include "intstk.h"
#include "analyze.h"


#define INTSTK_STKSZ		0
#define INTSTK_STK			1


// ���󥹥ȥ饯��
CApiIntStack::CApiIntStack()
{
	// �ѥ�᡼������ʸ����
	m_iParamSyntax[0] = 0;		// ñ�ȥѥ�᡼����
	m_iParams = 2;

	// �����å��ݥ���
	m_szStackPointer[0] = '\0';
}


// �ǥ��ȥ饯��
CApiIntStack::~CApiIntStack()
{
}


// ��ưID�ֹ�������
int CApiIntStack::AutoId(void)
{
	return CFG_ERR_OK;
}


// API�β���
int CApiIntStack::AnalyzeApi(const char* pszApiName, const char* pszParams)
{
	static bool blEx = false;
 
	if ( strcmp(pszApiName, "HOS_INT_STK") == 0 )
	{
		if ( blEx == true )
		{
			return CFG_ERR_MULTIDEF;
		}
		blEx = true;
		return AddParams(pszParams);
	}
	else if ( strcmp(pszApiName, "HOS_INT_SP") == 0 )
	{
		if ( blEx == true )
		{
			return CFG_ERR_MULTIDEF;
		}
		blEx = true;
		strcpy(m_szStackPointer, pszParams);
		return CFG_ERR_OK;
	}

	return CFG_ERR_NOPROC;
}


// cfg�ե�����������񤭽Ф�
void  CApiIntStack::WriteCfgDef(FILE* fp)
{
	const char* pszSize;
	const char* pszStack;

	// �ѥ�᡼���ɤ߽Ф�
	if ( m_iObjs <= 0 && m_szStackPointer[0] == '\0' )
	{
		return ;
	}

	// �����Ƚ���
	fputs(
		"\n\n\n"
		"/* ------------------------------------------ */\n"
		"/*             interrupt stack                */\n"
		"/* ------------------------------------------ */\n\n"
		, fp);

	// �������ѥ����å��ݥ��󥿽���
	if ( m_szStackPointer[0] != '\0' )
	{
		fprintf(
			fp,
			"const VP kernel_int_sp = (VP)(%s);\t/* interrupt stack pointer */\n",
			m_szStackPointer);
	}
	else
	{
		pszSize  = m_pParamPacks[0]->GetParam(INTSTK_STKSZ);
		pszStack = m_pParamPacks[0]->GetParam(INTSTK_STK);

		if ( strcmp(pszStack, "NULL") == 0 )
		{
			fprintf(
				fp,
				"VP         kernel_int_stkblk[((%s) + sizeof(VP) - 1) / sizeof(VP)];\t/* interrupt stack block*/\n"
				"const VP   kernel_int_sp  = &kernel_int_stkblk[sizeof(kernel_int_stkblk) / sizeof(VP)];\t/* interrupt stack pointer */\n",
				pszSize);
		}
		else
		{
			fprintf(
				fp,
				"const VP kernel_int_sp = (VP)((UB *)(%s) + (%s));\t/* interrupt stack pointer */\n",
				pszStack, pszSize);
		}
	}
}


// ---------------------------------------------------------------------------
//  Copyright (C) 1998-2002 by Project HOS                                    
// ---------------------------------------------------------------------------
