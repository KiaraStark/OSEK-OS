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
	printf("activate task4,5,6,7\n");
	ActivateTask(Task4);
	ActivateTask(Task5);
	ActivateTask(Task6);
	ActivateTask(Task7);

	printf("set TaskAlarm...\n");	
	SetRelAlarm(TaskAlarm, 3000, 10000);
	
	printf("task1 wait event: 0x20\n");
	WaitEvent(0x20);
	printf("task1 get event 0x20 from TaskAlarm\n");

	printf("task1 cancel TaskAlarm...\n");
	CancelAlarm(TaskAlarm);
	
	printf("task1 set event 0x30 for task2...\n");
	SetEvent(Task2, 0x30);

	printf("task1 wait event: 0x90\n");
	WaitEvent(0x90);
	printf("task1 get the last event 0x90...\n");

	printf("activate task8...\n");
	ActivateTask(Task8);

 	printf("**********************task 1 end**************************\n"); 
	printf("Event chain (Task1 -> Task7 -> Task1) complete.\n");
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

	printf("task3 set event 0x50 for task4...\n");
	SetEvent(Task4, 0x50);

	
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
	GetTaskID(&taskId);
    printf("**********************task 4 running**********************\n");
	printf("task4 wait event: 0x50\n");
	WaitEvent(0x50);
	printf("task4 get event 0x50...\n");

	printf("task4 set event 0x60 for task5...\n");
	SetEvent(Task5, 0x60);
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
	GetTaskID(&taskId);
    printf("**********************task 5 running**********************\n");
	printf("task5 wait event: 0x60\n");
	WaitEvent(0x60);
	printf("task5 get event 0x60...\n");

	printf("task5 set event 0x70 for task6...\n");
	SetEvent(Task6, 0x70);

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
	GetTaskID(&taskId);
    printf("**********************task 6 running**********************\n");

	printf("task6 wait event: 0x70\n");
	WaitEvent(0x70);
	printf("task6 get event 0x70...\n");

	printf("task6 set event 0x80 for task7...\n");
	SetEvent(Task7, 0x80);
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
	GetTaskID(&taskId);
    printf("**********************task 7 running**********************\n");
	printf("task7 wait event: 0x80\n");
	WaitEvent(0x80);
	printf("task7 get event 0x80...\n");

	printf("task7 set event 0x90 for task1...\n");
	SetEvent(Task1, 0x90);

	printf("**********************task 7 end**************************\n");
	TerminateTask();
}

// 全局共享通信数据
volatile int sharedCommunicationData = 0;

/*************************************************
**************** Task8 ***************************
**************************************************
*/
TASK(Task8)
{ 
	TaskType taskId;
	GetTaskID(&taskId);
    printf("**********************task 8 running**********************\n");
	showTaskInfo(taskId); 

	// Task 8 产生初始数据并启动通信链
	sharedCommunicationData = 100;
	printf("task8 send data: %d to task9\n", sharedCommunicationData);
	
	// 激活 Task 9，将数据和执行权传递给它
	ActivateTask(Task9);

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
	int receivedData;
	GetTaskID(&taskId);
    printf("**********************task 9 running**********************\n");
	
	// 接收数据并处理
	receivedData = sharedCommunicationData;
	printf("task9 received data: %d\n", receivedData);
	sharedCommunicationData = receivedData + 1;
	printf("task9 send data: %d to task10\n", sharedCommunicationData);
	
	ActivateTask(Task10);

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
	int receivedData;
	GetTaskID(&taskId);
    printf("**********************task 10 running**********************\n");
	
	receivedData = sharedCommunicationData;
	printf("task10 received data: %d\n", receivedData);
	sharedCommunicationData = receivedData + 1;
	printf("task10 send data: %d to task11\n", sharedCommunicationData);
	
	ActivateTask(Task11);

	printf("**********************task 10 end**************************\n");
	TerminateTask();
}

/*************************************************
**************** Task11 ***************************
**************************************************
*/
TASK(Task11)
{ 
	TaskType taskId;
	int receivedData;
	GetTaskID(&taskId);
    printf("**********************task 11 running**********************\n");
	
	receivedData = sharedCommunicationData;
	printf("task11 received data: %d\n", receivedData);
	sharedCommunicationData = receivedData + 1;
	printf("task11 send data: %d to task12\n", sharedCommunicationData);
	
	ActivateTask(Task12);

	printf("**********************task 11 end**************************\n");
	TerminateTask();
}

/*************************************************
**************** Task12 ***************************
**************************************************
*/
TASK(Task12)
{ 
	TaskType taskId;
	int receivedData;
	GetTaskID(&taskId);
    printf("**********************task 12 running**********************\n");
	
	receivedData = sharedCommunicationData;
	printf("task12 received data: %d\n", receivedData);
	sharedCommunicationData = receivedData + 1;
	printf("task12 send data: %d to task13\n", sharedCommunicationData);
	
	ActivateTask(Task13);

	printf("**********************task 12 end**************************\n");
	TerminateTask();
}

/*************************************************
**************** Task13 ***************************
**************************************************
*/
TASK(Task13)
{ 
	TaskType taskId;
	int receivedData;
	GetTaskID(&taskId);
    printf("**********************task 13 running**********************\n");
	
	receivedData = sharedCommunicationData;
	printf("task13 received data: %d\n", receivedData);
	sharedCommunicationData = receivedData + 1;
	printf("task13 send data: %d to task14\n", sharedCommunicationData);
	
	ActivateTask(Task14);

	printf("**********************task 13 end**************************\n");
	TerminateTask();
}

/*************************************************
**************** Task14 ***************************
**************************************************
*/
TASK(Task14)
{ 
	TaskType taskId;
	int receivedData;
	GetTaskID(&taskId);
    printf("**********************task 14 running**********************\n");
	
	receivedData = sharedCommunicationData;
	printf("task14 finally received data: %d\n", receivedData);
	printf("Communication chain (Task8 -> Task14) complete.\n");

	printf("**********************task 14 end**************************\n");
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