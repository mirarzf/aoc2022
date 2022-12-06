#include <iostream>
#include <fstream> 
#include <sstream>
#include <string>

#include "Dailypuzzle.hpp"

using namespace std; 

// Constructors 

Dailypuzzle::Dailypuzzle() : input("") {}; 

Dailypuzzle::Dailypuzzle(string newinput) {
    input = newinput; 
}

// Getters 

// virtual string Dailypuzzle::getSolution(int puzzlepart) const {
// }; 

string Dailypuzzle::getSolution(int puzzlepart) {
    stringstream inputss(input); 
    string row; 
    while (inputss.good()) { 
        getline(inputss, row); 
    }
    

    if (puzzlepart == 1) {
        return to_string(1); 
    } else { 
        return to_string(2); 
    }
}