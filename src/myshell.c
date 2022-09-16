/*

The shell's internal commands are:

cd - change the shell's current directory. If the directory doesn't exist,
the shell will inform the user. If no argument is provided, the current working
directory will be reported.

clr - clear the screen
dir - list the contents of the current directory.
echo - echo a string to the terminal.
help - display the user manual (note: the more filter is applied).
pause - pause operation of the shell until 'Enter' is pressed.
quit - quit the shell.
********************************************************************
version: 1.0
date:    February 2022
author:  Luke Whelan (Student Number: 20463814)
School of Computing
Dublin City University, Glasnevin
luke.whelan38@mail.dcu.ie
*******************************************************************/

#include <stdio.h>
#include "utility.h"

int main(int argc, char *argv[])
{
    printf("Welcome to my shell.\n");
    sleep(2.5);
    printf("This is the CA216 submission of Luke Whelan (Student Number: 20463814)\n");
    sleep(2.5);
    printf("The shell will now begin. Use help to view a range of commands.\n");
    sleep(2.5);
    startShell(argc, argv);
}
