#include <sstream> 
#include <string>

#include "../Dailypuzzle.hpp"
#include "day01.hpp"

using namespace std; 

// Constructors 

Day01::Day01(string myfilename) {
    filename = myfilename; 
    day = 1; 
}

// Getters 

int Day01::getSolution(int puzzlepart) { 
    stringstream inputss = getStringstreamFromFile(); 
    if (puzzlepart == 1) { 

    }
}