#include <stdio.h>
int char_compare(char one, char second);
int mystrcmp_withoutcasesensitive(const char *str1, const char *str2);

int mystrcmp_withoutcasesensitive(const char *str1, const char *str2)
{
    if(!str1 || !str2)
    {
        printf("\n invalid input parameter\n");
        return -1;
    }

    while( *str1 && *str2 && char_compare(*str1, *str2))
    {
        ++str1;
        ++str2;
    }

    return *str1 - *str2;
}

int char_compare(char one, char second)
{
    if (one==second)
    {
        return 1;
    }

    if ( (one+32) == second ||
         (one-32) == second ||
         one == (second+32) ||
         one == (second-32) )
    {
        return 1;
    }

    return 0;
}

int main()
{
    char a[] = "test";
    char b[] = "Test";

    if( 0 == mystrcmp_withoutcasesensitive(a,b))
        printf("strings are equal");
    else
        printf("string are not equal");
}
