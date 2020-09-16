#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int theta;
    double i, j, rad;
    //variables as doubles here, will be redefined lower as int so can make the triangle 
    cout << "Please input an angle between 15˚ and 75˚" << endl;
    cin >> theta;
    rad = theta * M_PI/180;
    
   for (int length=0; length<31; length++){
       i = length; 
       j = floor(i*tan(rad));
     
       if( j>=20 && j<=30){
          j=20;
      }
       
      for (int width=0; width<j; width++) {
          cout << '*' ;
      }
      cout << endl;
   }
    // is return 0; neccessary???
}