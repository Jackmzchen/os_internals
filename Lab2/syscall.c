#include <stdio.h>

main()
{
    int c, n = 0;                                                       //Declare variables c and n and initializes variable n with 0
    while((c=getchar())!='Q')                                           //while variable c does not equal to Q the program will run
    printf("char %3d is character %c with ascii code %d\n", n++,c,c);   //print the current value of n + 1, the value that is stored in variable c, and the ascii value of the letter in variable c
}