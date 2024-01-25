/*
Single Inheritance
A-->B
*/

#include <bits/stdc++.h>
using namespace std;

// Base class
class Base
{
    // private data
    int d1;

public:
    int d2;
    void setData()
    {
        d1 = 10;
        d2 = 20;
    }

    int getData1()
    {
        return d1;
    }

    int getData2()
    {
        return d2;
    }
};

// derived class
class Derived : private Base
{
public:
    int d3;
    void process()
    {
        setData();
        d3 = d2 * getData1();
    }
    void display()
    {
        cout << "Value of d3 after processing is " << d3 << endl;
    }
};

int main()
{
    Derived d;
    // d.setData();
    d.process();
    d.display();
    return 0;
}