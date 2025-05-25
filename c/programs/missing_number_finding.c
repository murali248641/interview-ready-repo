#include <stdio.h>

int find_missing_number(int a[], int n);

int find_missing_number(int a[], int n)
{
    int i, given_xor=0, org_xor=0;

    for(i=0; i<n-1; ++i)
    {
        given_xor ^= a[i];
    }

    for(i=1; i<=n;++i)
    {
        org_xor ^= i;
    }

    return org_xor ^ given_xor;
}

/* using sum solution */
/* 
int find_missing_number(int a[], int n)
{
    int sum = ((n*(n+1))/2);
    int i, org_arr_sum = 0;

    for (i=0;i<n-1; ++i)
    {
        org_arr_sum += a[i];
    }

    return sum - org_arr_sum;
}
*/

int main()
{
    int a[] = {1,2,3,4,5,6,8};
    int n=8;

    printf("\n missing in given array is: ");
    printf("%d", find_missing_number(a,8));

}