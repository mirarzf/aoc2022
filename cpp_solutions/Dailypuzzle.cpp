#include <iostream>
#include <fstream> 
#include <sstream>
#include <string>

#include "Dailypuzzle.hpp"

using namespace std; 

// Constructors 

Dailypuzzle::Dailypuzzle(string myfilename, int myday) {
    day = myday; 
    filename = myfilename; 
} 

// Getters 

int Dailypuzzle::getSolution(int puzzlepart) {
    if (puzzlepart == 1) {
        return 1; 
    } else { 
        return 2; 
    }
}

string Dailypuzzle::getFilename() { 
    return filename; 
}

stringstream Dailypuzzle::getStringstreamFromFile() { 
    ifstream file; 
    file.open(getFilename()); 

    string line; 
    stringstream inputss; 
    while (file.good()) { 
        
        getline(file, line);
        inputss << line; 
        inputss << "\n"; 
    } 
    file.close(); 
    return inputss; 
}