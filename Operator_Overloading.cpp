/*
Operator Overloading:
-> Compile Time polymorphism implemented using -> operator overloading
-> Asking an operator to take multiple forms
-> Excluded operators that cannot be overloaded-> ::(scope resolution), ?:(ternary opr), .(member access) etc
*/

#include <bits/stdc++.h>
using namespace std;

class A
{
    int a;
    int b;

public:
    A()
    {
    }
    A(int num1, int num2)
    {
        a = num1;
        b = num2;
    }

    // Syntax of Operator overloading:
    // Its just that whenever we use a valid operator as a fucntion identifier -> we need to use a keyword operator before the operator symbol
    // <returntype> operator<operator_tobe_overloaded>()
    // {
    // }

    // overlaoding + operator
    int operator+(A &obj)
    {
        int val1 = a;
        int val2 = obj.a;
        // cout << val1 - val2 << endl;
        return val1 - val2;
    }
    // overloading ()  operator
    void operator()()
    {
        cout << "Mujhe isne call kiya hai " << this->a << endl;
    }
    // overloading * operator
    A operator*(A obj)
    {
        // define a default constructor always -> coz compiler wont provide that
        A temp;
        temp.a = a * (obj.a);
        temp.b = b * (obj.b);

        return temp;
    }
    // overlaoding preincrement ++x operator
    A operator++()
    {
        // first increment the values in a and b -> then copy
        A temp;
        temp.a = ++a;
        temp.b = ++b;
        return temp;
    }

    // just to avoid confusion by the compiler between both the fucntions -> we show a slight change in the prototype by including int param
    A operator ++(int) // note we dont actually have to pass any int value while calling
    {
        A temp;
        // first copy values in a and b and then incr in actual a, b
        temp.a = a++;
        temp.b = b++;

        return temp;
    }
    // Extraction >> and insertion << operator overloading -> if we need to take a complex obj as input ex: cin>>c1 -> not possible primitively llar goes with cout<<c1
    /*
    Here's how the need of friend function comes into picture
    Actually, here we cannot make the overloading func as a mem func of this class A as we cannot use the object of this class as a caller object
    Ex: cout<<c1 -> here cout (and not complex class object) must be a caller object thus -> need to make a general friend func
                    this will also help in chaining -> cout<<c1<<c2-> here cout<<c1 ->must also return obj of type cout

    Note: We cannot use or return the ostream and istream class objects directly so we need to use reference
    */

    friend istream & operator>>(istream &, A &); // here ref is required as modifications need to be performed on object of A-> taking user input
    friend ostream & operator<<(ostream &, A);   // here ref is not required we are just printing

    void showData()
    {
        cout << "Value of a is " << a << " and Value of b is " << b << endl;
    }
};

//--------------------------------------------------------
// Important:
//return type is ref opf class ostream and istream resp:-> as we cannot use the obj of that class directly
//note: If we cannot use an object of a class directly -> use its reference -> has a wide application remember this...
ostream& operator<<(ostream &res_out, A obj)
{
    //here passing the object of class ostream was imp to return it and use in further chaining -> 
    //note we need to implement operator overloading in such a way that -> all features of that operator as it is can be used on user defined objects
    cout << obj.a << " " << obj.b << endl;
    return res_out;
}

istream &operator>>(istream &res_in, A &obj)
{
    cin >> obj.a >> obj.b;
    return res_in;
}

//--------------------------------------------------------

int main()
{
    A obj1(1, 4), obj2(4, 5), obj3;
    // overloading an operator -> + operator performs - operation
    // obj1 + obj2;

    cout << obj1 + obj2 << endl;
    obj1();

    obj3 = obj1 * obj2;
    obj3.showData();
    obj3 = obj1++;
    obj3.showData();

    obj3 = ++obj1;
    obj3.showData();

    A obj;
    cout << "Enter the value of object of class A" << endl;
    cin >> obj;

    cout << "Check the values of object of class A" << endl;
    cout << obj << endl;

    return 0;
}
