/*
Objects can also be passed as args to other functions
*/

#include <bits/stdc++.h>
using namespace std;

class Complex
{
    int x;
    int y;

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

    //A member func or external function-> can access the object of same or diff class as its arg
    void SumofComplex(Complex o1, Complex o2)
    {
        x = o1.x + o2.x;
        y = o1.y + o2.y;
    }
};

int main()
{
    Complex c1, c2, c3;
    c1.setComplex(2, 4);
    c1.displayComplex();

    c2.setComplex(3, 9);
    c2.displayComplex();

    c3.SumofComplex(c1, c2);
    c3.displayComplex();

    return 0;
}