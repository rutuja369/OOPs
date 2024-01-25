/*
Implementing Deep and Shallow copy

Shallow Copy:
- Creating a copy of object by copying the data from that object as it is
- Here only values held by data members are copied actaul memory resources are not copied
- Means if that object contains any memory allocations associated with it-> that is also copied as it is -> address is copied of that mem allocation instead of values stored in that mem location

Deep Copy:
- Here only values are copied from tha previous object and if any memory allocations associated with that object then -> those are allocated newly for new object and only values from previous obj are copied and transferred to newly allocated location
- Memory resources if held by any object-> those are also created newly ( a copy of such resources is created for new obj)

Conclusion: Shallow copy must not be used when obj has some memory resources associated with it using ptrs -> deep copy must be used here


#### Also note: never forget that copy constructor is not the only way to copy an object -> we also have "implicit copy assignment operator" -> but to implement deep copy here as well we need to follow same concept

*/

#include <bits/stdc++.h>
using namespace std;

class Num
{
private:
    int x;
    int *ptr;

public:
    Num(int a, int b)
    {
        // constructor -> here initialization happens
        x = a;         // x initialized
        ptr = new int; // ptr initialized
        *ptr = b;
    }

    // Shallow copy-> compiler -> by providing its own copy constructor -> performs shallow copy by default
    // Num(Num &obj)
    // {
    //     x = obj.x;
    //     ptr = (obj.ptr); // this way the copy of address stored by obj.ptr is shared to this.ptr and thus both obj start pointing to same mem allocation
    // }

    // Thus-> to solve above issue -> user needs to explicitly perform deep copy and ensure that all ptrs are provided with new mem allocations and then only the contents are copied in those new locations
    Num( const Num &obj) //use const to avoid modification in body of constructor -> to be safe
    {
        x = obj.x;
        // In Deep copy version -> we'll need to explicitly allocate memory to all the ptrs pointing to external memory and then copy only the content of ori obj to new ptrs -> this way we'll generate separate mem allocations for both the objects
        ptr = new int;
        *ptr = *(obj.ptr);
    }

    /*
    When performing shallow copy-> destructor destroys the external memory allocation for the curr obj-> but other objects also suffer-> as their ptrs become dangling ptrs -> since they are pointing to a destructed memory
    Since, they were sharing the memory allocation -> thus their ptrs become dangling ptrs now-> pointing to destroyed mem allocations
    */
    ~Num()
    {
        delete ptr;
    }

    void showData()
    {
        cout << "Value in member variable is " << x << endl;
        cout << "Value in ptr member variable is " << *(ptr) << endl;
        cout << "Also whats stored in this ptr: address of ptr var " << ptr << endl;
    }
};

int main()
{
    // Num num1(5, 6);
    Num num1 = Num(5, 6);  //above and this both are same -> but use const for copy constructor args to implement without error
    num1.showData();

    Num num2 = num1;
    num2.showData();

    return 0;
}