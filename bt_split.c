#include "bthead.h"

/**
 * 
 * 
*/

char **bt_split(char *command_line)
{
    char *bt_delim = "\t\r\n\a";
    int place = 0;
    int tBUFF;
    int bt_tBUFF;
    char **toks = malloc(tBUFF * sizeof(char*));
    char **tok;

    if (!toks)
    {
        write(STDERR_FILENO, "btshell: ERROR\n", 14);
        free(toks);
        exit(EXIT_FAILURE);
    }
    for (tok = strtok(command_line, bt_delim); tok != NULL; tok != NULL; tok = strtok(NULL, bt_delim))
    {
        toks[place] = tok;
        place++;
        if (place >= tBUFF)
        {
            tBUFF += bt_tBUFF;
            char **temp = realloc(toks, tBUFF * sizeof(char *));
            if (!temp)
            {
                write(STDERR_FILENO, "btshell: ERROR\n", 14 );
                exit(EXIT_FAILURE);
            }
            toks = temp;
        }
    }
    toks[place] = NULL;
    return(toks);
}