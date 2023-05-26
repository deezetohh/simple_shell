#include "bthead.h"
/**
 * 
 * 
*/
extern char **environ;

int hsh_env(char **a __attribute__((unused)), char *p __attribute__((unused)))
{
    int T;
    size_t tlen;
    tlen = 0; 

    for (T = 0; environ[T] != NULL; T++)
    {
        tlen += bt_lstring(environ[T]);
    }
    char *buffer = malloc(tlen + T);
    if (buffer == NULL)
    {
        return(-1);
    }
    char *ptr = buffer;
    for (T = 0, environ[T] != NULL, T++)
    {
        char *src = environ[T]; 
        while (*src !='\0')
        {
            *ptr = *src;
            ptr++;
            src++
            ;
        }
        *ptr = '\n';
        ptr++;
    }
    ssize_t btERR = write(STDOUT_FILENO, buffer, tlen + T);
    free(buffer);
    if (btERR == 0)
    {
        return(-1);
    }
    return(1);
}