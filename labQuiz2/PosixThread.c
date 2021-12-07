#include <stdio.h>
#include <pthread.h>
#include <ctype.h>
#include <stdlib.h>

void *get_character(void *m)
{
    int c;
    while( (c = getchar()) !='Q')
    putchar(c);
    return m;
}

int main()
{
    char chracter;
    pthread_t       thread1;
    pthread_create(&thread1,NULL,get_character,(void *) &chracter);
    pthread_join(thread1,NULL);
}