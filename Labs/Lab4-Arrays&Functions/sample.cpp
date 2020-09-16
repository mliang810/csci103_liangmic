#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

//prototype
int roll(); 
void printHistogram(counts[])

    
int main(){
    int counts[21];
    for(int i=0; i<21; i++)
        counts[i] = i/2;
    printHistogram(counts);
}


//functions 
int roll(){
    srand((unsigned int)time(0));
    return (rand()%6) + 1;;
}

void printHistogram(){
    int counts[21]; //declare size
    for(int i = 0; i<21; i++){ //initialize
        counts[i] = 0;
    }

    for(int i = 0; i<21; i++){ //assign number to an array spot 
        if(rollsum = i + 4){
            int xcounter = 0;
            xcounter = xcounter++;
  
        }
        
        
        
        
        /*(counts[i] = i+4){
            int number = i + 4;
            cout << number << ":";
        }
    }    
            */
    