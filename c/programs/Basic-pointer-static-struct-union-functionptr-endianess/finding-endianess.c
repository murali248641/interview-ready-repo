#include <stdio.h>

int main()
{
    int a = 1;
    char *ptr = (char *) &a;

    if (*ptr == 1)
        printf("\n little endian machine\n");
    else    
        printf("\n Big endian macine\n");
}