/*
Friend Function:
- A friend Function is a special function -> can be an external func or member function of some "other" class
- Used to access private data of a class -> gets privileges to access private data by "friend" keyword
- Note that declaring an external func as friend -> doesn't make it a member func of that class -> its just that it gets some extra privileges of accessing private data of that class
  So-> Complex obj; -> obj.SumofComplex() -> this is completely invalid
*/

#include <bits/stdc++.h>
using namespace std;

class Complex
{
    int x;
    int y;
    // friend function -> getting permissions to access private data of this class
    friend Complex SumofComplex(Complex o1, Complex o2);

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

// External Function-> trying to access private data o1.x... of class complex-> need to add an declaration pf friend function
Complex SumofComplex(Complex o1, Complex o2)
{
    Complex o;
    // To access this private data-> this external function must have privileges from that class-> thus need to declare it as a friend function of that class
    o.setComplex((o1.x + o2.x), (o1.y + o2.y));
    return o;
}

int main()
{
    Complex c1, c2, c3;
    c1.setComplex(2, 4);
    c1.displayComplex();

    c2.setComplex(3, 9);
    c2.displayComplex();

    c3 = SumofComplex(c1, c2);
    c3.displayComplex();

    return 0;
}