#include <iostream>
#include <math.h>


// Function taking average suqare difference of 2 arrays and comparing it to and error
// takes arrays, dimensions and error. Returns bool

///////////////////  Structure   ////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// - call variables to be used
// - goes through all correspoding values in arrays, squares them and takes their difference
// - averages the difference of squares
// - compares the average difference to square of error. Returns false if bigger, true if smaller
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



// returns bool, false if convergeance not achieve (difference bigger than error) true if under error
bool convergeanceCheck ( double ** oldArray, double ** newArray, unsigned height, unsigned width, double error ) {
// take two arrays, their dimensions and error value
    
    
    
    //--------Vairbles--------///
    bool Check;           // call the bool variable to be used and return
    double totalDiff = 0; // The sum of all the squre differences
    double arrayDiff = 0; // The average of the differences to be compared


    
    //--------Taking the square differences--------///
    //goes through all correspoding values in arrays, squares them and takes their difference
    for ( int i = 1 ; i < height - 1 ; i++ ) { // sweep vertical centre of array (place on grid where stuff changes)
        
        for ( int j = 0 ; j < width ; j++ ) { // sweep whole horizontal range of array
            
            totalDiff += pow(newArray[i][j], 2) - pow(oldArray[i][j], 2); //takes difference of every values and averages it
            
        } // end of horizontal sweep
        
    } //end of vertical sweep
    

    
    //--------averages the difference of squares------////
    arrayDiff = totalDiff / ( width * ( height - 1 ) );
    
    

    //-------Compare square root of result to error---/////
    //returns false if bigger
    if ( sqrt (arrayDiff)  >= error ) Check = false;
    
    //true if smaller
    else if ( sqrt (arrayDiff) < error ) Check = true;
    
    
    return Check;
    
}

