#include <iostream>
using namespace std;

struct employee
{
    string name;
    int age;

    void introduce(void)
    {
        cout << "name: " << name << " Age: " << age << endl;        
    }
};

class employeee
{
    string name;
    int age;
    
    public: 
        employeee(string ne, int a)
        {
            name = ne;
            age = a;
        }

        void introduce(void)
        {
            cout << "name: " << name << " Age: " << age << endl;
        }
};


int main()
{
    employee e;
    e.age = 10;
    e.name = "test";
    e.introduce();

    employeee e1("test1", 12);
    e1.introduce();

    return 0;
}