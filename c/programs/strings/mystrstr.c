#include <stdio.h>
#include <string.h>

char* mystrstr(char *heystack, char *needle);

char* mystrstr(char *heystack, char *needle)
{
    int length;
    
    if((heystack == NULL) || (needle ==NULL))
    {
        printf("\n invaild parameter \n");
        return NULL;
    }

    if (*needle == '\0')
    {
        return heystack;
    }

    length = strlen(needle);

    while(*heystack)
    {
        if(*heystack == *needle)
        {
            int i;

            for (i=0; i<length; ++i)
            {
                if(*(heystack+i) != *(needle+i))
                {
                    break;
                }
            }
            
            if (i == length)
            {
                return heystack;
            }            
        }

        ++heystack;
    }

    return NULL;
}

int main()
{
    char a[] = "hello wold ee world";
    char b[] = "world";

    printf("%s", mystrstr(a, b));
}