/* Author: Michelle Liang
 * Program: color_conv
 * Description: Converts RGB -> CMYK color representation
 */
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
   // Enter your code here

    double red, green, blue, white, cyan, magenta, yellow, black, temp;
    cout<<"enter RGB values" <<endl;
   
    cin>>red>>green>>blue;
   //white = max{red/255,green/255,blue/255};
    temp = max(red/255.0,green/255.0);
   white = max(temp, blue/255.0);
    //use RGB to calc other colors
    cyan = (white-red/255)/white;
    magenta=(white-green/255)/white;
    yellow=(white-blue/255)/white;
    black=1-white;
   
   //print color values
   cout<<"cyan is: " << cyan << endl; 
   cout<<"magenta is: " << magenta << endl;
   cout<< "yellow is: " << yellow << endl;
   cout<< "black is: " << black << endl;
   return 0;
}
