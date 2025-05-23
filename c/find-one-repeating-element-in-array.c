#include <stdio.h>

int main()
{
    int a[5] = {4, 5, 4, 6, 6}, i, value=0;

    printf("\nArray of integer values are: \n");    
    for(i=0; i<5; ++i)
    {
        printf("%d ", a[i]);
    }
    printf("\n");

    /* this will find the only one unique value in an array */
    for(i=0;i<5;++i)
    {
        value ^= a[i];
    }

    printf("\n Non-repeating element is : %d\n", value);

}