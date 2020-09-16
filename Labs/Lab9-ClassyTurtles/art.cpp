#include "turtle.h"
#include "draw.h"
#include <cmath>

int main(){
    draw::setrange(-100, 100);
    draw::setpenwidth(10);
    
    draw::setcolor(0,0,255); //why is the first step black then the others blue
    
    Turtle one(-20, 50, 25);
    Turtle two(0, 15, 65);
    Turtle three(-80, -20, -25);
    Turtle four(50, -50, 68);
    
    //one
    
    one.setcolor(draw::BLUE);
    for(int i=0;i<7;i+=2){
        one.turn(27);
        one.move(10);
        draw::show(200);
    }
    one.move(50);
    
    draw::show(200);
    
    //two
    two.setcolor(draw::GREEN);
    two.turn(15);
    two.move(19);
    
    draw::show(200);
    
    two.turn(270);
    two.move(97);
    
    draw::show(200);
    
    two.turn(140);
    two.move(45);
    
    draw::show(200);
    
    //three
    three.setcolor(draw::YELLOW);
    three.turn(320);
    three.move(50);
    
    draw::show(200);
    
    three.turn(86);
    three.move(65);
    
    draw::show(200);
    
    three.turn(400);
    three.move(40);
    
    draw::show(200);
    
    
    //four
    four.setcolor(draw::RED);
    four.turn(25);
    four.move(70);
    
    draw::show(200);
    
    for(int i=10; i<31; i+=10){
        four.turn(i);
        four.move(i+8);
        draw::show(200);
    }
    
    return 0;
}
