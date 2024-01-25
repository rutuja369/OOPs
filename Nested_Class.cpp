/*
Nested Class:
A class defined completely inside another class is called Nested class.

When to use the nested classes?
- The demonstrated example is best example - where we can see that address class has no individual significance and is valid or imp only when associated with a student obj t
- Thus, we define that class inside the student class itself -> its the beauty of OOPS so that we can store info in systematic manner and use efficiently

Properties or Imp points to remember:
1. Class defined completely inside other class is called nested class
2. Nested class is also treated as other data members and thus all those accessibility rights that they have same are applicable to this class as well
3. All the members of the nested class will also have the same accessibility rights as of the general class data members
*/

#include <bits/stdc++.h>
#include <string.h>
using namespace std;

class Student
{
private:
    int roll_no;
    char name[20]; // character array
    class Address
    {
    private:
        /*
        Note: Very imp ->
        - even if this class is defined inside the Outer class -> still its data members cannot access the private data of this class
        - they have acess to the object of this class but not the private members directly
        */
        int plot_no;
        char street[20];
        char area[20];
        char pincode[6]; // since we aren't performing any opr on them
        char district[20];
        char state[20];

    public:
        void setAddress(int p_no, const char *s, const char *a, const char *pin, const char *dis, const char *st)
        {
            plot_no = p_no;

            /*
            Note:
            - Whenever using a char array instead of string always remember !! fundamentals -> we cannot assign values like this
            - Always in case of char arrays -> use strcpy function
            - Syntax:
              strcpy(dest_array_ptr, src_array_ptr);  //same like cudamemcpy(dest_ptr, src_ptr, no_of_bytes, direction) -> ig all cpy func have this thing in common 1st dest_ptr then src_ptr

            So, below is valid in case of strings
            street = s;
            area = a;
            pincode = pin;
            district = dis;
            state = st;
            */

            strcpy(street, s);
            strcpy(area, a);
            strcpy(pincode, pin);
            strcpy(district, dis);
            strcpy(state, st);
        }

        void showAddress()
        {
            cout << "Address of student:" << endl;
            cout << plot_no << " " << street << endl;
            cout << area << " " << pincode << endl
                 << district << " " << state << endl;
        }
    };

public:
    // Creating the obj of nested class
    Address add;

    /*
    In C++, string literals are of type const char*, and attempting to assign them directly to a char* pointer
    without the const qualifier results in a warning.
    The warning is informing you that the conversion from a string literal to a non-const char* is not allowed in ISO C++.
    */
    void setStudentDetails(int roll, const char *n, int p_no, const char *s, const char *a, const char *pin, const char *dis, const char *st)
    {
        roll_no = roll;
        strcpy(name, n);

        // to set address -> access the setAddress() func of nested class address -> using "add" object
        add.setAddress(p_no, s, a, pin, dis, st);
    }

    void showStudentDetail()
    {
        cout << "Name: " << name << endl;
        cout << "Roll no: " << roll_no << endl;
        // to show address of student -> use showAddress() func of nested class uisng its object "add"
        cout << "Address: " << endl;
        add.showAddress();
    }
};

int main()
{

    Student rutu;
    /*
    Now, for nested classes -> 2 cases
    1. Class defined in private part: -> then obviously we cannot create the object of nested class in outside functions like main
    2. Class defined in public part: -> then to create and use the nested class object we need to use the scope resolution operator
    Syntax:
        Student::Address add;
    */
    // Student::Address add; //only valid when nested class defined in public part of outer class
    rutu.setStudentDetails(63, "Rutuja", 6, "Datta Nagar", "Jule Solapur", "413004,", "Solapur", "Maharashtra");
    rutu.showStudentDetail();

    return 0;
}
