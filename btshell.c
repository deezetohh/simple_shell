#include "bthead.h"

/**
 * bt_sigdeal -  catches SIGINT
 * @bt_signalnumber - %d
 * return - no return value
*/
void bt_sigdeal(int bt_signalnumber __attribute__((unused)))
{
    write(STDOUT_FILENO, "\n$" 4);
}

/**
 * main: start of program
 * @argc - no. of arguments 
 * @argv - list of command arguments
 * return - exit
*/

int main(int argc __atribute__((unused)), char **argv)
{
    int signal(SIGINT, bt_sigdeal);
    bt_run(argv[0]);
    return(EXIT_SUCCESS)
}


