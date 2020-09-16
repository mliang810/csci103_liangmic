/********************************************************
 * CS 103 PA 1: Abundant numbers
 * Name: Michelle Liang
 * USC email: liangmic@usc.edu
 * Comments (you want us to know):
 *
 * Description:
 *   Displays the top 3 most "abundant" (see writeup)
 *   numbers in the input sequence.  The input sequence
 *   is assumed to be valid natural numbers separated
 *   by spaces and ending with 0.
 *
 *   ABSOLUTELY NO ARRAY or `string`/`vector`/etc. usage
 *   is allowed!

 *   You may only declare: bool, int, or unsigned int
 *   No library functions (beyond cin/cout) are allowed.
 *
 *   You may NOT modify any of the given template code.
 *   This ensures our automated checkers can parse your
 *   output.  Failure to follow this direction will lead
 *   to a score of 0 on this part of the assignment.
 ********************************************************/

#include <iostream>
using namespace std;

int main()
{
  // n1 is the number with the highest abundance, a1
  // n2 is the number with the 2nd-highest abundance, a2
  // n3 is the number with the 3rd-highest abundance, a3

     unsigned int n1 = 0, n2 = 0, n3 = 0;
     int a1 = 0 , a2 = 0, a3 = 0;


  // num_abundant counts how many numbers in the input
  // sequence are abundant
  int num_abundant = 0;

  cout << "Enter a sequence of natural numbers, separated by spaces, ";
  cout << "and ending with 0."<< endl;

  /* Your code here */
    //variables
    bool isabundant = true;
    int sumf = 0;
    int n;
    int temp;
    
 
    
    while(cin >> n && n!=0){
       sumf = 0;
       for(int i=1; i < n; i++){ 
           if(n%i == 0){
               sumf = sumf + i;
               
           }
       }
           
 //above is to det whether any number is abdt, here we start storing
       if(sumf > n){
           isabundant = true;
           num_abundant++;
           
           if(n1==0 || n2==0 || n3==0){
               if(n1==0){
                 a1 = sumf;
                 n1 = n;
               }
               else if(n2==0 && n1!=0){
                   a2 = sumf;
                   n2 = n;
               }
               else if(n3==0 && n2!=0){
                   a3 = sumf;
                   n3 = n;
               }
           }

            else if(isabundant && n1!=0 && n2!=0 && n3!=0){
              if(a1<a2 && a1<a3 && sumf>a1 && n!= n1 && n!= n2 && n!= a3){
                    a1 = sumf;
                    n1 = n;
                }
        
              else if(a2<a1 && a2<a3 && sumf>a2 && n!= n1 && n!= n2 && n!= a3){
                    a2 = sumf;
                    n2 = n;
                }
               
              else if(a3<a2 && a3<a1 && sumf>a3 && n!= n1 && n!= n2 && n!= a3){
                    a3 = sumf;
                    n3 = n;
                }
                
           
           }
       }
        
        else{
            isabundant = false;
        }
        
    }
    
    //put them in order
    
    if(a2 > a1 && a2 > a3){
             
        temp = a1;
        a1 = a2;
        a2 = temp;
        
        temp = n1;
        n1 = n2;
        n2 = temp;
       
        if(a3>a2){
             
            temp = a2;
            a2 = a3;
            a3 = temp;
            
            temp = n2;
            n2 = n3;
            n3 = temp;
        }
            
    }
    
    else if(a3 > a1 && a3 > a2){
        temp = a1;
        a1 = a3;
        a3 = temp;
        
        temp = n1;
        n1 = n3;
        n3 = temp;
        
        if(a3>a2){ 
            temp = a2;
            a2 = a3;
            a3 = temp;
            
            temp = n2;
            n2 = n3;
            n3 = temp;
        }
        
    }
    
    
    else if(a3 > a2){
        temp = a2;
        a2 = a3;
        a3 = temp;
           
        temp = n2;
        n2 = n3;
        n3 = temp;
    }
       
        
    

    
    
    
  /* End of your code */ //--> DONT FORGET to uncomment the skeleton code

 cout << "Abundant number count: " << num_abundant << endl;
 cout << "Top 3 most abundant numbers: " << endl;
 cout << n1 << " : " << a1 << endl;
 cout << n2 << " : " << a2 << endl;
 cout << n3 << " : " << a3 << endl;


  return 0;

}
