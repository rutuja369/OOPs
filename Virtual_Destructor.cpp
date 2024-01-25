/*
Virtual Destructors:

Revising Destructors:
Syntax:
class A
{
    public:
    A()
    {
        //Constructor...
    }

    ~A()
    {
        //Destructor...
    }
};

- So, destructor is also a func like constructor -> which is definitely, guaranteedly being called for the object -> but while the scope of object ends-> or when life of obj finishes off-> before that this is the last func being called for that object
- Constructor: 1st func being called after object creation -> used for memory allocation related to object
  Destructor: last func being called before object destruction -> used for memory destruction related to object
- Its a special function that is used to perform tasks that are related to releasing the memory associated with object ( such as external mem being pointed by some pointers of object)
  Such cleanup tasks are carried out in destructors

Ex:
class A
{
    int *p
    public:
    void func()
    {
        p = new int;
        *p =10;
    }
    ~A()
    {
        So, here before deleting the object -> its important to make sure that all the associated memory is deleted
        here, p -> the ptr gets deleted after the scope of object ends. But what about that memory which is being pointed by the pointer p -> who will free it up
        Such memory allocations need to be deallocated before obj gets destroyed and hence we need to explicitly use delete keyword and delete the memory
        Such tasks are performed in destructor

        Note: here p is not getting deleted -> instead the memory whose address is stored in p -> gets deleted!
        delete p;

    }
};

## new and delete
1. new keyword:
Syntax:
   new <data_type> (ex: new int)
- here new returns the address of memory allocated to store an int value -> means 4 bytes of memory is allocated and address returned-> which can be stored into some ptr var
- also memory allocated using new keyword -> does not automatically gets deleted as other variables -> we need to explicitly delete it using delete keyword

2. delete keyword:
Syntax:
   delete <pointer_name>
- here delete keyword deletes the memory that the pointer points to.



### Base ptr can point to the object of derived class
*/

#include <bits/stdc++.h>
using namespace std;

class Parent
{
    int a;

public:
    void func1()
    {
        cout << "Func from Parent class" << endl;
    }
    ~Parent()
    {
        //...
    }
};

class Child : public Parent // publically inheriting the parent class-> means protected members of parent class will stay protected and public will be inherited publically and private will never be inherited
{
    int b;

public:
    void func2()
    {
        cout << "Func from child class" << endl;
    }
    ~Child()
    {
        //...
    }
};

void func()
{
    /*
    We have basic understanding saying -> var jis type ka hai usi type ka ptr bhi hona chahiye
    int *p = new int
    thus,
    Child *p= new Child
    this syntax is completely valid -> coz p should be of type same as the object that its pointing
    But, in case of inheritance in cpp

    Parent *p = new Child;

    This syntax is also completely valid -> and we can point the pointer of base class to child class
    But remember -> it will have access to only those properties that are created in class parent and inherited by class B
    and thats obvious also coz-> at compile time early binding happens -> the compiler only has syntax with it and syntax says that pointer is of type A
    so, it expects that ptr p must point to only those properties that A binds or contains
    */

    Parent *p = new Child;
    p->func1(); // this is valid as at compile time due to early binding -> Parent is the type pf p-> so p can access props of Parent
    // p->func2(); //this throws error

    /*
    Now that func-> terminates here -> so the scope of Child obj also ends -> p is a local var so it gets deleted automatically but
    but, the obj that was allocated memory using new-> that remains as it is so to delete that obj-> need to explicitly invoke delete
    */

    delete p;

    /*
    Problem:
    The major question here is -> which destructor will the compiler call ???
    See, if obj was not created dynamically (using new) and was created statically -> in that scenario: while destructing such static objects -> destructor of B is called first and later that B class ka destructor calls A class ka (parent) destructor
    But, here as the object is created dynamically and main point is its being pointed by a ptr of class parent
    Ex:
    B *p = new B;
    In above case also the seq of destructor would have been -> 1st child -> then parent

    But,
    A *p = new B;
    In this scenario-> due to early binding -> compiler at compile time checks the type of ptr -> which is A
    and thus only calls destructor of class A. Now, as object of class B -> will obviously contain the properties of its own + properties inherited from A (parent)
    and destructor of only parent is invoked -> thus resulting in incomplete memory deallocation
    A ka -> destructor -> will deallocate only its own properties inherited by that obj
    B ka -> destructor -> is ignored completely -> leaving its properties as it is-> wasting the memory (dynamic memory if any)

    Solution:
    To avoid this -> we declare the destructor of parent class as vritual -> and also the destructor of child class also becomes virtual and thus late binding happens
    Now, at runtime the compiler checks actual content being pointed by ptr p instead of its type -> finds out that p is actually pointing to child ka object and thus the virtual keyword helps to exe
    the child class version of virtual destructor 1st -> later on the parent class destructor -> and this way complete memory deallocation is done!
    */
}

int main()
{
    func(); // func call
    return 0;
}