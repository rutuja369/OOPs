/*

// tellg and tellp functions

NOTE: The content inside the file is itself the input stream

1. tellg()
- Defined in istream class
- Syntax: streampos tellg();
- This func returns the position of current character in the "input stream"-> and thats an unsigned value
- Yeh batata hai ki input stream me currently pointer kis character ko pnt kar raha hai

2. tellp()
- Defined in ostream class
- Syntax: streampos tellp();
- This func returns the position of current character in the "output stream" -> and thats an unsigned value again

*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    // implementing tellg() -> toh i need ifstream class obj -> read opr
    // ifstream fin;
    // fin.open("myfile.txt");

    // int curr_pos = fin.tellg();
    // cout << curr_pos << endl; // here the curr_pos stores 0 as ptr is pointing to 1st character

    // // Now-> when will, this get updated-> when we start reading the file
    // while (!fin.eof())
    // {
    //     char ch;
    //     ch = fin.get();
    //     curr_pos = fin.tellg();
    //     cout << curr_pos << endl;

    //     // note: the ptr that points to a curr char of "input stream" -> is called *get pointer* -> and tellg() gives the position of this get ptr
    // }
    // fin.close();

    // Note: these get ptr and put ptr are both made in ifstream and ofstream class

    //-----------------------------------------------------------------------------------------

    // implementing tellp() -> toh i need ofstream class obj -> write opr
    ofstream fout;
    fout.open("myfile.txt", ios::app); // since i want to append the text in existing file -> using the mode ios::app

    int curr_pos = fout.tellp();
    /*
    As per video
    Note: Very imp: curr_pos -> gives output as 0 -> coz since we are in append mode -> previously existing text is ignored by put ptr and starts from next empty position after prev text and marks it as 0
    -> so in file actually total text is -> hello students my name is rutuja
    -> but, curr_pos -> starts pointing using put ptr only from new added text and gives range as 0 to 18


    but but but -> my output says -> put ptr starts from the last index of exsiting text and goes on incr it 
    so here my output is 14 and finally after appending final output is 32 (14+18=32)
    */
    cout << curr_pos << endl; 

    fout << "my name is rutuja!";

    curr_pos = fout.tellp();
    cout << curr_pos << endl;

    fout.close();

    return 0;
}