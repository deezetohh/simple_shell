#include "bthead.h"

/**
 * bt_comparestr - compares two strings(pointers)
 * @string1: str1
 * @string2: str2
 * Return - 0 or +z
*/

int bt_comparestr(const char *string1, const char *string2)
{
    for (; *string1 && (*string1 == *string2); string1++, string2++)
    {

    }
    return((unsigned char)(*string1) - (unsigned char)(*string2));
}