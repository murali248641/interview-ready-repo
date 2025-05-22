#include <stdio.h>

#define SETBIT(value, pos)       value = (value | (1<<(pos-1))) 
#define CLEARBIT(value, pos)     value = (value & ~(1<<(pos-1)))
#define TOGGLE_BIT(value, pos)   value = (value ^ (1<<(pos-1)))
#define ODD_NUMBER_CHECK(value)  (((value&1)==1)? "ODD": "EVEN")
#define GET_BIT(value, pos)      (1 &  (value>>(pos-1)))

int main()
{
    char a = 2;

    printf("\n value of a is : %d\n", a);

    SETBIT(a,7);

    printf("\n value of a after setbit is : %d\n", a);

    CLEARBIT(a,2);

    printf("\n value of a after clear bit is : %d\n", a);

    TOGGLE_BIT(a,2);

    printf("\n value of a after toggle bit is : %d\n", a);

    printf("\n odd number check : %s \n", ODD_NUMBER_CHECK(20));

    printf("\n get bit value of 8 is : %d\n", GET_BIT(32, 6));
}