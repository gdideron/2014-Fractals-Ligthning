#include <iostream>

void displayArray( double ** array, unsigned height, unsigned width ) { // taking array pointing to pointers pointing to double and dimesions
    
    for( int i = 0 ;  i < height ; ++ i ) { // sweeping through the whole array vertically
        
        std::cout << std::endl; // Break line for every new row
        
        for( int j = 0 ; j < width ; ++j ) { // sweeping through the whole array horizontally
            
            std:: cout << array[i][j] << ", " ; // Display the cell values for a row seperated by spaces and commas
            
        }
    }
    std::cout
    << std::endl
    << "End of Array"
    << std::endl;
}