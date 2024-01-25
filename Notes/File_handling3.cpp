/*

seekg() and seekp() functions:
- These functions help in randomly accessing the positions in a file


1.seekg()
- Defined in istream class
- Syntax:
istream& seekg(streampos pos);
istream& seekg(stream_off, ios_base::seekdir way); (beg, cur, end)

here, pos-> new absolute value of position of an added element in the stream
      off-> off is offset value, relative to the way parameter
      way-> values are ios_base::beg, ios_base::curr and ios_base::end

2.seekp()
- Defined in ostream class
- Syntax:
ostream& seekp(streampos pos);
ostream& seekp(streamoff off, ios_bas::seekdir way); (beg, cur, end)


*/

#include <bits/stdc++.h>
using namespace std;

int main()
{

    // implementing seekg()
    // ifstream fin;
    // fin.open("myfile.txt");

    // cout << fin.tellg(); // gives position of curr ptr-> 0 initially
    // cout << char(fin.get()) << endl;

    // // Note: for seekg() -> by default seekdir way is ios_base::cur
    // fin.seekg(3);        // by default it assumes to skip the get ptr to 3 positions from current position
    // cout << fin.tellg(); // gives modified position of curr ptr as 3
    // cout << char(fin.get()) << endl;

    // fin.seekg(4, ios_base::cur);
    // cout << fin.tellg(); // gives modified position of curr ptr as 8 (3 to 4, 5, 6, 7 to 8 )
    // cout << char(fin.get()) << endl;

    // // similarly if i want to get back from end-> provide the offset as negative value
    // fin.seekg(-4, ios_base::end);
    // cout << fin.tellg(); // gives modified position of curr ptr as 8 (3 to 4, 5, 6, 7 to 8 )
    // cout << char(fin.get()) << endl;

    // implementing seekp()
    ofstream fout;
    fout.open("myfile.txt", ios::ate | ios::app);

    cout << fout.tellp();
    fout << "rutuja here";

    // so here put ptr position is changed from end of curr text to position 2 from beginning
    fout.seekp(3, ios_base::beg);
    cout << fout.tellp(); //doubt!!!

    // this func is important to reflect the changes -> or else changes will only take place in copy of file that is present in ram and not on hard disk
    fout.close();
    return 0;
}