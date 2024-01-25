#include <bits/stdc++.h>
using namespace std;

// globally accessible structure by any function
struct book
{
    // private:
    int bookID;

    public:
    char title[20];
    int price;
    book()
    {
        this->bookID = 10001;
        strcpy(this->title, "hello ");
        this->price = 100;
    }
    // friend void display(book);
};

book input()
{
    book b;
    cout << "Enter the values of bookID, book ka title and price" << endl;
    cin >> b.bookID >> b.title >> b.price;
    return b; // returna an object of struct book
}
void display(book b)
{
    cout << "Book ID is " << b.bookID << "\nTitle of book is " << b.title << "\nBook pricing is " << b.price << endl;
    // cout << "Book ID is " << bookID << "\nTitle of book is " << title << "\nBook pricing is " << b.price << endl;
}
int main()
{
    // this declaration is also correct -> Cpp allows to declare struct objects wihtout using keyword struct
    //  struct book b; and book b; -> both correct

    book b1;
    b1.bookID = 101;
    // Wrong -> this is not how we store a string in char array -> coz left hand includes b1.title i.e array name which indicates the address of 1st element-> and its constant in nature -> thus cant assign a value to it
    //  b1.title ="hello";

    // Correct-> init char arrays this way
    strcpy(b1.title, "Secret");

    // We can use a function to init our object
    book b2;
    b2 = input();
    display(b2);

    book b3 = book();
    display(b3);

    return 0;
}