#include <stdio.h>
#include <string.h>

int mystrlen(char *string);

int main()
{
    char *string = "length check";

    printf("\n string length value is: %d\n", mystrlen(string));

    printf("\n string length value using pre-defined fun: %d \n", strlen(string));
}

int mystrlen(char *string)
{
    int length =0;

    while(string && *string)
    {
        ++string;
        ++length;
    }

    return length;
}