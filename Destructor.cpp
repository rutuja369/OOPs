/*
Destructor
*/

#include <bits/stdc++.h>
using namespace std;

class Num
{
    static int count;

public:
    Num()
    {
        count++;
        cout << "Calling constructor for object number " << count << endl;
    }

/*
    The destructor is not just used to release the resources but also to provide a
    place for cleanup operations and to execute some code when the object's lifetime ends. 
    So, here the task is decrementing the count
*/

    ~Num()
    {
        cout << "calling destructor for object number" << count << endl;
        count--;
    }
};

int Num ::count = 0;
int main()
{
    cout << "Inside main" << endl;
    cout << "Object one is getting created" << endl;

    Num n1;

    {
        cout << "Inside the block" << endl;
        cout << "Creating two objects" << endl;
        Num n2, n3;
        cout << "Exiting the block" << endl;
        //-> here the scope of n2 and n3 terminates
    }

    cout << "Back to main" << endl; //-> here the scope of n1 terminates

    return 0;
}