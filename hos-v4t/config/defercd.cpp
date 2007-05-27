// ---------------------------------------------------------------------------
//  Hyper Operating System V4  ����ե�����졼����                           
//    ���顼�����ɴ���                                                        
//                                                                            
//                                    Copyright (C) 1998-2002 by Project HOS  
//                                    http://sourceforge.jp/projects/hos/     
// ---------------------------------------------------------------------------


#include "defercd.h"


static const char *szErrMsg[] =
	{
		"unanticipated EOF.",		// ͽ������EOF
		"illegal CR.",				// �����ʲ���
		"status too long.",			// �����ơ��Ȥ�Ĺ������
		"syntax error."	,			// ��ʸ���顼
		"expect \')\' but found.",	// ()��������
		"expect \'}\' but found.",	// {}��������
		"expect \';\' but found.",	// ���ߥ����̵��
		"illegal text.",			// ������ʸ�������
		"conflict ID.",				// ID����
		"illegal parameter.",		 // �ѥ�᡼��������
		"multiple definition.",		// ͣ��Ǥ���٤�API�����ʣ��
	};


// ���顼ʸ�������
const char* GetErrMessage(int iErr)
{
	if ( iErr < 1 || iErr > 11 )
	{
		return "unknown expression error.";
	}

	return szErrMsg[iErr - 1];
}


// ---------------------------------------------------------------------------
//  Copyright (C) 1998-2002 by Project HOS                                    
// ---------------------------------------------------------------------------
