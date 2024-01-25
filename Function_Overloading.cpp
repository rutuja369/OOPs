/*
Function Overloading-> Ek naam kai kaam
- Function overloading states that I can implement same function identifier with different argument list to do various task
- For a Function to overload we need to follow major condition that-> Function identifier must be same
                                                                   -> Function argument list must have some variation -> means datatype must be diff or number of parameters passed should be diff-> then only we can state that its function overloading
- Also a common doubt is-> What if I change my return type or keep it same
-> here both the cases are valid and Function overloading never depends on return type ( int ya float pharak nahi padta)
- Comes in compile time polymorphism-> here compiler matches the prototypes of the function calls with function definitions existing in the code and matches based on arg list
*/

#include <bits/stdc++.h>
using namespace std;

// Cylinder's Volume
int volume(int radius, int height)
{
    cout << "Cylinder ke volume ka int version called" << endl;
    return (3.14 * radius * radius * height);
}
// Error: Fucntion overloading is possible only when there is atleast some modification in arg list such  as changing- datatype or number of arg> and return type pr toh depend hi nai karta so change it or dont doesn't matter!!!!!!!!
// float volume(int height, int radius)
// {
//     //Note: Here arg list is same -> changing seq won't be sufficient -> need to change either the datatype or number of arg passed
//     return (3.14 * radius * radius * height);
// }

// This is valid as here arg list is modified by changing the return type of atleast one parameter
float volume(int radius, float height)
{
    cout << "Cylinder ke volume ka float version called" << endl;
    return (3.14 * radius * radius * height);
}

// Cube's volume
int volume(int a)
{

    cout << "Cube ke volume ka functional version called" << endl;
    return (a * a * a);
}

// Reactangle's Volume
float volume(int l, int b, float h)
{
    cout << "Rectangle ke volume ka functional version called" << endl;
    return (l * b * h);
}

int main()
{
    // Implementing function overloading-> Compile checks for prototype of function and tries to match with the functions of same identifier
    // cout << "Volume of Cylinder is" << volume(3, 4) << endl;
    // Note:here while function overlaoding adding suffix f-> for float values is imp
    cout << "Volume of Cylinder is" << volume(2, 3) << endl;

    //here function overloading is resolved using 3 way rule -> type conversion of arg in req datatype caused t=due to no exact matching
    cout << "Volume of Rectangle is" << volume(3, 4, 5.1) << endl;
    cout << "Volume of Cube " << volume(3) << endl;
    return 0;
}