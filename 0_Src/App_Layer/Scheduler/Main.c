/*-----Include Header File-----*/
#include "Main.h"
#include "Driver_Sys.h"
#include "Scheduler.h"
#include "IfxCpu.h"

/*-----Define-----*/

/*-----Typedefs-----*/

/*-----Static Function Prototype-----*/
static void RegisterCallback(void);

/*-----Variables-----*/

/*-----Functions-----*/
int main(void)
{
    /*System Initialization*/
    Driver_Sys();

    /*Register Callback Function*/
    RegisterCallback();

    /*Enable the global interrupts of this CPU*/
    IfxCpu_enableInterrupts();
    
    while(1u)
    {
        Scheduler();
    }

    return 0;
}

static void RegisterCallback(void)
{
    /*Register Scheduler Callback Function*/
    Scheduler_Init();
}