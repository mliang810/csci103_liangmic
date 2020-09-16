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
       
       

// Fill in this function:
void draw_ellipse(int cy, int cx, int height, int width) {
      double rx = width/2;
      double ry = height/2;
   
    for(double degree = 0.0; degree<2*M_PI; degree+=0.01){
        int x = (int)(rx*cos(degree)); 
        int y = (int)(ry*sin(degree));
        
        x+=cx;
        y+=cy;
        
        if(x>0 && x<SIZE  && y>0 && y<SIZE){
                image[y][x]=0;
            }
        }
    }


int main() { 
    //prototypes
    void draw_ellipse(int cy, int cx, int height, int width);
    void draw_rectangle(int top, int left, int height, int width);
    
    // initialize to white
   for (int i=0; i < SIZE; i++) {
      for (int j=0; j < SIZE; j++) {
         image[i][j] = 255;
      }
   }
    
   // Main program loop here
    
    //options 
    int opt = 0;
    

    while(opt < 2){
        cout << "To draw a rectangle, enter: 0" << endl;
        cout << "To draw an ellipse, enter: 1" << endl;
        cout << "To save your drawing as ""output.bmp"" and quit, enter: 2" << endl;
        
        cin >> opt;
        if(opt == 2){
            break;
        }
        if(opt == 0){
           //rectangle input
            int top, left, height, width;
            cout << "Enter top, left, height, and width in the stated order - no commas" << endl;
            cin >> top >> left >> height >> width;
        
            //function
            draw_rectangle(top, left, height, width);
            
            
        }
        if(opt == 1){
            //eclipse input
            int cr, cc, height, width;
            cout << "Enter center row, center column, height, and width in the stated order - no commas" << endl;
            cin >> cr >> cc >> height >> width;
            
            //function
            draw_ellipse(cr, cc, height, width);
            
        }
        
    }
   
   // Write the resulting image to the .bmp file
   writeGSBMP("output.bmp", image);
   
   return 0;
}
