
#include "osprop.h"
#include "osapi.h"
#include "cfg.h"

#define TASK_STACK_SIZE		120 		//task stack size
#define	MESSAGE_BUF_SIZE	30			//message buffer size

OSBYTE	taskStack[CONFIG_OSEK_TASK_NUMBER][TASK_STACK_SIZE]; //task stacks
OSBYTE	messageBuf[OCC_NMSGS][MESSAGE_BUF_SIZE];			 //message buffers
OSBYTE	messageQueue[OCC_NMSGS][MESSAGE_BUF_SIZE];			 //message queues

#pragma LINK_INFO DERIVATIVE "mc9s12xep100"

#pragma CODE_SEG NON_BANKED
/*==================================================================================
|
| 					Interrupt Service Routines
|
===================================================================================*/



#ifndef Ir_RealTimInt

ISR(Ir_RealTimInt)
{
    CounterTrigger(SysCounter);
}

#endif
#pragma CODE_SEG DEFAULT

StatusType MessageInit()
{
	return E_OK;
}


//interrupt type configurations
OSBYTE	osekConfig_InterruptTypeTable[OCC_ISRLEVELNUM] = 
{
		2,
		2,
		2,
		2,
		2,
		2,
		2,
		2,
		2,
		2,
		2,
		2,
		2,
		2,
		2,
		2,
		2,
		2,
		2,
		2,
		2,
		2,
		2,
		2,
		2,
		2,
		2,
		2,
		2,
		2,
		2,
		2,
		2,
		2,
		2,
		2,
		2,
		2,
		2,
		2,
		2,
		2,
		2,
		2,
		2,
		2,
		2,
		2,
		2,
		2,
		2,
		2,
		2,
		2,
		2,
		2,
		2,
		2,
		2,
		2,
		2,
		2,
		2,
		2,
		2,
		2,
		2,
		2,
		2,
		2,
		2,
		2,
		2,
		2,
		2,
		2,
		2,
		2,
		2,
		2,
		2,
		2,
		2,
		2,
		2,
		2,
		2,
		2,
		2,
		2,
		2,
		2,
		2,
		2,
		2,
		2,
		2,
		2,
		2,
		2,
		2,
		2,
		2,
		2,
		2,
		2,
		2,
		2,
		2,
		2,
		2,
		2,
		2,
		2,
		2,
		2,
		2,
		2,
		2,
		2,
		2,
		2,
		2,
		2,
		2,
		2,
		2,
		2,
};

//ISR functions
T_OSEK_TASK_Entry	osekConfig_InterruptEntryTable[OCC_ISRLEVELNUM] = 
{
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		(T_OSEK_TASK_Entry)Ir_RealTimInt,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
};



/* task configurations */

