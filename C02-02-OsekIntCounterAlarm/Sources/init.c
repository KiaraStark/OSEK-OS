/****************************************************************************
 *
 * 		Copyright (C) 2005-2018 ESEC UESTC All Rights Reserved.
 ***************************************************************************/

/**
 * @file 	init.c
 * @brief
 * @date
 */



#include "include.h"
#include <stdio.h>
#include <string.h>


void showLogo();

int main(int argc ,char *argv[])
{

  //volatile int x=sizeof(OSDWORD);


 	BSP_UartInit(); 	
	BSP_TimerInit();
	EnableInterrupts;
	//showLogo();
	StartOS(OSDEFAULTAPPMODE);
	
	
	return 0;

}

//show LOGO information
void showLogo()
{
	printf("************************************************************\n");
	printf("****************ESEC OSEK INT COUNTER ALARM*****************\n");
	printf("************************************************************\n\n");
}

//output task ID and state
void showTaskInfo(TaskType taskId)
{
	TaskStateType taskState;
	GetTaskState(taskId, &taskState);
	printf("task id: %u, ", (int)taskId);
	switch(taskState)
	{
		case RUNNING:
			printf("taskState: running\n");
		break;
		case WAITING:
			printf("taskState: waiting\n");
		break;
		case READY:
			printf("taskState: ready\n");
		break;
		case SUSPENDED:
			printf("taskState: suspended\n");
	    break;
	    default:
	    break;
	}
}

/*************************************************
**************** Task1 ***************************
**************************************************
*/
TASK(Task1)
{
	TaskType taskId;
	GetTaskID(&taskId);
	
	showLogo();
	
	printf("**********************task 1 running**********************\n");
	showTaskInfo(taskId); 
	
	printf("activate task2...\n");
	ActivateTask(Task2);
	printf("activate task3...\n");
	ActivateTask(Task3);

	printf("set TaskAlarm...\n");	
	SetRelAlarm(TaskAlarm, 3000, 10000);
	
	printf("task1 wait event: 0x20\n");
	WaitEvent(0x20);
	printf("task1 get event 0x20 from TaskAlarm\n");
	printf("task1 cancel TaskAlarm...\n");
	CancelAlarm(TaskAlarm);
	
	printf("task1 set event 0x30 for task2...\n");
	SetEvent(Task2, 0x30);
	
 	printf("**********************task 1 end**************************\n"); 
 	
	TerminateTask();
}



/*************************************************
**************** Task2 ***************************
**************************************************
*/

TASK(Task2)
{
	TaskType taskId;
	GetTaskID(&taskId);
    printf("**********************task 2 running**********************\n");
	showTaskInfo(taskId); 
	
	printf("task2 wait event: 0x30\n");
	WaitEvent(0x30);
	printf("task2 get event 0x30...\n");
	
	printf("task2 set event 0x40 for task3...\n");
	SetEvent(Task3, 0x40);
	
	printf("**********************task 2 end**************************\n");
	TerminateTask();
}



/*************************************************
**************** Task3 ***************************
**************************************************
*/
TASK(Task3)
{ 
	TaskType taskId;
	GetTaskID(&taskId);
    printf("**********************task 3 running**********************\n");
    showTaskInfo(taskId); 
    
	printf("task3 wait event: 0x40\n");
	WaitEvent(0x40);
	
	printf("task3 get event 0x40...\n");	
	printf("**********************task 3 end**************************\n");
	TerminateTask();
	ShutdownOS(0xff);
}

/*************************************************
**************** Task Idle ***********************
**************************************************
*/
TASK(Idle)
{
	while(1)
	{
	
	}
}