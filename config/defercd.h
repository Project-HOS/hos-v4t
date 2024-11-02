// ---------------------------------------------------------------------------
//  Hyper Operating System V4  ����ե�����졼����                           
//    ���顼�����ɴ���                                                        
//                                                                            
//                                    Copyright (C) 1998-2002 by Project HOS  
//                                    http://sourceforge.jp/projects/hos/     
// ---------------------------------------------------------------------------


#ifndef __HOSV4CFG_DefErrorCode_h__
#define __HOSV4CFG_DefErrorCode_h__


// ����ϥ��顼��������� */
#define CFG_ERR_NOPROC			(-2)	// ̤����
#define CFG_ERR_COMPLETE		(-1)	// ��λ
#define CFG_ERR_OK				0		// ����

// �۾�ϥ��顼���������
#define CFG_ERR_EOF				1		// ͽ������EOF
#define CFG_ERR_CR				2		// �����ʲ���
#define CFG_ERR_STATE_LEN		3		// �����ơ��Ȥ�Ĺ������
#define CFG_ERR_SYNTAX			4		// ��ʸ���顼
#define CFG_ERR_PAREN			5		// ()��������
#define CFG_ERR_BRACE			6		// {}��������
#define CFG_ERR_SEMICOLON		7		// ���ߥ����̵��
#define CFG_ERR_TEXT			8		// ������ʸ�������
#define CFG_ERR_ID_CONFLICT		9		// ID����
#define CFG_ERR_PARAM			10		// �ѥ�᡼��������
#define CFG_ERR_MULTIDEF		11		// ͣ��Ǥ���٤������ʣ��


const char* GetErrMessage(int iErr);


#endif	// __HOSV4CFG_DefErrorCode_h__


// ---------------------------------------------------------------------------
//  Copyright (C) 1998-2002 by Project HOS                                    
// ---------------------------------------------------------------------------
