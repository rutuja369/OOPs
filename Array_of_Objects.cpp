/*
Array of objects:
Creating array of objects of a class is very helpful when we need a set of objects in a huge count

Passing objects as function arguments
*/

#include <bits/stdc++.h>
using namespace std;

class Employee
{
    int emp_id;
    string emp_name;

public:
    void setData(void);
    void getData(void);
    // friend void Spy(Employee obj);
};

void Employee::setData()
{
    cout << "Enter your ID" << endl;
    cin >> emp_id;
    cout << "Enter your Name" << endl;
    cin >> emp_name;
}

void Employee::getData()
{
    cout << "Employee with Emp ID " << emp_id << " is " << emp_name << endl;
}

// External function
// void Spy(Employee emp)
// {
//     cout << "Employee data is" << emp.getData() << endl;
// }

int main()
{

    // This way we can actually create an array of Employee class objects 
    // Employee google[3];
    // for (int i = 0; i < 3; i++)
    // {
    //     google[i].setData();
    //     google[i].getData();
    // }
    // Spy(google[0]);

    // Another way of creating array of objects

    Employee *ptr = new Employee[3]; // here compiler's default constructor is called
    Employee *temp = ptr;//to restart from position 1
    for (int i = 0; i < 3; i++)
    {
        cout << "Enter the ID and Name of Employee number " << i + 1 << endl;
        ptr->setData();
        ptr++;
    }
    for (int i = 0; i < 3; i++)
    {
        temp->getData();
        temp++;
    }

    return 0;
}