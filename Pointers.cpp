/*
Deep dive into pointers:
- Even if pointers are storing addresses still float* ptr is different from int *ptr
- Coz, while dereferencing these pointers the declaration helps compiler to collect that value and use it in some expresion
Ex: float a=10.4;
    float *ptr=&a;
    cout<<(*ptr)+1<<endl;-> here compiler uses the float value coz ptr is declared to point to a float value
- new -> used to dynamically allocate memory
- delete-> used to free up dynamically allocated memory by new
- malloc-> used to dynamically allocate memory in C
- free-> used to free up dynamically allocated memory by malloc

Syntax of malloc: (void*)malloc(sizeof(int)*5);
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    // int a = 10;
    // int *ptr = &a;
    // cout << (*ptr) << endl;

    // // creating a float variable dynamically
    // float *f = new float(18.7478);
    // cout << (f) << endl;

    // float b = 10.4;
    // float *p = &b;
    // cout << (*p) + 1 << endl;

    // // We can even dynamically assign a block of memory using new keyword and malloc() function
    // int *str = (int *)malloc(sizeof(int) * 3);
    // str[0] = 10;
    // str[1] = 20;
    // str[2] = 30;
    // cout << (*str) << endl;
    // cout << (*(str + 1)) << endl;
    // cout << (*(str + 2)) << endl;
    // cout << (*(str + 3)) << endl;
    // free(str);

    int *parr = new int[2];
    parr[0] = 10;
    parr[1] = 20;

    // DELETING A BLOCK OF MEMORY ASSIGNED -> USING DELETE IS DONE AS FOLLOWS
    delete[] parr;
    cout << (*parr) << endl;
    cout << (*(parr + 1)) << endl;

    int xyz = 12;
    /*
    Note: Very important
    - Although pointers store the memory addresses which are generally in hexadecimal format-> its not a good practice to store hardcoded hex values
    - Coz, format of memory addresses may vary across diff devices/systems and thus may lead to -> segmentation fault etc..
    - Also, int *a= (some hex value)-> this is also wrong coz every pointer variable must know which type of var is it pointing to -> whether its an int, float , array , object etc..-> must know in order to dereference values correctly
    - And hardcoding only a random hex value doesn't give this info-> thus we need to then explicitly type cast the val ex: int *a= (int *)0x1A5F9B8D ;
    - Better use dynamic memory allocation and explicitly free up the space allocated at runtime OR go for static allocation like : Ex:int a=10; int *ptr= &a -> here memory is released automatically
    */

    int *a = (int *)0x1A5F9B8D; // Pointer var cannot store anything else than a address of some other variable-> means
    cout << (a) << endl;        //-> prints the given address -> but since we dont know whether this is actaully an address of some memory of type int in system -> it gives seg fault as mentioned earlier

    int data = 10;
    int &ref_var = data;//consider just as an alias name for data variable
    cout << data << endl;
    ref_var++;
    cout << data << endl;
    cout << ref_var << endl;
    return 0;
}