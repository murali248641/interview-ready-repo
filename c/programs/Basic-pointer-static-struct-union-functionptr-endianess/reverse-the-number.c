#include <stdio.h>

void print_reverse(int number);

void print_reverse(int number)
{
    int reversed_number = 0;

    while(number)
    {
        reversed_number = (reversed_number*10)+(number%10);
        number = number/10;
    }    

    printf("\n Reversed number is : %d", reversed_number);
}

int main()
{
    int a=345;
    
    printf("\nEnter the number to reverse: ");
    scanf("%d", &a);

    print_reverse(a);
}