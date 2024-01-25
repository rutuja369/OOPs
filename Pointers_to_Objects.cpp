/*
Pointers to objects
*/

#include <bits/stdc++.h>
using namespace std;
class Complex
{

    int real, imaginary;

public:
    Complex()
    {
        real = 10;
        imaginary = 20;
    }
    Complex(int r, int i)
    {
        real = r;
        imaginary = i;
    }
    void printComplex()
    {
        cout << "Complex number formed is " << real << " + " << imaginary << "i" << endl;
    }
};

int main()
{
    // static object creation
    Complex c1(1, 2);
    c1.printComplex();

    // We can also create a pointer of Complex class-> means it points to an object of type Complex

    // Method 1: Pointer pointing to existing object
    Complex *ptr = &c1;
    // This is same as
    (*ptr).printComplex();
    // this below syntax
    ptr->printComplex();

    // Method 2: Pointer pointing to an object that is dynamically created
    Complex *p = new Complex(4, 15);
    // Again below two syntaxs are same
    p->printComplex();
    (*p).printComplex();

    Complex *objarr = new Complex[3];
    for (int i = 0; i < 3; i++)
    {
        objarr[i].printComplex();
    }
    delete[] objarr; // deletes the allocated continous block of memory

    return 0;
}