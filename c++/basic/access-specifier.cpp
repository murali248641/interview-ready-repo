#include <iostream>
using namespace std;

class Base
{
    private:
        int a;
    protected: 
        int b;
    public:
        int c;
        Base(/* args */);
        Base(int n1, int n2, int n3);
        ~Base();
        virtual void print(void);
};

void Base::print(void)
{
    cout << a << b << c << endl;
}

Base::Base(int n1, int n2, int n3)
{
    cout << "parameterized constructor" << endl;
    a = n1;
    b = n2;
    c = n3;
}

Base::Base(/* args */)
{
    cout << "constructor" << endl;
}

Base::~Base()
{
    cout << "desstructor" << endl;
}

class derived : public Base
{
    private:
        /* data */
    public:
        derived (/* args */);
        ~derived ();
        void print(void);
};

derived::~derived()
{
    cout << "derived destructor called" << endl;
}

derived::derived():Base(2,4,5)
{
    cout << "derived consturctor" << endl;
}

void derived::print(void)
{
    cout << "derived" << b << c ;
}

int main()
{
    derived d;
    d.print();
}