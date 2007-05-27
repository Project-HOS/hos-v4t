// ---------------------------------------------------------------------------
//  Hyper Operating System V4  ����ե�����졼����                           
//    ATT_ISR API �ν���                                                      
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


// ���󥹥ȥ饯��
CApiAttIsr::CApiAttIsr()
{
	// �ѥ�᡼������ʸ����
	m_iParamSyntax[0] = 4;		// 4�ĤΥѥ�᡼�����֥�å�
	m_iParams = 1;

	m_iMaxIntNo = 0;
	m_iMinIntNo = 0;
	m_iMaxIsrId = 0;
}

// �ǥ��ȥ饯��
CApiAttIsr::~CApiAttIsr()
{
}


// ��ưID�ֹ�������
int CApiAttIsr::AutoId(void)
{
	return CFG_ERR_OK;
}


// API�β���
int CApiAttIsr::AnalyzeApi(const char* pszApiName, const char* pszParams)
{
	if ( strcmp(pszApiName, "ATT_ISR") == 0 )
	{
		return AddParams(pszParams);
	}

	return CFG_ERR_NOPROC;
}


// cfg�ե�����������񤭽Ф�
void  CApiAttIsr::WriteCfgDef(FILE* fp)
{
	int	i,j,max;

	// ���֥�������¸�ߥ����å�
	if ( m_iObjs == 0 )
	{
		return;
	}

	// �������ֹ�κ����ͤ�õ��
	for ( i = max = 0; i < m_iObjs; i++ )
	{
		if (( j = atoi(m_pParamPacks[i]->GetParam(ATTISR_INTNO))) > max)
		{
			max = j;
		}
	} 

	// �����Ƚ���
	fputs(
		"\n\n\n"
		"/* ------------------------------------------ */\n"
		"/*        interrupt control objects           */\n"
		"/* ------------------------------------------ */\n"
		, fp);

	// �����ߴ����ơ��֥�����
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


// cfg�ե������������񤭽Ф�
void  CApiAttIsr::WriteCfgIni(FILE* fp)
{
}



// ---------------------------------------------------------------------------
//  Copyright (C) 1998-2002 by Project HOS                                    
// ---------------------------------------------------------------------------
