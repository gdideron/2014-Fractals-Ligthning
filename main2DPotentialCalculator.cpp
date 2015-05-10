#include <iostream>
#include "displayArray.cpp"

//Define constants
//number of ierations of the potential calculation
//dimensions of the array

int main() {
    
    //Define constants
    const int iterations = 10000;//number of ierations of the potential calculation
    const int height = 10, width = 10;//dimensions of the array

    
    
// Create a NxN array that represents the grid
    double grid[height][width];

    
    
// Fill the array with 0s but for points associated with
// the bottom line of the grid (ground). Those are filled with 1s
// First going through the height of the array
    for ( int i = 0 ; i < height ; i++ ){ //i is vertical coordinate, N heigth
        
        // Then through the width of the array
        for ( int j = 0 ; j < width ; j++ ){ //j is horizontal coordinate, M width

// Set condition if it is the bottom line
            if ( i == 0 )  grid [i][j] = 1;// Then make the point equal to 1
            
                // Otherwise set point to 0
                else grid[i][j] = 0;

        } //end width loop
    }// end height loop
    

    

     // For testing, print the array calculated
     displayArray(grid);


    
    
// Go through the array again to get potential
//iterate the process an arbitrary number of times
for ( int c = 0; c < iterations ; c++ ){ // May replace with a while loop later if bool is used to check for convergence
    
    // First going through the height of the array minus 1
    // on both ends to discard bottom and top line of constant potential
    for ( int i = 1 ; i < height - 1 ; i++ ){
     
        // Then through the whole width of the array
        for ( int j = 0 ; j < width ; j++ ){
            
            // Set conditions if point is on side of grid to only take 3 points
        
            // If it is on the left, j == 0
            // take points i - 1, i + 1, j + 1
            if ( j == 0 ) grid[i][j] = ( grid[i - 1][j] + grid[i + 1][j] + grid[i][j + 1] ) / 3;

            // If it is on the right, j == N - 1
            // take points i - 1, i + 1, j - 1
            if ( j == width - 1 ) grid[i][j] = ( grid[i - 1][j] + grid[i + 1][j] + grid[i][j - 1] ) / 3;

            // Otherwise
            // Take the potential of the four surrounding
            // points and average them.
            // point i - 1, i + 1, j - 1, j + 1
            else grid[i][j] = ( grid[i - 1][j] + grid[i + 1][j] + grid[i][j - 1] + grid[i][j + 1] ) / 4;

            }// end of vertical scan
        
        }//end of horizontal scan
    
} //end of itertions
    
    
    
    // For testing, print the array calculated
    displayArray(grid);
    
    
    
    return 0; //end main func
}



//comments:
/*
 -find a way to output in python retreivable formatan
 
 -break tasks down into functions to call from the main file
 
 -start with a finite number of iterations before moving on to
 recognising convergence
 
 -later allow the size of array dimensions to be flexible to 
 allow for further investigation
 */
