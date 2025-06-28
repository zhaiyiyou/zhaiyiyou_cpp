#include <iostream>
#include <string>
using namespace std;

class MyClass
{
    string name;
    int age;

public:
    void set(int a, string n);
    void print();
    MyClass()
    {
        name = "张三";
        age = 18;
        cout << "构造函数执行完毕" << endl;
    };
};

void MyClass::set(int a, string n)
{
    age = a;
    name = n;
}
void MyClass::print()
{
    cout << "name:" << name << " age:" << age << endl;
}
int main()
{
    MyClass myclass;
    myclass.set(13, "zyy");
    myclass.print();
    // MyClass *pp = &myclass;
    // pp->print();
    MyClass myclass2;
    myclass2.print();
    return 0;
}
