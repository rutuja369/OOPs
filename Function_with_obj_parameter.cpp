// Functions with objects as parameters
#include <bits/stdc++.h>
using namespace std;

class Complex
{
private:
    int real, img;

public:
    void input()
    {
        cout << "Enter values of real part(a) and imaginary part(b) of object " << this << endl;
        cin >> real >> img;
    }
    void display()
    {
        cout << "Complex no. is " << real << " + " << img << "i" << endl;
    }

    // Special custom add function-> takes an object as input
    Complex add(Complex b)
    {
        Complex c;
        c.real = real + b.real;
        c.img = img + b.img;
        return c;
    }
};

int main()
{
    Complex a, b, c;
    // This is not directly possible coz compiler doesnt have any implementation for + opr where operands are custom objects-> we need to define this implementation explicitly
    //  c3= c1+c2;
    // So, this special function-> which takes object as parameter needs to be a member function of class -> to get direct access of properties of an object
    a.input();
    a.display();

    b.input();
    b.display();

    c = a.add(b);
    c.display();

    return 0;
}