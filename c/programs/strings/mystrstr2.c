#include <stdio.h>

/* all match occurance in string*/
void mystrstr(const char* orgstring, const char* substring)
{
    if((orgstring==NULL) || (substring == NULL))
    {
        printf("\n invaild input parameter\n");
        return;
    }

    if (*substring == '\0')
    {
        printf("%s", orgstring);
        return;
    }

    while (*orgstring)
    {
        const char *org = orgstring;
        const char *sub = substring;
        
        while(*org && *sub && (*org == *sub))
        {
            ++org;
            ++sub;
        }

        if(*sub == '\0')
        {
            printf ("\nfound : %s", orgstring);
        }

        ++orgstring;
    }    
}

int main()
{
    char a[] = "Hello world and welcome to our world";
    char b[] = "world";

    mystrstr(a, b);
}

