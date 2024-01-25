/*
Constructors:-
- These are special member Functions -> used to init the objects i.e properties of objects
- They have their name same as that of class-> thats the reason why they are invoked automatically
- They donot have any return type -> not even void -> nastoch return type
- 3 Types: Default, Parameterized, Copy
- We cannot refer to their address-> search this!!
*/

#include <bits/stdc++.h>
using namespace std;

class Complex
{
    int a, b;

public:
    // Declaring a constructor of this class->
    // Note: Declaration must always be in public part as obj invokes it directly-> so it must be in public part
    Complex(void); // This one is a default constructor -> with no parameters

    Complex(Complex &obj)
    {
        cout << "Inside copy constructor" << endl;
        a= obj.a;
        b= obj.b;
    }
    void printData()
    {
        cout << "Complex number is " << a << "+" << b << "i" << endl;
    }
};

// Defined constructor outside
Complex::Complex(void)
{
    a = 10;
    b = 0;
}

int main()
{
    // Static method of obj creation
    Complex c1;
    
    //Here copy constructor provided by compiler is used if no custom implementation provided
    Complex c2(c1);
    c1.printData();
    c2.printData();
    return 0;
}