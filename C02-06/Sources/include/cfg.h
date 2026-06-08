#ifndef OCC_CFG_H
#define OCC_CFG_H

#define		OSDEFAULTAPPMODE		0

extern		void		Ir_RealTimInt(void);

// Task IDs. Periodic task IDs use valid C identifiers; logs keep the requested names.
#define		ini_LLD			0
#define		HLS_ini			1
#define		HLS_ini2		2
#define		ini_LLD2		3
#define		Task100ms		4
#define		Task200ms		5
#define		Task400ms		6
#define		Task1000ms		7
#define		HLS_inisyn		8
#define		HLS_rstsyn		9
#define		HLS_firstsyn	10
#define		HLS_syn			11
#define		comTask1		12
#define		comTask2		13
#define		comTask3		14
#define		comTask4		15

extern	void	Funcini_LLD(void);
extern	void	FuncHLS_ini(void);
extern	void	FuncHLS_ini2(void);
extern	void	Funcini_LLD2(void);
extern	void	FuncTask100ms(void);
extern	void	FuncTask200ms(void);
extern	void	FuncTask400ms(void);
extern	void	FuncTask1000ms(void);
extern	void	FuncHLS_inisyn(void);
extern	void	FuncHLS_rstsyn(void);
extern	void	FuncHLS_firstsyn(void);
extern	void	FuncHLS_syn(void);
extern	void	FunccomTask1(void);
extern	void	FunccomTask2(void);
extern	void	FunccomTask3(void);
extern	void	FunccomTask4(void);

#define		SysCounter		0

#define		AlarmError		&osekAlarm_AlarmTable[0]
#define		Alarm100ms		&osekAlarm_AlarmTable[0]
#define		Alarm200ms		&osekAlarm_AlarmTable[1]
#define		Alarm400ms		&osekAlarm_AlarmTable[2]
#define		Alarm1000ms		&osekAlarm_AlarmTable[3]

#define		Resource1		&osekResource_ResourceTable[0]
#define		Resource2		&osekResource_ResourceTable[1]
#define		Resource3		&osekResource_ResourceTable[2]

#if defined (OCC_LOCALMESSAGESONLY)
#define		Msg1		&osekMsg_MessageTable[0]
#define		Msg2		&osekMsg_MessageTable[1]
#define		Msg3		&osekMsg_MessageTable[2]
#define		Msg4		&osekMsg_MessageTable[3]
#endif

#endif
