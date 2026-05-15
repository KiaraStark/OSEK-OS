#ifndef OCC_CFG_H
#define OCC_CFG_H

#define		OSDEFAULTAPPMODE		0


//ISR functions
extern		void		Ir_RealTimInt(void);



//Task IDs

#define		Task1		0
#define		Task2		1
#define		Task3		2
#define		Task4		3
#define		Task5		4
#define		Task6		5
#define		Task7		6

//task functions
//extern	void	FuncTaskError(void);
extern	void	FuncTask1(void);
extern	void	FuncTask2(void);
extern	void	FuncTask3(void);
extern	void	FuncTask4(void);
extern	void	FuncTask5(void);
extern	void	FuncTask6(void);
extern	void	FuncTask7(void);




//COUNTER IDs
#define		SysCounter		0


//ALARM configuration lists
#define		AlarmError		&osekAlarm_AlarmTable[0]




#if defined (OCC_LOCALMESSAGESONLY)
//message IDs
#define		Msg1		&osekMsg_MessageTable[0]
#define		Msg2		&osekMsg_MessageTable[1]


#endif  /* OCC_LOCALMESSAGESONLY */




#endif/*	ifndef OCC_CFG_H	*/



