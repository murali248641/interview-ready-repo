#include <stdio.h>
#include <string.h>

int is_overlapping(const char *src, char *dest)
{
    int len = strlen(src)+1;

    return ( (dest < (src+len)) && (src < (dest+len)) );
}

char* mystrcpy(char* dest, const char* src)
{
    char *ret_dest = dest;

    if(!dest || !src)
    {
        printf("invaild parameter");
        return NULL;
    }

    if (dest == src)
    {
        printf("\n src and dest are same\n");
        return dest;
    }

    if(is_overlapping(src, dest))
    {
        printf("\n overlapping need to do the memmove \n");
        return NULL;
    }

    while(*src)
    {
        *dest = *src;
        ++src;
        ++dest;
    }

    *dest = '\0';

    return ret_dest;
}


int main()
{
    char src_string[] = "copy test";
    char dest_string[100] ;

    printf("\n my copied string is : %s\n", mystrcpy(dest_string, src_string));

}