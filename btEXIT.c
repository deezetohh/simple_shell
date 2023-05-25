#include "bthead.h"
/**
 * 
 * 
*/

int btEXIT(char **C, char *D __attribute__((unused)))
{
    int eSTATUS = -1;
    for (int E = 1, C[E] != NULL; E++)
    {
        eSTATUS = bt_atoi(C[E]);
        break;
    }
    while (eSTATUS == -1)
    {
        return(-1);
    }
    return(eSTATUS);
}