#include "bthead.h"

/**
 * 
 * 
*/

char **bt_split(char *command_line)
{
    char *bt_delim = "\t\r\n\a";
    int place = 0;
    int tBUFF = 64;
    int bt_tBUFF = 16;
    char **toks = malloc(tBUFF * sizeof(char *));
    char **temp;
    char *tok;

    if (!toks)
    {
        write(STDERR_FILENO, "btshell: ERROR\n", 15);
        exit(EXIT_FAILURE);
    }

    tok = strtok(command_line, bt_delim);
    while (tok != NULL)
    {
        toks[place] = tok;
        place++;
        if (place >= tBUFF)
        {
            tBUFF += bt_tBUFF;
            temp = realloc(toks, tBUFF * sizeof(char *));
            if (!temp)
            {
                write(STDERR_FILENO, "btshell: ERROR\n", 15);
                exit(EXIT_FAILURE);
            }
            toks = temp;
        }
        tok = strtok(NULL, bt_delim);
    }

    toks[place] = NULL;
    return toks;
}