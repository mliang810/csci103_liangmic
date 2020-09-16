/* Author: Michelle Liang
 */
#include <iostream>
using namespace std;


bool is23Prime = true;
int main(){

//variables
int twos = 0;
int threes = 0;
int i;
    
cout << "enter a positive integer" << endl;
cin >> i;

while (i!=1 && is23Prime == true )
{
    if ((i%2 ==0) || (i%3 == 0)){
        if(i%2==0){ 
            i = i/2;
            twos++;
        }
        if(i%3 == 0){
            i = i/3;
            threes++;
        }
    }else{
        is23Prime = false;
    }
    
}
    if (is23Prime == true){
    cout << "yes" << endl;
    cout << "Twos = " << twos <<" Threes = " << threes << endl;
    }
    
    if (is23Prime == false){
        cout << "no" << endl;
    }
    
    
    
    
    
    
    
}
