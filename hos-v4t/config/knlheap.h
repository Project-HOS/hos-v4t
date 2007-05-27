// ---------------------------------------------------------------------------
//  Hyper Operating System V4  ����ե�����졼����                           
//    HOS_KERNEL_HEAP API �ν���                                              
//                                                                            
//                                    Copyright (C) 1998-2002 by Project HOS  
//                                    http://sourceforge.jp/projects/hos/     
// ---------------------------------------------------------------------------


#ifndef __HOSV4CFG_KernelHeap_h__
#define __HOSV4CFG_KernelHeap_h__


#include "apidef.h"
#include "parpack.h"


// HOS_KERNEL_HEAP ��
class CApiKernelHeap : public CApiDef
{
public:
	CApiKernelHeap();		// ���󥹥ȥ饯��
	~CApiKernelHeap();		// �ǥ��ȥ饯��

	int   AnalyzeApi(const char* pszApiName, const char* pszParams);	// API�β���
	int   AutoId(void);
	void  WriteCfgDef(FILE* fp);		// cfg�ե�����������񤭽Ф�
	void  WriteCfgStart(FILE* fp);		// cfg�ե����뵯ư���񤭽Ф�
};


#endif	// __HOSV4CFG_KernelHeap_h__


// ---------------------------------------------------------------------------
//  Copyright (C) 1998-2002 by Project HOS                                    
// ---------------------------------------------------------------------------