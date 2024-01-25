/*
Static data members:-> default value is already 0
- Static data members are those variables that are associated with a class and not with any specific object
- Very imp-> these are always init outside the class-> can't init inside the class
 Reason: If init in class-> every obj will run class code-> and init it but since its static-> we wish to init it only once and later just keep updating

- They retain their previous value even if their scope terminates
- They are actually destroyed only when -> program terminates
- And also they are assigned memory only once at the first creation and later on just keep updating themselves
- We can access them directly using Class :: <static_var>; Ex:Employee::count

NOTE: BoTh of these are considered as property of the class and not any specific object

Static Member Functions:
- These are also special member functions that are associated with the class instead of a specific object
- These have access only to other static properties of the class-> such as static var and static methods
- Thus, accessing any non-static property(var/method) -> inside this func-> gives error!!!!
- These can also be used directly by Class::<static_method> as they are a property of Class!
*/

#include <bits/stdc++.h>
using namespace std;

class Employee
{
    // static var are only declared in class -> init is always done ouside the class
    static int count;

public:
    string emp_name;
    int emp_id;

    void setData(void);
    void displayData(void);

    static void getCount()
    {
        cout << "I'm a static member function" << endl;
        cout << count << endl;
        //Note: When trying to access a nonstatic prop like this -> in static method-> throws error 
        // cout << emp_id << endl;
    }
};

// Static var always defined and init outside the class
int Employee::count ;

void Employee::setData(void)
{
    count++;
    cout << "Enter Emp ID of employee " << count << endl;
    cin >> emp_id;
    cout << "Enter Emp Name of employee " << count << endl;
    cin >> emp_name;
}

void Employee::displayData(void)
{
    cout << "Emp with ID " << emp_id << " is " << emp_name << endl;
}

int main()
{
    Employee rutu;
    rutu.setData();
    rutu.displayData();
    Employee::getCount();

    Employee divya;
    divya.setData();
    divya.displayData();
    Employee::getCount();

    return 0;
}