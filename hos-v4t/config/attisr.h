// ---------------------------------------------------------------------------
//  Hyper Operating System V4  ����ե�����졼����                           
//    ATT_ISR API �ν���                                                      
//                                                                            
//                                    Copyright (C) 1998-2002 by Project HOS  
//                                    http://sourceforge.jp/projects/hos/     
// ---------------------------------------------------------------------------


#ifndef __HOSV4CFG_AttIsr_h__
#define __HOSV4CFG_AttIsr_h__


#include "apidef.h"
#include "parpack.h"


// ATT_ISR ��
class CApiAttIsr : public CApiDef
{
public:
	CApiAttIsr();		// ���󥹥ȥ饯��
	~CApiAttIsr();		// �ǥ��ȥ饯��

	int   AnalyzeApi(const char* pszApiName, const char* pszParams);	// API�β���
	int   AutoId(void);
	void  WriteCfgDef(FILE* fp);	// cfg�ե�����������񤭽Ф�
	void  WriteCfgIni(FILE* fp);	// cfg�ե������������񤭽Ф�

protected:
	int m_iMaxIntNo;
	int m_iMinIntNo;
	int m_iMaxIsrId;
};


#endif	// __HOSV4CFG_AttIsr_h__


// ---------------------------------------------------------------------------
//  Copyright (C) 1998-2002 by Project HOS                                    
// ---------------------------------------------------------------------------
