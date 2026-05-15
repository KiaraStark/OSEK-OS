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


 	BSP_UartInit(); 	
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
	printf("*********************ESEC OSEK RESOURCE*********************\n");
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
	StatusType status;
	
	GetTaskID(&taskId);

	printf("**********************task 1 running**********************\n");
	showTaskInfo(taskId); 
	
	
    //get Resource7
    status = GetResource(Resource7);
    printf("task1 get resource7...\n");
    if(status != E_OK)
    {
    	printf("task1 get resource7 error: %d\n", status);	
    }
    //get Resource1
    status = GetResource(Resource1);
    printf("task1 get resource1...\n");
    if(status != E_OK)
    {
    	printf("task1 get resource1 error: %d\n", status);	
    }
    
    //release Resource1
    printf("task1 release resource1...\n");
    status = ReleaseResource(Resource1);
    if(status != E_OK)
    {
    	printf("task1 release resource1 error: %d\n", status);	
    }
    
    //release Resource7
    printf("task1 release resource7...\n");
    status = ReleaseResource(Resource7);   
    if(status != E_OK)
    {
    	printf("task1 release resource7 error: %d\n", status);	
    }
    
    
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
    
	//get Resource1
    status = GetResource(Resource1);
    printf("task2 get resource1...\n");
    if(status != E_OK)
    {
    	printf("task2 get resource1 error: %d\n", status);	
    }
    //get Resource2
    status = GetResource(Resource2);
    printf("task2 get resource2...\n");
    if(status != E_OK)
    {
    	printf("task2 get resource2 error: %d\n", status);	
    }
    
    //activate task1
    printf("activate task1...\n");
    ActivateTask(Task1);
    
    //release Resource2
    printf("task2 release resource2...\n");
    status = ReleaseResource(Resource2);
    if(status != E_OK)
    {
    	printf("task2 release resource2 error: %d\n", status);	
    }
    
    //release Resource1
    printf("task2 release resource1...\n");
    status = ReleaseResource(Resource1);   
    if(status != E_OK)
    {
    	printf("task2 release resource1 error: %d\n", status);	
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
	
	GetTaskID(&taskId);
    printf("**********************task 3 running**********************\n");
    showTaskInfo(taskId); 
   
   //get Resource2
    status = GetResource(Resource2);
    printf("task3 get resource2...\n");
    if(status != E_OK)
    {
    	printf("task3 get resource2 error: %d\n", status);	
    }
    //get Resource3
    status = GetResource(Resource3);
    printf("task3 get resource3...\n");
    if(status != E_OK)
    {
    	printf("task3 get resource3 error: %d\n", status);	
    }
    
    //activate task2
    printf("activate task2...\n");
    ActivateTask(Task2);
    
    //release Resource3
    printf("task3 release resource3...\n");
    status = ReleaseResource(Resource3);
    if(status != E_OK)
    {
    	printf("task3 release resource3 error: %d\n", status);	
    }
    
    //release Resource2
    printf("task3 release resource2...\n");
    status = ReleaseResource(Resource2);   
    if(status != E_OK)
    {
    	printf("task3 release resource2 error: %d\n", status);	
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
	
	GetTaskID(&taskId);
	
    printf("**********************task 4 running**********************\n");
    showTaskInfo(taskId); 
    
    //get Resource3
    status = GetResource(Resource3);
    printf("task4 get resource3...\n");
    if(status != E_OK)
    {
    	printf("task4 get resource3 error: %d\n", status);	
    }
    //get Resource4
    status = GetResource(Resource4);
    printf("task4 get resource4...\n");
    if(status != E_OK)
    {
    	printf("task4 get resource4 error: %d\n", status);	
    }
    
    //activate task3
    printf("activate task3...\n");
    ActivateTask(Task3);
    
    //release Resource4
    printf("task4 release resource4...\n");
    status = ReleaseResource(Resource4);
    if(status != E_OK)
    {
    	printf("task4 release resource4 error: %d\n", status);	
    }
    
    //release Resource3
    printf("task4 release resource3...\n");
    status = ReleaseResource(Resource3);   
    if(status != E_OK)
    {
    	printf("task4 release resource3 error: %d\n", status);	
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
	
	GetTaskID(&taskId);	  
    printf("**********************task 5 running**********************\n");
   	showTaskInfo(taskId); 
    
    //get Resource4
    status = GetResource(Resource4);
    printf("task5 get resource4...\n");
    if(status != E_OK)
    {
    	printf("task5 get resource4 error: %d\n", status);	
    }
    //get Resource5
    status = GetResource(Resource5);
    printf("task5 get resource5...\n");
    if(status != E_OK)
    {
    	printf("task5 get resource5 error: %d\n", status);	
    }
    
    //activate task4
    printf("activate task4...\n");
    ActivateTask(Task4);
    
    //release Resource5
    printf("task5 release resource5...\n");
    status = ReleaseResource(Resource5);
    if(status != E_OK)
    {
    	printf("task5 release resource5 error: %d\n", status);	
    }
    
    //release Resource4
    printf("task5 release resource4...\n");
    status = ReleaseResource(Resource4);   
    if(status != E_OK)
    {
    	printf("task5 release resource4 error: %d\n", status);	
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
	
	GetTaskID(&taskId);
    printf("**********************task 6 running**********************\n");
    showTaskInfo(taskId); 
    
    //get Resource5
    status = GetResource(Resource5);
    printf("task6 get resource5...\n");
    if(status != E_OK)
    {
    	printf("task6 get resource5 error: %d\n", status);	
    }
    //get Resource6
    status = GetResource(Resource6);
    printf("task6 get resource6...\n");
    if(status != E_OK)
    {
    	printf("task6 get resource6 error: %d\n", status);	
    }
    
    //activate task5
    printf("activate task5...\n");
    ActivateTask(Task5);
    
    //release Resource6
    printf("task6 release resource6...\n");
    status = ReleaseResource(Resource6);
    
    if(status != E_OK)
    {
    	printf("task6 release resource6 error: %d\n", status);	
    }
    
    //release Resource5
    printf("task6 release resource5...\n");
    status = ReleaseResource(Resource5);
    
    if(status != E_OK)
    {
    	printf("task6 release resource5 error: %d\n", status);	
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
	GetTaskID(&taskId);
    	
    showLogo();
    	
    printf("**********************task 7 running**********************\n");
    showTaskInfo(taskId); 
    
    //get Resource6
    status = GetResource(Resource6);
    printf("task7 get resource6...\n");
    if(status != E_OK)
    {
    	printf("task7 get resource6 error: %d\n", status);	
    }
    //get Resource7
    status = GetResource(Resource7);
    printf("task7 get resource7...\n");
    if(status != E_OK)
    {
    	printf("task7 get resource7 error: %d\n", status);	
    }
    
    //activate task6
    printf("activate task6...\n");
    ActivateTask(Task6);
    
    //release Resource7
    printf("task7 release resource7...\n");
    status = ReleaseResource(Resource7);
    if(status != E_OK)
    {
    	printf("task7 release resource7 error: %d\n", status);	
    }
    
    //release Resource6
    printf("task7 release resource6...\n");
    status = ReleaseResource(Resource6);
    if(status != E_OK)
    {
    	printf("task7 release resource6 error: %d\n", status);	
    }
    
    printf("**********************task 7 end**************************\n");
    TerminateTask();
}

/*************************************************
**************** Task Idle ***********************
**************************************************
*/
TASK(Idle)
{
	ShutdownOS(0xff);
}

