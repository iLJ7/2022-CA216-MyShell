#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

// My implementation of the requested commands.

extern char **environ;

void clear(){
    system("clear");
}

void dir(char *target){

    char targetDir[256];

    getcwd(targetDir, sizeof(targetDir));
    system("ls -al $targetDir");
}

void cd(char *target) {
    chdir(target);
}

// If it's not a redirection character, we print it.

void echo(char *argv[], int stopAt) {
    for(int i = 1; i <= stopAt; i++)
    {
        if(argv[i][0] != '<' && argv[i][0] != '>' && argv[i][0] != '=')
        {
            printf("%s ", argv[i]);
        }
    }

    printf("\n");
}

// We pause the shell using getchar.
void pauseIt(){
    printf("Shell has been paused. Press ENTER key to continue...\n");
    getchar();
}

// Prints the prompt.
void printPrompt(char *prompt, char *cwd){
    fputs(prompt, stdout);
    fputs(cwd, stdout);
    fputs(": ", stdout);
}

// This will print the manual, using the more filter.
void help(){
    system("more ../manual/readme.md");
}

// handles external commands to run in the background.
// If the program is in the child, we execute the command.
/* This means it runs as a background process; the parent does NOT wait
   for the program in the child to finish executing */

void externalCommand(char *argv[])
{
    int id = fork();
    if(id == -1){
        printf("Fork failed.\n");
    }
    else if(id == 0){
        execvp(argv[0], argv);
    }
}

// handles external commands to run in the foreground.

// Here, the parent waits for the child process to finish executing before returning to stdin.
void externalCommandFG(char *argv[])
{

    int id = fork();
    int status;

    if(id == -1){
        printf("Fork failed.\n");
    }
    else if(id == 0){
        execvp(argv[0], argv);
    }
    else{
        while(wait(&status) != id);
    }
}

// prints the environment variables.
void printEnviro(char *argv[])
{
    int i;
    for(i = 0; environ[i] != NULL; i++)
    {
        printf("%s\n", environ[i]);
    }
}
