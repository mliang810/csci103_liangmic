/* 
maze.cpp

Author:

Short description of this file:
*/

#include <iostream>
#include "mazeio.h"
#include "queue.h"

using namespace std;

// Prototype for maze_search, which you will fill in below.
int maze_search(char**, int, int);

// main function to read, solve maze, and print result
int main(int argc, char* argv[]) {
   int rows, cols, result;
   char** mymaze = NULL;
   mymaze = read_maze(argv[1], &rows, &cols);
   if(argc < 2)
   {
       cout << "Please provide a maze input file" << endl;
       return 1;
   }
   
   
   if (mymaze == NULL) {
      cout << "Error, input format incorrect" << endl;
      return 1;
   }

   // when working on Checkpoint 3, you will call maze_search here.
   // here. but for Checkpoint 1, just assume we found the path.
   result = maze_search(mymaze, rows, cols); // TO BE CHANGED

   // examine value returned by maze_search and print appropriate output
   if (result == 1) { // path found!
      print_maze(mymaze, rows, cols);
   }
   else if (result == 0) { // no path :(
      cout << "No path could be found!" << endl;
   }
   else { // result == -1
      cout << "Invalid maze." << endl;
   }

   // ADD CODE HERE to delete all memory 
   // that read_maze allocated
   for(int i = 0; i<rows; i++){
       delete [] mymaze[i];
   }
    delete [] mymaze;
      

   return 0;
}

/**************************************************
 * Attempt to find shortest path and return:
 *  1 if successful
 *  0 if no path exists
 * -1 if invalid maze (not exactly one S and one F)
 *
 * If path is found fill it in with '*' characters
 *  but don't overwrite the 'S' and 'F' cells
 *************************************************/
int maze_search(char** maze, int rows, int cols) 
{
    //creating queue that has row/col spaces
    Queue line(rows*cols);
    bool finish = false; //change to true when finish is found
    bool strt = false;
    bool fin = false;
    Location start;
    int strtcounter = 0;
    int fincounter = 0;

    //check if the maze has a start
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            if(maze[i][j] == 'S'){
                start.row = i;
                start.col = j; 
                strt = true;
                strtcounter++;
            }
            if(maze[i][j] == 'F'){ //check if maze has finish
                fin = true;
                fincounter++;
            }
        }
    }
    
    //if no start/finish, then return -1 
    if(strt == false ||fin == false||fincounter>1||strtcounter>1){
        return -1;
    }
    //add start to queue
    line.add_to_back(start);
    
    //dynamically allocate the 'visited' array
    int**visited = new int*[rows];
    for(int i=0; i<rows; i++){
        visited[i] = new int[cols];
    }
    
    //set whole visited array to zero (1 stands for visted) 
    for (int i=0; i < rows; i++) {
      for (int j=0; j < cols; j++) {
          visited[i][j] = 0;
      }
    }
    
    visited[start.row][start.col] = 1; //marking start pt as visited
    
    //do predecessor array
    Location** predecessor = new Location*[rows];
    for(int i=0; i<rows; i++){
        predecessor[i] = new Location[cols];
    }
    Location initialpred;
    initialpred.row = -1;
    initialpred.col = -1;
    
    for (int i=0; i < rows; i++) {
      for (int j=0; j < cols; j++) {
          predecessor[i][j] = initialpred; //make all pred spots -1,-1
      }
    }
    
    //while queue is not empty, 
    while(!line.is_empty()&& finish==false){
        Location curr = line.remove_from_front();
        
        //NWSE Neighbor Checking
        //NORTH
        Location north;
        north.row = curr.row-1;
        north.col = curr.col; 
        //can you go that way? aka in bounds or not
        if(north.row< rows && north.row>=0){
            if(north.col < cols && north.col>=0){
               //is it the finish line?
                if(maze[north.row][north.col] == 'F'){ 
                   while(maze[curr.row][curr.col] != 'S'){
                       finish = true;
                       //start tracing sequence
                       maze[curr.row][curr.col] = '*';
                       curr = predecessor[curr.row][curr.col]; //update curr
                       
                   }
                    break;
                }
            
                else if(maze[north.row][north.col] == '.'
                         && visited[north.row][north.col] == 0){
                    visited[north.row][north.col] = 1; //change to visited
                    predecessor[north.row][north.col] = curr; //update pred
                    line.add_to_back(north);
                }
            }
        }
    
        
        //WEST
        Location west;
        west.row = curr.row;
        west.col = curr.col - 1;
        
        //can you go that way? aka in bounds or not
        if(west.row < rows && west.row>=0){
            if(west.col < cols && west.col>=0){
               //is it the finish line?
                if(maze[west.row][west.col] == 'F'){ 
                   while(maze[curr.row][curr.col] != 'S'){
                       finish = true;
                       //start tracing sequence
                       maze[curr.row][curr.col] = '*';
                       curr = predecessor[curr.row][curr.col]; //update curr
                      
                   }
                    break;
                }
                
            
                else if(maze[west.row][west.col] == '.'
                         && visited[west.row][west.col] == 0){
                    visited[west.row][west.col] = 1; //change to visited
                    predecessor[west.row][west.col] = curr; //update pred
                    line.add_to_back(west);
                }
            }
        }
                
            
        
        //SOUTH
        Location south;
        south.row = curr.row+1;
        south.col = curr.col;
        
        //can you go that way? aka in bounds or not
        if(south.row < rows && south.row>=0){
            if(south.col < cols && south.col>=0){
               //is it the finish line?
                if(maze[south.row][south.col] == 'F'){ 
                   while(maze[curr.row][curr.col] != 'S'){
                       finish = true;
                       //start tracing sequence
                       maze[curr.row][curr.col] = '*';
                       curr = predecessor[curr.row][curr.col]; //update curr
                       
                   }
                    break;
                }
            
                else if(maze[south.row][south.col] == '.'
                         && visited[south.row][south.col] == 0){
                    visited[south.row][south.col] = 1; //change to visited
                    predecessor[south.row][south.col] = curr; //update pred
                    line.add_to_back(south);
                }
            }
        }
        
           //EAST
        Location east;
        east.row = curr.row;
        east.col = curr.col+1;
        
        //can you go that way? aka in bounds or not
        if(east.row < rows && east.row>=0){
            if(east.col < cols && east.col>=0){
               //is it the finish line?
                if(maze[east.row][east.col] == 'F'){ 
                   while(maze[curr.row][curr.col] != 'S'){
                       finish = true;
                       //start tracing sequence
                       maze[curr.row][curr.col] = '*';
                       curr = predecessor[curr.row][curr.col]; //update curr
                       
                   }
                    break;
                }
            
                else if(maze[east.row][east.col] == '.'
                         && visited[east.row][east.col] == 0){
                    visited[east.row][east.col] = 1; //change to visited
                    predecessor[east.row][east.col] = curr; //update pred
                    line.add_to_back(east);
                }
            }
        }
        
        
    } // while loop
    
    //fail to find finish, delete
    if(line.is_empty() && finish == false){
        for(int i=0; i<rows; i++){
            delete [] predecessor[i];
            delete [] visited[i];
        }
    delete [] predecessor;
    delete [] visited;
    return 0;
    }
    
    //find finish, delete
    for(int i=0; i<rows; i++){
        delete [] predecessor[i];
        delete [] visited[i];
    }
    delete [] predecessor;
    delete [] visited;
    return 1; 
  
}
