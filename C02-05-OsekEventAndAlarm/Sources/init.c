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
	printf("**********************task 1 running**********************\n");
	showTaskInfo(taskId);

	//Set 8 alarms: Alarm1-4 activate Task2-5; Alarm5-8 set events for Task6-9.
	SetRelAlarm(Alarm1, 1000, 0);  //activates Task2
	SetRelAlarm(Alarm2, 1100, 0);  //activates Task3
	SetRelAlarm(Alarm3, 1200, 0);  //activates Task4
	SetRelAlarm(Alarm4, 1300, 0);  //activates Task5

	SetRelAlarm(Alarm5, 1400, 0);  //sets event 0x50 for Task6
	SetRelAlarm(Alarm6, 1500, 0);  //sets event 0x60 for Task7
	SetRelAlarm(Alarm7, 1600, 0);  //sets event 0x70 for Task8
	SetRelAlarm(Alarm8, 1700, 0);  //sets event 0x80 for Task9

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
	StatusType status;
	EventMaskType mask;

	GetTaskID(&taskId);
	printf("**********************task 2 running**********************\n");
	showTaskInfo(taskId);

	status = GetResource(Resource1);
	if(status != E_OK)
	{
		printf("task2 get resource1 error: %d\n", status);
	}else
	{
		printf("task2 get resource1...\n");
	}


	status = ReleaseResource(Resource1);
	if(status != E_OK)
	{
		printf("task2 release resource1 error: %d\n", status);
	}else
	{
		printf("task2 release resource1...\n");
	}

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
	StatusType status;
	EventMaskType mask;

	GetTaskID(&taskId);

	printf("**********************task 3 running**********************\n");
	showTaskInfo(taskId);

	status = GetResource(Resource2);
	if(status != E_OK)
	{
		printf("task3 get resource2 error: %d\n", status);
	}else
	{
		printf("task3 get resource2...\n");
	}


	status = ReleaseResource(Resource2);
	if(status != E_OK)
	{
		printf("task3 release resource2 error: %d\n", status);
	}else
	{
		printf("task3 release resource2...\n");
	}

	printf("**********************task 3 end**************************\n");
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
	EventMaskType mask;

	GetTaskID(&taskId);

	printf("**********************task 4 running**********************\n");

	status = GetResource(Resource3);
	if(status != E_OK)
	{
		printf("task4 get resource3 error: %d\n", status);
	}else
	{
		printf("task4 get resource3...\n");
	}


	status = ReleaseResource(Resource3);
	if(status != E_OK)
	{
		printf("task4 release resource3 error: %d\n", status);
	}else
	{
		printf("task4 release resource3...\n");
	}

	printf("**********************task 4 end**************************\n");
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
	EventMaskType mask;

	GetTaskID(&taskId);

	printf("**********************task 5 running**********************\n");
	showTaskInfo(taskId);

	status = GetResource(Resource1);
	if(status != E_OK)
	{
		printf("task5 get resource1 error: %d\n", status);
	}else
	{
		printf("task5 get resource1...\n");
	}


	status = ReleaseResource(Resource1);
	if(status != E_OK)
	{
		printf("task5 release resource1 error: %d\n", status);
	}else
	{
		printf("task5 release resource1...\n");
	}

	printf("**********************task 5 end**************************\n");
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
	EventMaskType mask;
	GetTaskID(&taskId);

	printf("task6 wait event: 0x50\n");
	WaitEvent(0x50);
	GetEvent(taskId, &mask);
	printf("task6 get event: %d\n", (int)mask);
	ClearEvent(0x50);

	printf("**********************task 6 running**********************\n");
	showTaskInfo(taskId);

	status = GetResource(Resource2);
	if(status != E_OK)
	{
		printf("task6 get resource2 error: %d\n", status);
	}else
	{
		printf("task6 get resource2...\n");
	}


	status = ReleaseResource(Resource2);
	if(status != E_OK)
	{
		printf("task6 release resource2 error: %d\n", status);
	}else
	{
		printf("task6 release resource2...\n");
	}

	printf("**********************task 6 end**************************\n");
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
	EventMaskType mask;

	GetTaskID(&taskId);

	printf("task7 wait event: 0x60\n");
	WaitEvent(0x60);
	GetEvent(taskId, &mask);
	printf("task7 get event: %d\n", (int)mask);
	ClearEvent(0x60);

	printf("**********************task 7 running**********************\n");
	showTaskInfo(taskId);

	status = GetResource(Resource3);
	if(status != E_OK)
	{
		printf("task7 get resource3 error: %d\n", status);
	}else
	{
		printf("task7 get resource3...\n");
	}


	status = ReleaseResource(Resource3);
	if(status != E_OK)
	{
		printf("task7 release resource3 error: %d\n", status);
	}else
	{
		printf("task7 release resource3...\n");
	}

	printf("**********************task 7 end**************************\n");
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
	EventMaskType mask;

	GetTaskID(&taskId);

	printf("task8 wait event: 0x70\n");
	WaitEvent(0x70);
	GetEvent(taskId, &mask);
	printf("task8 get event: %d\n", (int)mask);
	ClearEvent(0x70);

	printf("**********************task 8 running**********************\n");
	showTaskInfo(taskId);

	status = GetResource(Resource1);
	if(status != E_OK)
	{
		printf("task8 get resource1 error: %d\n", status);
	}else
	{
		printf("task8 get resource1...\n");
	}


	status = ReleaseResource(Resource1);
	if(status != E_OK)
	{
		printf("task8 release resource1 error: %d\n", status);
	}else
	{
		printf("task8 release resource1...\n");
	}

	printf("**********************task 8 end**************************\n");
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
	EventMaskType mask;

	GetTaskID(&taskId);

	printf("task9 wait event: 0x80\n");
	WaitEvent(0x80);
	GetEvent(taskId, &mask);
	printf("task9 get event: %d\n", (int)mask);
	ClearEvent(0x80);

	printf("**********************task 9 running**********************\n");
	showTaskInfo(taskId);

	status = GetResource(Resource2);
	if(status != E_OK)
	{
		printf("task9 get resource2 error: %d\n", status);
	}else
	{
		printf("task9 get resource2...\n");
	}


	status = ReleaseResource(Resource2);
	if(status != E_OK)
	{
		printf("task9 release resource2 error: %d\n", status);
	}else
	{
		printf("task9 release resource2...\n");
	}
	printf("**********************task 9 end**************************\n");
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
	EventMaskType mask;
	GetTaskID(&taskId);

	printf("**********************task 10 running**********************\n");
	showTaskInfo(taskId);

	status = GetResource(Resource3);
	if(status != E_OK)
	{
		printf("task10 get resource3 error: %d\n", status);
	}else
	{
		printf("task10 get resource3...\n");
	}


	status = ReleaseResource(Resource3);
	if(status != E_OK)
	{
		printf("task10 release resource3 error: %d\n", status);
	}else
	{
		printf("task10 release resource3...\n");
	}
	
	printf("**********************task 10 end**************************\n");
	TerminateTask();
}
