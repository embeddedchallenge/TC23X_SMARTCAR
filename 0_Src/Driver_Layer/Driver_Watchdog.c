/*-----Include Header File-----*/
#include "Driver_Watchdog.h"
#include "IfxCpu.h"

/*-----Define-----*/

/*-----Typedefs-----*/

/*-----Static Function Prototype-----*/

/*-----Variables-----*/

/*-----Functions-----*/
/*Init Function*/
void Driver_WatchdogInit(void)
{
    IfxScuWdt_disableCpuWatchdog (IfxScuWdt_getCpuWatchdogPassword ());
    IfxScuWdt_disableSafetyWatchdog (IfxScuWdt_getSafetyWatchdogPassword ());
}


