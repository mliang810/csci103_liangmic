#include "turtle.h"
#include <cmath>

using namespace std; 

//class constructor 
Turtle::Turtle(double x0, double y0, double dir0){
    x = x0;
    y = y0;
    dir = dir0;
    color = draw::BLACK;
    val = 0;
    
}
//member function implementation
void Turtle::move(double dist){
    double x2 = x + (dist * cos(dir * M_PI/180));
    double y2 = y + (dist * sin(dir * M_PI/180));
    draw::setcolor(color);
    if(val = 0){
        draw::line(x, y, x2, y2);
    }
   //update new x, y values to reflect new position
   x = x2;
   y = y2;
}

void Turtle::turn(double deg){
    dir+=deg;
}

void Turtle::setColor(Color c){
    color = c;
}
    
void Turtle::off(){
    val = 1;
}

void Turtle::on(){
    val = 0;
}
