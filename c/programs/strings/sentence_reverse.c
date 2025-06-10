#include <stdio.h>
#include <string.h>

void reverse(char *left, char *right)
{
    if ((NULL == left) || (right == NULL))
    {
        printf("\n given input is wrong");
        return;
    }

    while (left < right)
    {
        char temp = *left;
        *left = *right;
        *right = temp;
        ++left;
        --right;
    }
}


int main()
{
    char a[] = "i am the man working hard";
    char *left, *right, *org = a;

    printf("\noriginal string is : %s", a);

    reverse(a, (a+(strlen(a)-1)));

    printf("\nafter the sentence reverse string is : %s", a);

    left = org;
    while(*org)
    {
        if ((*org == ' ') || (*org == '\0'))
        {
            right = (org-1);
            reverse(left, right);
            left = org+1;
        }
        ++org;
    }

    printf("\nafter word reverse the sentence is : %s", a);

}