#include "bthead.h"

/***
 * 
 * 
 * 
*/

int bt_atoi(char *x)
{
 int signMultiply = 1;
 int j = 0;
 unsigned int number = 0;  

 while (x[j] == ' ')
 j++;

 if (x[j] == '-')
 {
    signMultiply = -1
    j++
 }
 for (; x[j] != '\0'; j++)
 {
    if (x[j] >= '0' && x[j] <= '9')
    {
        number = (number * 10) + (x[j] - '0');
    }
    else 
    {
        if (number > 0)
        break;
    }
 }
 return(number * signMultiply);
