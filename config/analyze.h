// ---------------------------------------------------------------------------
//  HOS V4 ����ե�����졼����                                               
//    ��ʸ���ϥ��饹                                                          
//                                                                            
//                                    Copyright (C) 1998-2002 by Project HOS  
//                                    http://sourceforge.jp/projects/hos/     
// ---------------------------------------------------------------------------


#ifndef __HOSV4CFG__Analyze_h__
#define __HOSV4CFG__Analyze_h__



// ��ʸ���ϥ��饹
class CAnalyze
{
public:
	static int  SplitState(char* pszApiName, char* pszParams, const char *pszState);	// ���ơ��ȥ��Ȥ�API̾�ȥѥ�᡼������ʬ��
	static int  SearchChar(char* pszBuf, const char* &pszText, char c);		// ����ʸ���ΤޤǤ��ڤ�Ф�
	static int  GetParameter(char* pszBuf, const char* &pszText);			// �ѥ�᡼�������ڤ�Ф�
	static int  DecodeText(char *pszBuf, const char* pszText);				// ʸ���������Ÿ������
	static void SpaceCut(char* pszText);			// ����ζ����������
};


#endif	// __HOSV4CFG__Analyze_h__


// ---------------------------------------------------------------------------
//  Copyright (C) 1998-2002 by Project HOS                                    
// ---------------------------------------------------------------------------
