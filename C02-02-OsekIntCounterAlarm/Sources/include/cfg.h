#ifndef OCC_CFG_H
#define OCC_CFG_H

#define		OSDEFAULTAPPMODE		0


//ISR function
extern		void		Ir_RealTimInt(void);



//Task IDs

#define		Task1		0
#define		Task2		1
#define		Task3		2


//task functions
//extern	void	FuncTaskError(void);
extern	void	FuncTask1(void);
extern	void	FuncTask2(void);
extern	void	FuncTask3(void);
extern  void	FuncIdle(void);




//COUNTER IDs
#define		SysCounter		0

//ALARM configuration lists
#define		TaskAlarm		&osekAlarm_AlarmTable[0]




#if defined (OCC_LOCALMESSAGESONLY)

#endif  /* OCC_LOCALMESSAGESONLY */




#endif/*	ifndef OCC_CFG_H	*/



