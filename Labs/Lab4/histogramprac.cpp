/*
Michelle Liang
liangmic@usc.edu
*/
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

//prototype
//int roll(); 
void printHistogram(int counts[]);

int main(){
    int counts[21];
    for(int i=0; i<21; i++)
        counts[i] = i/2;
    printHistogram(counts);
}

void printHistogram(int counts[]){ //print X++ until do not encounter any more "number" 
    for(int i = 0; i<21; i++){
        int number = i + 4;
        cout << number << ":";
        
        for(int j=0; j < counts[i]; j++){ 
            cout << "X";
        }
        cout << endl;

    }
}    