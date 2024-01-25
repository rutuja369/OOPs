/*
Note: For more details about namespace -> refer the note on namespaces in notes section

Namespaces:
*/

// #include <bits/stdc++.h>

/*
Note:
- Below is a file (iostream)-> and not a header file as header files include '.h' -> extension
- This file contains the declarations for standard input and output streams cout and cin under the namespace std
-> cout and cin are standard input/output streams that are part of the iostream library.
-> cout: It is an instance of the ostream class, which stands for output stream.
-> cin: It is an instance of the istream class, which stands for input stream.
- Thus using namespace std -> to avoid the scope resolution every time
*/

#include <iostream>
using namespace std;

namespace Myspace
{
    int a;
    int func1();
    class Hello
    {
    public:
        void func2();
    };

}

// to access and define the functions from namespace -> need to use scope resolution operator
int Myspace::func1()
{
    cout << "Hello, I'm in func1" << endl;
    return 0;
}

// Now for func2-> We need to see that Myspace ka scope has hello class and hello class ke scope me hai func2
void Myspace::Hello::func2()
{
    cout << "Hello i'm in func2" << endl;
}

int main()
{
    // Cannot define a namespace in main function
    // Also now if i want to access any property of defined namespace ot init it->  i always need to define its scope
    Myspace::a = 5; // specifies that a lies in scope of Myspace

    // To avoid this scope declaration every time -> using namespace <name_of_out_namespace> ; //this helps a lot
    // This line can be used or declared anywhere in the code after which we dont need to use the scope resolution every time -> not necessary to be declared globally only -> anywhere is okay
    using namespace Myspace;
    cout << "value of a from Myspace is " << a << endl;

    // Similarly calling the func1 of Myspace without any scope resolution
    func1();

    // Similarly calling the func2 -> using the obj of Hello
    Hello h;
    h.func2();

    return 0;
}