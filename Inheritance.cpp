/*
Inheritance-
Important points:
1. Access modifiers- public
                     private
                     protected

2. Private members of the base class never get inherited ( keep this in mind forever!!)
3. Default access modifier is: "Private"
4. If access modifier specified as
    a. private:-> as we are explicitly mentioning that inherit properties in private mode-> public and protected members become -> private members of derived class
    b. protected:-> as we are explicitly mentioning to inherit properties in protected mode-> public and protected members become protected members of derived class
    c. public:-> as we are explicitly mentioning to inherit properties in public mode-> protected will stay protected and public will become public members of derived class
*/

#include <bits/stdc++.h>
using namespace std;

// Base class
class Employee
{
protected:
    int emp_id;

public:
    string emp_name;
    // Make sure that my base class always has a default constructor-> custom implementation
    Employee() {}

    Employee(string name)
    {
        cout<<"setting employee name as "<<name<<endl;
        this->emp_name = name;
    }
};

// Derived Class
// Note: If nothing mentioned -> default access modifier is private
class Programmer : public Employee
{
public:
    int language_code = 0;

    Programmer(int id, string name) : Employee("rutuja")
    {
        emp_id = id;
        language_code = 2; //-> C++
        cout<<"setting employee name as "<<name<<endl;
        emp_name = name;
    }

    void getData()
    {
        cout << "ID of the programmer is " << emp_id << " who uses language with code " << language_code << endl;
        cout << "Name of the programmer is " << emp_name << endl;
    }
};

int main()
{
    // whenever derived class constructor is called-> automatically base class ka "default constructor" is called!!!
    Programmer rutuja(2, "neha");
    rutuja.getData();

    return 0;
}