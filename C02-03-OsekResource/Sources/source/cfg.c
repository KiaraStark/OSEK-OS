
#include "osprop.h"
#include "osapi.h"
#include "cfg.h"

#define TASK_STACK_SIZE		100		//task stack size

OSBYTE	taskStack[CONFIG_OSEK_TASK_NUMBER][TASK_STACK_SIZE];	//task stacks

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



//interrupt type configuration
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

//ISR function configuration
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
	/*Task1	ID:0 priority:CONFIG_OSEK_TASK_PRIORITY_NUMBER-0-1 */
	{
		(T_OSEK_TASK_Entry)FuncTask1,   		//task function
		Task1,									//task ID
		0 |  OSEK_TASK_EXTENDED,				//task initial attributes
		&taskStack[Task1][TASK_STACK_SIZE-1],   //top of the task stack 
		&taskStack[Task1][0],					//bottom of the task stack
	},
	/*Task2	ID:1 priority:CONFIG_OSEK_TASK_PRIORITY_NUMBER-1-1 */			
	{
		(T_OSEK_TASK_Entry)FuncTask2,  
		Task2,
		0 | OSEK_TASK_EXTENDED,
		&taskStack[Task2][TASK_STACK_SIZE-1],
		&taskStack[Task2][0],
	},		
	/*Task3	ID:2 priority:CONFIG_OSEK_TASK_PRIORITY_NUMBER-2-1 */
	{
		(T_OSEK_TASK_Entry)FuncTask3,  
		Task3,
		0 | OSEK_TASK_EXTENDED,
		&taskStack[Task3][TASK_STACK_SIZE-1],
		&taskStack[Task3][0],
	},
	/*Task4	ID:3 priority:CONFIG_OSEK_TASK_PRIORITY_NUMBER-3-1 */
	{
		(T_OSEK_TASK_Entry)FuncTask4,  
		Task4,
		0 | OSEK_TASK_EXTENDED,
		&taskStack[Task4][TASK_STACK_SIZE-1],
		&taskStack[Task4][0],
	},											
	/*Task5	ID:4 priority:CONFIG_OSEK_TASK_PRIORITY_NUMBER-4-1 */
	{
		(T_OSEK_TASK_Entry)FuncTask5,  
		Task5,
		0 |OSEK_TASK_EXTENDED,
		&taskStack[Task5][TASK_STACK_SIZE-1],
		&taskStack[Task5][0],
	},
	/*Task6	ID:5 priority:CONFIG_OSEK_TASK_PRIORITY_NUMBER-5-1 */
	{
		(T_OSEK_TASK_Entry)FuncTask6,  
		Task6,
		0 | OSEK_TASK_EXTENDED,
		&taskStack[Task6][TASK_STACK_SIZE-1],
		&taskStack[Task6][0],
	},
	/*Task7	ID:6 priority:CONFIG_OSEK_TASK_PRIORITY_NUMBER-6-1 */
	{
		(T_OSEK_TASK_Entry)FuncTask7,  
		Task7,
		0 | OSEK_TASK_EXTENDED | OSEK_TASK_ACTIVE,
		&taskStack[Task7][TASK_STACK_SIZE-1],
		&taskStack[Task7][0],
	},	
	/*Task Idle	*/			
	{
		FuncIdle, 
		OSEK_TASK_IDLE_ID,
		OSEK_TASK_ACTIVE
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
		Task1,
#if (defined(OCC_ECC1) || defined(OCC_ECC2)) && defined(OCC_ALMSETEVENT)
		0,
#endif
		SysCounter,
	},
};

//resource ceiling priority configurations
OSPRIOTYPE osekConfig_ResourcePriorityTable[CONFIG_OSEK_RESOURCE_NUMBER] = 
{
	31,
	31,
	31,
	31,
	31,
	31,
	31
};




