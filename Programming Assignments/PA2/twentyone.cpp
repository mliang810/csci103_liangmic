/*******************************************************************************
 * CS 103 Twenty-One (Blackjack) PA
 * Name: 
 * USC email: 
 * Comments (you want us to know):
 *
 *
 ******************************************************************************/

// Add other #includes if you need
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

/* Prototypes */
void shuffle(int cards[]);
void printCard(int id);
int cardValue(int id);
void printHand(int hand[], int numCards);
int getBestScore(int hand[], int numCards);

const int NUM_CARDS = 52;

/**
 * Global arrays to be used as look-up tables, if desired.
 * It is up to you if and how you want to use these 
 */
const char suit[4] = {'H','S','D','C'};
const char* type[13] = 
  {"2","3","4","5","6","7",
   "8","9","10","J","Q","K","A"};
const int value[13] = {2,3,4,5,6,7,8,9,10,10,10,10,11};

/**
 * Should permute the deck of cards, effectively shuffling it.
 * You must use the Fisher-Yates / Durstenfeld shuffle algorithm
 *  described in the assignment writeup.
 */
void shuffle(int cards[])
{
  /******** You complete ****************/
    
    for(int i=51; i>=1; i--){
        int temp;
        int j = rand() % (i+1);
        temp = cards[i];
        cards[i] = cards[j];
        cards[j] = temp;
    }
}
        
/**
 * Prints the card in a "pretty" format:   "type-suit"
 *  Examples:  K-C  (King of clubs), 2-H (2 of hearts)
 *  Valid Types are: 2,3,4,5,6,7,8,9,10,J,Q,K,A
 *  Valid Suits are: H, D, C, S
 */
void printCard(int id)
{
  /******** You complete ****************/
    cout << type[id%13] << "-" << suit[id/13];

}

/**
 * Returns the numeric value of the card.
 *  Should return 11 for an ACE and can then
 *  be adjusted externally based on the sum of the score.
 */
int cardValue(int id)
{
  /******** You complete ****************/
    
    return value[id%13]; //the numeric value of the card is spit out 
      

}

/**
 * Should print out each card in the hand separated by a space and
 * then print a newline at the end.  
 * Should use printCard() to print out each card.
 */
void printHand(int hand[], int numCards)
{
  /******** You complete ****************/
    for(int i=0; i<numCards; i++){
        printCard(hand[i]);
        cout << " ";
    }
}

/**
 * Should return the total score of the provided hand.  
 * ACES should be treated as 11s to make the highest possible hand
 *  and only being reduced to 1s as needed to avoid busting.
 */
int getBestScore(int hand[], int numCards)
{
  /******** You complete ****************/
    int score = 0;
    int acecount = 0;
    
    for(int i=0; i<numCards; i++){
        score = score + cardValue(hand[i]);
        
        if (cardValue(hand[i])==11){
            acecount++;
        }
        
        while(score > 21 && acecount>0){
            score = score - 10;
            acecount--;
            
        }
    }
    
    return score;

}

/**
 * Main program logic for the game of 21
 */
int main(int argc, char* argv[])
{
  //---------------------------------------
  // Do not change this code -- Begin
  //---------------------------------------
  if(argc < 2){
    cout << "Error - Please provide the seed value." << endl;
    return 1;
  }
  int seed = atoi(argv[1]);
  srand(seed);

  int cards[52];
  int dhand[9];
  int phand[9];
  //---------------------------------------
  // Do not change this code -- End
  //---------------------------------------

  /******** You complete ****************/
  bool again = true;
  
  while(again){
      for(int i=0; i<52; i++){ //initialize
            cards[i] = i;
      }
      shuffle(cards);
        
      for(int j=0; j<2 ;j++){
          phand[j] = cards[j*2];
          dhand[j] = cards[j*2 +1]; 
      }
        
        //show start cards
      cout << "Dealer: " << '?' << " ";
      printCard(dhand[1]); 
      cout << endl;  //only showed the second card, first card isnt there
        
      cout << "Player: ";
      printHand(phand, 2);
            
    
      int pcards = 2, dcards = 2, allcards = 4;

      char choice;
        
      while(getBestScore(phand, pcards) < 21){ //can i leave the [] in?
          cout << "Type 'h' to hit and 's' to stay" << endl;
          cin >> choice;
        
          if (choice == 'h'){
              phand[pcards] = cards[allcards];
              pcards++, allcards++;
              cout << "Player: ";
              printHand(phand, pcards);
              cout << endl; //need this?
          }
        
          else{
            //exit program if any other input 
              break;
          }

      }
    
        
      if(getBestScore(phand, pcards) > 21){ //player busts
          cout << "Player Busts" << endl;
          cout << "Lose " << getBestScore(phand, pcards) << " " << 
              getBestScore(dhand, dcards) << endl;
      }
        
      if(getBestScore(phand, pcards) <22){
          while(getBestScore(dhand, dcards) < 17){
              dhand[dcards] = cards[allcards];
              dcards++, allcards++;
              //printHand(dhand, dcards);
          }
            
          if(getBestScore(dhand, dcards) >= 17 && getBestScore(dhand, dcards) <21){ 
              cout << "Dealer: ";
              printHand(dhand, dcards);
              cout << endl;
              
              if(getBestScore(dhand, dcards) < getBestScore(phand, pcards)){
                  cout << "Win " << getBestScore(phand, pcards) 
                      << " " << getBestScore(dhand, dcards) << endl;
              }
                
              if(getBestScore(dhand, dcards) == getBestScore(phand, pcards)){
                  cout << "Tie " << getBestScore(phand, pcards) 
                      << " " << getBestScore(dhand, dcards) << endl;
              }
                
              if(getBestScore(dhand, dcards) > getBestScore(phand, pcards)){
                  cout << "Lose " << getBestScore(phand, pcards) 
                      << " " << getBestScore(dhand, dcards) << endl;
              }
          }
          
          if(getBestScore(dhand, dcards) > 21){ 
              cout << "Dealer Busts" << endl;
              cout << "Win " << getBestScore(phand, pcards) 
                  << " " << getBestScore(dhand, dcards) << endl;
          }
      }

      char playagain;

      cout << endl;
      cout << "Play again? [y/n]" << endl;
      cin >> playagain;
        
      if(playagain == 'y'){
          again = true;
      }

      else{
          again = false;
          break;
      }
    
    
    
    


  }
  return 0;
}
