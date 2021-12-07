#include <stdio.h>                                    //default header file, contains commonly use library function
#include <stdlib.h>                                   //optional header file for certain library functions
#define MAX 10                                        //defines a constant variable called MAX and initializes it to 10

int i=12345;                                          //defined as a global variable and initialize the variable i as an int data type and set it to 12345
double y=1.23456;                                     //defined as a global variable and initialize the variable y as a double data type and set it to 1.23456

void display_variables()                              //defines user-created function with the name display_variables
{
    double y=4.352;                                   //defined as a local variable and initializes the variable y as a double data type and set it to 4.352
    printf("i=%d, y=%f\n",i,y);                       //prints the values stored in variable i and y at the time that the function is called in main
}

int main()                                            //required function to run any code or user-defined functions
{
    printf("i=%d, y=%f\n",i,y);                       //prints the values stored in variables i and y
    display_variables();                              //calls the display_variables function
    int c, i=0;                                       //defined as local variables, with names c and i, while also initializing variable i to 0
    for(c =0; c <= MAX; c++)                          //for loop that prints out the contents within the loop up to the number defined by MAX
    {
        printf("%d\n", fib(i));                       //print the values that the fib function returns
        i++;                                          //increments variable i by 1 each time the loops executes
    }
    return 0;
}

int fib(int n)                                        //defines a user-created function with the name fib and take the variable n as a parameter
{
    if(n==0)                                          //if variable n is equal to 0, then return 0
        return 0;
    else if(n==1)                                     //else if variable n is equal to 1 then return 1
        return 1;
    else                                              //if the variable n is not 0 or 1 then return the number - 1 + the number -2
        return (fib(n-1) + fib(n-2));
}