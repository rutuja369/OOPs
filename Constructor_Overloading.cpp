/*
Constructor Overloading
*/

#include <bits/stdc++.h>
using namespace std;

class Complex
{
    int a, b;

public:
    // Default Constructor
    // Complex()
    // {
    //     a = 0;
    //     b = 0;
    // }

    // Parameterized Constructor-> with one default value
    Complex(int num = 12)
    {
        a = num;
        b = 0;
    }

    // Parameterized Constructor-> with two values
    Complex(int num1, int num2)
    {
        a = num1;
        b = num2;
    }

    void printData()
    {
        cout << "Complex number is " << a << "+" << b << "i" << endl;
    }
};

int main()
{
    Complex c1;
    c1.printData();

    Complex c2(5);
    c2.printData();

    Complex c3(3, 7);
    c3.printData();

    return 0;
}