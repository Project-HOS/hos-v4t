// ---------------------------------------------------------------------------
//  Hyper Operating System V4  ����ե�����졼����                           
//    �ᥤ��롼����                                                          
//                                                                            
//                                    Copyright (C) 1998-2002 by Project HOS  
//                                    http://sourceforge.jp/projects/hos/     
// ---------------------------------------------------------------------------


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "defercd.h"
#include "read.h"
#include "analyze.h"
#include "apiinc.h"
#include "idlstk.h"
#include "intstk.h"
#include "knlheap.h"
#include "cretsk.h"
#include "cresem.h"
#include "creflg.h"
#include "attisr.h"
#include "attini.h"


#define DEFAULT_INPUTFILE		"system.i"
#define DEFAULT_IDFILE			"kernel_id.h"
#define DEFAULT_CFGFILE			"kernel_cfg.c"


int  ReadConfigFile(FILE* fpConfig);	// ����ե�����졼�����ե������ɤ߹���
void WriteIdFile(FILE* fp);				// ID ����إå��ե��������
void WriteCfgFile(FILE* fp);			// C ���쥽��������
void PrintUsage(void);


CApiInclude    g_ApiInclude;
CApiIdleStack  g_ApiIdleStack;
CApiIntStack   g_IntStack;
CApiKernelHeap g_ApiKernelHeap;
CApiCreTsk     g_ApiCreTsk;
CApiCreSem     g_ApiCreSem;
CApiCreFlg     g_ApiCreFlg;
CApiAttIsr     g_ApiAttIsr;
CApiAttIni     g_ApiAttIni;

static const char *s_szPhysicalInputFile  = NULL;
static const char *s_szIdFile             = DEFAULT_IDFILE;
static const char *s_szCfgFile            = DEFAULT_CFGFILE;

// API����ꥹ��
static CApiDef* g_ApiList[] =
	{
		&g_ApiInclude,
		&g_ApiIdleStack,
		&g_IntStack,
		&g_ApiKernelHeap,
		&g_ApiCreTsk,
		&g_ApiCreSem,
		&g_ApiCreFlg,
		&g_ApiAttIsr,
		&g_ApiAttIni,
	};

#define API_COUNT	(sizeof(g_ApiList) / sizeof(CApiDef*))		// API�Ŀ�




// �ᥤ��ؿ�
int main(int argc, char *argv[])
{
	FILE* fpInput;
	FILE* fpCfg;
	FILE* fpId;
	int  iErr;
	int  i;

	// ���ޥ�ɥ饤�����
	for ( i = 1; i < argc; i++ )
	{
		if ( strcmp(argv[i], "-c") == 0 )
		{
			i++;
			if ( i >= argc )
			{
				fprintf(stderr, "option error \"-c\"\n");
                               PrintUsage();
				return 1;
			}
			s_szCfgFile = argv[i];
		}
		else if ( strcmp(argv[i], "-i") == 0 )
		{
			i++;
			if ( i >= argc )
			{
				fprintf(stderr, "option error \"-i\"\n");
                               PrintUsage();
				return 1;
			}
			s_szIdFile = argv[i];
		}
               else if ( strcmp(argv[i], "-help") == 0 )
               {
                       PrintUsage();
                       return 0;
               }
               else if ( argv[i][0] == '-' && argv[i][1] != '\0' )
               {
                       fprintf(stderr, "unknown option \"%s\"\n", argv[i]);
                       PrintUsage();
                       return 1;
               }
		else
		{
			if ( s_szPhysicalInputFile != NULL )
			{
				fprintf(stderr, "too many input files\n");
				PrintUsage();
				return 1;
			}
			s_szPhysicalInputFile = argv[i];
		}
	}

	// ���ϥե������ά���Υǥե��������
	if ( s_szPhysicalInputFile == NULL )
	{
		s_szPhysicalInputFile = DEFAULT_INPUTFILE;
	}

	// ���ϥե����륪���ץ�
	if ( strcmp(s_szPhysicalInputFile, "-") == 0) {
		s_szPhysicalInputFile = "stdin";
		fpInput = stdin;
	}
	else if ( (fpInput = fopen(s_szPhysicalInputFile, "r")) == NULL )
	{
               fprintf(stderr, "could not open file \"%s\"\n", s_szPhysicalInputFile);
		return 1;
	}
	
	// ����ե�����졼�����ե������ɤ߹���
	iErr = ReadConfigFile(fpInput) != 0;
	fclose(fpInput);
	if ( iErr != 0 )
	{
		return 1;
	}

	// ��ưID�ֹ�������
	for ( i = 0; i < API_COUNT; i++ )
	{
		g_ApiList[i]->AutoId();
	}

	// ID ����ե����륪���ץ�
	if ( (fpId = fopen(s_szIdFile, "w")) == NULL )
	{
               fprintf(stderr, "could not open file \"%s\"\n", s_szIdFile);
		return 1;
	}

	WriteIdFile(fpId);

	fclose(fpId);


	// Cfg�ե����륪���ץ�
	if ( (fpCfg = fopen(s_szCfgFile, "w")) == NULL )
	{
               fprintf(stderr, "could not open file \"%s\"\n", s_szCfgFile);
		return 1;
	}

	WriteCfgFile(fpCfg);

	fclose(fpCfg);

	return 0;
}


