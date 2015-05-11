#include <iostream>
#include "displayArray.cpp"
#include "createArray.cpp"
#include "solveArray.cpp"
#include "writeArray.cpp"

// Main programme, contains main function

///////////////////  Structure   ////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// - Define main variables of the simulations: dimensions of grid and error tow hich the potential field should be calculated
// - Creates the original empty grid to be used
// - Apply potential calculation on grid
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


int main() {
    
    //------------Simulation Variables---------// (change variables here)
    const int height = 10, width = 10; // dimensions of the array
    const double error = 0.0000001; // maximum limit for difference between successive iterations
    
    
    //------------Empty grid potential grid creation---------//
    double ** grid = createArray(height, width); // The array is actually a pointer to pointers to values
    
    
    // For testing, print the array calculated
    displayArray(grid, height, width);
    
    
    //------------Potential Calculation---------//
    double ** newGrid = solveArray(grid, height, width, error); // iterations of the potential solver
    
    
    // For testing, print the array calculated
    displayArray(newGrid, height, width);
    
    // Write result array into a text file
    writeArray(newGrid, height, width);
    
    
    return 0; //end main func
}

//comments:
/*
 -find a way to output in python retreivable format
 -probably need to change the file name as ligthning path is probably going to be computed here
 
 */