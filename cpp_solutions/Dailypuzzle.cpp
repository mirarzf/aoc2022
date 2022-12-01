#include <iostream>
#include <fstream> 
#include <sstream>
#include <string>

#include "Dailypuzzle.hpp"

using namespace std; 

// Constructors 

Dailypuzzle::Dailypuzzle() { 
    filename = "day01.txt"; 
}

Dailypuzzle::Dailypuzzle(string myfilename) {
    filename = myfilename; 
} 

// Getters 

int Dailypuzzle::getSolution(int puzzlepart) const {
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