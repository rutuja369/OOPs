/*
Diamond Problem: -> Virtual Base Class is the solution for it!!!!!!
*/

#include <bits/stdc++.h>
using namespace std;

class A
{
    int a;

public:
    void set_Data(int num)
    {
        a = num;
    }
    void get_Data()
    {
        cout << "Value of a is " << a << endl;
    }
};

class B : virtual public A
{
    int b;

public:
    void set_b(int num)
    {
        b = num;
    }

    void get_b()
    {
        cout << "Value of b is " << b << endl;
    }
};

class C : virtual public A
{
    int c;

public:
    void set_c(int num)
    {
        c = num;
    }
    void get_c()
    {
        cout << "Value of c is " << c << endl;
    }
};

class D : public B, public C
{

    int d;

public:
    void display()
    {
        // here get_data() is creating ambiguity as 2 copies of it are inherited in D -> one from B and other from C
        //  To solve this redundancy and duplicacy -> we need to declare the Base class A as Virtual Base Class
        get_Data();//-> func inherited twice 
        get_b();
        get_c();
        cout << "Values are perfect" << endl;
    }
};

int main()
{
    D d;
    d.set_Data(10);
    d.set_b(12);
    d.set_c(32);
    d.display();
    return 0;
}