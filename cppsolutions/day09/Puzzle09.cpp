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
    if (puzzlepart == 1) { 
        Rope rope = Rope(input, 2); 
        return to_string(rope.getNumberOfVisitedPositions()); 
    } else { // puzzlepart == 2 
        Rope rope = Rope(input, 10); 
        return to_string(rope.getNumberOfVisitedPositions()); 
    }
};