#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "myshell.h"
#include <errno.h>
#include <dirent.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>
#include <unistd.h>

#define MAX_BUFFER 1024                        // max line buffer
#define MAX_ARGS 64                            // max # args
#define SEPARATORS " \t\n"                     // token separators

// Our function which starts the shell.

int startShell(int argc, char * argv[])
{
    char buf[MAX_BUFFER];                      // line buffer
    char * args[MAX_ARGS];                     // pointers to arg strings
    char ** arg;                               // working pointer thru args
    char * prompt = "==>";                     // shell prompt
    int count = 0;                             // Another argument count, to be used later.
    int batchMode = 0;                         // batchMode is off by default.

    // If the argc is more than 1, we've been given a batch file. So we set
    // stdin to the batch file.
    if(argc > 1)
    {
        batchMode = 1;
        freopen(argv[1], "r", stdin);
    }

    // keep reading input until "quit" command or eof of redirected input
    while(!feof(stdin)) {

        char cwd1[256];
        getcwd(cwd1, sizeof(cwd1)); // Getting the current working directory.

        // If we're not in batch mode, print the prompt.
        if(batchMode == 0)
        {
            printPrompt(prompt, cwd1);
        }

        // Reading a line:
        if(fgets(buf, MAX_BUFFER, stdin)) {

           /* tokenize the input into args array */
            arg = args;
            *arg++ = strtok(buf,SEPARATORS); // tokenise input

            count = 0;
            while((*arg++ = strtok(NULL,SEPARATORS)))
            {
                count += 1;
            }

            // a stopAt variable records where the echo arguments should stop.
            int stopAt = count;

            // Checking the command line for redirection characters.
            int i = 0;
            while(args[i])
            {

                // Checking if an output redirection character exists in the line.
                if(args[i][0] == '>')
                {
                    freopen(args[i + 1], "a+", stdout);
                    stopAt = i;
                }

                // Checking if an input redirection character exists in the line.
                if(args[i][0] == '<')
                {
                    printf("Input redirection detected.\n");
                    printf("Despite my best efforts, issues with the freopen function means my shell does NOT support input redirection from the prompt.\n");
                    printf("To read stdin from a text file, use batch mode (include a file as argv[1] when starting the shell).");
                    stopAt = i;
                }
                i++;
            }

            // Our control flow. If an in-built command is detected (e.g. clr), we pass it to the relevant function in myshell.h.
            // Otherwise, we pass the command line argument onto the externalCommand or externalCommandFG function.
            // externalCommand will run the external command in the background. externalCommandFG will run it in the foreground.

            if(args[0]){
                if(!strcmp(args[0],"clr")) {
                    clear();
                    continue;
                }

                else if(!strcmp(args[0], "dir")) {
                    dir(args[0]);
                }

                else if(!strcmp(args[0], "cd")) {
                    if(count == 0){
                        char cwd[256];
                        getcwd(cwd, sizeof(cwd));
                        printf("No directory given. The current working directory is: %s\n", cwd);
                    }

                    else {
                        DIR* dir = opendir(args[1]);
                        if(dir){
                            printf("Changing the current directory to %s.\n", args[1]);
                            cd(args[1]);
                        }

                        else {
                            printf("This directory doesn't exist.\n");
                        }
                        closedir(dir);
                    }
                }

                else if(!strcmp(args[0], "echo")){
                    echo(args, stopAt);
                }

                else if(!strcmp(args[0], "pause")){
                    pauseIt();
                }

                else if(!strcmp(args[0], "help")){
                    help();
                }

                else if(!strcmp(args[0], "quit")) {
                    break;                          // We break out of the while loop when we want to quit our shell.

                }

                else if(args[count][0] == '&')
                {
                    externalCommand(args);
                }

                else
                {
                    externalCommandFG(args);
                }

            // Setting stdin and stdout back to the terminal.

            freopen("/dev/tty", "w", stdout);

            }

        }

    }
    freopen("/dev/tty", "w", stdin);    // Setting our stdin back to the terminal.
    return 0;
}
