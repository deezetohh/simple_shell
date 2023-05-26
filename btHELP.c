#include "bthead.h"
/**
 * 
 * 
*/
int btHelp(char **args __attribute__((unused)), char *K __attribute__((unused)))
{
    const char *message[] = {
     "Welcome to the  btshell!\n",
        "Available commands:\n",
        "1. cd: Change directory\n",
        "2. help: Display available commands\n",
        "3. exit: Exit the shell\n",
        "4. env: Display environment variables\n",
        "5. ls: List files and directories\n",
        "Thank you!\n"      
    };

    size_t lenmsg[] = {
        bt_lstring(message[0]),
        bt_lstring(message[1]),
        bt_lstring(message[2]),
        bt_lstring(message[3]),
        bt_lstring(message[4]),
        bt_lstring(message[5]),
        bt_lstring(message[6]),
        bt_lstring(message[7])
    };
    write(STDOUT_FILENO, message[0], lenmsg[0]);
    write(STDOUT_FILENO, message[1], lenmsg[1]);
    write(STDOUT_FILENO, message[2], lenmsg[2]);
    write(STDOUT_FILENO, message[3], lenmsg[3]);
    write(STDOUT_FILENO, message[4], lenmsg[4]);
    write(STDOUT_FILENO, message[5], lenmsg[5]);
    write(STDOUT_FILENO, message[6], lenmsg[6]);
    write(STDOUT_FILENO, message[7], lenmsg[7]);

return(1);
}