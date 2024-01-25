/*
Dynamic Constructor:

What is the role of constructor in object's life?
- Constructor ye obj ke life me chalne vala very first and guaranted function hai
- Object is called an object only when -> it represents any real life entity(ex: student) and when actual data of a student is stored in it
- So, basically before using any methods of the object -> all its data must be filled and this initialization of data members is imp which is done by constructor
- Also note that -> constructor is called after object creation -> constructor is not the one creating that onj -> object toh pehle banega
  Instead, constructor will initialize that obj -> just after its creation ( so constructor init object !!)

Now What is Dynamic Constructor?
- A myth: dynamic constructor is the one that is called when we create an object dynamically
- While object creation -> first obj is created its assigned memory and then constructor is called as per the class written  ( so clearly constructor is not the one which allocates object ki memory -> its the one which initializes its properties)
  Car *p = new Car() ; -> but thats not true
- A dynamic constructor is any general constructor which is creating or allocating a memory block -> which will be pointed by one of the data members of that object
  Means: this constructor will allocate dynamically created memory to its object and that object will be using that memory allocation -> which is dynamicallu created by that constructor in its further life

Conclusion:
- Always remember -> dynamic concstructor -> object ki memory nahi banata -> woh object ke dwara handle hone wali dynamic memory create(allocate) karta hai
- Its not the constructor which is called when object is created dynamically -> rather its a constructor which will allocate dynamic memory block for the use of one of the data members of that object
- Ex:
  class Complex
  {
    int a, b, *p;
    public:
    //This is a dynamic constructor -> as its allocating a memory block for its obj -> which will be pointed by ptr p
    Complex()
    {
        p = new int;
        *p =0;
    }

    //Similarly this is also a dynamic constructor: Mhanje asa constructor jyat dynamic mem allocation hotay
    Complex(int x, int y, int z)
    {
        a= x;
        b= y;
        //dynamic mem allocation
        p = new int;
        *p = z;
    }
    Constructor ke dwara -> object ke dwara handle hone wali memory ka creation karna -> dynamic creation -> aisa constructor dynamic constructor kehlata hai...
  }

*/

#include <bits/stdc++.h>
using namespace std;

class Complex
{

private:
    int a, b, *p;

public:
    Complex()
    {
        a = 0;
        b = 0;

    } // default constructor
    // Now below is a dynamic constructor -> as its creating a dynamic memory which will be used by p ( data mem of object)
    Complex(int x, int y)
    {
        a = x;
        b = y;
        p = new int;
        *p = 10;
    }

    void showData()
    {
        cout << "Complex number is " << a << "+i" << b << endl;
        cout << "And value at address held by ptr p is " << *p << endl;
    }
};

int main()
{
    Complex c1 /*default called*/, c2(2, 3) /* parametarized called*/;
    c1.showData();
    c2.showData();

    return 0;
}