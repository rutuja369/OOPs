/*
Order of execution of Constructors in Inheritance:

- Multiple Inheritance: Order in which declaration is done -> same order followed
Ex: class C: public A, public B :-> A() then B() then  C()

- Multilevel Inheritance: Order of inheritance is followed while calling constructors
Ex: A-> B-> C :-> A() then B() then C()

- Special case of Virtual Base class
Ex: class C: public A, virtual public B, public D :-> B() then A() then D() the finally C()
Note: If there exists a virtual base class in order declared -> then its given more priority to execute its constructor
      If there are multiple such virtual base classes -> then follow the order in which they are declared
*/

#include <bits/stdc++.h>
using namespace std;

class A
{
    int a;

public:
    A(int a)
    {
        this->a = a;
        cout << "Constructor of A called!!" << endl;
    }
    void print_a()
    {
        cout << "Value of a is " << a << endl;
    }
};

class B
{
    int b;

public:
    B(int b)
    {
        this->b = b;
        cout << "Constructor of B called!!" << endl;
    }
    void print_b()
    {
        cout << "Value of b is " << b << endl;
    }
};

// To decide the order of execution for consrtuctors-> this below defined order is imp
class C : public A, public B
{
    int c;

public:
    C(int a, int b, int c) : A(a), B(b) // This order doesnt matter -> can change it!!!
    {
        this->c = c;
        cout << "Constructor of C called!!" << endl;
    }
    void printData()
    {
        print_a();
        print_b();
        cout << "Value of c is " << c << endl;
    }
};

int main()
{
    C c(1, 2, 3);
    c.printData();
    return 0;
}