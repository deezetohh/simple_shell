#include "bthead.h"
/**
 * 
 * 
*/
int btHelp(char **args __attribute__((unused)), char *K __attribute__((unused)))
{
    int i;
    i = 0; 
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
        sizeof("Welcome to the btshell!\n"),
        sizeof("Available commands:\n"),
        sizeof("1. cd: Change directory\n"),
        sizeof("2. help: Display available commands\n"),
        sizeof("3. exit: Exit the shell\n"),
        sizeof("4. env: Display environment variables\n"),
        sizeof("5. ls: List files and directories\n"),
        sizeof("Thank you!\n")
    };

    for (i = 0; i < (sizeof(message) / sizeof(message[0])); i++)
    {
        write(STDOUT_FILENO, message[i], lenmsg[i]);
    }
return(1);
}