#include <string>

#include "Puzzle08.hpp"
#include "TreeGrid.hpp"

using namespace std; 

// Useful functions 


// Constructors 

Puzzle08::Puzzle08() : input("") {}; 

Puzzle08::Puzzle08(string newinput) { 
    input = newinput; 
}

// Getters 
string Puzzle08::getSolution(int puzzlepart) { 
    TreeGrid trees = TreeGrid(input); 
    if (puzzlepart == 1) { 
        return to_string(trees.getNbVisibleTrees()); 
    } else if (puzzlepart == 2) {
        return to_string(trees.getHighestScenicScore()); 
    }
    return 0;  
};