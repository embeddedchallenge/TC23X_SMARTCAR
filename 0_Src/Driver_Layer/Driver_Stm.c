/*-----Include Header File-----*/
#include "Driver_Stm.h"
#include "IfxStm.h"
#include "IfxCpu_Irq.h"
#include "Common.h"

/*-----Define-----*/
#define ISR_PRIORITY_STM_INT0       40 /**< \brief Define the System Timer Interrupt priority.  */
#define STM_TIME_1MS                100000u

/*-----Typedefs-----*/
typedef struct stm_info
{
    Ifx_STM             *stmSfr;            /**< \brief Pointer to Stm register base */
    IfxStm_CompareConfig stmConfig;         /**< \brief Stm Configuration structure */
}STM_INFO;

/*-----Static Function Prototype-----*/
static void Driver_Stm0Init(void);

/*-----Variables-----*/
STM_INFO gstnuStmInfo;
void (*Driver_Stm0CallbackFnc)(void);

/*-----Functions-----*/
/*Interrupt Define*/
IFX_INTERRUPT(STM_Int0Handler, 0, ISR_PRIORITY_STM_INT0);

/*Interrupt Service Routine*/
void STM_Int0Handler(void)
{
    IfxStm_clearCompareFlag(gstnuStmInfo.stmSfr, gstnuStmInfo.stmConfig.comparator);
    IfxStm_increaseCompare(gstnuStmInfo.stmSfr, gstnuStmInfo.stmConfig.comparator, STM_TIME_1MS);

    /*Stm Collback Function*/
    Driver_Stm0CallbackFnc();
}

/*Callback Function*/
void Driver_RegStm0CallbackFnc(void (*pDriver_RegCallbackFnc)(void))
{
    Driver_Stm0CallbackFnc = pDriver_RegCallbackFnc;
}

/*Init Function*/
void Driver_StmInit(void)
{
    Driver_Stm0Init();
}

static void Driver_Stm0Init(void)
{
    IfxStm_enableOcdsSuspend(&MODULE_STM0);

    gstnuStmInfo.stmSfr = &MODULE_STM0;
    IfxStm_initCompareConfig(&gstnuStmInfo.stmConfig);

    gstnuStmInfo.stmConfig.triggerPriority = ISR_PRIORITY_STM_INT0;
    gstnuStmInfo.stmConfig.typeOfService   = IfxSrc_Tos_cpu0;
    gstnuStmInfo.stmConfig.ticks           = STM_TIME_1MS*10u;            /*1ms*10 = 10ms*/

    IfxStm_initCompare(gstnuStmInfo.stmSfr, &gstnuStmInfo.stmConfig);
}
