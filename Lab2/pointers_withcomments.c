#include <stdio.h>
int main()
{
    int x;
    int *p;
    x = 2;
    printf("variable x=%d\n", x);
    p = &x;
    printf("P contains the memory of variable x (pointer) p= %p\n", p);
    *p = 5;
    printf("variable x = %d\n",x);
    printf("variable (pointer) p = %p\n",p);

    int y = 10;                                                  //defines an int variable with the name y and assigns it the value of 10
    int *s = &y;                                                 //defines an int pointer variable with the name s and assigns it the address of y
    printf("variable y contains %d\n",y);                        //prints the contents of variable y
    printf("The memory addres of variable y is %p\n",s);         //prints the memory address of variable y
                                                                 
    printf("variable (pointer) s contains %d\n", *s);            //prints the contents of pointer variable s
    printf("The memory address of variable s is %p\n", s);       //prints the memory address of pointer variable s

    *s = 15;                                                     //sets the value of pointer s to 15

    printf("variable (pointer) s contains %d\n", *s);            //prints the contents of variable s to verify that the change has been made

}