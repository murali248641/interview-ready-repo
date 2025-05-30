#include <stdio.h>

void print_min_max_array(int array[], int length);

void print_min_max_array(int array[], int length)
{
    int min, max, i;
    
    if(!array)
    {
        printf("\n array is empty\n");
        return;
    }

    min = max = array[0];
    
    for(i=1;i<length;++i)
    {
        if(min > array[i])
            min = array[i];

        if(max < array[i])
            max = array[i];
    }

    printf("\n maximum and minimum of array are:%d %d\n", min, max);
}

int main()
{
    int a[] = {4, 5, 2, 9, 22, 1000, 22, 11, 1111, 1};
    //int a[] = {4,2};
    int length =  sizeof(a)/sizeof(a[0]);

    print_min_max_array(a, length);
}