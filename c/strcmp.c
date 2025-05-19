#include <stdio.h>

int mystrcmp(char *str1, char *str2);

int mystrcmp(char *str1, char *str2)
{
    if (!str1 || !str2)
    {
        printf("\n invalid parameter something is null\n");
        return 0;
    }

    while(*str1 && *str2 && (*str1==*str2))
    {
        ++str1;
        ++str2;
    }

    return (*str1 - *str2);
}

int main()
{
    char str1[] = "check";
    char str2[] = "check";

    if(mystrcmp(str1,str2) == 0)
        printf("\n string are equal\n");
    else    
        printf("\n strings are not equal\n");

}