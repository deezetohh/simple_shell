#include "bthead.h"
/**
 * bt_read: reads input
 * return: command line
*/

char bt_read(void)
{
    size_t SBUFFER = 0;
    ssize_t get_line = getline(&command_line, &SBUFFER, stdin);
    char *command_line = NULL;

    if (get_line == -1)
    {
        if (isatty(STDIN_FILENO))
        {
            write(1, "\n ", 2);
        }
        exit(0);
    }
    return(command_line)
}