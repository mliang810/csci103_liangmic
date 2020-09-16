/* Author: Michelle Liang
 * Program: digits
 */
#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char *argv[])
{
    int number, ones, tens, hundreds;
    cout<< "provide an integer between 0 and 999 ";
    cin >> number;
    
    //math
    hundreds = number/100;
    tens = (number%100)/10;
    ones = number - ((number/100)*100) - (((number - ((number/100)*100))/10)*10); //original - hundred - ten
    
    //print result
    cout<< "100's digit: " << hundreds << endl;
    cout<< "10's digit: " << tens << endl;
    cout<< "1's digit: " << ones << endl;
      
   return 0;
}