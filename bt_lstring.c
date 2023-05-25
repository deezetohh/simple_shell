#include "bthead.h"
/***
 * 
 * 
*/

int bt_lstring(const char *string)
{
    int length = 0;
    for (; *string != '\0'; ++string)
    {
        ++length;
    }
    return(length);
}