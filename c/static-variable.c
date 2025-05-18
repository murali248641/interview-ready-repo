#include <stdio.h>

void init_module(void);

void init_module(void)
{
    static int init_module = 0;

    if(init_module == 0)
    {
        printf("\n initialized the module\n");
        init_module = 1;
    }
    else
    {
        printf("\n already initialized the module\n");
    }
}

int main()
{
    printf("\n welcome to static variable execise\n");

    init_module();
    init_module();
    init_module();
}