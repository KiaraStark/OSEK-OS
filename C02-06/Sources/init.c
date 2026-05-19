/****************************************************************************
 *
 * 		Copyright (C) 2005-2009 ESEC UESTC All Rights Reserved.
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


	//初始化串口
 	BSP_UartInit();
	//初始化定时器
	BSP_TimerInit();
	EnableInterrupts;
	//showLogo();
	StartOS(OSDEFAULTAPPMODE);


	return 0;

}

//show LOGO
void showLogo()
{
	printf("************************************************************\n");
	printf("****************ESEC OSEK EVENT AND MESSAGE*****************\n");
	printf("************************************************************\n\n");
}

//output task ID and states
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

//print with resource lock helper
void printWithResource(ResourceType res, const char* msg)
{
    GetResource(res);
    printf("%s\n", msg);
    ReleaseResource(res);
}

/*************************************************
**************** Task1 ***************************
**************************************************
*/
TASK(Task1)
{
	TaskType taskId;
	StatusType status;

	GetTaskID(&taskId);

	showLogo();

	printWithResource(Resource1, "**********************task 1 running**********************");

	//Set 8 alarms to activate tasks 2-9 with events
	SetRelAlarm(Alarm1, 1000, 0);   //activates Task2 with event 0x01
	SetRelAlarm(Alarm2, 1100, 0);  //activates Task3 with event 0x02
	SetRelAlarm(Alarm3, 1200, 0);  //activates Task4 with event 0x03
	SetRelAlarm(Alarm4, 1300, 0);  //activates Task5 with event 0x04
	SetRelAlarm(Alarm5, 1400, 0);  //activates Task6 with event 0x05
	SetRelAlarm(Alarm6, 1500, 0);  //activates Task7 with event 0x06
	SetRelAlarm(Alarm7, 1600, 0);  //activates Task8 with event 0x07
	SetRelAlarm(Alarm8, 1700, 0);  //activates Task9 with event 0x08

	//Activate tasks 6-10 that wait for events
	ActivateTask(Task6);
	ActivateTask(Task7);
	ActivateTask(Task8);
	ActivateTask(Task9);
	ActivateTask(Task10);

	//Wait for completion events from Task10
	WaitEvent(0x10);
	ClearEvent(0x10);

	printWithResource(Resource1, "**********************task 1 end**************************");
	TerminateTask();
}



/*************************************************
**************** Task2 ***************************
**************************************************
*/

TASK(Task2)
{
	TaskType taskId;
	StatusType status;

	GetTaskID(&taskId);

	//Wait for event 0x01 set by Alarm1
	WaitEvent(0x01);
	ClearEvent(0x01);

	printWithResource(Resource1, "**********************task 2 running**********************");
	showTaskInfo(taskId);
	printWithResource(Resource1, "**********************task 2 end**************************");
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

	//Wait for event 0x02 set by Alarm2
	WaitEvent(0x02);
	ClearEvent(0x02);

	printWithResource(Resource2, "**********************task 3 running**********************");
	showTaskInfo(taskId);
	printWithResource(Resource2, "**********************task 3 end**************************");
	TerminateTask();
}


/*************************************************
**************** Task4 ***************************
**************************************************
*/
TASK(Task4)
{
	TaskType taskId;
	StatusType status;

	GetTaskID(&taskId);

	//Wait for event 0x03 set by Alarm3
	WaitEvent(0x03);
	ClearEvent(0x03);

	printWithResource(Resource3, "**********************task 4 running**********************");
	printWithResource(Resource3, "**********************task 4 end**************************");
	TerminateTask();
}

/*************************************************
**************** Task5 ***************************
**************************************************
*/
TASK(Task5)
{
	TaskType taskId;
	StatusType status;

	GetTaskID(&taskId);

	//Wait for event 0x04 set by Alarm4
	WaitEvent(0x04);
	ClearEvent(0x04);

	printWithResource(Resource1, "**********************task 5 running**********************");
	showTaskInfo(taskId);
	printWithResource(Resource1, "**********************task 5 end**************************");
	TerminateTask();
}

/*************************************************
**************** Task6 ***************************
**************************************************
*/
TASK(Task6)
{
	TaskType taskId;
	StatusType status;
	GetTaskID(&taskId);

	//Wait for event 0x05 set by Alarm5
	WaitEvent(0x05);
	ClearEvent(0x05);

	printWithResource(Resource2, "**********************task 6 running**********************");
	showTaskInfo(taskId);
	printWithResource(Resource2, "**********************task 6 end**************************");
	TerminateTask();
}

/*************************************************
**************** Task7 ***************************
**************************************************
*/
TASK(Task7)
{
	TaskType taskId;
	StatusType status;

	GetTaskID(&taskId);

	//Wait for event 0x06 set by Alarm6
	WaitEvent(0x06);
	ClearEvent(0x06);

	printWithResource(Resource3, "**********************task 7 running**********************");
	showTaskInfo(taskId);
	printWithResource(Resource3, "**********************task 7 end**************************");
	TerminateTask();
}

/*************************************************
**************** Task8 ***************************
**************************************************
*/
TASK(Task8)
{
	TaskType taskId;
	StatusType status;

	GetTaskID(&taskId);

	//Wait for event 0x07 set by Alarm7
	WaitEvent(0x07);
	ClearEvent(0x07);

	printWithResource(Resource1, "**********************task 8 running**********************");
	showTaskInfo(taskId);
	printWithResource(Resource1, "**********************task 8 end**************************");
	TerminateTask();
}


/*************************************************
**************** Task9 ***************************
**************************************************
*/
TASK(Task9)
{
	TaskType taskId;
	StatusType status;

	GetTaskID(&taskId);

	//Wait for event 0x08 set by Alarm8
	WaitEvent(0x08);
	ClearEvent(0x08);

	printWithResource(Resource2, "**********************task 9 running**********************");
	showTaskInfo(taskId);
	printWithResource(Resource2, "**********************task 9 end**************************");
	TerminateTask();
}

/*************************************************
**************** Task10 ***************************
**************************************************
*/
TASK(Task10)
{
	TaskType taskId;
	StatusType status;

	GetTaskID(&taskId);

	printWithResource(Resource3, "**********************task 10 running**********************");
	showTaskInfo(taskId);

	//Set completion event for Task1
	SetEvent(Task1, 0x10);

	printWithResource(Resource3, "**********************task 10 end**************************");
	TerminateTask();
}