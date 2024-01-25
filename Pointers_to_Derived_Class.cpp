/*
Pointers to Derived Class
*/

#include <bits/stdc++.h>
using namespace std;

class Base
{
public:
    int base_var;
    Base()
    {
        base_var = 1;
    }
    virtual void display()
    {
        cout << "Value of the base class var is " << base_var << endl;
    }
};

class Derived : public Base
{
public:
    int derived_var;

    Derived()
    {
        derived_var = 10;
    }
    void display()
    {
        cout << "Value of the base class var is " << base_var << endl;
        cout << "Value of the derived class var is " << derived_var << endl;
    }
    void greet()
    {
        cout << "Guten Morgen" << endl;
    }
};

int main()
{
    // Even if we do this-> Base class version of the display() version is only called
    // Coz since my object is of base class -> it gives priority for base class version to execute in compile time
    // here at the compile time-> Compiler cannot decide which function is to be called even if we declare the base class version as virtual

    Base b1 = Derived();
    b1.display();

    /*
    Very Very important ->>>>

    Benefits of Virtual Functions and base class ptr->
    1. Using Single Base Class ptr and declaring base class version of a function as virtual -> we can access the derived class versions of that overriden function
    2. Also, note that -> here the base class ptr can access only those methods that are inherited from itself in derived classes
                       -> Extra properties that belong to derived class are never accessible to base class ptr
    3. Also, note that -> Base class ptr can point to derived class object but inverse is not true
    4. Derived class ptr can never access or point to base class object

    Conclusion:
    - Without virtual fucntion declaration in base class -> By default always base clss's version only executes -> since the ptr is of base class
    - Only exe of derived class version takes place when -> Function overriding is implimented -> using virtual functions
    */

    Base *base_ptr = new Derived();
    base_ptr->display();

    // This is never possible -> Never try this-> as derived class has its own extra properties as well apart from those which are inherited
    // Derived *derived_ptr = new Base();

    return 0;
}