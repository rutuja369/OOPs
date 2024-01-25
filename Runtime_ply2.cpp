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
    virtual void abc()
    {
        cout << "Hello I'm base class version of abc" << endl;
    }
};

class Derived1 : public Base
{
public:
    Derived1() {}

    void xyz()
    {
        cout << "Hello I'm derived1 class version of xyz" << endl;
    }
};

class Derived2 : public Base
{
public:
    Derived2() {}

    void abc()
    {
        cout << "Hello I'm derived2 class version of abc" << endl;
    }
};

int main()
{
    /*
    Base class object -> either created statically or dynamically will always follow this
    when points to xyz() -> executes its own version as priority is first given to its own version
    */

    // Base *b1 = new Derived1();
    // b1->xyz();

    Base *b1 = new Derived2();
    b1->abc();

    /*
    When virtual func concept -> comes into picture-> we are able to implement it strictly in runtime only thus-> statically created base class obj cannot invoke derived class version of xyz()
    But, dynamically create obje-> ptr of base class is able to exe derived class version of xyz() -> due to declaring its own version as virtual
    This way, a single base class ptr can be used to exe its child's version of an overwritten func
    */
    Base b2 = Derived2();
    b2.xyz();

    /*
    Derived class object -> either created statically or dynamically will always follow this
    when points to xyz() -> executes its own version as priority is first given to its own version
    */

    Derived1 d1;
    d1.xyz();

    Derived2 *d2 = new Derived2();
    d2->xyz();

    return 0;
}