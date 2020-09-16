/*
Michelle Liang
liangmic@usc.edu
*/
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;


//dummy main 1
/*
int main(){
    cout << roll() << endl;
}
*/

//dummy main 2
/*
int main(){ //counts aka testCounts
    int counts[21];
    for(int i=0; i<21; i++)
        counts[i] = i/2;
    printHistogram(counts);
}
*/
    
//actual code - uncomment out
int main(){

    //prototype
    int roll(); 
    void printHistogram(int counts[]);
    
    srand((unsigned int)time(0));
    
    int n;
    int d; //dice roll rand num
    int rollsum = 0;
    
    
    cout << "How many rolls do you want?"<< endl;
    cin >> n;
    
    //initializing the array
        int counts[21];
    for(int i = 0; i<21; i++){
        counts[i] = 0;
    }
    
    for (int i=0; i<n; i++){ //n      rolls
        for(int j = 0; j<4; j++){ //reflection: change i to 10 for 10 dice instead of 4
            d = roll();
            rollsum = rollsum + d;
        }
        //increment counts at rollsum - 4

        counts[rollsum - 4]++;
        rollsum = 0;  
        }   
        
    
    printHistogram(counts);
    return 0;
}


//functions

int roll(){
    return (rand()%6) + 1; //reflection: change 6 to 3 for 3 sided die
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
    
