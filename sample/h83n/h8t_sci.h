#ifndef __H8TINY_SCI_H_
#define __H8TINY_SCI_H_


/* SCI�̿�®����� (16MHz�ΤȤ�) */
#define SCI_2400   207
#define SCI_4800   103
#define SCI_9600    51
#define SCI_19200   25
#define SCI_31250   15
#define SCI_38400   12
#define SCI_57600    8		/* �� -3.5% ���꤮�ꤤ���뤫�� (^^;; */

/* SCI3 */
void SCI3_Initialize(unsigned char rate);	/* SCI3����� */
void SCI3_RxiHandler(VP_INT exinf);		/* ���������ߥϥ�ɥ� */
void SCI3_PutChar(char c);			/* ��ʸ������ */
int  SCI3_GetChar(void);			/* ��ʸ������ */

/* assign SCI3 for SCI*/
#define Sci_Initialize SCI3_Initialize
#define Sci_RxiHandler SCI3_RxiHandler
#define Sci_PutChar SCI3_PutChar
#define Sci_GetChar SCI3_GetChar

#endif /* __H8TINY_SCI_H__ */
