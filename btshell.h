#ifndef _BTSHELL_H
#define _BTSHELL_H

/*Header files for btshell*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <stdbool.h>

/*Fucntion Declarations*/
bool is_delimiter(char c);
int nbcount(const char *line);
void parse(const char *line, int nbtok, char *argv[], int comnum);

#endif