#include<iostream>
#include<cmath>
using namespace std;

int decimalToBinaryMethod1(int n){
    //Division Method 
    // while(n>0)//condition
    // {
    //     int bit = n % 2;//initialization
    //     cout<<bit;
    //     n = n/2;//updation
    // } 
    int binaryno = 0;
    int i=0;
    while(n>0){
        int bit = n%2;
        binaryno = bit*pow(10,i) + binaryno;
        i++;
        n = n/2;
    }
    return binaryno;
}


int main()
{
    //function call
    int n;
    cout<<"Enter the decimal nummber :=";
    cin>>n;
    int binary = decimalToBinaryMethod1(n);
    cout<<binary<<endl;
    return 0;
    
}






// // By division method.
// #include<iostream>
// using namespace std;
// int decimalToBinary(int decimalNumber){
//     int number;
//     cout<<"Enter the decimal number:=";
//     cin>>number;
//     for(int i=number;i<2;i++){
//         number=number%2;
//         int bit=i;
//         cout<<bit;
//     }
//     return 0;
// }
// int main(){
//       decimalToBinary(23);
// }