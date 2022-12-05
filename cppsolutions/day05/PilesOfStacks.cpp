#include <vector>
#include <string>
#include <sstream>

#include "PilesOfStacks.hpp"

using namespace std; 

// Useful functions 
bool isALetter(char c) { 
    int i = c; 
    if (i >= 65 && i <= 90) {
        return true; 
    }
    return false; 
}; 

// Constructors 
PilesOfStacks::PilesOfStacks() : content({}), instructions({"move 0 from 1 to 2"}) {}; 

PilesOfStacks::PilesOfStacks(string input) { 
    stringstream inputss(input); 
    string row; 
    instructions = {}; 

    inputss >> row; 
    int n = row.length();
    int nbOfStacks = (n-3)/4; 
    vector<vector<char>> temp(nbOfStacks); 
    inputss.str(""); 
    inputss << input; 

    while (inputss.good()) {
        if (row[0] != 'm' && !row.empty()) {
            for (int i = 0; i < nbOfStacks; i++) {
                int j = i*4+1; 
                if (isALetter(row[j])) {
                    temp[i].push_back(row[j]); 
                }
            }
        } else if (!row.empty()) { 
            instructions.push_back(row); 
        }
    }

    content = {}; 
    for (int i = 0; i < nbOfStacks; i++ ) {
        Stack newStack = Stack(temp[i]); 
        content.push_back(newStack); 
    }
}

// Getters 
vector<Stack> PilesOfStacks::getContent() { 
    return content; 
}; 

vector<string> PilesOfStacks::getInstructions() { 
    return instructions; 
}

// Setters 
void move(string instruct) { 
    
}