#include <stdio.h>

int main()
{
    int a=5, b=7;

    printf("\n values of a and b is : %d  %d \n", a, b);

    // solution 1
    /* a = a+b;
       b = a-b;
       a = a-b; */

    //solution 2
    a = a ^ b;
    b = a ^ b;
    a = a ^ b; 

    printf("\n swapped values of a and b is : %d  %d\n", a, b);




}