// ---------------------------------------------------------------------------
//  Hyper Operating System V4  ����ե�����졼����                           
//    INCLUDE API �ν���                                                      
//                                                                            
//                                    Copyright (C) 1998-2002 by Project HOS  
//                                    http://sourceforge.jp/projects/hos/     
// ---------------------------------------------------------------------------


#ifndef __HOSV4CFG_ApiInclude_h__
#define __HOSV4CFG_ApiInclude_h__


#include "apidef.h"
#include "parpack.h"


// INCLUDE ��
class CApiInclude : public CApiDef
{
public:
	CApiInclude();		// ���󥹥ȥ饯��
	~CApiInclude();		// �ǥ��ȥ饯��

	int   AnalyzeApi(const char* pszApiName, const char* pszParams);	// API�β���
	int   AutoId(void);							// ��ưID�ֹ�������
	void  WriteCfgDef(FILE* fp);				// cfg�ե�����������񤭽Ф�
};


#endif	// __HOSV4CFG_ApiInclude_h__


// ---------------------------------------------------------------------------
//  Copyright (C) 1998-2002 by Project HOS                                    
// ---------------------------------------------------------------------------
