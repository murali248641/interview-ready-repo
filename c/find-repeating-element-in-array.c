#include <stdio.h>

int main()
{
    int a[] = {3, 5, 3, 7, 8, 9, 8, 9, 3, 3, 10, 12, 7, 10};
    int i, j, length =sizeof(a)/sizeof(a[0]);
    int temp, found;

    printf("\nLength of array is : %d\n", length);

    for(i=0;i<length;++i)
    {
        printf("%d ", a[i]);
    }
    
    printf("\n");
    
    printf("\nUnique numbers in array are: \n");
    for(i=0;i<length;++i)
    {
        temp = a[i];
        found = 0;

        for(j=0; j<length; ++j)
        {
            if( (i != j) && (temp == a[j]))
            {
                found = 1;
                break;
            }
        }

        if(!found)
            printf("%d ", a[i]);
    }
}