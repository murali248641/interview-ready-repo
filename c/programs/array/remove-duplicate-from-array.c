#include <stdio.h>

void print_array(int a[], int a_leng);
void remove_duplicate(int a[], int a_leng, int ret[], int* ret_length);

void remove_duplicate(int a[], int a_leng, int ret[], int* ret_length)
{
    int i, j, k=0;

    if(!(a_leng <= *ret_length))
    {
        printf("\n src and dest array length is not matching\n");
        return;
    }

    for (i=0; i<a_leng; ++i)
    {
        int found = 0; 
        for(j=0; j<k;++j)
        {
            if(a[i] == ret[j])
            {
                found =1;
                break;
            }
        }

        if(!found)
            ret[k++] = a[i];
    }

    *ret_length = k;
}

void print_array(int a[], int a_leng)
{
    int i;

    printf("\n array printing: ");
    for(i=0; i<a_leng; ++i)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main()
{
    int a[] = {3,4,5,7,4,3,6};
    int a_leng = sizeof(a)/sizeof(a[0]);
    int ret[a_leng];
    int ret_leng = a_leng;

    print_array(a, a_leng);
    remove_duplicate(a, a_leng, ret, &ret_leng);
    
    print_array(ret, ret_leng);
}