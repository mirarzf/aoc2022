#include <iostream>
#include <fstream> 
#include <sstream>
#include <string>

#include "Dailypuzzle.hpp"
#include "PairElves.hpp"

using namespace std; 

// Constructors 

Dailypuzzle::Dailypuzzle() : input("") {}; 

Dailypuzzle::Dailypuzzle(string newinput) {
    input = newinput; 
} 

// Getters 

int Dailypuzzle::getSolution(int puzzlepart) {
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
    return score; 
}