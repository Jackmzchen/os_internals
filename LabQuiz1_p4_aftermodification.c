#include <stdio.h>

int main()
{
    int z= 0, y = 10, *p, *s;
    //p = &z;
    printf("the address of z is %p \n", &z);
    *p = 13;
    s = &y;
    s = p;
    p = z;
    printf("the address of pointer p is %p \n", p);
    printf("the address of pointer s is %p \n", s);

}