#include "bthead.h"
/**
 * bt_run - recieves inputted infor and executes
 * 
*/

void bt_run(char *btshell)
{
    int BT_STATUS;
    int bt_interact;
    char *command_line;
    char **arguments

    do
    {
        bt_interact = isatty(STDIN_FILENO);
        

        if(bt_interact == 1)
        {
            write(1, "btshell$ ", 10);
        }

        command_line = bt_read();
        if (command_line == NULL)
        {
            break;
        }
        
        arguments = bt_split();
        if(arguments == NULL)
        {
            free(line);
            break;
        }
         BT_STATUS = bt_do(arguments, btshell);
         free(command_line);
         free(arguments);
    }
    while(BT_STATUS);
}