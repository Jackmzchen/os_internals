#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

main()
{
    int fork_rv;
    printf("before: my pid is %d\n", getpid());
    fork_rv = fork();                                               //create new process
    if(fork_rv == -1)                                               //check for error
        {perror("fork");}
    
    if(fork_rv > 0)
        wait(NULL);
    if(fork_rv == 0)
    {
        printf("my PID is %d\n",getpid());
        sleep(5);
    }
    printf("I am waiting for my child %d\n",getpid());
}
