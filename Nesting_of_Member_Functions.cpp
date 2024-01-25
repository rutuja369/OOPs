/*
Nesting of member fucntions:
If we want that specific function must not be directly accessed by the end user -> and should be actually executed internally
*/

#include <bits/stdc++.h>
using namespace std;

class A
{
private:
    string s;
    void check_bin();

public:
    void getBin();
    string ones_complement();
    void display(void); // doesn't take any arguments
};

void A::getBin()
{
    cout << "Enter your binary num " << endl;
    string str;
    cin >> str;
    this->s = str;
}

void A::check_bin()
{
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != '0' && s[i] != '1')
        {
            cout << "Incorrect Binary Format" << endl;
            exit(0); // exits the program -> directly
        }
    }
}

void A::display()
{
    cout << "Displaying your data" << endl;
    for (int i = 0; i < s.size(); i++)
    {
        cout << s[i];
    }
    cout << endl;
}

string A::ones_complement()
{
    /*
    Nesting of member function to-> This is one of the way abstraction is implemented
    - Avoid Direct acces to user make it private and nest it in some other member function
    - This way the func remains private and also used in its intended place
    - If one member function depends on result of some other member func-> use nesting -> call that func first and then-> evaluate based on its results
    */
    check_bin();

    cout << "Calculating Ones Complement of binary num" << endl;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '0')
            s[i] = '1';
        else if (s[i] == '1')
            s[i] = '0';
    }
    return s;
}

int main()
{
    A a;
    a.getBin();
    a.display();
    a.ones_complement();
    a.display();

    return 0;
}