#include "btshell.h"
/**
* main - entyr point of btshell
* @argc - count arguments
* @argv -
*/

int main(int argc, char *argv[]) {
    size_t BUFF = 0;
    char *LINE = NULL;
    int A;
    int comnum = 1;
    int shinteract;

    /* Use signal function that will ignore the signal specified by the first argument */
    signal(SIGINT, SIG_IGN);

    /* Check if the shell is in interactive or non-interactive mode */
    shinteract = isatty(STDIN_FILENO);
    if (shinteract == 0 && argc == 1) {
        ssize_t line_l;
        while ((line_l = getline(&LINE, &BUFF, stdin)) != -1) {
            write(STDOUT_FILENO, "Command: ", 9);
            write(STDOUT_FILENO, LINE, line_l);
            LINE[line_l - 1] = '\0';  /*Remove the newline character at the end*/

            /*Tokenize the command line into arguments*/
            char *args[2];
            args[0] = LINE;
            args[1] = NULL;

            /*Fork a new process to execute the command*/
            pid_t pid = fork();
            if (pid < 0) {
                perror("fork");
                exit(EXIT_FAILURE);
            } else if (pid == 0) {
                    /*Child process*/
                execve(args[0], args, NULL);
                 /*If the command execution failed, print an error message*/
                perror("execve");
                exit(EXIT_FAILURE);
            } else {
                /* Parent process */
                int status;
                waitpid(pid, &status, 0);
            }
        }
        free(LINE);
        return 0;
    }

    while (shinteract) {
        write(STDOUT_FILENO, "btshell$", 9);
        A = getline(&LINE, &BUFF, stdin);
        if (A < 0) {
            free(LINE);
            write(STDOUT_FILENO, "\n", 1);
            break;
        }
        write(STDOUT_FILENO, "Command: ", 9);
        write(STDOUT_FILENO, LINE, A);
        LINE[A - 1] = '\0';  /*Remove the newline character at the end*/

        /*Tokenize the command line into arguments*/
        char *args[2];
        args[0] = LINE;
        args[1] = NULL;

        /*Fork a new process to execute the command*/
        pid_t pid = fork();
        if (pid < 0) {
            perror("fork");
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
            /*Child process*/
            execve(args[0], args, NULL);
            /*If the command execution failed, print an error message*/
            perror("execve");
            exit(EXIT_FAILURE);
        } else {
            /* Parent process */
            int status;
            waitpid(pid, &status, 0);
        }

        comnum++;
        LINE = NULL;
    }

    return 0;
}