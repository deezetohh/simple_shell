#include "bthead.h"

/**
 * 
 * 
*/
int btCD(char **arguments, char *btshell)
{
    if (arguments[1] == NULL)
    {
        write(STDOUT_FILENO, btshell, bt_lstring(btshell));
        write(STDOUT_FILENO,": Error: Please provide a directory argument\n", bt_lstring(": Error: Please provide a directory argument\n"));
        return(0);
    }
    else
    {
        if(chdir(arguments[1]) != 0 )
        {
            perror(btshell);
            return(0);
        }
    }
    return(1);
}