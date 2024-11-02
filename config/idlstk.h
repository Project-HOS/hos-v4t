// ---------------------------------------------------------------------------
//  Hyper Operating System V4  ����ե�����졼����                           
//    HOS_IDL_STK API �ν���                                                  
//                                                                            
//                                    Copyright (C) 1998-2002 by Project HOS  
//                                    http://sourceforge.jp/projects/hos/     
// ---------------------------------------------------------------------------


#ifndef __HOSV4CFG_IdleStack_h__
#define __HOSV4CFG_IdleStack_h__


#include "apidef.h"
#include "parpack.h"


// HOS_KERNEL_HEAP ��
class CApiIdleStack : public CApiDef
{
public:
	CApiIdleStack();		// ���󥹥ȥ饯��
	~CApiIdleStack();		// �ǥ��ȥ饯��

	int   AnalyzeApi(const char* pszApiName, const char* pszParams);	// API�β���
	int   AutoId(void);
	void  WriteCfgDef(FILE* fp);		// cfg�ե�����������񤭽Ф�
};


#endif	// __HOSV4CFG_IdleStack_h__


// ---------------------------------------------------------------------------
//  Copyright (C) 1998-2002 by Project HOS                                    
// ---------------------------------------------------------------------------
