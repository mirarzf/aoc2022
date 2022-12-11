#include <string>

#include "Puzzle09.hpp"
#include "Rope.hpp"

using namespace std; 

// Useful functions 


// Constructors 

Puzzle09::Puzzle09() : input("") {}; 

Puzzle09::Puzzle09(string newinput) { 
    input = newinput; 
}

// Getters 
string Puzzle09::getSolution(int puzzlepart) { 
    Rope rope = Rope(input); 
    return to_string(rope.getNumberOfVisitedPositions());  
};