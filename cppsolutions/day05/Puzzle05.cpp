#include <iostream>
#include <fstream> 
#include <sstream>
#include <string>

#include "Puzzle05.hpp"
#include "Stack.hpp"
#include "PilesOfStacks.hpp"

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
    PilesOfStacks piles = PilesOfStacks(input); 
    piles.move(); 
}