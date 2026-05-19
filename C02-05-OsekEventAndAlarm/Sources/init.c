/****************************************************************************
 *
 *      Copyright (C) 2005-2009 ESEC UESTC All Rights Reserved.
 ***************************************************************************/

/**
 * @file    init.c
 * @brief
 * @date
 */

#include "include.h"
#include <stdio.h>
#include <string.h>

void showLogo();

int main(int argc ,char *argv[])
{
    //初始化串口
    BSP_UartInit();
    //初始化定时器 
    BSP_TimerInit();
    EnableInterrupts;
    
    StartOS(OSDEFAULTAPPMODE);

    return 0;
}

//show LOGO
void showLogo()
{
    printf("************************************************************\n");
    printf("****************ESEC OSEK EVENT AND ALARM*******************\n");
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

    GetTaskID(&taskId);

    showLogo();

    printf("**********************task 1 running**********************\n");

    //show task information
    showTaskInfo(taskId); 

    // 设置警报器1-8开启
    printf("task 1 sets alarms for other tasks...\n");
    SetRelAlarm(Alarm1, 10, 0);
    SetRelAlarm(Alarm2, 20, 0);
    SetRelAlarm(Alarm3, 30, 0);
    SetRelAlarm(Alarm4, 40, 0);
    SetRelAlarm(Alarm5, 50, 0);
    SetRelAlarm(Alarm6, 60, 0);
    SetRelAlarm(Alarm7, 70, 0);
    SetRelAlarm(Alarm8, 80, 0);

    // 唤醒任务10
    printf("task 1 activates Task10...\n");
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

    GetTaskID(&taskId);

    printf("**********************task 2 running**********************\n");
    showTaskInfo(taskId); 

    // 获取资源 R1
    printf("task2 requests Resource R1\n");
    GetResource(R1);

    // 任务2是被Alarm1激活的
    printf("Task 2 activated by Alarm1 and executing.\n");

    // 释放资源 R1
    printf("task2 releases Resource R1\n");
    ReleaseResource(R1);

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
    
    // 获取资源 R2
    printf("task3 requests Resource R2\n");
    GetResource(R2);

    // 任务3是被Alarm2激活的
    printf("Task 3 activated by Alarm2 and executing.\n");

    // 释放资源 R2
    printf("task3 releases Resource R2\n");
    ReleaseResource(R2);

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
    showTaskInfo(taskId); 
    
    // 获取资源 R3
    printf("task4 requests Resource R3\n");
    GetResource(R3);

    // 任务4是被Alarm3激活的
    printf("Task 4 activated by Alarm3 and executing.\n");

    // 释放资源 R3
    printf("task4 releases Resource R3\n");
    ReleaseResource(R3);

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
    showTaskInfo(taskId); 

    // 获取资源 R1
    printf("task5 requests Resource R1\n");
    GetResource(R1);

    // 任务5是被Alarm4激活的
    printf("Task 5 activated by Alarm4 and executing.\n");

    // 释放资源 R1
    printf("task5 releases Resource R1\n");
    ReleaseResource(R1);

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
    showTaskInfo(taskId); 

    // 等待 Alarm5 设置的事件
    printf("task6 waiting for Event 0x01 from Alarm5...\n");
    WaitEvent(0x01);
    printf("task6 event received!\n");

    // 获取资源 R2
    printf("task6 requests Resource R2\n");
    GetResource(R2);

    // 任务6执行
    printf("Task 6 reactivated by Alarm5 Event and executing.\n");

    // 释放资源 R2
    printf("task6 releases Resource R2\n");
    ReleaseResource(R2);

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
    showTaskInfo(taskId); 
    
    // 等待 Alarm6 设置的事件
    printf("task7 waiting for Event 0x01 from Alarm6...\n");
    WaitEvent(0x01);
    printf("task7 event received!\n");

    // 获取资源 R3
    printf("task7 requests Resource R3\n");
    GetResource(R3);

    // 任务7执行
    printf("Task 7 reactivated by Alarm6 Event and executing.\n");

    // 释放资源 R3
    printf("task7 releases Resource R3\n");
    ReleaseResource(R3);

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

    GetTaskID(&taskId);
    printf("**********************task 8 running**********************\n");
    showTaskInfo(taskId); 

    // 等待 Alarm7 设置的事件
    printf("task8 waiting for Event 0x01 from Alarm7...\n");
    WaitEvent(0x01);
    printf("task8 event received!\n");

    // 获取资源 R1
    printf("task8 requests Resource R1\n");
    GetResource(R1);

    // 任务8执行
    printf("Task 8 reactivated by Alarm7 Event and executing.\n");

    // 释放资源 R1
    printf("task8 releases Resource R1\n");
    ReleaseResource(R1);

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

    GetTaskID(&taskId);
    printf("**********************task 9 running**********************\n");
    showTaskInfo(taskId); 

    // 等待 Alarm8 设置的事件
    printf("task9 waiting for Event 0x01 from Alarm8...\n");
    WaitEvent(0x01);
    printf("task9 event received!\n");

    // 获取资源 R2
    printf("task9 requests Resource R2\n");
    GetResource(R2);

    // 任务9执行
    printf("Task 9 reactivated by Alarm8 Event and executing.\n");

    // 释放资源 R2
    printf("task9 releases Resource R2\n");
    ReleaseResource(R2);

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

    GetTaskID(&taskId);
    printf("**********************task 10 running**********************\n");
    showTaskInfo(taskId); 

    // 获取资源 R3
    printf("task10 requests Resource R3\n");
    GetResource(R3);

    // 任务10直接由初始化任务激活
    printf("Task 10 activated directly by Task1 and executing.\n");

    // 释放资源 R3
    printf("task10 releases Resource R3\n");
    ReleaseResource(R3);

    printf("**********************task 10 end**************************\n");
    TerminateTask();
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
