/*
Type Conversion 1:
Primitive to Class type
Solution: Using Constructors
Note: Constructors are also called at that time -> when we try assigning a diff type of value to an obj
      But for this the value we are trying to assign must me similar to atleast one of the data members of the class else gives a compile time error

Coz:
Complex c;
int x=5;
c = x; //gives error
*/

#include <bits/stdc++.h>
using namespace std;

class Complex
{
private:
    int x, y;

public:
    // Default constructor! -> we need to provide -> compiler wont as we have a user defined constructor already in code
    Complex() {}

    Complex(int k)
    {
        x = k;
        y = 0;
        //OR below is also allowed -> upto programmer
        x=k;
        y=k;
    }

    void showData()
    {
        cout << "Value of x and y are " << x << " And " << y << endl;
    }
};

int main()
{
    Complex c;
    int x = 10;

    /* Primitive to class type conversion -> solved using constructor*/
    //this conversion -> throws an error -> as by default theres no such conversion!!-> Solution a constructor
    //now error disappears-> as a constructor is called (when we try assigning a diff type val to the obj) which takes int value and its upto us where to assign it in object
    //its same as Complex c= Complex(x) -> imp
    c = x; 
    c.showData();

    return 0;
}
