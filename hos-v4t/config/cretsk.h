// ---------------------------------------------------------------------------
//  Hyper Operating System V4  ����ե�����졼����                           
//    CRE_TSK API �ν���                                                      
//                                                                            
//                                    Copyright (C) 1998-2002 by Project HOS  
//                                    http://sourceforge.jp/projects/hos/     
// ---------------------------------------------------------------------------


#ifndef __HOSV4CFG_CreTak_h__
#define __HOSV4CFG_CreTak_h__


#include "apidef.h"
#include "parpack.h"


// CRE_TSK ��
class CApiCreTsk : public CApiDef
{
public:
	CApiCreTsk();		// ���󥹥ȥ饯��
	~CApiCreTsk();		// �ǥ��ȥ饯��

	int   AnalyzeApi(const char* pszApiName, const char* pszParams);	// API�β���
	void  WriteId(FILE* fp);					// ID ����ե�����񤭽Ф�
	void  WriteCfgDef(FILE* fp);				// cfg�ե�����������񤭽Ф�
	void  WriteCfgIni(FILE* fp);				// cfg�ե������������񤭽Ф�
	void  WriteCfgStart(FILE* fp);				// cfg�ե����뵯ư���񤭽Ф�
};


#endif	// __HOSV4CFG_CreTak_h__


// ---------------------------------------------------------------------------
//  Copyright (C) 1998-2002 by Project HOS                                    
// ---------------------------------------------------------------------------
