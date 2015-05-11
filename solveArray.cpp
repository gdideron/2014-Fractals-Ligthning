#include <iostream>
#include "convergeanceChecker.cpp" // for boolean function that checks convergence


// Function to compute the potential of an grid represented of an array
// Takes arrays, their dimensions and error to which potential is calculated

///////////////////  Structure   ////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// - take array and place it into a biffer array "oldArray"
// - create a second buffer array "newArray" and make its values equal the old array ones
// - start while loop that only stops when broken if difference between successive arrays is less than error
//      * Go through the newArray and compute potential for every point
//      * Check if difference between old and new array less than error, if so break loop
//      * if not replace values of oldArray with newArray's
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


// The function itself needs the original array on which to compute the laplacian, its dimensions and the max error required
double ** solveArray( double ** array, unsigned height, unsigned width, double error ) { // will pass to finction checking convergence ) {
    
    
    
    
//--------------Create oldArray----------------//
// create "oldArray" and store the array values in it
double ** oldArray = 0; // inititalise it
oldArray = new double * [height]; // point at number of pointers
    
for ( int i = 0 ; i < height ; i++ ) { // sweep through entire array vertically
        
    oldArray[i] = new double [width]; // point each pointer at another number "width" of pointers
        
    for ( int j = 0 ; j < width ; j++ ) { // sweep through entire array horizontally
            
        oldArray[i][j] = array[i][j] ;
            
    }// end of horizontal sweep
    
}// end of vertical sweep
    
    
//--------------Create newArray----------------//
//create newArray and set it equal to the previous one
static double ** newArray = 0;
newArray = new double * [height]; // point at number of pointers
    
for ( int i = 0 ; i < height ; i++ ) {
        
    newArray[i] = new double [width]; // point each pointer at another number of pointers
        
    for ( int j = 0 ; j < width ; j++ ) {
            
        newArray[i][j] = oldArray[i][j] ;
            
    }// end of horizontal sweep
    
}// end of vertical sweep


//--------------While Loop---------------------//
while ( true ) {
    
    //******loop through new Array and compute potential******//
    for ( int i = 1 ; i < height - 1 ; i++ ) {
    
        for ( int j = 0 ; j < width ; j++ ) {
        
            // Set conditions if point is on side of grid to only take 3 points
            
            // If it is on the left, j == 0
            // take points i - 1, i + 1, j + 1
            if ( j == 0 ) newArray[i][j] = ( newArray[i - 1][j] + newArray[i + 1][j] + newArray[i][j + 1] ) / 3;
            
            // If it is on the right, j == N - 1
            // take points i - 1, i + 1, j - 1
            else if ( j == width - 1 ) newArray[i][j] = ( newArray[i - 1][j] + newArray[i + 1][j] + newArray[i][j - 1] ) / 3;
        
            // Otherwise
            // Take the potential of the four surrounding
            // points and average them.
            // point i - 1, i + 1, j - 1, j + 1
            else newArray[i][j] = ( newArray[i - 1][j] + newArray[i + 1][j] + newArray[i][j - 1] + newArray[i][j + 1] ) / 4;
            
            }// end of horizontal sweep
    
    }// end of vertical sweep
    
    //******Ceck for convergence******//
    if ( convergeanceCheck ( oldArray, newArray, height, width, error ) ) break ;
    

    
    //******mreplace value of old with values of new******//    
    else {
            
        for ( int i = 1 ; i < height - 1 ; i++ ) {
                
            for ( int j = 0 ; j < width ; j++ ) {
                    
                oldArray[i][j] = newArray[i][j] ;
            
            } // end of horizontal sweep
                
        }// end of vertical sweep



        } // end of else (newArray becoming old statement)
    
    
    
} // end of while loop
                     
                     
    
    
        return newArray; // Array is a pointer to pointer to value as usual
} // end of function



// COMMENTS:
// -May be more effcient to have function that calculates sum of teh squares of an array's values and compare difference with error in the break statement
