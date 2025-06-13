#include <stdio.h>


char* mystrstr(char *heystack, char *needle)
{
    if( (heystack == NULL) || (needle == NULL) )
    {
        printf("\n invaild input parameter \n");
        return NULL;
    }

    if (*needle == '\0')
    {
        return heystack;
    }

    while (*heystack)
    {
        char *h = heystack;
        char *n = needle;

        while(*h && *n && (*h == *n))
        {
            ++h;
            ++n;            
        }

        if(*n == '\0')
        {
            return heystack;
        }

        ++heystack;
    }
    
    return NULL;
}

int main()
{
    char a[] = "hello world check";
    char b[] = "world";

    printf("substring: %s", mystrstr(a,b));

}