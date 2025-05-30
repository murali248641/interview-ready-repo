#include <stdio.h>


void print_array(int a[], int length);
void sort_array(int a[], int length);

void print_array(int a[], int length)
{
    int i;

    for(i=0; i<length;++i)
    {
        printf("%d ", a[i]);
    }

    printf("\n");
}

void sort_array(int a[], int length)
{
    int i, j, temp;
    
    if(length <= 1)
    {
        printf("\n array is empty or nothing to sort\n");
        return;
    }

    for(i=0; i<length;++i)
    {
        for(j=i+1; j<length; ++j)
        {
            if(a[i] > a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

int main()
{
    int a[] = {1, 5, 3, 9 ,2, 4, 3, 24}, 
        length = (sizeof(a)/sizeof(a[0]));

    printf("\n printing the array before sorting: \n");

    print_array(a, length);

    printf("\n printing the array after sorting: \n");

    sort_array(a, length);
    print_array(a, length);
}