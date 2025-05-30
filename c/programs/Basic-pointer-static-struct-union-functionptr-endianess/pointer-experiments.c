#include <stdio.h>

int main()
{
    int a[] = {10, 20, 30, 40, 50};
    int *ptr = a;

    int x = ++*ptr++ + *++ptr;

    printf("\n value : %d\n", x);
    return 0;
}