#include <iostream>
#include <cmath>
#include "bmplib.h"

using namespace std;

// global variable. bad style but ok for this lab
unsigned char image[SIZE][SIZE];

void draw_ellipse(int cy, int cx, int height, int width) {
    //half axis
      double rx = width/2;
      double ry = height/2;
   
    for(double degree = 0.0; degree<2*M_PI; degree+=0.01){
        //fill in
        
        int x = (int)(rx*cos(degree));
        int y = (int)(ry*sin(degree));
        
        x+=cx;
        y+=cy;
        
        if(x>0 && x<SIZE  && y>0 && y<SIZE){
                image[x][y]=0;
            }

        }
    }
    
    




int main() {
     for (int i=0; i < SIZE; i++) {
      for (int j=0; j < SIZE; j++) {
         image[i][j] = 255;
      }
   }
    int cr, cc, h, w;
       cout << "Enter Center Row: ";
      cin >> cr;
      cout << "Enter Center Column: ";
      cin >> cc;
      cout << "Enter Height ";
      cin >> h;
      cout << "Enter Width: ";
      cin >> w;
      draw_ellipse(cr, cc, h, w);
   
    writeGSBMP("eclipseprac.bmp", image);
    
    
return 0;
}