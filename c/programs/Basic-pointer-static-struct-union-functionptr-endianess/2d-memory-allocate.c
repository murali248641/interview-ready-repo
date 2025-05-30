#include <stdio.h>
#include <stdlib.h>

int main()
{
    int row=3, col=3;

/* static memory allocation

    int a[3][3] = {{3,4,5}, {6,7,8}, {9,10,11}};
    int i,j;

    printf("\n");
    for(i=0;i<row;++i)
    {
        for(j=0;j<col;++j)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    printf("\n");
*/

    /* dynamic array allocation*/
    int **two_array;
    int i, j;

    two_array = (int**)malloc(row * sizeof(int *)); 

    for(i=0;i<row;++i)
    {
        *(two_array+i) = (int*) malloc (col*sizeof(int));
    }

    printf("\n");
    for(i=0;i<row;++i)
    {
        for(j=0;j<col;++j)
        {
            two_array[i][j] = i+j;
            printf("%d ", two_array[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    for(i=0;i<row;++i)
    {
        free(two_array[i]);
    }

    free(two_array);
}