#include <iostream>

void displayArray( double ** array, unsigned heigth, unsigned width ) { // taking array pointing to pointers pointing to double and dimesions
    
    for( int i = 0 ;  i < heigth ; ++ i ) {
        
        std::cout << std::endl; // Break line for every new row
        
        for( int j = 0 ; j < width ; ++j ) {
            
            std:: cout << array[i][j] << " " ; // Display the cell values for a row seperated by spaces
            
        }
    }
    std::cout
    << std::endl
    << "End of Array"
    << std::endl;
}