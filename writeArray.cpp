#include <iostream>
#include <fstream>
using namespace std;

// take array as argument
// goes trhough array and write each value on file separated by commas and line breaks

void writeArray( double ** array, unsigned height, unsigned width ) {
    
    const char *path="/Users/gridArray.txt"; // create file to write in
    ofstream fout("gridArray.txt") ; // call on file as output
    
    for( int i = height - 1 ;  i >= 0 ; ++ i ) { // sweeping through the whole array vertically
        
        for( int j = 0 ; j < width ; ++j ) { // sweeping through the whole array horizontally
            
            fout << array[i][j] << " " ; // Display the cell values for a row seperated by spaces and commas
            
        }
        
        fout << std::endl; // Break line for every new row
        
    }

    fout.close(); //closes file
}

