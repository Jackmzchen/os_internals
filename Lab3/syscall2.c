#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdlib.h>

main()
{
    char *args[3];      // Define pointer to array of arglist
    args[0] = "ps";     // Build arglist
    args[1] = "-al";
    args[2] = NULL;     // Terminate with NULL

    int forkvalue = fork();

    if(forkvalue > 0)
        sleep(120);
    if(forkvalue == 0)
    {
        printf("\nAbout to execute ps -al with PID: %d\n", getppid());
        execvp("ps", args);
        exit(0);
    }
    else
    {
        printf("I am the parent, my PID is: %d\n", forkvalue);
        wait(NULL);
    }
}