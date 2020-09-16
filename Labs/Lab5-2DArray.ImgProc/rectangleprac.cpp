#include <iostream>
#include <cmath>
#include "bmplib.h"

using namespace std;

// global variable. bad style but ok for this lab
unsigned char image[SIZE][SIZE];

// Fill in this function:
void draw_rectangle(int top, int left, int height, int width) {

    for(int j= left; j <= (left+width); j++){
        if(j>=0 && j<=255){
            if(top>=0 && top<=255){
                image[top][j] = 0;
            }
            if((top+height)<255 && (top+height)>=0){
                image[top+height][j] = 0;
            }
        }
     } 
    for(int i= top; i <= (top+height); i++){
        if(i>=0 &&i<=255){
            if(left>=0 && left<=255){
                image[i][left] = 0;
            }
            if((width+left)<SIZE && (width+left)>=0){
                image[i][left+width] = 0;
            }
        }
     }
    
}
       

   //check if top and topmax are in bounds, dont print if arent 

        
    /*for(int j= left; j <= (left+width); j++){ //start from top, add "i" from then on until reach the desired h
       if(j>=0 && j<SIZE){
        if(j == left ||j == left + width){
           for(int i = top; i<= (top+height); i++){
            image[i][j] = 0;
           }
        }
       }
        
        else{
            for(int j= left; j <= (left+width); j++){
               if(left<0){
                   if(j == left ||j == left + width){
                       for(int i = top; i<= (top+height); i++){
                            image[i][j] = 0;
               
                       }
                   }
               }
           }
        }
    }


}
*/


int main(){
    //prototype
    void draw_rectangle(int top, int left, int height, int width); 
    
    for (int i=0; i < SIZE; i++) {
      for (int j=0; j < SIZE; j++) {
         image[i][j] = 255;
      }
   }
    cout << "input the top row, top left corner, input the height, input the width in order as stated" << endl;
    int t, l, h, w;
    cin >> t >> l >> h >> w;
        
    draw_rectangle(t, l, h, w);
    
    
    writeGSBMP("rectangleprac.bmp", image);
    return 0;
}
    
    
    
    

                        