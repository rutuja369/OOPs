/*
Arrays in Classes and Object memory allocation

- When is memory allocation done in classes?
-> Memory for those properties and methods that are common for all the objects created for the class will be allocated only once -> obvious right?
-> Whereas, the properties that have individual existance for every object-> those are allocated memory whenever an object is created
EX: For an Employee class-> member functions such as Bonus_Cal, No.of holidays etc -> will be common -> thus allocated memory only once while class creation
    And individual data/props for every object such as emp_name, salary these variable will be allocated memory -> when object is created

*/

#include <bits/stdc++.h>
using namespace std;

class Shop
{
    int ItemId[10];
    int ItemPrice[10];
    int count = 0; // this can be init here as well -> instead of creating a initcount method-> coz whenever new obj is created these variable are newly assigned to them and this class blueprint is executed

public:
    // For every shop-> every obj req is that my item count must start with 0 right?-> so initcount
    // void initCount(void) { count = 0; }
    void setItem(void);
    void displayItems(void);
};

void Shop::setItem(void)
{

    cout << "Enter your item ID for item no. " << count + 1 << endl;
    cin >> ItemId[count];
    cout << "Enter your item price for item no. " << count + 1 << endl;
    cin >> ItemPrice[count];
    count++;
}

void Shop::displayItems(void)
{
    for (int i = 0; i < count; i++)
    {
        cout << "Price for Item ID " << ItemId[i] << " is Rs." << ItemPrice[i] << endl;
    }
}

int main()
{
    Shop dukaan;
    // Init counter -> 0
    // dukaan.initCount();
    for (int i = 0; i < 3; i++)
    {
        dukaan.setItem();
    }
    dukaan.displayItems();

    return 0;
}