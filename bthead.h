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

/* bt_process*/
#include <sys/types.h>

 /*bt_do*/
 #include <strings.h>
 
typedef struct btBUILDt
{
    const char *bt_BUILDstr;
    int (*bt_BUILDf)(char **arguments, char *btshell);
} btBUILDt;


/* Function Declarations*/3
int bt_process(char **arguments, char *);
int bt_lstring(const char *string);
void bt_run(char *);
int bt_do (char **arguments, char *);
char *bt_read(void);
char **bt_split(char *command_line);
int bt_comparestr(const char *string1, const char *string2);

/*Built-ins*/
int btCD(char **arguments, char *);
int btEXIT(char **arguments, char *)

#endif