/********************************************************
 * CS 103 PA 1: Commas
 * Name: Michelle Liang
 * USC email: liangmic@usc.edu
 * Comments (you want us to know): 
 *
 * Description:
 *  Displays a 64-bit integer (long long) with
 *   commas for thousands, millions, billions, etc.
 *
 * ** ABSOLUTELY NO ARRAYS, NO `string`, NO `vector` **
 *  usage is allowed.
 *
 * Instead, you may only declare:
 *
 *    bool,
 *    int, or
 *    int64_t (long long)
 *
 *  The only library function allowed is pow(base, exp)
 *    defined in the <cmath> library.
 *
 *
 ********************************************************/

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
  long long n;
  cout << "Enter an integer:" << endl;
//enter Code  
   cin >> n;
   int commas = 0;
   long long subn  = n;
   while (abs(subn) > 999){
       subn/=1000;
       commas++;
   }
   for (int i = commas; i > 0; i--){
       if (n<0){
           cout << "-";
           n = abs(n);
       }
       int temp = n/(pow(1000,i));
       if (temp==0){
           cout << "000" << ",";
       }
       else{
           cout << temp << ",";
       }
       n-=temp*(pow(1000,i));
       }
       
       if(n<1000){
           if (n == 0){
               cout << "000" << endl;
           }

           else{
               cout << n << endl;
           }
       }

    return 0;
}