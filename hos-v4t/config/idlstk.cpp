// ---------------------------------------------------------------------------
//  Hyper Operating System V4  ����ե�����졼����                           
//    HOS_IDL_STK API �ν���                                                  
//                                                                            
//                                    Copyright (C) 1998-2002 by Project HOS  
//                                    http://sourceforge.jp/projects/hos/     
// ---------------------------------------------------------------------------


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "defercd.h"
#include "idlstk.h"
#include "analyze.h"


#define IDLSTK_STKSZ		0
#define IDLSTK_STK			1


// ���󥹥ȥ饯��
CApiIdleStack::CApiIdleStack()
{
	// �ѥ�᡼������ʸ����
	m_iParamSyntax[0] = 0;		// ñ�ȥѥ�᡼����
	m_iParams = 2;
}


// �ǥ��ȥ饯��
CApiIdleStack::~CApiIdleStack()
{
}


// ��ưID�ֹ�������
int CApiIdleStack::AutoId(void)
{
	return CFG_ERR_OK;
}


// API�β���
int CApiIdleStack::AnalyzeApi(const char* pszApiName, const char* pszParams)
{
	static bool blEx = false;

	if ( strcmp(pszApiName, "HOS_IDL_STK") == 0 )
	{
		if ( blEx == true )
		{
			return CFG_ERR_MULTIDEF;
		}

		blEx = true;

		return AddParams(pszParams);
	}

	return CFG_ERR_NOPROC;
}


// cfg�ե�����������񤭽Ф�
void  CApiIdleStack::WriteCfgDef(FILE* fp)
{
	const char* pszSize;
	const char* pszStack;

	// �����Ƚ���
	fputs(
		"\n\n\n"
		"#if 0\n"
		"/* ------------------------------------------ */\n"
		"/*                 idle stack                 */\n"
		"/* ------------------------------------------ */\n\n"
		, fp);

	// �ѥ�᡼���ɤ߽Ф�
	if ( m_iObjs > 0 )
	{
		pszSize  = m_pParamPacks[0]->GetParam(IDLSTK_STKSZ);
		pszStack = m_pParamPacks[0]->GetParam(IDLSTK_STK);
	}
	else
	{
		pszSize  = "128";		// ���̵꤬����Хǥե���ȥ�����
		pszStack = "NULL";		// ���̵꤬�����NULL(��ư����)
	}

	// �����ɥ�롼���ѥ����å�����
	if ( strcmp(pszStack, "NULL") == 0 )
	{
		fprintf(
			fp,
			"VP         mknl_idl_stkblk[((%s) + sizeof(VP) - 1) / sizeof(VP)];\t/* idle stack block*/\n"
			"const VP   mknl_idl_stk   = (VP)(mknl_idl_stkblk);\t/* idle stack */\n"
			"const SIZE mknl_idl_stksz = (SIZE)sizeof(mknl_idl_stkblk);\t/* idle stack size */\n",
			pszSize);
	}
	else
	{
		fprintf(
			fp,
			"const VP   mknl_idl_stk   = (VP)(%s);\t/* idle stack */\n"
			"const SIZE mknl_idl_stksz = (SIZE)(%s);\t/* idle stack */\n",
			pszSize, pszStack);
	}

	fputs( "#endif\n", fp);
}


// ---------------------------------------------------------------------------
//  Copyright (C) 1998-2002 by Project HOS                                    
// ---------------------------------------------------------------------------
