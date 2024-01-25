/*
To store the program data permanently into a file and then -> into a hard disk or any permanent storage
File Handling is used

//These two are mediator channels through which data flows from one source to destination-> i.e here from program to file and vice-versa
Output Stream: -> An output stream is used to write data to a destination, such as the console or a file.
                  In C++, the ostream class is the base class for output streams.
                  You can use it to perform operations like writing data to the console using cout or to a file using file streams.
Input Stream : -> An input stream is used to read data from a source, such as the keyboard or a file.
                  In C++, the istream class is the base class for input streams.
                  You can use it to perform operations like reading data from the keyboard using cin or from a file using file streams.



Inbuilt stream classes:

                          IOS
 istream                   |                 ostream
    | \                 fstream              / |
    |  ifstream                      ofstream  |
 istream_withassign                      ostream_withassign
 Ex: cin                                 Ex: cout

 Note:
 - Insertion '<<' (insertion on the screen) operator is of class -> ostream and extraction '>>' (extraction from user) operator is of class -> ifstream
 - cin and cout are inbuilt functions but we need to create our custom objects of classes ifstream, ofstream and fstream resp
 - when we want to do output operations -> create object of class ofstream -> this one obj represents one output stream
 - llarly,  ifstream class obj represents input stream
 - fstream is combo of ifstream and ofstream classes -> means having fun of both read and write -> useful when we want to perform both operations on a file
 - cin is associated with keyboard!!



File Opening Modes:
-  here are some arguments that we need to pass on to open()  func
1. ios::in (i/p / read)-> its a constant value used to indicate that we are opening file to read
2. ios::out (o/p/write) [This is the default mode] -> in this mode the file is openned in write mode and Note that -> the previous content is flushed and wrote opr is performed newly in this mode
3. ios::app (append) -> if we don't want to erase previous data and append the incoming data in file -> use this mode
4. ios::ate (update) -> if we want to perform a random modification in file -> use this mode
5. ios::binary (binary) ->

/*
Default modes :
ofstream fout;
fout.open("myfile.txt", ios::out); -> default mode is ios::out

ifstream fin;
fout.open("myfile.txt", ios::in); -> default mode is ios::in

fstream file;
fout.open("myfile.txt", ios::out/ios::in); -> default mode is both ios::out and ios::in
*/

/*
Text Mode and Binary Mode:
NOTE: This is for all types of files -> regardless of their extension
- text mode is default opening mode
  here the special characters are detected and implemented -> ex: fout<<"My name is \n Rutuja" -> here the data written in file will be of : My name is <newline> Rutuja
- binary mode can be specified as ios::binary
  here the special characters are not detected and written as it is -> here o/p will be : My name is \n Rutuja
*/

#include <bits/stdc++.h>
// #include <fstream.h>
using namespace std;

int main()
{

  //--------------------------------------------------
  // Write operation on a file:
  //--------------------------------------------------

  // creating an object of class ofstream -> which takes input from program variable and stores in a file via outputstream
  ofstream fout;
  // since we have given just file name -> thus this file must be present in curr dir only or if doen't exist -> then should be created here only
  // Also since fout obj has called it -> so the file will automatically get linked to output stream of fout obj
  // Note: open() -> it opens an existing file and also can create a file if it doesn't exist
  // Note: initially -> when program runs for the first time -> file is created for the first time followed by next writes in next executions
  fout.open("myfile.txt");

  // Note: getch() -> jaha jaha getch()-> likha hai waha waha program rukega user se i/p lene keliye
  // Till this stage -> just file banegi -> once user presses a key and terminates getch() then program continues

  /*
This first getch() shows an error but i have two more getch() instances present in my code , then my question is why is this compiler not showing error for all three getch() instances and why only to the first one is it that the compiler is compiling line by line and did not proceed after executing the 1st error occurrence
->  I see what you mean now. The reason you might be observing this behavior is due to the way your code is being compiled and executed. C++ compilers often process code line by line, and when they encounter an error on a particular line, they may not proceed to analyze and flag potential errors in the lines that follow. This is often the case when there's a syntax error or a problem in the code that prevents the compiler from accurately parsing the rest of the code.
  In your code, the first occurrence of getch() is where the error is detected, and the compiler may stop processing the code at that point. This means that the subsequent getch() calls may not be flagged as errors by the compiler because it didn't reach that part of the code due to the error in the first getch() line.
  To resolve this, you should address the error(s) in your code, typically starting with the first one detected by the compiler. Once you've fixed that issue, you can then address any other potential errors that might be present in your code.
  Additionally, it's worth noting that getch() is not a standard C++ function, so you might want to consider using standard input and output functions provided by the C++ Standard Library for user interaction if your goal is to write portable C++ code.
  */
  // getch();

  // now, we are performing output opr on file -> using fout obj
  // This hello -> goes into the file
  // till this stage -> hello bas ram wale file me gaya hai -> uss data ko abhi hard disk wale file me copy karna baki hai abhi
  fout << "hello";
  // getch();
  // Again -> user i/p keliye program rukega and then stiil -> we observe file size as 0

  // at this stage -> data is copyed to file on hard disk and file closes
  fout.close();

  // final getch() -> and program terminates
  // getch();

  //---------------------------------------------------------------------------------------------------

  //--------------------------------
  // Read operation on file;
  //--------------------------------

  // this obj of ifstream class -> will represent  i/p stream
  ifstream fin;

  fin.open("myfile.txt");

  char ch;

  // note: cin>>ch ; -> here the cin takes user input only via keyboard and that char is stored in ch -> as by default this cin is associated with keyboard-> ans uss char ko input stream se hote hue ch me laya jayega
  // similarly -> as cin-> is associated with keyboard in same way -> fin obj is associated with myfile.txt
  // fin >> ch; // yaha file me ka first char read hoga na i/p stream through ch me aayega using fin obj

  // Now, since we want to read entire file here-> thus run a loop

  /*
  Note: Problem here is >> -> extraction operator treats space, tab and nextline as special characters that are used in separating the data and thus does not read them!!!
  Solution: So, as we know problem of >> opr -> better not use it instead we'll use a get() func  -> this get() does not ignore space , tabs and nextlines
  */

  ch = fin.get();

  // fin.eof() -> returns 1 -> if file ka end aagaya else -> returns 0
  while (!fin.eof())
  {
    cout << ch;
    // note : now next time when we call fin>>ch -> internally fileptr already started pointing towards next character
    ch = fin.get();
  }

  fin.close(); // closes file
  // getch();

  //---------------------------------------
  // Exploring file modes:
  //---------------------------------------

  // creating obj of ofstream class-> since we want to perform write opr
  ofstream fout;
  fout.open("myfile.txt", ios::out); // here ios::out is a kind of default arg -> even if we don't pass it -> still the file opens in output mode

  // Note: we can even pass multiple modes together
  fout.open("myfile.txt", ios::app | ios::binary);
  // But remember -> some associations never workout -> its logically invalid
  // fout.open("myfile.txt", ios::app| ios::in);//-> incalid as fout is a obj of class ofstream and we cannot use it to perform read opr like ios::in

  return 0;
}