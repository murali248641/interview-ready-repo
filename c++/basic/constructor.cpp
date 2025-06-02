#include <iostream>
using namespace std;

class Base
{
    private: 
        int a,b;
    public:
        Base();
        Base(int a1, int b1);
        ~Base();
        void print(void);
}; 

Base :: Base() : a(0), b(0)
{
    cout << "BASE constructor called" << endl;
}

Base::~Base()
{
    cout << "BASE destuctor is called " << endl;
}

Base::Base(int a1, int b1) : a(a1), b(b1)
{
    //a = a1;
    cout << "BASE parameterized constuctor is called" << endl;
}

void Base::print(void)
{
    cout << "printing a value: " << a << " b is: "<< b << endl;
}

class derived : public Base
{
        int c;
        
    public:
        derived();
        derived(int a1, int b1, int c1);
        ~derived();
        void print(void);
};

void derived::print(void)
{
    Base::print();
    cout <<"c value is: " << c << endl;
}

derived::derived(int a1, int b1, int c1): Base(a1,b1), c(c1)
{
    cout << "derived class parameterized constructor is called"<< endl;
}

derived::derived() : c(0)
{
    cout << "derived class constructor called" <<endl;
}

derived::~derived()
{
    cout << "derived class descrtor is called" <<endl;
}

int main()
{
    //Base b(51,20);
    //b.print();

    derived d(10 ,20, 40);
    d.print();
}