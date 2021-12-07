/* - thread to count words for two files */

#include <stdio.h> 
#include <pthread.h>
#include <ctype.h>
#include <stdlib.h>

struct arg_set{
                char *fname;            //file to examine           
                int count;              //number of words
};

int main(int ac,char *av[])
{
    pthread_t         t1;            //Thread ID
    pthread_t         t2;            //added a new thread for counting file 2
    struct arg_set args1;           // structure argsets
    void *count_words(void*);

    if(ac != 3)                     //modified to 3 so that it can hold 2 files
    {
        printf("usage: %s error check input \n", av[0]);
        exit(-1);
    }
    args1.fname = av[1];
    args1.count = 0;
    pthread_create(&t1, NULL, count_words, (void *) &args1);
    pthread_join(t1, NULL);
    printf("Thread 1 counting words for %5d %s\n",args1.count, av[1]);
    args1.fname = av[2];          //added this
    args1.count = 0;              //added this
    pthread_create(&t2, NULL, count_words, (void *) &args1);                //added this
    pthread_join(t2, NULL);                                                 //added this
    printf("Thread 2 counting words for %5d %s\n",args1.count, av[2]);      //added this
}
void *count_words(void *a)
{
        struct arg_set *args = a;            //case arg back to correct type
        FILE *fp;
        int c, prevc = '\0';

        if((fp = fopen(args -> fname, "r")) != NULL)
        {
            while((c = getc(fp)) != EOF)
            {
                if(!isalnum(c) && isalnum(prevc))
                    args->count++;
                prevc = c;
            }
            fclose(fp);
        }
        else
            perror(args->fname);
        return NULL;
}