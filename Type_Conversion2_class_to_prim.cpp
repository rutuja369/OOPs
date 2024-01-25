/*
Type Conversion 2:
Class type to primitive type conversion
Solution: Using casting operator

Syntax:
operator type()
{
    return (type->data); // jis type of data ko value assign karna hai usi type ki value return karni padegi na common sense!
}

Coz:
Complex c;
int x = c; //this conversion throws error

*/

#include <bits/stdc++.h>
using namespace std;

class Complex
{
private:
    int x, y;

public:
    Complex() {}
    Complex(int a, int b)
    {
        x = a;
        y = b;
    }

    void showData()
    {
        cout << x << " " << y << endl;
    }

    /*
    Casting Operator to rescue : make it as one of the member function
    Note: check out the syntax

    operator type()
    {
        return (type-data);
    }
    */ 

    operator int()
    {

        // or any data member associated with the object whose data type matches with the var we want to assign data to!
        // return x;
        // return y;
        return 10;
    }
};

int main()
{
    Complex c(2, 3);
    c.showData();

    /* Class to primitive conversion*/
    int x;
    /*
    This throws an error -> to solve it we have CASTING OPERATOR...
    Now the error disappears -> c obj now calls its casting operator to return the relevant type of data
    */
    x = c;
    
    /*
    Had it been a variable of float or double then syntax would be
    operator float()
    {
        return float_val;
    }
    */
    cout << x << endl;
    return 0;
}