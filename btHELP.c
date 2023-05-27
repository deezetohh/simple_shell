#include "bthead.h"
/**
 * 
 * 
*/
int btHelp(char **args __attribute__((unused)), char *K __attribute__((unused)))
{
    const char *message[] = {
        "Welcome to the btshell!\n",
        "Available commands:\n",
        "1. cd: Change directory\n",
        "2. help: Display available commands\n",
        "3. exit: Exit the shell\n",
        "4. env: Display environment variables\n",
        "5. ls: List files and directories\n",
        "Thank you!\n"
    };

    size_t lenmsg[] = {
        sizeof("Welcome to the btshell!\n") - 1,
        sizeof("Available commands:\n") - 1,
        sizeof("1. cd: Change directory\n") - 1,
        sizeof("2. help: Display available commands\n") - 1,
        sizeof("3. exit: Exit the shell\n") - 1,
        sizeof("4. env: Display environment variables\n") - 1,
        sizeof("5. ls: List files and directories\n") - 1,
        sizeof("Thank you!\n") - 1
    };

    long unsigned int i;
    for (i = 0; i < (int)(sizeof(message) / sizeof(message[0])); i++)
    {
        write(STDOUT_FILENO, message[i], lenmsg[i]);
    }
return(1);
}