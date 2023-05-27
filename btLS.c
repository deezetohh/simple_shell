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
    char **narg;
    int outcome;

    while (arguments[argC] != NULL)
    {
        argC++;
    }
   narg = malloc((argC + 2) * sizeof(char *));
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
    
    outcome = bt_process(narg, btshell);

free(narg);
return(outcome);

}