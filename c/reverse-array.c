#include<stdio.h>

void reverse_array(int a[], int length);

void reverse_array(int a[], int length)
{
    int i,j;
    int temp;

    for (i=0, j=length-1;i<(length/2); ++i, --j)
    {
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
}

int main()
{
    int a[] = {2,3,4,5,6,7,9}, i, length = sizeof(a)/sizeof(a[0]);

    printf("\n array values are: \n");
    for(i=0; i<length; ++i)
    {
        printf("%d ", a[i]);
    }

    printf("\n");

    reverse_array(a, length);

    printf("\n reversed array values are: \n");
    for(i=0; i<length; ++i)
    {
        printf("%d ", a[i]);
    }

    printf("\n");

}
