/****************************************************************************
 *
 * 		Copyright (C) 2005-2009 ESEC UESTC All Rights Reserved.
 ***************************************************************************/

/**
 * @file 	init.c
 * @brief   ECU OSEK task, alarm, event and message demo.
 */

#include "include.h"
#include <stdio.h>
#include <string.h>

#define TICK_100MS      1000
#define TICK_200MS      2000
#define TICK_400MS      4000
#define TICK_1000MS     10000

#define EVT_INISYN      0x01
#define EVT_RSTSYN      0x02
#define EVT_FIRSTSYN    0x04
#define EVT_SYN         0x08

#define MSG_SIZE        30

void showLogo(void);

static void sendSyncMessage(MsgType msg, TaskType comTask, const char *text)
{
	char data[MSG_SIZE];

	memset(data, 0, sizeof(data));
	strncpy(data, text, sizeof(data) - 1);
	SendMessage(msg, data);
	ActivateTask(comTask);
}

static void receiveComMessage(MsgType msg, const char *taskName)
{
	char data[MSG_SIZE];

	memset(data, 0, sizeof(data));
	ReceiveMessage(msg, data);
	printf("%s received message: %s\n", taskName, data);
}

int main(int argc, char *argv[])
{
	BSP_TimerInit();
	BSP_UartInit();
	EnableInterrupts;
	StartOS(OSDEFAULTAPPMODE);

	return 0;
}

void showLogo(void)
{
	printf("************************************************************\n");
	printf("**************** ECU OSEK EVENT AND MESSAGE ****************\n");
	printf("************************************************************\n\n");
}

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
			printf("taskState: unknown\n");
	    break;
	}
}

void printWithResource(ResourceType res, const char *msg)
{
    GetResource(res);
    printf("%s\n", msg);
    ReleaseResource(res);
}

/*************************************************
**************** Initialization tasks ************
**************************************************/

TASK(ini_LLD)
{
	showLogo();
	printf("ini_LLD running: initialize low level drivers\n");
	StartCOM();
	SetRelAlarm(Alarm100ms, TICK_100MS, 0);
	printf("ini_LLD set Alarm100ms for 100msTask\n");
	ActivateTask(HLS_ini);
	TerminateTask();
}

TASK(HLS_ini)
{
	printf("HLS_ini running: initialize HLS stage 1\n");
	SetRelAlarm(Alarm200ms, TICK_200MS, 0);
	printf("HLS_ini set Alarm200ms for 200msTask\n");
	ActivateTask(HLS_ini2);
	TerminateTask();
}

TASK(HLS_ini2)
{
	printf("HLS_ini2 running: initialize HLS stage 2\n");
	SetRelAlarm(Alarm400ms, TICK_400MS, 0);
	printf("HLS_ini2 set Alarm400ms for 400msTask\n");
	ActivateTask(ini_LLD2);
	TerminateTask();
}

TASK(ini_LLD2)
{
	printf("ini_LLD2 running: finalize initialization\n");
	SetRelAlarm(Alarm1000ms, TICK_1000MS, 0);
	printf("ini_LLD2 set Alarm1000ms for 1000msTask\n");
	TerminateTask();
}

/*************************************************
**************** Periodic tasks ******************
**************************************************/

TASK(Task100ms)
{
	printf("100msTask running: set event for HLS_inisyn\n");
	SetEvent(HLS_inisyn, EVT_INISYN);
	TerminateTask();
}

TASK(Task200ms)
{
	printf("200msTask running: set event for HLS_rstsyn\n");
	SetEvent(HLS_rstsyn, EVT_RSTSYN);
	TerminateTask();
}

TASK(Task400ms)
{
	printf("400msTask running: set event for HLS_firstsyn\n");
	SetEvent(HLS_firstsyn, EVT_FIRSTSYN);
	TerminateTask();
}

TASK(Task1000ms)
{
	printf("1000msTask running: set event for HLS_syn\n");
	SetEvent(HLS_syn, EVT_SYN);
	TerminateTask();
}

/*************************************************
**************** Synchronization tasks ***********
**************************************************/

TASK(HLS_inisyn)
{
	EventMaskType mask;

	while(1)
	{
		WaitEvent(EVT_INISYN);
		GetEvent(HLS_inisyn, &mask);
		ClearEvent(EVT_INISYN);
		printf("HLS_inisyn synchronized by 100msTask, event: 0x%lx\n", mask);
		sendSyncMessage(Msg1, comTask1, "HLS_inisyn -> comTask1");
	}
}

TASK(HLS_rstsyn)
{
	EventMaskType mask;

	while(1)
	{
		WaitEvent(EVT_RSTSYN);
		GetEvent(HLS_rstsyn, &mask);
		ClearEvent(EVT_RSTSYN);
		printf("HLS_rstsyn synchronized by 200msTask, event: 0x%lx\n", mask);
		sendSyncMessage(Msg2, comTask2, "HLS_rstsyn -> comTask2");
	}
}

TASK(HLS_firstsyn)
{
	EventMaskType mask;

	while(1)
	{
		WaitEvent(EVT_FIRSTSYN);
		GetEvent(HLS_firstsyn, &mask);
		ClearEvent(EVT_FIRSTSYN);
		printf("HLS_firstsyn synchronized by 400msTask, event: 0x%lx\n", mask);
		sendSyncMessage(Msg3, comTask3, "HLS_firstsyn -> comTask3");
	}
}

TASK(HLS_syn)
{
	EventMaskType mask;

	while(1)
	{
		WaitEvent(EVT_SYN);
		GetEvent(HLS_syn, &mask);
		ClearEvent(EVT_SYN);
		printf("HLS_syn synchronized by 1000msTask, event: 0x%lx\n", mask);
		sendSyncMessage(Msg4, comTask4, "HLS_syn -> comTask4");
	}
}

/*************************************************
**************** Communication tasks *************
**************************************************/

TASK(comTask1)
{
	receiveComMessage(Msg1, "comTask1");
	TerminateTask();
}

TASK(comTask2)
{
	receiveComMessage(Msg2, "comTask2");
	TerminateTask();
}

TASK(comTask3)
{
	receiveComMessage(Msg3, "comTask3");
	TerminateTask();
}

TASK(comTask4)
{
	receiveComMessage(Msg4, "comTask4");
	TerminateTask();
}
