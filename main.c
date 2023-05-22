#include "btshell.h"
/** 
* main - btshell entry point
* return: 0 when successful
*/

int main(char *argv[], int argc)
{
    size_t BUFF;
    BUFF = 0;
    char *LINE = NULL;
    int A;
    int nbtok = 0;
    int comnum = 1;
    int shinteract; 

/*Use signal function that will ignore the signal specified by the first argument*/
    int signal(SIGINT, SIG_IGN);

/* We now need to check if the shell is in interactive or non-interactive mode*/
    shinteract = isatty(STDIN_FILENO);
    if (shinteract == 0 && argc == 1)
    {
        signal(SIGINT, deal_signt);
    }
    getline(&LINE, &BUFF, stdin);
   
    

}