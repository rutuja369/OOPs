/*
Exception Handling

Exceptions:
- They are any unexpected behaviours/runtime errors in our program -> whose handling needs to be taken care of
- These are just off beat situations which need to be precalculated and our program must be designed in such a way that if such errors occur what is to be done or printed or resolved is already known so that we can manage such errors easily
- Ex: For an factorial program-> user enters -ve val -> now user can't be stopped from entering any value -> so we need to make sure that our program itself handles that thing very robustly and handle this exception
- In cpp we have a provision of handling error -> called exception handling -> using which we can respond and manage runtime errors effectively

Cpp Exception handling mechanism:
- This mechanism involves 3 components: try -> throw -> catch



### try, throw and catch all three are keywords ###


Try and Catch blocks: Control flow constructs
- Dont misinterpret them as functions as they are entered into automatically when error occurs-> not after a call
- These are control flow constructs
Throw:
- Its a keyword in cpp and java used to handle and throw the exception

1. try{ } block:
- Program statements that we consider might contain some error or need monitoring are included in try block
- only try without catch -> gives error and vice versa

2. throw keyword:
- Syntax:
    throw <data>
- If any exception occurs within the try block then it is thrown using throw keyword
- throw keyword should be used within the try block only but it does not necessarily need the try block -> can exist independently without any error
- throw must be followed by some data i.e our exception no. or any data

3. catch{ } block:
- The exception thrown using throw is caught here -> and processed
- needs try block -> only catch without try also gives error as mentioned


Overall Syntax of try and catch
try{
    throw <data/exception>
}
catch( type 1 arg)
{

}
catch (type 2 arg)
{

}
.
.
catch(type N arg)
{

}

Note:
- There should be a continous series of try and its corresponding catch blocks no intermediate code should interrupt
- after try -> lagech catch block must start
- single try and multiple catches allowed based on what type of data is to be catched or handled
-

*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    cout << "Currently everything is fine here" << endl;

    /* Continous seq must be there-> no */
    int num = 20;
    try
    {
        /* code */
        if (num % 2 == 0)
            throw 10;
        else
            throw 10.0; // if entered here -> gives termination as no catch block to handle this double type error
        cout << "hello" << endl;
    }
    // this is a generic or catch-all wala catch block (try or catch me koi dusra statement nai aana chahiye or else it will not consider the below catch block-> ball throw karne ke baad jaldi se catch honi chahiye na without any delay -> same with errors hehe)
    catch (int)
    {
        /*
         ->As cout is an output stream associated with the standard output device
         ->cerr is an output stream associated with the standard error device (indicates that the info being output is from some error)
        */
        cout << "Exception caught!!" << endl;
        cerr << "Exception handled well!!" << endl;
    }

    /*

    Observations !! Try them out
    1. Try ko catch and catch ko try chahiye hi chahiye -> either of them is absent -> gives error

    2. Only throw with data (ex: throw 10;)-> hai without try and catch -> works -> but then since no catch block to handle that error -> so it terminates the program by calling a termination function -> which further calls an abort function and program is aborted!!

    3. Only throw followed by no data/exception returned (ex: throw ;) -> gives again a same termination -> this time saying no active exception

    4. Also if my exception thrown is of type int and there's no corresponding catch block to catch it -> then also program terminates as no catch block to handle it

    5. Once a catch block catches the exception -> no further catch blocks are considered just like switch statement

    6. A single try block can have multiple statements or conditions of diff errors and we can also have a single catch block for any type of exception using
    Syntax:
    try{

    }
    // this is a generic or catch-all wala catch block
    catch(...)
    {

    }

    7. "..."  -> is called -> ellipsis it is used in function calls and to define templates that can take variable no. of arguments

    8. NOT necessary that catch block must have a arg to store the values -> its completely optional to store the data thrown from throw -> but yes need to mention the type of that data
    Syntax:
    catch (int){} -> is fine to handle an int type error

    9. Also this data type can be primitive or class type -> i.e user defined datatype
    Syntax:
    catch(Student)
    {

    }
    where Student is -> user defined datatype

    10.Finally not necessary that throw has to be called inside the try block directly -> we can call a function there -> which will then call a throw inside it -> so this variation can also be tried
    Syntax:
    func()
    {
        throw <data>;
    }
    func1()
    {
        try
        {
            if( num % 2==0)
            func();
        }
        catch( int ) //here arg is not necessary -> its only when you want to store that exception value -> But the datatype of exception must be mentioned!!
        {
            cout<<"Exception with value 10 is caught"<<endl;
        }
    }

    So,
    Specifications for catch block:
    1. Specifying arg in catch func call -> is not necessary
    2. But do Specify the datatype of exception -> or use ...(ellipsis) for catching all types of values
    3. Any type of exception can be caught-> primitive or user defined data

    Specifications for throw keyword:
    1. General form: throw <exception_data>
    2. Not necessary that throw must be written in try block itself-> we can make a func call inside the try block and that function can also contain throw statement-> this will also result in ending up in appropriate catch block


    Note: this syntax is truely valid!! 
    */

    cout << "Done with exception handling" << endl;
    return 0;
}