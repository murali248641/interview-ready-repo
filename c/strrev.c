#include<stdio.h>
#include<string.h>

char* mystrrev(char *string)
{
    int i, j, length = strlen(string);
    char temp;

    if (!string)
        return NULL;

    for(i=0, j=length-1; i<(length/2); ++i, --j)
    {
        temp = string[i];
        string[i] = string[j];
        string[j] = temp;
    }
    
    return string;
}

int main()
{
    char str[] = "test check";

    printf("\n reversed string is: %s\n", mystrrev(str));
}