#include <iostream>
//#include "displayArray.cpp"


double ** createArray( unsigned height, unsigned width ) { // function returns a pointer pointing at an array of pointers pointing at an array of double values
   
    double ** array = 0; // initialise the pointer aka the grid array
    array = new double * [height]; // point it at a number "height" of pointers, the number of rows in the grid
    
    for ( int i = 0 ; i < height ; i++ ) {
        array[i] = new double[width]; //point each of the "height" number of pointers at a number "width" of values, aka the number of colums
        
        for ( int j = 0 ; j < width ; j++ ) {
            
            // Set condition if it is the bottom line
            if ( i == 0 )  array [i][j] = 0;// Then make the point equal to 1
            
            else if ( i == height - 1 ) array [i][j] = 1;
            
            // Otherwise set point to 0
            else array [i][j] = i / ( double(height) - 1 ) ;
            
        }
        
    }
    
    return array;
}



//display the output for testing (include display in header)

/*
int main() {
    
    double ** grid = createArray(100, 100);
    displayArray(grid, 100 ,100);
    
    return 0;
}

*/