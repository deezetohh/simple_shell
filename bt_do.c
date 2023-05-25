#include "bthead.h"
/**
 * bt_do: starts shell
 * @btshell: name of shell
 * @arguments: argument list
 * return: 1 = continue and 0 = stop
*/

int bt_do(char **arguments, char btshell)
{
    btBUILDt bt_BUILDcom[] = {
        {NULL, NULL},
        {"cd", btCD},
        {"exit", btEXIT},
        {"env", btENV},
        {"help", btHELP},
        {"ls", btLS},
      

    };
    if (arguments[0] == NULL)
    {
        return(1);
    }
int B = 0;
while (bt_BUILDcom[B].bt_BUILDstr != NULL)
{
    if (bt_comparestr(arguments[0],bt_BUILDcom[B].bt_BUILDstr) == 0)
    {
        return(bt_BUILDcom[B].bt_BUILDf(arguments, btshell));
    }
    B++
}
return(bt_process(arguments, btshell))
}