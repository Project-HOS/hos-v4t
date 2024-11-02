// ---------------------------------------------------------------------------
//  Hyper Operating System V4  ����ե�����졼����                           
//    CRE_FLG API �ν���                                                      
//                                                                            
//                                    Copyright (C) 1998-2002 by Project HOS  
//                                    http://sourceforge.jp/projects/hos/     
// ---------------------------------------------------------------------------


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "defercd.h"
#include "creflg.h"
#include "analyze.h"



#define CREFLG_FLGID		0
#define CREFLG_FLGATR		1
#define CREFLG_IFLGPTN		2



// ���󥹥ȥ饯��
CApiCreFlg::CApiCreFlg()
{
	// �ѥ�᡼������ʸ����
	m_iParamSyntax[0] = 0;		// ñ�ȥѥ�᡼����
	m_iParamSyntax[1] = 2;		// 2�ѥ�᡼�����Υ֥�å�
	m_iParams = 2;
}

// �ǥ��ȥ饯��
CApiCreFlg::~CApiCreFlg()
{
}


// API�β���
int CApiCreFlg::AnalyzeApi(const char* pszApiName, const char* pszParams)
{
	if ( strcmp(pszApiName, "CRE_FLG") == 0 )
	{
		return AddParams(pszParams);
	}

	return CFG_ERR_NOPROC;
}


// ID ����ե�����񤭽Ф�
void CApiCreFlg::WriteId(FILE* fp)
{
	int i;

	// ID ľ�ܻ���Ǥʤ����֥������Ȥ��ߤ뤫�ɤ���������
	for ( i = 0; i < m_iObjs; i++ )
	{
		if ( atoi(m_pParamPacks[i]->GetParam(CREFLG_FLGID)) == 0 )
		{
			break;
		}
	}
	if ( i == m_iObjs )
	{
		return;
	}

	fputs("\n\n/* event flag ID definetion */\n", fp);
	for ( i = 0; i < m_iObjs; i++ )
	{
		if ( atoi(m_pParamPacks[i]->GetParam(CREFLG_FLGID)) == 0 )
		{
			fprintf(
				fp,
				"#define %s\t\t%d\n",
				m_pParamPacks[i]->GetParam(CREFLG_FLGID),
				m_iId[i]);
		}
	}

	fprintf( fp,"\n#define TMAX_FLGID\t\t%d\n", m_iMaxId );
}


// cfg�ե�����������񤭽Ф�
void  CApiCreFlg::WriteCfgDef(FILE* fp)
{
	// �����Ƚ���
	fputs(
		"\n\n\n"
		"/* ------------------------------------------ */\n"
		"/*        create event flag objects           */\n"
		"/* ------------------------------------------ */\n"
		, fp);

	if ( m_iObjs > 0 )
	{
		fprintf(
			fp,
			"\n/* event flag control block */\n"
			"T_KERNEL_FLGCB kernel_flgcb_tbl[%d];\n",
			m_iObjs);
	}

	// �ơ��֥륵�����������
	fprintf(
		fp,
		"\n/* event flag control block count */\n"
		"const INT kernel_flgcb_cnt = %d;\n",
		m_iMaxId);
}


// cfg�ե������������񤭽Ф�
void  CApiCreFlg::WriteCfgIni(FILE* fp)
{
}


// cfg�ե����뵯ư���񤭽Ф�
void  CApiCreFlg::WriteCfgStart(FILE* fp)
{
}


// ---------------------------------------------------------------------------
//  Copyright (C) 1998-2002 by Project HOS                                    
// ---------------------------------------------------------------------------
