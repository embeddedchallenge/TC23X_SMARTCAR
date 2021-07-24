/*-----Include Header File-----*/
#include "Scheduler.h"
#include "Middle_Stm.h"
#include "Common.h"

/*-----Define-----*/

/*-----Typedefs-----*/
typedef struct
{
    uint8_t u8nuScheduler1msFlag;
    uint8_t u8nuScheduler5msFlag;
    uint8_t u8nuScheduler10msFlag;
    uint8_t u8nuScheduler50msFlag;
    uint8_t u8nuScheduler100msFlag;
    uint8_t u8nuScheduler200msFlag;
    uint8_t u8nuScheduler500msFlag;
    uint8_t u8nuScheduler1sFlag;    
}AppTask;

/*-----Static Function Prototype-----*/
static void AppNoTimeTask(void);
static void AppTask1ms(void);
static void AppTask5ms(void);
static void AppTask10ms(void);
static void AppTask50ms(void);
static void AppTask100ms(void);
static void AppTask200ms(void);
static void AppTask500ms(void);
static void AppTask1s(void);

static void TaskSchedulerCallbackFnc(void);

/*-----Variables-----*/
AppTask stnuAppTaskInfo;
uint32_t u32nuScheduler1msCounter = 0u;

/*-----Functions-----*/
/*NoTime Taksing*/
static void AppNoTimeTask(void)
{

}

/*AppTask 1ms*/
static void AppTask1ms(void)
{

}


/*AppTask 5ms*/
static void AppTask5ms(void)
{

}


/*AppTask 10ms*/
static void AppTask10ms(void)
{

}

/*AppTask 50ms*/
static void AppTask50ms(void)
{

}

/*AppTask 100ms*/
static void AppTask100ms(void)
{

}

/*AppTask 200ms*/
static void AppTask200ms(void)
{
}

/*AppTask 500ms*/
static void AppTask500ms(void)
{

}

/*AppTask 1s*/
static void AppTask1s(void)
{    

}


/*CallbackFunc*/
static void TaskSchedulerCallbackFnc(void)
{
    u32nuScheduler1msCounter++;

    stnuAppTaskInfo.u8nuScheduler1msFlag = ON;

    if((u32nuScheduler1msCounter % 1u) == 0u)
    {
        stnuAppTaskInfo.u8nuScheduler1msFlag = ON;
    }

    if((u32nuScheduler1msCounter % 5u) == 0u)
    {
        stnuAppTaskInfo.u8nuScheduler5msFlag = ON;
    }

    if((u32nuScheduler1msCounter % 10u) == 0u)
    {
        stnuAppTaskInfo.u8nuScheduler10msFlag = ON;
    }

    if((u32nuScheduler1msCounter % 50u) == 0u)
    {
        stnuAppTaskInfo.u8nuScheduler50msFlag = ON;
    }

    if((u32nuScheduler1msCounter % 100u) == 0u)
    {
        stnuAppTaskInfo.u8nuScheduler100msFlag = ON;
    }

    if((u32nuScheduler1msCounter % 200u) == 0u)
    {
        stnuAppTaskInfo.u8nuScheduler200msFlag = ON;
    }

    if((u32nuScheduler1msCounter % 500u) == 0u)
    {
        stnuAppTaskInfo.u8nuScheduler500msFlag = ON;
    }

    if((u32nuScheduler1msCounter % 1000u) == 0u)
    {
        stnuAppTaskInfo.u8nuScheduler1sFlag = ON;        
    }

    if(u32nuScheduler1msCounter >= 3000u) /*Reset at 3Sec*/ 
    {
        u32nuScheduler1msCounter = 0u;
    }
}
/*---------------------Register CallbackFunc--------------------------*/
void Scheduler_Init(void)
{
    Middle_RegTimerCallbackFnc(TaskSchedulerCallbackFnc);
}

/*---------------------Scheduler--------------------------*/
void Scheduler(void)
{
    AppNoTimeTask();
    
    if(stnuAppTaskInfo.u8nuScheduler1msFlag == ON)
    {
        stnuAppTaskInfo.u8nuScheduler1msFlag = OFF;
        AppTask1ms();

        if(stnuAppTaskInfo.u8nuScheduler5msFlag == ON)
        {
            stnuAppTaskInfo.u8nuScheduler5msFlag = OFF;
            AppTask5ms();
        }

        if(stnuAppTaskInfo.u8nuScheduler10msFlag == ON)
        {
            stnuAppTaskInfo.u8nuScheduler10msFlag = OFF;
            AppTask10ms();
        }

        if(stnuAppTaskInfo.u8nuScheduler50msFlag == ON)
        {
            stnuAppTaskInfo.u8nuScheduler50msFlag = OFF;
            AppTask50ms();
        }

        if(stnuAppTaskInfo.u8nuScheduler100msFlag == ON)
        {
            stnuAppTaskInfo.u8nuScheduler100msFlag = OFF;
            AppTask100ms();
        }

        if(stnuAppTaskInfo.u8nuScheduler200msFlag == ON)
        {
            stnuAppTaskInfo.u8nuScheduler200msFlag = OFF;
            AppTask200ms();            
        }

        if(stnuAppTaskInfo.u8nuScheduler500msFlag == ON)
        {
            stnuAppTaskInfo.u8nuScheduler500msFlag = OFF;
            AppTask500ms();
        }

        if(stnuAppTaskInfo.u8nuScheduler1sFlag == ON)
        {
            stnuAppTaskInfo.u8nuScheduler1sFlag = OFF;
            AppTask1s();
        }
    }
}
