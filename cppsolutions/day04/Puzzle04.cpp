#include <iostream>
#include <fstream> 
#include <sstream>
#include <string>

#include "Puzzle04.hpp"
#include "PairElves.hpp"

using namespace std; 

// Constructors 

Puzzle04::Puzzle04() : input("") {}; 

Puzzle04::Puzzle04(string newinput) {
    input = newinput; 
} 

// Getters 

string Puzzle04::getSolution(int puzzlepart) {
    stringstream inputss(input); 
    string row; 
    int score = 0; 
    while (getline(inputss, row)) { 
        PairElves elfteam = PairElves(row); 
        if (puzzlepart == 1 && elfteam.completeOverlap()) {
            score++; 
        } else if (puzzlepart == 2 && elfteam.overlap()) { 
            score++; 
        }
    }
    return to_string(score); 
}