#ifndef _BTHEAD_H_
#define _BTHEAD_H

/*Header files*/

/*btshell.c*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

/*bt_run.c*/
#include <string.h>
#include <sys/wait.h>




/* Function Declarations*/
void bt_run(char *);
int bt_do (char **arguments, char *)
char *bt_read(void)
char **bt_split(char *command_line)