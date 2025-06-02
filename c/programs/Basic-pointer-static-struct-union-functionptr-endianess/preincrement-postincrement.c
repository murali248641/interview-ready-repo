#include <stdio.h>

int main()
{
    int a = 5;

    a = a++ + ++a;

    printf("a=%d", a);
    return 0;
}