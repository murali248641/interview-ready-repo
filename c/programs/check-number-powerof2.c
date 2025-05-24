#include <stdio.h>

#define POWER_OF_2(value)  ((value && ((value & (value-1)) == 0)) ? "True": "False")

int main()
{
    int value = 64;

    printf("\n value is power of 2 : %s\n", POWER_OF_2(value)); 
}