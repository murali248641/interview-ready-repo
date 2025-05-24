#include <stdio.h>

int is_array_sorted(int a[], int length);

int is_array_sorted(int a[], int length)
{
    int sorted = 1, i;

    for(i=0;i<length-1;++i) 
    {
        if(!(a[i]<a[i+1]))
        {
            sorted = 0;
            break;
        }
    }

    return sorted;
}

int main()
{
    int a[] = { 3, 5, 7, 9, 22, 44, 3, 88};

    printf("\n array is sorted: %d\n", is_array_sorted(a, sizeof(a)/sizeof(a[0])));
}