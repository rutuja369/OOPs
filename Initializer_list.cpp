/*
Initializer List:
- Initializer list is used to initialize data members of a class
- Syntax:
        class Num
        {
        private:
            int a;
        public:
            Num(): a(<value>)
            {

            }
        };
- This initialization list is used in two situations:
1. To initialize non-static constant data member values
2. To initialize reference members
*/

#include <bits/stdc++.h>
using namespace std;

class Num
{
private:
    int a;
    const int const_val;
    int &b;

public:
    // this is throwing error coz: a const and ref data member must always be init in the initialization list and not in the body of the default or param constructor
    // Num() : a(10), const_val(2.9),  {}

    Num(int &data) : a(1), const_val(3.14), b(data)
    {
        b = data;
    }
};
int main()
{
    int x = 10;
    Num obj(x);

    return 0;
}