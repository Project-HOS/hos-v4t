// ---------------------------------------------------------------------------
//  Hyper Operating System V4  ����ե�����졼����                           
//    HOS_INT_STK API �ν���                                                  
//                                                                            
//                                    Copyright (C) 1998-2002 by Project HOS  
//                                    http://sourceforge.jp/projects/hos/     
// ---------------------------------------------------------------------------


#ifndef __HOSV4CFG_IntStack_h__
#define __HOSV4CFG_IntStack_h__


#include "apidef.h"
#include "parpack.h"


// HOS_KERNEL_HEAP ��
class CApiIntStack : public CApiDef
{
public:
	CApiIntStack();		// ���󥹥ȥ饯��
	~CApiIntStack();		// �ǥ��ȥ饯��

	int   AnalyzeApi(const char* pszApiName, const char* pszParams);	// API�β���
	int   AutoId(void);
	void  WriteCfgDef(FILE* fp);		// cfg�ե�����������񤭽Ф�

protected:
	char  m_szStackPointer[API_MAX_PARAM];
};


#endif	// __HOSV4CFG_IntStack_h__


// ---------------------------------------------------------------------------
//  Copyright (C) 1998-2002 by Project HOS                                    
// ---------------------------------------------------------------------------
