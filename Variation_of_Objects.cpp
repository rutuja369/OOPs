/*
Variation of Constructors
Some important points about constructors

- Every class is provided with a default constructor and a copy constructor by compiler, but only when it does not find any user defined implementation of any kind of constructor(default, param, copy)
- If compiler finds even a single instance of user defined constructor then -> it will never provide uts own version and asks for all user defined implementations of any type of constructor that i want
EX: if i have a param con defined in my code and i am somewhere creating a blank object -> this needs a default con so compiler refuses and asks to declare my own default const

*/

#include <bits/stdc++.h>
using namespace std;

class BankDeposit
{
    int principal;
    int years;
    float rate;
    float res;

public:
    // Need to define my own default constructor as i have param implementation in my code
    BankDeposit() {}
    BankDeposit(int p, int n, float r);
    BankDeposit(int p, int n, int r);

    void Show()
    {
        cout << "Principle amount was " << principal << " Return value after " << years << " years is " << res << endl;
    }
};

BankDeposit ::BankDeposit(int p, int n, float r)
{
    principal = p;
    years = n;
    rate = r;
    res = p;
    for (int i = 0; i < n; i++)
    {
        res = res * (1 + rate);
    }
}

BankDeposit ::BankDeposit(int p, int n, int r)
{
    principal = p;
    years = n;
    rate = float(r) / 100;
    res = p;
    for (int i = 0; i < n; i++)
    {
        res = (res * (1 + rate));
    }
}

int main()
{
    BankDeposit bd1, bd2, bd3;

    int p, n, R;
    float r;

    bd3.Show(); //-> returns garbage value

    cout << "Enter the values of p, n and r" << endl;
    cin >> p >> n >> r;
    bd1 = BankDeposit(p, n, r);
    bd1.Show();

    cout << "Enter the values of p, n and R" << endl;
    cin >> p >> n >> R;
    bd2 = BankDeposit(p, n, R);
    bd2.Show();

    return 0;
}