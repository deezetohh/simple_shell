#include "btshell.h"
/** 
* main - btshell entry point
* return: 0 when successful
*/
#define MAX_LINE_LENGTH 1024

bool is_delimiter(char c) {
    return (c == ' ' || c == '\t' || c == '\n');
}

int count_tokens(const char *line) {
    int count = 0;
    bool in_token = false;

    for (int i = 0; line[i] != '\0'; i++) {
        if (is_delimiter(line[i])) {
            in_token = false;
        } else if (!in_token) {
            count++;
            in_token = true;
        }
    }

    return count;
}

int main(int argc, char *argv[]) {
    size_t BUFF = 0;
    char *LINE = NULL;
    int A = 0;
    int nbtok = 0;
    int comnum = 1;
    int shinteract = 0;

   int signal(SIGINT, SIG_IGN);
    shinteract = isatty(STDIN_FILENO);

    if (shinteract == 0 && argc == 1) {
        ssize_t line_l;

        while ((line_l = getline(&LINE, &BUFF, stdin)) != -1) {
            int nbtok = count_tokens(LINE);
            parse(LINE, nbtok, argv, comnum);
            comnum++;
        }

        free(LINE);
        return 0;
    }

    while (shinteract) {
        write(1, "btshell$", 10);
        nbtok = 0;
        A = getline(&LINE, &BUFF, stdin);

        if (A < 0) {
            free(LINE);
            write(1, "\n", 1);
            break;
        }

        bool in_token = false;

        for (int j = 0; j < A; j++) {
            if (is_delimiter(LINE[j])) {
                in_token = false;
            } else if (!in_token) {
                nbtok++;
                in_token = true;
            }
        }

        parse(LINE, nbtok, argv, comnum);
        comnum++;
        LINE = NULL;
    }

    return 0;
}