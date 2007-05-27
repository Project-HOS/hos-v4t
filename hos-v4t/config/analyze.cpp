// ---------------------------------------------------------------------------
//  Hyper Operating System V4  ����ե�����졼����                           
//    ��ʸ���ϥ��饹                                                          
//                                                                            
//                                    Copyright (C) 1998-2002 by Project HOS  
//                                    http://sourceforge.jp/projects/hos/     
// ---------------------------------------------------------------------------


#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "defercd.h"
#include "analyze.h"



// ���ơ��ȥ��Ȥ�API̾�ȥѥ�᡼������ʬ��
int CAnalyze::SplitState(char* pszApiName, char* pszParams, const char *pszState)
{
	int iErr;

	// ���ޥ��̾���ڤ�Ф�
	while ( *pszState != '(' )
	{
		if ( *pszState == '\0' )
		{
			return CFG_ERR_SYNTAX;
		}
		*pszApiName++ = *pszState++;
	}
	*pszApiName = '\0';
	pszState++;

	// �ѥ�᡼���������ڤ�Ф�
	iErr = SearchChar(pszParams, pszState, ')');
	if ( iErr != CFG_ERR_OK )
	{
		return iErr;
	}

	// ��³�����å�
	if ( *pszState != '\0' )
	{
		return CFG_ERR_SEMICOLON;
	}

	return CFG_ERR_OK;
}


// ����ʸ���ΤޤǤ��ڤ�Ф�
int CAnalyze::SearchChar(char* pszBuf, const char* &pszText, char c)
{
	char cDelimiter;
	bool blText = false;
	bool blEsc  = false;
	int  iErr;

	for ( ; ; )
	{
		// ��ü�����å�
		if ( *pszText == '\0' )
		{
			iErr = CFG_ERR_SYNTAX;
			break;
		}

		// ʸ�������å�
		if ( *pszText == c )
		{
			pszText++;
			iErr = CFG_ERR_OK;
			break;
		}

		// '\' �μ���ʸ����̵���˥���������
		if ( blEsc )
		{
			*pszBuf++ = *pszText++;
			blEsc = false;
			continue;
		}
		blEsc = false;

		// '\' �����å�
		if ( *pszBuf == '\\' )
		{
			*pszBuf++ = *pszText++;
			blEsc = true;
			continue;
		}

		// ʸ���󳫻ϥ����å�
		if ( !blText && *pszText == '\"' || *pszText == '\'' )
		{
			cDelimiter = *pszText;
			*pszBuf++ = *pszText++;
			blText = true;
			continue;
		}

		// ʸ��������
		if ( blText )
		{
			if ( *pszText == cDelimiter )
			{
				*pszBuf++ = *pszText++;
				blText = false;
			}
			else
			{
				*pszBuf++ = *pszText++;
			}
			continue;
		}

		// '{' �����å�
		if ( *pszText == '{' )
		{
			*pszBuf++ = *pszText++;
			iErr = SearchChar(pszBuf, pszText, '}');
			if ( iErr != CFG_ERR_OK )
			{
				iErr = CFG_ERR_BRACE;
			}
			pszBuf  += strlen(pszBuf);
			*pszBuf++ = '}';
			continue;
		}

		// '(' �����å�
		if ( *pszText == '(' )
		{
			*pszBuf++ = *pszText++;
			iErr = SearchChar(pszBuf, pszText, ')');
			if ( iErr != CFG_ERR_OK )
			{
				iErr = CFG_ERR_PAREN;
			}
			pszBuf  += strlen(pszBuf);
			*pszBuf++ = ')';
			continue;
		}

		*pszBuf++ = *pszText++;
	}

	*pszBuf = '\0';

	return iErr;
}


// �ѥ�᡼�������ڤ�Ф�
int CAnalyze::GetParameter(char* pszBuf, const char* &pszText)
{
	int iErr;

	// ����ޤޤ��ڤ�Ф�
	iErr = SearchChar(pszBuf, pszText, ',');
	if ( iErr == CFG_ERR_SYNTAX )
	{
		// ����б�OK�ǽ�ü�ʤ饳��ޤ����Ĥ���ʤ��Ƥ��
		iErr = CFG_ERR_OK;
	}

	return iErr;
}


// ʸ���������Ÿ������
int CAnalyze::DecodeText(char *pszBuf, const char* pszText)
{
	bool blEsc = false;

	if ( *pszText++ != '\"') 
	{
		return CFG_ERR_TEXT;
	}

	for ( ; ; )
	{
		if ( *pszText == '\0' )
		{
			return CFG_ERR_TEXT;
		}

		// ����ʸ���� '\' �ʤ��ɤ����Ф�
		if ( blEsc )
		{
			*pszBuf++ = *pszText++;
			blEsc = false;
			continue;
		}

		// ����������ʸ�������å�
		if ( *pszText == '\\' )
		{
			pszText++;
			blEsc = true;
			continue;
		}

		// ��ü�����å�
		if ( *pszText == '\"' )
		{
			pszText++;
			break;
		}

		*pszBuf++ = *pszText++;
	}

	// ���뤷�Ƥ��ʤ���Х��顼
	if ( *pszText != '\0' )
	{
			return CFG_ERR_TEXT;
	}

	*pszBuf = '\0';

	return CFG_ERR_OK;
}


// ����ζ����������
void CAnalyze::SpaceCut(char* pszText)
{
	char *pszTmp;
	int  i = 0;

	pszTmp = pszText;

	// ��Ƭ�ζ�����ɤ����Ф�
	while ( *pszTmp == ' ' )
	{
		pszTmp++;
	}

	// ���ԡ�
	while ( *pszTmp != '\0' )
	{
		pszText[i++] = *pszTmp++;
	}

	// �����ζ������
	while ( i > 0 && pszText[i - 1] == ' ' )
	{
		i--;
	}

	pszText[i] = '\0';
}


// ---------------------------------------------------------------------------
//  Copyright (C) 1998-2002 by Project HOS                                    
// ---------------------------------------------------------------------------
