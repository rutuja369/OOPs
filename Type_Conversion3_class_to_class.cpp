/*
Class type to Class type conversion
Solution:
1. using constructor (c = x) constructor in c (LHS)
2. using casting operator (x = c) casting opr in c (RHS)
*/

#include <bits/stdc++.h>
using namespace std;

class Item
{
private:
    int x, y;

public:
    Item() {}

    /*
    Solution to type conversion -> create Item constructor here
    */
    // Item(Product obj)
    // {
    //     x = obj.getval1();
    //     y = obj.getval2();
    // }

    void setX(int val1)
    {
        x = val1;
    }
    void setY(int val2)
    {
        y = val2;
    }

    void showData()
    {
        cout << "Values of x and y are " << x << " " << y << endl;
    }
};

class Product
{
private:
    int a, b;

public:
    Product() {}

    Product(int val1, int val2)
    {
        a = val1;
        b = val2;
    }

    void showData()
    {
        cout << "Values of a and b are " << a << " " << b << endl;
    }

    int getval1()
    {
        return a;
    }

    int getval2()
    {
        return b;
    }

    /*
      Other solution for same type conversion problem
    */
    operator Item()
    {
        //this can be declared here and set the values of x and y using a and b -> return obj of type ITEM
        Item obj;
        obj.setX(a);
        obj.setY(b);
        return obj;
    }
};

int main()
{
    Product pro(3, 2);
    pro.showData();

    Item item;

    /*
    Class type to class type conversion:
    1. Constructor ( c=x) -> done
    2. Casting operator (x=c)-> now this ->  done
    */

    item = pro;
    item.showData();

    return 0;
}