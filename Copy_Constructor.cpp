/*
Copy Constructor
- Imp points to note
1. Compiler provides a default copy constructor as well but only if it doesn't find any user defined implementation of "copy" constructor
Reason: If you do not explicitly define a copy constructor in your class, the compiler will automatically generate a default copy constructor for you.
        The default copy constructor performs a shallow copy of the class data members, which means it copies each member from the source object to the new object.
        For pointers and dynamically allocated resources, this can lead to issues if a deep copy is required.

2. The default copy constructor of compiler -> performs shallow copy
3. Implement shallow and deep copy here later on
4. If i want a deep copy implementation-> then i need to define my own version of deep copy constructor


Types of Copy:
1. Implicit copy assignment opr 
2. Shallow Copy
3. Deep copy

1. Implicit copy Assignment opr:
- An obj can be copied into another using = opr
- Syntax:
Number n1;
Number n2;
n2= n1; //n2 is a copy of n1 created using copy assignment opr

2. Shallow copy
- Creating copy of  obj by copying data of all data members as it is 
- Here both the copied and ori object share same ref to an external memory associated with data members 
- Thus, changes made by one reflect on other

3. Deep copy
- Creating on object by copying data of another obj along with the new ref to external memory allocations associated with original object
- Here, both the objects have separate ref to external memory allocations-> thus changes made by one do not reflect on other


Note: Copy constructor is called for an object o2 only when it is being initialized with some object o of same class -> at the time of creation itself
means:
ex: Pencil apsara= natraj; //this is where copy constructor will be definitely called for apsara -> thus copy is carried out using copy constructor in this case
    Pencil apsara;
    apsara= natraj; //in this case it wont be called as we are not assigning while creation itself -> thus copy is carried out using implicit assignment operator here
*/


#include <bits/stdc++.h>
using namespace std;

class Number
{
    int a;

public:
    Number()
    {
        a = 0;
    }

    Number(int num)
    {
        a = num;
    }

    // Here if I dont have my user defined copy constructor -> the compiler provides me with its own default copy constructor
    Number(Number &obj)
    {
        cout << "Copy constructor called!!!!!" << endl;
        a = obj.a;
    }

    void display()
    {
        cout << "Data is " << a << endl;
    }
};

int main()
{
    Number n1;
    n1.display();

    Number n2(2);
    n2.display();

    // Copy constructor called-> valid
    Number n3(n2);
    n3.display();

    // Copy constructor called-> valid
    /*
    This is a shallow copy -> also when an object is assigned after its creation to other obj -> thats called obj copying with implicit copy assignment opr
    Ex:
    Number n1;
    n1= n2; //this is copy with implicit copy assignment opr
    and
    Number n3 = n2 ;// this is copy with copy constructor -> copy constructor is called only when copy is carried out while obj creation itself
    */
    Number n4 = n2;
    n4.display();

    Number n5;
    n5 = n1; // here copy constructor wont be called
    n5.display();

    return 0;
}