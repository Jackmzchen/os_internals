#include <stdio.h>                                    
#include <stdlib.h>                                  
#define MAX 10                                        

int i=12345;                                          
double y=1.23456;                                     

void display_variables()                              
{
    double y=4.352;                                   
    printf("i=%d, y=%f\n",i,y);                       
}

int main()                                            
{
    int forkval;
    forkval = fork();                                   //creates the child process

    if(forkval == -1)
        exit(-1);
    if(forkval == 0)
    {                                   //prints the fibonacci and sleeps for 3 seconds
        printf("i=%d, y=%f\n",i,y);                       
        display_variables();                              
        int c, i=0;                                       
        for(c =0; c <= MAX; c++)                          
        {
            printf("%d\n", fib(i));                       
            i++;                                          
        }
        printf('sleeping for 3 seconds...\n');
        sleep(3);
    }

    else
        wait(NULL);                                   //parent waits for the child
    return 0;
}

int fib(int n)                                        
{
    if(n==0)                                          
        return 0;
    else if(n==1)                                     
        return 1;
    else                                             
        return (fib(n-1) + fib(n-2));
}