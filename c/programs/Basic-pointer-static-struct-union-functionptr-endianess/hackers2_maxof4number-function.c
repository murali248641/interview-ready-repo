#include <stdio.h>

int max_number(int a, int b, int c, int d)
{
    int max = a;

    if (b>max)
        max = b;

    if (c>max)
        max = c;

    if (d>max)
        max = d;

    return max;
}

int main()
{
    printf("Maximum value is: %d", max_number(34, 63, 87, 22));
}