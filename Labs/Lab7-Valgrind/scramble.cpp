// wscramble.cpp
// Word Scramble guessing game
// Illustrates string library functions, character arrays,
//  arrays of pointers, etc.
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <fstream>

using namespace std;

// Scramble the letters of this string randomly
void permute(char items[], int len);

/* Delete the array below and replace by reading in words from a file 
   in main() */
/*
const char* wordBank[] = {
   "computer", "president", "trojan", "program", "coffee",
   "library", "football", "popcorn", "science", "engineer"};

const int numWords = 10;
*/
int main(int argc, char* argv[]) {
    srand(time(0));
    char guess[80];

    bool wordGuessed = false;
    int numTurns = 10;
  
    
    //checking conditions - if arguments work 
    if(argc < 2){
        cout << "Please enter the name of the file" << endl;
        return 1;
    }
    
    //checking conditions - if filename works
    ifstream inputfile(argv[1]);
    if(inputfile.fail()){
        cout << "Bad filename - Try again" << endl;
        inputfile.clear(); //clear fail data
        return 1;
    }
    
    int numwords;
    inputfile >> numwords;
    
    if(inputfile.fail()){
        cout << "Failed to read input as integer" << endl;
        return 1;
    }
    
    
  /* Add code to declare the wordBank array, read in each word
     and store it */
    char** wordBank = new char*[numwords];
    char buffer[41];
    
   
    for(int i=0; i<numwords; i++){
        inputfile >> buffer;
        int lenstr = strlen(buffer);  
        wordBank[i] = new char[lenstr+1]; //includes null value 
        strncpy(wordBank[i], buffer, lenstr+1);
    }
    
  //close input file
    inputfile.close();  
    
  // Pick a random word from the wordBank
    int target = rand() % numwords;
    int targetLen = strlen(wordBank[target]);
 
  // Make a dynamically-allocated copy of the word and scramble it
    char* word = new char[targetLen+1];
    strcpy(word, wordBank[target]);
    permute(word, targetLen);
  
  // An individual game continues until a word
  //  is guessed correctly or 10 turns have elapsed
    while (!wordGuessed && numTurns > 0) {
        cout << "Scrambled word: " << word << endl;
        cout << "What do you guess the original word is? ";
        cin >> guess;
    /* Complete the next line of code */
        wordGuessed = (strcmp(wordBank[target], guess) == 0); //if returns true, wg = true
        numTurns--;   // Every guess counts as a turn
    }
    
    if (wordGuessed) {
        cout << "You win!" << endl;
    }
    else {
        cout << "Too many turns...You lose!" << endl;
    }
  /* Free up any necessary memory */
    delete [] word;
    for(int i=0; i<numwords; i++){ //delete all the words in wordbank
        delete [] wordBank[i];
    }
    delete [] wordBank; //delete the array
    return 0;
}

// Scramble the letters. See "Knuth shuffle".
void permute(char items[], int len) {
  for (int i = len-1; i > 0; --i) {
    int r = rand() % i;
    char temp = items[i];
    items[i] = items[r];
    items[r] = temp;
  }
}

