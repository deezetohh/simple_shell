#include "bthead.h"

/***
 * 
 * 
 * 
*/

int bt_atoi(char *r)
{
 int signMultiply = 1;
 int j = 0;
 unsigned int number = 0;  

 while (r[j] == ' ')
 j++;

 if (r[j] == '-')
 {
    signMultiply = -1;
    j++;
 }
 for (; r[j] != '\0'; j++)
 {
    if (r[j] >= '0' && r[j] <= '9')
    {
        number = (number * 10) + (r[j] - '0');
    }
    else 
    {
        if (number > 0)
        break;
    } 
 }
 return(number * signMultiply);
}

