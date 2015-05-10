#include <iostream>

const int N = 10, M = 10; // Initialise the dimensions of the array
                          // N is height M is width

void displayArray( double n[N][M] ) {
    
    for( int i = 0 ;  i < N ; ++ i ) {
        
        std::cout << std::endl; // Break line for every new row
        
        for( int j = 0 ; j < M ; ++j ) {
            
            std:: cout << n[i][j] << " " ; // Display the cell values for a row seperated by spaces
            
        }
    }
    std::cout
    << std::endl
    << "End of Array"
    << std::endl;
}