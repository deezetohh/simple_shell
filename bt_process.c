#include "bthead.h"
/**
 * 
 * 
*/
int bt_process(char **arguments, char *btshell)
{
    int BTSTATUS;
    pid_t bt_pid;

    bt_pid = fork();

    if (bt_pid == 0)
    {
        if (execve(arguments[0], arguments, NULL)== -1)
        {
            perror(btshell);
            exit(EXIT_FAILURE);
        }
    }
    else if (bt_pid < 0)
    {
        perror("btshell");
        return(-1);
    }
    else
    {
        do
        {
            if(waitpid(bt_pid, &BTSTATUS, WUNTRACED) == 1)
            {
                perror("waitpid");
                return(-1);
            }
        }
        while (!WIFEXITED(BTSTATUS) && !WIFSIGNALED(BTSTATUS));
        
    }
    if (WIFEXITED(BTSTATUS))
    {
        return(WIFEXITED(BTSTATUS));
    }
    else if (WIFSIGNALED(BTSTATUS))
    {
        return(WTERMSIG(BTSTATUS));
    }
    else
    {
        return(-1)
    }
}