// ����ե�����졼�����ե������ɤ߹���
int ReadConfigFile(FILE* fpConfig)
{
	char szState[READ_MAX_STATE];
	char szApiName[READ_MAX_STATE];
	char szParams[READ_MAX_STATE];
	int  iErr;
	int  i;

	CRead read(fpConfig, s_szPhysicalInputFile);	// �ɤ߽Ф����֥�����������

	// �ɤ߹���
	while (	(iErr = read.ReadState(szState)) != CFG_ERR_COMPLETE )
	{
		// �ɤ߹��ߥ��顼�����å�
		if ( iErr != CFG_ERR_OK )
		{
                       fprintf(stderr, "%s line(%d) : %s\n",
					read.GetLogicalInputFile(),
					read.GetLogicalLineNum(), GetErrMessage(iErr));
			return 1;
		}

		// ��ʸ����
		iErr = CAnalyze::SplitState(szApiName, szParams, szState);
		if ( iErr != CFG_ERR_OK )
		{
                       fprintf(stderr, "%s line(%d) : %s\n",
					read.GetLogicalInputFile(),
					read.GetLogicalLineNum(), GetErrMessage(iErr));
			return 1;
		}
		CAnalyze::SpaceCut(szApiName);
		CAnalyze::SpaceCut(szParams);

		// API����
		iErr = CFG_ERR_SYNTAX;
		for ( i = 0; i < API_COUNT; i++ )
		{
			iErr = g_ApiList[i]->AnalyzeApi(szApiName, szParams);
			if ( iErr != CFG_ERR_NOPROC )
			{
				break;
			}
		}
		if ( iErr != CFG_ERR_OK )
		{
                       fprintf(stderr, "%s line(%d) : %s\n",
					read.GetLogicalInputFile(),
					read.GetLogicalLineNum(), GetErrMessage(iErr));
			return 1;
		}
	}

	return 0;
}


// ID����إå��ե��������
void WriteIdFile(FILE* fp)
{
	int i;

	/* �إå����� */
	fputs(
		"/* ------------------------------------------------------------------------ */\n"
		"/*  HOS-V4  kernel configuration                                            */\n"
		"/*    kernel object ID definition                                           */\n"
		"/*                                                                          */\n"
		"/* ------------------------------------------------------------------------ */\n"
		"\n\n"
		"#ifndef __HOS_V4__kernel_cfg_h__\n"
		"#define __HOS_V4__kernel_cfg_h__\n"
		"\n"
		, fp);

	// ID ����ե��������
	for ( i = 0; i < API_COUNT; i++ )
	{
		g_ApiList[i]->WriteId(fp);
	}

	// �եå�����
	fputs(
		"\n\n\n"
		"#endif\t/* __HOS_V4__kernel_cfg_h__ */\n"
		"\n\n"
		"/* ------------------------------------------------------------------------ */\n"
		"/*  End of file                                                             */\n"
		"/* ------------------------------------------------------------------------ */\n"
		, fp);
}


// C ���쥽��������
void WriteCfgFile(FILE* fp)
{
	int i;

	/* �إå����� */
	fprintf(
		fp,
		"/* ------------------------------------------------------------------------ */\n"
		"/*  HOS-V4  kernel configuration                                            */\n"
		"/*    kernel object create and initialize                                   */\n"
		"/*                                                                          */\n"
		"/* ------------------------------------------------------------------------ */\n"
		"\n\n"
		"#include \"kernel.h\"\n"
		"#include \"%s\"\n"
		, s_szIdFile);

	// ID ����ե��������
	for ( i = 0; i < API_COUNT; i++ )
	{
		g_ApiList[i]->WriteCfgDef(fp);
	}

	// ������ؿ������Ƚ���
	fputs(
		"\n\n\n"
		"/* ------------------------------------------ */\n"
		"/*          initialize functions              */\n"
		"/* ------------------------------------------ */\n",
		fp);

	// ������ؿ�����
	fputs(
		"\n/* object initialize */\n"
		"void hoscfg_ini(void)\n"
		"{\n",
		fp);
	for ( i = 0; i < API_COUNT; i++ )
	{
		g_ApiList[i]->WriteCfgIni(fp);
	}
	fputs("}\n", fp);

	// ������ؿ�����
	fputs(
		"#if 0\n"
		"/* start up */\n"
		"void kernel_cfg_start(void)\n"
		"{\n",
		fp);
	for ( i = 0; i < API_COUNT; i++ )
	{
		g_ApiList[i]->WriteCfgStart(fp);
	}
	fputs(
		"}\n"
		"#endif\n",
		fp);

	// �եå�����
	fputs(
		"\n\n"
		"/* ------------------------------------------------------------------------ */\n"
		"/*  End of file                                                             */\n"
		"/* ------------------------------------------------------------------------ */\n"
		, fp);
}

// �Ȥ���ɽ��
void PrintUsage(void)
{
       fprintf(stderr,
               "usage: hos4cfg [options] [input-file]\n"
               "options are:\n"
               "   -i FILE    specify auto-assginment headerfile (default: " DEFAULT_IDFILE ")\n"
               "   -c FILE    specify kernel configuration file  (default: " DEFAULT_CFGFILE ")\n"
               "   -help      show this help\n"
               "\n"
               "input-file (default: " DEFAULT_INPUTFILE ")\n");
}


// ---------------------------------------------------------------------------
//  Copyright (C) 1998-2002 by Project HOS                                    
// ---------------------------------------------------------------------------
