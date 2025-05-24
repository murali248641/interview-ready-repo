#include <stdio.h>

#define NIBBLE_SWAP(value)      ( ((value>>4) & (0x0F)) | \
                                  ((value<<4) & (0xF0)) )

#define NIBBLE_SWAP1(value)     ( (value>>4) | (value<<4) & 0xFF)

int main()
{
    unsigned char a = 0x23;

    printf("\n value of a is: 0x%x \n", a);

    printf("\n nibble swapped value of a is: 0x%x\n", NIBBLE_SWAP(a));

    printf("\n nibble swapped1 value of a is: 0x%x\n", NIBBLE_SWAP1(a));

}