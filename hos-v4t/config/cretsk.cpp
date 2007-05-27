// ---------------------------------------------------------------------------
//  Hyper Operating System V4  ����ե�����졼����                           
//    CRE_TSK API �ν���                                                      
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



// ���󥹥ȥ饯��
CApiCreTsk::CApiCreTsk()
{
	// �ѥ�᡼������ʸ����
	m_iParamSyntax[0] = 0;		// ñ�ȥѥ�᡼����
	m_iParamSyntax[1] = 6;		// 6�ѥ�᡼�����Υ֥�å�
	m_iParams = 2;
}

// �ǥ��ȥ饯��
CApiCreTsk::~CApiCreTsk()
{
}



// API�β���
int CApiCreTsk::AnalyzeApi(const char* pszApiName, const char* pszParams)
{
	if ( strcmp(pszApiName, "CRE_TSK") == 0 )
	{
		return AddParams(pszParams);
	}

	return CFG_ERR_NOPROC;
}


// ID ����ե�����񤭽Ф�
void CApiCreTsk::WriteId(FILE* fp)
{
	int i;

	// ID ľ�ܻ���Ǥʤ����֥������Ȥ��ߤ뤫�ɤ���������
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


// cfg�ե�����������񤭽Ф�
void  CApiCreTsk::WriteCfgDef(FILE* fp)
{
	const char* pszParam;
	bool blOutput;
	int  i;

	// �����Ƚ���
	fputs(
		"\n\n\n"
		"/* ------------------------------------------ */\n"
		"/*          create task objects               */\n"
		"/* ------------------------------------------ */\n"
		, fp);

	// �����å��ΰ����
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

		// ����������ȥ���֥�å�����
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

	// �������������
	fprintf(
		fp,
		"\n/* task control block count */\n"
		"const INT kernel_tcb_cnt = %d;\n",
		m_iMaxId);
}


// cfg�ե������������񤭽Ф�
void  CApiCreTsk::WriteCfgIni(FILE* fp)
{
	int	i;

	// ���֥�������¸�ߥ����å�
	if ( m_iObjs == 0 )
	{
		return;
	}

	// �����������
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


// cfg�ե����뵯ư���񤭽Ф�
void  CApiCreTsk::WriteCfgStart(FILE* fp)
{
}


// ---------------------------------------------------------------------------
//  Copyright (C) 1998-2002 by Project HOS                                    
// ---------------------------------------------------------------------------
