// ---------------------------------------------------------------------------
//  Hyper Operating System V4  ����ե�����졼����                           
//    API������饹                                                           
//                                                                            
//                                    Copyright (C) 1998-2002 by Project HOS  
//                                    http://sourceforge.jp/projects/hos/     
// ---------------------------------------------------------------------------


#ifndef __HOSV4CFG_ApiDef_h__
#define __HOSV4CFG_ApiDef_h__


#include "parpack.h"


#define API_MAX_OBJS		1024		// ���祪�֥������ȿ�
#define API_MAX_PARAM		4096		// ����ѥ�᡼��ʸ����


// API������饹
class CApiDef
{
public:
	CApiDef();				// ���󥹥ȥ饯��
	virtual ~CApiDef();		// �ǥ��ȥ饯��

	virtual int   AnalyzeApi(const char* pszApiName, const char* pszParams) = 0;	// API�β���
	virtual int   AutoId(void);							// ��ưID�ֹ�������
	virtual void  WriteId(FILE* fp);					// ID ����ե�����񤭽Ф�
	virtual void  WriteCfgDef(FILE* fp);				// cfg�ե�����������񤭽Ф�
	virtual void  WriteCfgIni(FILE* fp);				// cfg�ե������������񤭽Ф�
	virtual void  WriteCfgStart(FILE* fp);				// cfg�ե����뵯ư���񤭽Ф�

protected:
	virtual int   AddParams(const char* pszParams);		// �ѥ�᡼�����ɲ�

	CParamPack* m_pParamPacks[API_MAX_OBJS];	// �ѥ�᡼�����ꥹ��
	int         m_iId[API_MAX_OBJS];			// ID�ֹ�ꥹ��
	int         m_iObjs;		// ���֥������ȿ�
	int         m_iMaxId;		// ���� ID �ֹ�
	int         m_iParams;						// �ѥ�᡼������
	int         m_iParamSyntax[PARAMPACK_MAX];	// �ѥ�᡼������ʸ
};


#endif	// __HOSV4CFG_ApiDef_h__


// ---------------------------------------------------------------------------
//  Copyright (C) 1998-2002 by Project HOS                                    
// ---------------------------------------------------------------------------
