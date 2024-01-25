/*
Member Friend Function:
Same as we can declare an external function as a friend of some class XYZ->
similarly, a member function of some class ABC can also be declared as friend of a class XYZ;

Friend Class:
If we want only 1 or 2 member function of class A to access private data of class B-> then we can individually declare them as friends of class B
But, if the requirement is that -> 5-6 member functions of class A -> wish to access private data -> then
Its better to declare the entire class A as friend of class B
*/

#include <bits/stdc++.h>
using namespace std;

// Forward Declaration is necessary -> to intend the compiler that it will find complex class further in the code
class Complex;

class Calculator
{

public:
    int add(int x, int y)
    {
        return (x + y);
    }

    //these also need to be implemented further after exe of Complex class -> as before that compiler doesn't know what x and y are
    int SumofReal(Complex, Complex);
    int SumofNonReal(Complex, Complex);
};

class Complex
{
    int x;
    int y;

    // Individually assigning friend declarations to mem func of Cal
    // friend int Calculator::SumofReal(Complex o1, Complex o2);
    // friend int Calculator::SumofNonReal(Complex o1, Complex o2);

    // But, what if??-> there are 10 such mem functions in class Cal to access private data-> thus we can declare an entire class as friend of Complex
    friend class Calculator;

public:
    void setComplex(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
    void displayComplex()
    {
        cout << "Complex number formed is " << x << "+" << y << "i" << endl;
    }
};

int Calculator::SumofReal(Complex o1, Complex o2)
{
    // throws error as this mem func is trying to access private data of class Complex-> solution-> friend
    return (o1.x + o2.x);
}

int Calculator::SumofNonReal(Complex o1, Complex o2)
{
    // throws error as this mem func is trying to access private data of class Complex-> solution-> friend
    return (o1.y + o2.y);
}


int main()
{

    Complex o1, o2;
    o1.setComplex(1, 3);
    o2.setComplex(3, 7);

    Calculator cal;
    int res1 = cal.SumofReal(o1, o2);
    int res2 = cal.SumofNonReal(o1, o2);
    cout << "Sum of real part of Complex numbers o1 and o2 is " << res1 << endl;
    cout << "Sum of non-real part of Complex numbers o1 and o2 is " << res2 << endl;
    return 0;
}