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
/*************************************************
**************** Task1 ***************************
**************************************************
*/
TASK(Task1)
{	
	TaskType taskId;
	StatusType status;
	EventMaskType mask;
	
	GetTaskID(&taskId);

	showLogo();

	
	printf("**********************task 1 running**********************\n");
	
	ActivateTask(Task2);
	ActivateTask(Task3);	
	ActivateTask(Task4);
	ActivateTask(Task5);
	ActivateTask(Task6);
	ActivateTask(Task7);
	ActivateTask(Task8);
	ActivateTask(Task9);
	ActivateTask(Task10);
		
	
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
	
	GetTaskID(&taskId);
	
    printf("**********************task 2 running**********************\n");
	showTaskInfo(taskId); 
	

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
	
	GetTaskID(&taskId);
    printf("**********************task 4 running**********************\n");

	
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
	
	GetTaskID(&taskId);	  
    printf("**********************task 5 running**********************\n");
   	showTaskInfo(taskId); 

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
	GetTaskID(&taskId);
    printf("**********************task 6 running**********************\n");
    showTaskInfo(taskId); 

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
	
	GetTaskID(&taskId);
    
    printf("**********************task 7 running**********************\n");
    showTaskInfo(taskId); 

	
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
	
	GetTaskID(&taskId);
    
    printf("**********************task 8 running**********************\n");
    showTaskInfo(taskId); 

	
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
	
	GetTaskID(&taskId);
    
    printf("**********************task 9 running**********************\n");
    showTaskInfo(taskId); 

	
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
	
	GetTaskID(&taskId);
    
    printf("**********************task 10 running**********************\n");
    showTaskInfo(taskId); 

	
    printf("**********************task 10 end**************************\n");
    TerminateTask();
}

