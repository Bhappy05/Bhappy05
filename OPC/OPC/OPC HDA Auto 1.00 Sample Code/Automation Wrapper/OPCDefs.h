// OPCDefs.h

#if !defined(OPCDEFS_H)
#define OPCDEFS_H

// Quality Flag:          QQSSSSLL

#define Q_BAD			0x0000
#define Q_UNCERTAIN		0x0040
#define Q_GOOD			0x00C0

#define S_BAD_NONSPEC		0x0000
#define S_BAD_CONFIG		0x0004
#define S_BAD_NOTCONN		0x0008
#define S_BAD_DEVFAIL		0x000C
#define S_BAD_SENSFAIL		0x0010
#define S_BAD_LASTKNOWN		0x0014
#define S_BAD_COMMFAIL		0x0018
#define S_BAD_OUTOFSERV		0x001C

#define S_UNC_NONSPEC		0x0000
#define S_UNC_LASTUSABLE	0x0004
#define S_UNC_NOTACCUR		0x0010
#define S_UNC_EUEXCEED		0x0014
#define S_UNC_SUBNORMAL		0x0018

#define S_GOOD_NONSPEC		0x0000
#define S_GOOD_LOCOVER		0x0018

#define L_NONE				0x0000
#define L_LOW				0x0001
#define L_HIGH				0x0002
#define L_CONST				0x0003

#endif