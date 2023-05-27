#include "bthead.h"
/**
 * 
 * 
*/
extern char **environ;

int btENV(char **a __attribute__((unused)), char *p __attribute__((unused)))
{
    int T = 0;
    size_t tlen;
    tlen = 0;

    {
        char *buffer;
        ssize_t btERR;
        char *ptr;

        buffer = malloc(tlen + T);
        btERR = write(STDOUT_FILENO, buffer, tlen + T);
        ptr = buffer;

        for (T = 0; environ[T] != NULL; T++)
        {
            tlen += bt_lstring(environ[T]);
        }

        if (buffer == NULL)
        {
            return (-1);
        }

        for (T = 0; environ[T] != NULL; T++)
        {
            char *src = environ[T];
            while (*src != '\0')
            {
                *ptr = *src;
                ptr++;
                src++;
            }
            *ptr = '\n';
            ptr++;
        }

        free(buffer);
        if (btERR == 0)
        {
            return (-1);
        }
    }

    return (1);
}