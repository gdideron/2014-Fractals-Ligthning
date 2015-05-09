#include <iostream>

//Define constants
//number of ierations of the potential calculation
//dimensions of the array

int main() {
    
    //Define constants
    const int iterations = 10;//number of ierations of the potential calculation
    const int N = 10, M = 10;//dimensions of the array

    
    
// Create a NxN array that represents the grid
    double grid[N][M];

    
    
    
// Fill the array with 0s but for points associated with
// the bottom line of the grid (ground). Those are filled with 1s
// First going through the height of the array
    for (int i = 0 ; i < N ; i++ ){ //i is vertical coordinate, N heigth
        
        // Then through the width of the array
        for (int j = 0 ; j < M ; j++){ //j is horizontal coordinate, M width

// Set condition if it is the bottom line
            if (i == 0)  grid [i][j] = 1;// Then make the point equal to 1
            
                // Otherwise set point to 0
                else grid[i][j] = 0;

        } //end width loop
    }// end height loop
    
    
    

// For testing, print the array calculated
 /*
    for (int i = 0 ; i < N ; i++ ){
        for (int j = 0 ; j < M ; j++){
    std::cout << grid[i][j];

        }
    }
    
*/
    
    
// Go through the array again

// First going through the height of the array minus 1
// on both ends to discard bottom and top line of constant potential
// for i from one to N - 1

// Then through the whole width of the array
// for j from 0 to M

// Set conditions if point is on side of grid to only take 3 points

// If it is on the left, j == 0
// take points i - 1, i + 1, j + 1

// If it is on the right, j == N - 1
// take points i - 1, i + 1, j - 1

// Otherwise
// Take the potential of the four surrounding
// points and average them.
// point i - 1, i + 1, j - 1, j + 1

// Change value of point to appropriate average



//iterate the process an arbitrary number of times

    return 0;
}

//comments:
/*
 -break tasks down into functions to call from the main file
 
 -start with a finite number of iterations before moving on to
 recognising convergence
 
 -later allow the size of array dimensions to be flexible to 
 allow for further investigation
 */
