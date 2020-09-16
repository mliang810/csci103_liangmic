#include "delist.h"
#include <cstddef>

using namespace std;
DEList::DEList()
{
    head = NULL;
    tail = NULL;
    size = 0;
}
DEList::~DEList()
{
    DEItem* temp;
    temp = tail; //temp points to tail
    while(head!=tail){ //if the list isnt empty AND theres more than one item
        tail = tail->prev; //set tail to point to previous, thats the new tail
            delete temp;
            temp = tail; //temp is the 2nd to last val
    }
    delete tail; //delete tail
}
bool DEList::empty()
{
    if(head == NULL && tail == NULL){
        return 1; //true
    }
    else{
        return 0; //false
    }
 
}
// returns number of items in the list
int DEList::size()
{
    return size;
}
// returns front item or -1 if empty list
int DEList::front()
{
    if(empty()){
        return -1;
    }
    else{
        return head->val;
    }
}

// returns back item or -1 if empty list
int DEList::back()
{
    if(empty()){
        return -1;
    }
    else{
        return tail->val;
        
    }
}
// Adds a new integer to the front of the list
void DEList::push_front(int new_val)
{
    //declare new pointer (Adds to the size of the list since theres no space) 
    DEItem* temp = new DEItem; 
    temp->val = new_val; //newval is inserted into val, in the new temp space
    temp->prev = NULL; //temp space is now at the front of the list bc theres nothing before it
    temp->next = head; //means that we put temp before head, establishes its link to the next thing
    //must update head and tail 
    if(empty()){
        //both head and tail ppint at temp 
        head = temp;
        tail = temp;
    }
    else{
        head->prev = temp; //update prev with the position of temp
        head = temp;  //update head to point at temp
    }
    size++;
    
}
// Adds a new integer to the back of the list
void DEList::push_back(int new_val)
{
    DEItem* temp = new DEItem; 
    temp->val = new_val; //newval is inserted into val, in the new temp space
    temp->next = NULL; //the next space in temp is NULL, meaning that nothing is after it 
    temp->prev = tail; //means that we put temp at the very end, the current tail is now before it
    if(empty()){
        //both head and tail ppint at temp 
        head = temp;
        tail = temp;  
    }
    
    else{
        tail->next = temp; //the next item after the tail box is temp, tail is no longer the end 
        tail = temp;//update tail to point at temp, updates tail to once again be a real tail
    }
    size++;
}
// Removes the front item of the list (if it exists)
void DEList::pop_front()
{
    DEItem* temp; 
    if(!empty()){
        if(size() == 1){
           delete head;
           head = NULL;
           tail = NULL;
        }
            
        else{
            temp = head->next; //saving the address of the box after the one ur trying to delete as new start
            temp->prev = NULL; //temp space is now the first item in the list 
            //can delete the head pointer now
            delete head;
            //now delcare head, where temp is now the start
            head = temp;
            size--;
        }
    }
}
// Removes the back item of the list (if it exists)
void DEList::pop_back()
{

    DEItem* temp; 
    if(!empty()){
        if(size() == 1){
           delete tail;
           head = NULL;
           tail = NULL;
        }
            
        else{
            temp = tail->prev; //saving the address of the box before the one ur trying to delete as new end
            temp->next = NULL; //temp space is now the last item in the list 
            //can delete the tail pointer now
            delete tail;
            //now delcare tail, where temp is now the end
            tail = temp;
            size--;
        }
    }
}
  