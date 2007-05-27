// ---------------------------------------------------------------------------
//  Hyper Operating System V4  ����ե�����졼����                           
//    �ǡ����ɤ߹��ߥ��饹                                                    
//                                                                            
//                                    Copyright (C) 1998-2002 by Project HOS  
//                                    http://sourceforge.jp/projects/hos/     
// ---------------------------------------------------------------------------


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "defercd.h"
#include "read.h"


// ���󥹥ȥ饯��
CRead::CRead(FILE *fp, const char *name)
{
	m_fpRead    = fp;
	m_iPhysicalLineNum = m_iLogicalLineNum = 1;
	m_blLineTop = true;
	strncpy(m_szLogicalInputFile, name, READ_MAX_PATH - 1);
	m_szLogicalInputFile[READ_MAX_PATH - 1] = '\0';
}


// �ǥ��ȥ饯��
CRead::~CRead()
{
}


// �����ơ����ɤ߹���
int CRead::ReadState(char *szState)
{
	bool blEsc   = false;
	bool blSpace = true;	// true �ǻϤ����Ƭ�ζ�����ɤ����Ф�
	int  iCount = 0;
	int  iErr;
	int  c;

	for ( ; ; )
	{
		// ��ʸ���ɤ߹���
		if ( (c = fgetc(m_fpRead)) == EOF )
		{
			if ( blEsc || iCount != 0 )
			{
				iErr = CFG_ERR_EOF;	// ͽ������EOF
			}
			else
			{
				iErr = CFG_ERR_COMPLETE;	// ��λ
			}
			break;
		}

		// �����������å�
		if ( iCount >= READ_MAX_STATE - 1 )
		{
			iErr = CFG_ERR_STATE_LEN;
			break;
		}

		// ��Ƭ�� # �ʤ饹���å�
		if ( m_blLineTop && c == '#' )
		{
                       iErr = SkipPreProcessorLine(szState, iCount);
			if ( iErr != CFG_ERR_OK )
			{
				break;
			}
			continue;
		}

		// ����ʸ���ν���
		if ( c == '\n' )
		{
			m_iPhysicalLineNum++;
			m_iLogicalLineNum++;
			m_blLineTop = true;
		}
		else
		{
			m_blLineTop = false;
		}

		// ����ʸ���Υ����å�
		if ( isspace(c) || c == '\n' )
		{
			if ( !blSpace )
			{
				szState[iCount++] = ' ';
				blSpace = true;
			}
			continue;
		}
		blSpace = false;

		// ʸ����ν���
		if ( c == '\"' || c == '\'' )
		{
			szState[iCount++] = c;
			iErr = ReadString(c, szState, iCount);
			if ( iErr != CFG_ERR_OK )
			{
				break;
			}
			continue;
		}

		// ���ơ��ȴ�λʸ���ʤ�
		if ( c == ';' )
		{
			iErr = CFG_ERR_OK;
			break;
		}

		// ʸ�����ɤ߹���
		szState[iCount++] = c;
	}

	// �����ζ���ʸ�����
	if ( iCount > 0 && szState[iCount - 1] == ' ' )
	{
		iCount--;
	}

	szState[iCount] = '\0';

	return iErr;
}


// �ץ�ץ��å��饤��Υ����å�
int CRead::SkipPreProcessorLine(char* szText, int iCountOrg)
{
	int  c;
	int iCount = iCountOrg;
	long tmpLineNum;
	char *p1, *p2;

	for ( ; ; )
	{
		// ��ʸ���ɤ߹���
		if ( (c = fgetc(m_fpRead)) == EOF )
		{
			return CFG_ERR_OK;
		}

		// �����������å�
		if ( iCount >= READ_MAX_STATE - 1 )
		{
			return CFG_ERR_STATE_LEN;
		}

		// �����Υ����å�
		if ( c == '\n' )
		{
			m_iPhysicalLineNum++;
			m_iLogicalLineNum++;

			szText[iCount] = '\0';

			// #line 123 "filename"
			// # 123 "filename"
			// �η����Τɤ���Ǥ�����դ���
			if (strncmp(&szText[iCountOrg], "line", 4) == 0)
				iCountOrg += 4;

			// #line123
			// #12
			// �ʤɤ��ӽ�
			if (!isspace(szText[iCountOrg]))
				return CFG_ERR_OK;

			// ���ֹ��ɤ߹���
			tmpLineNum = strtol(&szText[iCountOrg], &p1, 10);
			if (p1 == &szText[iCountOrg])
				return CFG_ERR_OK;

			// # 123a
			// �ʤɹ��ֹ�θ���;ʬ�ʤ�Τ��Ĥ��Ƥ�������ӽ�
			if (!isspace(*p1) && *p1 != '\0')
				return CFG_ERR_OK;

			// �ɤ߹�������ֹ��ȿ��
			m_iLogicalLineNum = tmpLineNum;

			// �ե�����̾��õ��
			while (isspace(*p1))
				p1++;
			if (*p1 != '\"')
				return CFG_ERR_OK;
			p1++;
			p2 = strchr(p1, '\"');
			if (p2 == NULL)
				return CFG_ERR_OK;
			*p2 = '\0';

			// �ե�����̾��ȿ��
			strncpy(m_szLogicalInputFile, p1, READ_MAX_PATH - 1);
			m_szLogicalInputFile[READ_MAX_PATH - 1] = '\0';

			return CFG_ERR_OK;
		}

		// ʸ�����ɤ߹���
		szText[iCount++] = c;
	}
}


// ʸ�����ɤ߹���
int CRead::ReadString(int cDelimiter, char* szText, int& iCount)
{
	bool blEsc  = false;
	int c;

	for ( ; ; )
	{
		// ��ʸ���ɤ߹���
		if ( (c = fgetc(m_fpRead)) == EOF )
		{
			return CFG_ERR_EOF;	// ͽ������EOF
		}

		// �����������å�
		if ( iCount >= READ_MAX_STATE - 1 )
		{
			return CFG_ERR_STATE_LEN;
		}

		// ���ԥ����å�
		if ( c == '\n' )
		{
			return CFG_ERR_CR;		// �����ʲ���
		}

		// ʸ��������
		szText[iCount++] = c;

		// \ �μ���̵���˥����å�
		if ( blEsc )
		{
			blEsc  = false;
			continue;
		}

		// \ �Υ����å�
		if ( c == '\\' )
		{
			blEsc  = true;
			continue;
		}

		blEsc  = false;

		// �ǥ�ߥ�ʸ���ʤ鴰λ
		if ( c == cDelimiter )
		{
			return CFG_ERR_OK;
		}
	}
}


// ---------------------------------------------------------------------------
//  Copyright (C) 1998-2002 by Project HOS                                    
// ---------------------------------------------------------------------------
