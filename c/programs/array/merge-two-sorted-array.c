#include <stdio.h>

void merge_sorted_array(int a1[], int a1_size, int a2[], int a2_size, int ret[]);

void merge_sorted_array(int a1[], int a1_size, int a2[], int a2_size, int ret[])
{
    int i, j, k;

    i=j=k=0;

    while((i<a1_size) && (j<a2_size))
    {
        if(a1[i] < a2[j])
            ret[k++] = a1[i++];
        else
            ret[k++] = a2[j++];
    }

    while(i<a1_size)
    {
        ret[k++] = a1[i++];
    }

    while(j<a2_size)
    {
        ret[k++] = a2[j++];
    }
}

int main()
{
    int a1[] = {4, 7, 8, 12, 23};
    int a2[] = {5, 9, 15, 25, 33, 40};

    int a1_length = sizeof(a1)/sizeof(a1[0]);
    int a2_length = sizeof(a2)/sizeof(a2[0]);

    int a3[a1_length+a2_length]; 
    int i;

    merge_sorted_array(a1, a1_length, a2, a2_length, a3);

    printf("\n Merged arrays are:\n");
    for(i=0; i<a1_length+a2_length; ++i)
       printf("%d ", a3[i]);
    printf("\n");
   
    return 0;
}