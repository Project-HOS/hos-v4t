/* ------------------------------------------------------------------------ */
/*  HOS-V4  kernel configuration                                            */
/*    kernel object ID definition                                           */
/*                                                                          */
/* ------------------------------------------------------------------------ */


#ifndef __HOS_V4__kernel_cfg_h__
#define __HOS_V4__kernel_cfg_h__



/* task ID definetion */
#define TSKID_PHILOSOPHER1		1
#define TSKID_PHILOSOPHER2		2
#define TSKID_PHILOSOPHER3		3
#define TSKID_PHILOSOPHER4		4
#define TSKID_PHILOSOPHER5		5

#define TMAX_TSKID		5


/* semaphore ID definetion */
#define SEMID_FORK1		1
#define SEMID_FORK2		2
#define SEMID_FORK3		3
#define SEMID_FORK4		4
#define SEMID_FORK5		5
#define SEMID_SYSCS		6
#define SEMID_SCI1_RCV		7
#define SEMID_SCI2_RCV		8

#define TMAX_SEMID		8


/* event flag ID definetion */
#define FLGID_SCI1_SND		1
#define FLGID_SCI2_SND		2

#define TMAX_FLGID		2



#endif	/* __HOS_V4__kernel_cfg_h__ */


/* ------------------------------------------------------------------------ */
/*  End of file                                                             */
/* ------------------------------------------------------------------------ */
