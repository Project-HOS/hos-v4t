/* ------------------------------------------------------------------------ */
/*  Hyper Operating System V4  ����ץ�ץ����                           */
/*    H8/3048 �� OS������ (ITU0������)                                      */
/*                                                                          */
/*                                  Copyright (C) 1998-2002 by Project HOS  */
/*                                  http://sourceforge.jp/projects/hos/     */
/* ------------------------------------------------------------------------ */


#ifndef __HOS_V4__SAMPLE__ostimer_h__
#define __HOS_V4__SAMPLE__ostimer_h__


#ifdef __cplusplus
extern "C" {
#endif

void OsTimer_Initialize(VP_INT exinf);		/* OS�����ޤν���� */
void OsTimer_TimerHandler(VP_INT exinf);	/* �������ѳ����ߥϥ�ɥ� */

#ifdef __cplusplus
}
#endif



#endif	/* __HOS_V4__SAMPLE__ostimer_h__ */


/* ------------------------------------------------------------------------ */
/*  Copyright (C) 1998-2002 by Project HOS                                  */
/* ------------------------------------------------------------------------ */
