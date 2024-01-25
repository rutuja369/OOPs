/*
Multiple Inheritance
A--> C <--B
*/

#include <bits/stdc++.h>
using namespace std;

class Base1
{
protected:
    int b1;

public:
    void set_base1(int num)
    {
        b1 = num;
    }
    void greet()
    {
        cout << "Good Morning!!!" << endl;
    }
};

class Base2
{
protected:
    int b2;

public:
    void set_base2(int num)
    {
        b2 = num;
    }
    void greet()
    {
        cout << "Good Afternoon!!!" << endl;
    }
};

class Base3
{
protected:
    int b3;

public:
    void set_base3(int num)
    {
        b3 = num;
    }
    void greet()
    {
        cout << "Good Evening!!!" << endl;
    }
};

class Derived : public Base1, public Base2, public Base3
{
public:
    void display()
    {
        cout << "The value inherited from base1 is " << b1 << endl;
        cout << "The value inherited from base2 is " << b2 << endl;
        cout << "The value inherited from base3 is " << b3 << endl;
        cout << "The sum of these inherited values is " << (b1 + b2 + b3) << endl;
    }
    void greet()
    {
        cout << "Guten Morgen!!" << endl;
    }
};

int main()
{
    Derived rutu;
    rutu.set_base1(20);
    rutu.set_base2(30);
    rutu.set_base3(19);
    rutu.display();

    rutu.greet();
    return 0;
}