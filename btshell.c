#include "bthead.h"

/**
 * bt_sigdeal - catches SIGINT
 * @bt_signalnumber: signal number
 * return: no return value
 */
void bt_sigdeal(int bt_signalnumber __attribute__((unused)))
{
    write(STDOUT_FILENO, "\n$", 2);
}

/**
 * main: start of program
 * @argc: no. of arguments
 * @argv: list of command arguments
 * return: exit status
 */
int main(int argc __attribute__((unused)), char **argv)
{
    signal(SIGINT, bt_sigdeal);
    bt_run(argv[0]);
    return EXIT_SUCCESS;
}


