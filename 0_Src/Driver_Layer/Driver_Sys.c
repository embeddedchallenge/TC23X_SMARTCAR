/*-----Include Header File-----*/
#include "Driver_Sys.h"
#include "Driver_Watchdog.h"
#include "Driver_Stm.h"

/*-----Define-----*/

/*-----Typedefs-----*/

/*-----Static Function Prototype-----*/

/*-----Variables-----*/

/*-----Functions-----*/
void Driver_Sys(void)
{
    /*Watchdog Init*/
    Driver_WatchdogInit();
    /*System Timer Moudle Init*/
    Driver_StmInit();
}

