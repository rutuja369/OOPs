/*
Templates:
1. Function Templates
2. Class Templates
*/

#include <bits/stdc++.h>
using namespace std;
//---------------------------------------------------
// Function Templates

// These two are datatype specific functions
//  int largest(int a, int b)
//  {
//      if (a > b)
//          return a;
//      else
//          return b;
//  }
//  float largest(float a, float b)
//  {
//      if (a > b)
//          return a;
//      else
//          return b;
//  }

// Instead of creating such datatype specific functions -> we can create a generic func which has same logic and works for multiple datatypes
template <class X>
X largest(X a, X b)
{
    if (a > b)
        return a;
    else
        return b;
}

//----------------------------------------------
// Class templates

// Datatype Specific Class Implementation
//  class Arraylist
//  {
//  private:
//      struct ControlBlock
//      {
//          /* data */
//          int capacity;
//          int *arr_ptr;
//      };
//      // just declared here-> but the structure will get the recognition only when we create an instance of it
//      ControlBlock *s;

// public:
//     Arraylist(int capacity)
//     {
//         // first creating an instance of ControlBlock
//         s = new ControlBlock;
//         s->capacity = capacity;
//         s->arr_ptr = new int[s->capacity];
//     }

//     void addElement(int index, int data)
//     {
//         if (index >= 0 && index <= (s->capacity - 1))
//         {
//             s->arr_ptr[index] = data;
//         }
//         else
//         {
//             cout << "Index is invalid" << endl;
//         }
//     }

//     int viewElement(int index)
//     {

//         if (index >= 0 && index <= (s->capacity - 1))
//         {
//             return s->arr_ptr[index];
//         }
//         else
//         {
//             cout << "Index is invalid" << endl;
//             return -1;
//         }
//     }

//     void viewList()
//     {
//         cout << "List is: ";
//         for (int i = 0; i < s->capacity; i++)
//         {
//             cout << (s->arr_ptr[i]) << " ";
//         }
//         cout << endl;
//     }
// };

// int main()
// {
//     // Implementing function templates
//     cout << "Largest int value is: " << largest(2, 7) << endl;
//     cout << "Largest float value is: " << largest(2.4f, 2.1f) << endl;
//     // now using generic largest func
//     cout << "Largest float value is: " << largest(2.4f, 2.1f) << endl;

//     // implementing class templates

//     Arraylist list1(3);
//     list1.addElement(0, 10);
//     list1.addElement(1, 20);
//     list1.addElement(2, 30);

//     cout << list1.viewElement(0) << " ";
//     cout << list1.viewElement(1) << " ";
//     cout << list1.viewElement(2) << endl;

//     list1.viewList();

//     return 0;
// }

/*
Now -> If you observe this class can be implemented further by creating further utility functions such as Arraylist sorting, maxele , minele etc
But, this class is restricted to int datatype what if i want it to be generic in nature like operations can be done on an array of ints, floats , doubles etc
*/

// Generic Version of above class:
template <class X>
class Arraylist
{
private:
    struct ControlBlock
    {
        /* data */
        int capacity;
        X *arr_ptr;
    };
    // just declared here-> but the structure will get the recognition only when we create an instance of it
    ControlBlock *s;

public:
    Arraylist(int capacity)
    {
        // first creating an instance of ControlBlock
        s = new ControlBlock;
        s->capacity = capacity;
        s->arr_ptr = new X[s->capacity];
    }

    void addElement(int index, X data)
    {
        if (index >= 0 && index <= (s->capacity - 1))
        {
            s->arr_ptr[index] = data;
        }
        else
        {
            cout << "Index is invalid" << endl;
        }
    }

    X viewElement(int index)
    {

        if (index >= 0 && index <= (s->capacity - 1))
        {
            return s->arr_ptr[index];
        }
        else
        {
            cout << "Index is invalid" << endl;
            return -1;
        }
    }

    void viewList()
    {
        cout << "List is: ";
        for (int i = 0; i < s->capacity; i++)
        {
            cout << (s->arr_ptr[i]) << " ";
        }
        cout << endl;
    }
};

int main()
{
    // Implementing function templates
    cout << "Largest int value is: " << largest(2, 7) << endl;
    cout << "Largest float value is: " << largest(2.4f, 2.1f) << endl;
    // now using generic largest func
    cout << "Largest float value is: " << largest(2.4f, 2.1f) << endl;

    // implementing class templates
    // Now since this class has become generic in nature -> need to add an additional syntax here <int> -> X=int
    // Integer ArrayList
    Arraylist<int> list1(3);
    list1.addElement(0, 10);
    list1.addElement(1, 20);
    list1.addElement(2, 30);

    cout << list1.viewElement(0) << " ";
    cout << list1.viewElement(1) << " ";
    cout << list1.viewElement(2) << endl;

    list1.viewList();

    // Float ArrayList
    Arraylist<float> list2(3);
    list2.addElement(0, 1.1f);
    list2.addElement(1, 2.2f);
    list2.addElement(2, 3.3f);

    cout << list2.viewElement(0) << " ";
    cout << list2.viewElement(1) << " ";
    cout << list2.viewElement(2) << endl;

    list2.viewList();

    return 0;
}

// Conclusion -> this is how functions and classes can be made generic in nature
