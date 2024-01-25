/*
Multilevel Inheritance
A--> B--> C
*/

#include <bits/stdc++.h>
using namespace std;

// base class for exam
class Student
{
protected:
    int roll_no;

public:
    void set_rollno(int roll)
    {
        roll_no = roll;
    }
    int get_rollno()
    {
        cout << "Roll no of student is " << roll_no << endl;
        return roll_no;
    }
};

//
class Exam : public Student
{
protected:
    float maths;
    float physics;

public:
    void set_marks(float m1, float m2)
    {
        maths = m1;
        physics = m2;
    }

    void get_marks()
    {
        cout << "Marks obtained in maths are " << maths << endl;
        cout << "Marks obtained in physics are " << physics << endl;
    }
};

class Results : public Exam
{
public:
    void display_results()
    {
        get_rollno();
        get_marks();
        cout << "Your result is " << (maths + physics) / 2 << "%" << endl;
    }
};

int main()
{
    Results rutuja;
    rutuja.set_rollno(63);
    rutuja.set_marks(95.6, 98.9);

    rutuja.display_results();
    return 0;
}