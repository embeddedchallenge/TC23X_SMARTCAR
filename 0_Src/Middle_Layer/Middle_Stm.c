/*-----Include Header File-----*/
#include "Middle_Stm.h"
#include "Driver_Stm.h"

/*-----Define-----*/

/*-----Typedefs-----*/

/*-----Static Function Prototype-----*/

/*-----Variables-----*/

/*-----Functions-----*/
/*Callback Function*/
void Middle_RegTimerCallbackFnc(void (*pMiddle_RegCallbackFnc)(void))
{
    Driver_RegStm0CallbackFnc(pMiddle_RegCallbackFnc);
}
