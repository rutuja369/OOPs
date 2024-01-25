/*
Runtime Polymorphism
*/
#include <bits/stdc++.h>
using namespace std;

class Base
{
public:
    Base() {}

    virtual void xyz()
    {
        cout << "Hello I'm base class version of xyz" << endl;
    }
};

class Derived : public Base
{
public:
    Derived() {}

    void xyz()
    {
        cout << "Hello I'm derived class version of xyz" << endl;
    }
};



int main()
{
    /*
    Base class object -> either created statically or dynamically will always follow this
    when points to xyz() -> executes its own version as priority is first given to its own version
    */
    Base *b1 = new Derived();
    b1->xyz();

    /*
    When virtual func concept -> comes into picture-> we are able to implement it strictly in runtime only thus-> statically created base class obj cannot invoke derived class version of xyz()
    But, dynamically create obj-> ptr of base class is able to exe derived class version of xyz() -> due to declaring its own version as virtual
    This way, a single base class ptr can be used to exe its child's version of an overwritten func, when that ptr points to that specific child class
    */
    Base b2 = Derived();
    b2.xyz();

    /*
    Derived class object -> either created statically or dynamically will always follow this
    when points to xyz() -> executes its own version as priority is first given to its own version
    */

    Derived d1;
    d1.xyz();

    Derived *d2 = new Derived();
    d2->xyz();

    return 0;
}