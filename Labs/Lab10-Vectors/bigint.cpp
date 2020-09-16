#include "bigint.h"
#include <iostream>

using namespace std;

//length for strings, size is for vectors

BigInt::BigInt(string s){ // convert string to sequence of digits
    length = (int)s.length() - 1;
    for(int i=length; i>= 0; i--){
        seqdig = s[i] - '0';
        number.push_back(seqdig); 
    }
    
       
    
}

string BigInt::to_string(){ //un-backwards the sequence of numbers so from 0123 to string--> 3210 
    size = (int)number.size() - 1; //why need this to avoid extra 0 in front for test 0?
    numberstring = ""; //declare it empty to clear old contents
    for(int i=size; i>= 0; i--){
        numberstring += (char)(number[i]+48);
        
    }
    
    return numberstring; 
}



void BigInt::add(BigInt b){
    //if theyre not the same length, use pushback and make them the same length
    while(number.size() != b.number.size()){ //can access private vars inside 'b'
        if(number.size() > b.number.size()){
            b.number.push_back(0);
        }
        else{
            number.push_back(0);
        }
        
    }
    
    
    sum = 0;
    top_carry = 0;
    
    for(int i = 0; i < number.size(); i++){
        sum = top_carry + number[i] + b.number[i];
        top_carry = 0; //reset the carry to 0 so prev doesnt carry over to the next calc
        top_carry = sum/10;
        number[i] = sum%10;
        
        
    }
    if(top_carry !=0){
        number.push_back(top_carry);
    }
    
    
}

/*
//remember to declare vector ints xnumber
//extra credit
//0-9 
// a10 b11 c12 d13 e14 f15
BigInt::BigInt(string s, int base){
    
    if(base != s.base){
        cout << "runtime error" << endl;
        return 1;
    }
    
    key = "A B C D E F"
    length = (int)s.length() - 1;
    stringtoint = new int*[length];
    
    //convert everything in hex number into an integer 
    for(int i=0; i<length; i++){
            for(int j=0; i<5; j++){
               if(s[i] == key[j]){
                   stringtoint[i] = j + 10;
               }
            }
        }
   
    xsum = 0;
    xcarry = 0;
    xnumber 
    //sum up the integers
    for(int i = 0; i < number.size(); i++){
        xsum = xcarry + stringtoint[i] + s.stringtoint[i];
        xcarry = 0;
            //go about converting sum into the appropriate 0-9/a-f
               if(xsum<=15){
                   if(xsum>10){ //if its a letter, then change the num val to a letter
                       seqchar = key[buffer -10];
                   }
                   
                   else{ //convert the num to a char
                       seqchar = (char)(xsum + 48);
                   }
                   
                   charnumber.push_back(seqchar);
               }
               
               if(xsum>15){
                   xcarry = 1;
                   buffer= xsum - 16;
                   
                   if(buffer > 9){
                       seqchar = key[buffer -10]; 
                   }
                   
                   else{//convert 0-9 buffer to text 0-9
                       seqchar =(char)(buffer+48);
                   }
                   
                   charnumber.push_back(seqchar);
                   charnumber.push_back(xcarry);
                   
               }
        
    }
    
    
    
}
*/