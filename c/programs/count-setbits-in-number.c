#include <stdio.h>

int count_setbits(unsigned char value);

int count_setbits(unsigned char value)
{
    int count = 0;

    while(value)
    {
        if(value&1)
            ++count;

        value >>= 1;
    }

    return count;    
}

int main()
{
    unsigned char value = 95;

    /*
    int count = 0, i;

    printf("\n sizeof char is: %d\n", sizeof(char)*8);


    for(i=0;i<(sizeof(char)*8); ++i)
    {
        if(value & 1)
        {
            ++count;
        }
        value >>= 1;
    }
  */
    printf("\n Total set bits are: %d\n", count_setbits(value));
}