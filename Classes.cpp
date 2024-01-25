/*
Classes Vs Structures
1. Structures
- use when you want to encapsulate a set of variable and methods under one entity
- use when you dont care much about data security coz structs in cpp have default visibility as public and default inheritance is also public
- Remember -> structures can also have data and methods -> just they are not secure as everything is public by defalut and accessible to anyone in the code -> we need to manually change the access specifier as private to hold some private data

2. Classes
- use classes when we want to encapsulate as well as protect our data secure it!!
- Entended version of structures ->has default visibility mode as private and default inheritance is also private
- They also have access modifiers public:, private:, protected-> based on which we can introduce a restriction on data access
*/

#include <bits/stdc++.h>
using namespace std;

// Classes
class Employee
{
    // Note: By default everything is private in a class
private:
    // Only accessible to member functions of this class -> no one else can access these props
    int a, b;

public:
    int c, d;
    // Declared the function
    void setData(int a, int b);
    void getData()
    {
        cout << "Value of a is " << a << endl;
        cout << "Value of b is " << b << endl;
        cout << "Value of c is " << c << endl;
        cout << "Value of d is " << d << endl;
    }
};
// Member FUnc of a class defined outside of it
void Employee ::setData(int a, int b)
{
    this->a = a;
    this->b = b;
}

// Structures
typedef struct Emp
{
    int a;
    int b;
    void setVal(int a, int b)
    {
        this->a = a;
        this->b = b;
    }
    void getVal()
    {
        cout << "Value of a in struct is " << a << endl;
        cout << "Value of b in struct is " << b << endl;
    }
} ep;




int main()
{
    // Class ka object
    Employee rutu;
    rutu.c = 12;
    rutu.d = 13;
    rutu.setData(10, 11);
    rutu.getData();

    // Structure ka object
    ep emp1;
    emp1.setVal(10, 20);
    emp1.getVal();

    return 0;
}