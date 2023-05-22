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
        char* LINE = NULL;
        size_t BUFF = 0;
        ssize_t line_l;
        while ((line_l = getline(&LINE, &BUFF, stdin)) != -1)
        {
           int nbtok = nbcount(LINE) ;
           parse(LINE, nbtok, argv, comnum);
        }
        free(LINE);
        return (0);
    }
 char c;
 bool is_delimiter(char c); 
 {
    return (c == ' ' || c == '\t' || c == '\n');
}

    while (shinteract)
    {
        write (1, "btshell$", 10);
        nbtok = 0;
        A = getline(&LINE, &BUFF, stdin);
        if (A < 0)
        {
            free(LINE);
            write(1, "\n", 1);
            break;
        }
        bool in_token = false;
        for (int j = 0; j < A; j++)
        {
            if (is_delimiter(LINE[j]))
            {
                in_token = false;
            }
            else if (!in_token)
            {
                nbtok++;
                in_token = true;
            }
        }
        parse(LINE, nbtok, argv, comnum);
        comnum++;
        LINE = NULL;
    }
return 0;
    
}