const		T_OSEK_TASK_ConfigTable_Struct		osekConfig_TaskTable[OCC_NTSKS]=	
{
	{
		(T_OSEK_TASK_Entry)Funcini_LLD,
		ini_LLD,
		0 | OSEK_TASK_ACTIVE | OSEK_TASK_EXTENDED | OSEK_TASK_NONPREEMPT,
		&taskStack[ini_LLD][TASK_STACK_SIZE-1],
		&taskStack[ini_LLD][0]
	},
	{
		(T_OSEK_TASK_Entry)FuncHLS_ini,
		HLS_ini,
		0 | OSEK_TASK_EXTENDED | OSEK_TASK_NONPREEMPT,
		&taskStack[HLS_ini][TASK_STACK_SIZE-1],
		&taskStack[HLS_ini][0]
	},
	{
		(T_OSEK_TASK_Entry)FuncHLS_ini2,
		HLS_ini2,
		0 | OSEK_TASK_EXTENDED | OSEK_TASK_NONPREEMPT,
		&taskStack[HLS_ini2][TASK_STACK_SIZE-1],
		&taskStack[HLS_ini2][0]
	},
	{
		(T_OSEK_TASK_Entry)Funcini_LLD2,
		ini_LLD2,
		0 | OSEK_TASK_EXTENDED | OSEK_TASK_NONPREEMPT,
		&taskStack[ini_LLD2][TASK_STACK_SIZE-1],
		&taskStack[ini_LLD2][0]
	},
	{
		(T_OSEK_TASK_Entry)FuncTask100ms,
		Task100ms,
		0,
		&taskStack[Task100ms][TASK_STACK_SIZE-1],
		&taskStack[Task100ms][0]
	},
	{
		(T_OSEK_TASK_Entry)FuncTask200ms,
		Task200ms,
		0,
		&taskStack[Task200ms][TASK_STACK_SIZE-1],
		&taskStack[Task200ms][0]
	},
	{
		(T_OSEK_TASK_Entry)FuncTask400ms,
		Task400ms,
		0,
		&taskStack[Task400ms][TASK_STACK_SIZE-1],
		&taskStack[Task400ms][0]
	},
	{
		(T_OSEK_TASK_Entry)FuncTask1000ms,
		Task1000ms,
		0,
		&taskStack[Task1000ms][TASK_STACK_SIZE-1],
		&taskStack[Task1000ms][0]
	},
	{
		(T_OSEK_TASK_Entry)FuncHLS_inisyn,
		HLS_inisyn,
		0 | OSEK_TASK_ACTIVE | OSEK_TASK_EXTENDED,
		&taskStack[HLS_inisyn][TASK_STACK_SIZE-1],
		&taskStack[HLS_inisyn][0]
	},
	{
		(T_OSEK_TASK_Entry)FuncHLS_rstsyn,
		HLS_rstsyn,
		0 | OSEK_TASK_ACTIVE | OSEK_TASK_EXTENDED,
		&taskStack[HLS_rstsyn][TASK_STACK_SIZE-1],
		&taskStack[HLS_rstsyn][0]
	},
	{
		(T_OSEK_TASK_Entry)FuncHLS_firstsyn,
		HLS_firstsyn,
		0 | OSEK_TASK_ACTIVE | OSEK_TASK_EXTENDED,
		&taskStack[HLS_firstsyn][TASK_STACK_SIZE-1],
		&taskStack[HLS_firstsyn][0]
	},
	{
		(T_OSEK_TASK_Entry)FuncHLS_syn,
		HLS_syn,
		0 | OSEK_TASK_ACTIVE | OSEK_TASK_EXTENDED,
		&taskStack[HLS_syn][TASK_STACK_SIZE-1],
		&taskStack[HLS_syn][0]
	},
	{
		(T_OSEK_TASK_Entry)FunccomTask1,
		comTask1,
		0,
		&taskStack[comTask1][TASK_STACK_SIZE-1],
		&taskStack[comTask1][0]
	},
	{
		(T_OSEK_TASK_Entry)FunccomTask2,
		comTask2,
		0,
		&taskStack[comTask2][TASK_STACK_SIZE-1],
		&taskStack[comTask2][0]
	},
	{
		(T_OSEK_TASK_Entry)FunccomTask3,
		comTask3,
		0,
		&taskStack[comTask3][TASK_STACK_SIZE-1],
		&taskStack[comTask3][0]
	},
	{
		(T_OSEK_TASK_Entry)FunccomTask4,
		comTask4,
		0,
		&taskStack[comTask4][TASK_STACK_SIZE-1],
		&taskStack[comTask4][0]
	},
	{
		0,
		OSEK_TASK_IDLE_ID,
		OSEK_TASK_ACTIVE,
	},
};



//COUNTER configuration table
T_OSEK_COUNTER_ConfigTable osekConfig_CounterTable[OCC_NCTRS] = 
{
	{
		32767,	// maximum value of the counter
		1,
		1
	},
};



//ALARM configuration table
T_OSEK_ALARM_ConfigTable osekConfig_AlarmTable[OCC_NALMS] =
{
	{
		Task100ms,
		0,
		SysCounter,
	},
	{
		Task200ms,
		0,
		SysCounter,
	},
	{
		Task400ms,
		0,
		SysCounter,
	},
	{
		Task1000ms,
		0,
		SysCounter,
	},
};

//resource ceiling priority configurations
OSPRIOTYPE osekConfig_ResourcePriorityTable[CONFIG_OSEK_RESOURCE_NUMBER] =
{
	31,  //Resource1
	31,  //Resource2
	31,  //Resource3
};

T_OSEK_MESSAGE_ConfigTable_Struct osekConfig_MsgTable[OCC_NMSGS] = 
{
   {
   		0,						 //ID
   		&messageBuf[0],			 //message butter
   		sizeof(messageBuf[0]),	 //size of the message buffer
   },
   {
   		1,						 //ID
   		&messageBuf[1],
   		sizeof(messageBuf[1]),
   },
   {
   		2,
   		&messageBuf[2],
   		sizeof(messageBuf[2]),
   },
   {
   		3,
   		&messageBuf[3],
   		sizeof(messageBuf[3]),
   }
};




