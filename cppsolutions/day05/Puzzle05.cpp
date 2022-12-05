#include <iostream>
#include <fstream> 
#include <sstream>
#include <string>

#include "Puzzle05.hpp"

using namespace std; 

// Constructors 

Puzzle05::Puzzle05() : input("") {}; 

Puzzle05::Puzzle05(string newinput) {
    input = newinput; 
} 

// Getters 

// int Puzzle05::getSolution(int puzzlepart) const {
// }; 

string Puzzle05::getSolution(int puzzlepart) {
    stringstream inputss(input); 
    string row; 
    while (inputss.good()) { 
        getline(inputss, row); 
    }
    if (puzzlepart == 1) {
        return "1"; 
    } else { 
        return "2"; 
    }
}