// ---------------------------------------------------------------------------
//  Hyper Operating System V4  ����ե�����졼����                           
//    �ѥ�᡼������Ǽ���饹                                                  
//                                                                            
//                                    Copyright (C) 1998-2002 by Project HOS  
//                                    http://sourceforge.jp/projects/hos/     
// ---------------------------------------------------------------------------


#ifndef __HOSV4CFG__ParamPack_h__
#define __HOSV4CFG__ParamPack_h__


#define PARAMPACK_MAX	16


// �ѥ�᡼������Ǽ���饹
class CParamPack
{
public:
	CParamPack();		// ���󥹥ȥ饯��
	~CParamPack();		// �ǥ��ȥ饯��

	void        SetParam(int iIndex, const char *pszParam);	// �ѥ�᡼��������
	const char* GetParam(int iIndex);						// �ѥ�᡼��������

protected:
	char *m_pszParam[PARAMPACK_MAX];
};


#endif	// __HOSV4CFG__ParamPack_h__


// ---------------------------------------------------------------------------
//  Copyright (C) 1998-2002 by Project HOS                                    
// ---------------------------------------------------------------------------
