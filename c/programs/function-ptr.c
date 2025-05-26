#include <stdio.h>

void foo(void);
void boo(void);
void koo(void);

void foo(void)
{
    printf("\n function foo \n");
}

void boo(void)
{
    printf("\n function boo \n");
}

void koo(void)
{
    printf("\n function koo \n");
}

int main()
{
    void (*func) (void);
    int i;
    void (*func1[]) () = {foo, koo, boo};
    void (**ptr) () = func1;

    func = foo;
    func();

    func = koo;
    func();

    func = boo;
    func();

    for (i=0; i<3; ++i)
        (func1[i]) ();
    
    printf("\n checking \n"); 

    (++ptr)[1] ();
}