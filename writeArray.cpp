#include <iostream>
#include <fstream>
using namespace std;

// take array as argument
// goes trhough array and write each value on file separated by commas and line breaks

void writeArray( double ** array, unsigned height, unsigned width ) {
    
    const char *path="/Users/dideronguillaume/Desktop/2015-Fractals-Lightning/gridArray.txt"; // create file to write in
    ofstream fout(path) ; // call on file as output
    
    for( int i = 0 ;  i < height ; ++ i ) { // sweeping through the whole array vertically
        
        fout << std::endl; // Break line for every new row
        
        for( int j = 0 ; j < width ; ++j ) { // sweeping through the whole array horizontally
            
            fout << array[i][j] << ", " ; // Display the cell values for a row seperated by spaces and commas
            
        }
    }

    fout.close(); //closes file
}

