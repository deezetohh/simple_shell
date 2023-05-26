#include "bthead.h"
/***
 * 
 * 
 * 
*/

int btLS(char **arguments, char *btshell)
{
    int Q;
    int argC = 0;

    while (arguments[argC] != NULL)
    {
        argC++;
    }
    char **narg = malloc((argC + 2) * sizeof(char *));
    if (narg == NULL)
    {
        return(1);
    }
    narg[0] = "/bin/ls";
    for(Q = 0; Q < argC; Q++)
    {
        narg[Q + 1] = arguments[Q];
    }
    narg[argC + 1] = NULL;
    int outcome;
    outcome = bt_process(narg, btshell);

free(narg);
return(outcome);

}