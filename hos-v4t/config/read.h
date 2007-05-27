// ---------------------------------------------------------------------------
//  HOS V4 ����ե�����졼���� Ver 1.00                                      
//    �ǡ����ɤ߹��ߥ��饹                                                    
//                                                                            
//                                    Copyright (C) 1998-2002 by Project HOS  
//                                    http://sourceforge.jp/projects/hos/     
// ---------------------------------------------------------------------------



#ifndef __HOSV4CFG_Read_h__
#define __HOSV4CFG_Read_h__


#define READ_MAX_PATH		1024	// ����ѥ�̾
#define READ_MAX_STATE		4096	// �����ơ��Ȥκ���ʸ����


// �ǡ����ɤ߹��ߥ��饹
class CRead
{
public:
	CRead(FILE *fp, const char *name);			// ���󥹥ȥ饯��
	~CRead();						// �ǥ��ȥ饯��

	int ReadState(char *szState);	// �����ơ����ɤ߹���
	int GetPhysicalLineNum(void)	// �ºݤ��ɤ߹�����Υե�����ι��ֹ����
	{ return m_iPhysicalLineNum; }
	int GetLogicalLineNum(void)	// cpp���̤����Υե�����ι��ֹ����
	{ return m_iLogicalLineNum; }
	const char *GetLogicalInputFile(void)
	{ return m_szLogicalInputFile; }

protected:
       int SkipPreProcessorLine(char* szText, int iCount);     // �ץ�ץ��å��饤��Υ����å�
	int ReadString(int cDelimiter, char* szText, int& iCount);	// ʸ�����ɤ߹���

	FILE *m_fpRead;					// �ɤ߹����ѥե�����ݥ���
	int  m_iPhysicalLineNum;			// �ºݤ��ɤ߹�����Υե�����ι��ֹ�
	int  m_iLogicalLineNum;				// cpp���̤����Υե�����ι��ֹ�
	bool m_blLineTop;				// �Ԥ���Ƭ
	char m_szLogicalInputFile[READ_MAX_PATH];	// cpp���̤����Υե�����̾
};


#endif	// __HOSV4CFG_Read_h__


// ---------------------------------------------------------------------------
//  Copyright (C) 1998-2002 by Project HOS                                    
// ---------------------------------------------------------------------------
