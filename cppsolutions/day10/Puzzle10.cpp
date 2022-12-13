#include <string>
#include <vector>

#include "Puzzle10.hpp"
#include "Register.hpp"

using namespace std; 

// Useful functions 


// Constructors 

Puzzle10::Puzzle10() : input("") {}; 

Puzzle10::Puzzle10(string newinput) { 
    input = newinput; 
}

// Getters 
string Puzzle10::getSolution(int puzzlepart) { 
    Register reg = Register(); 
    if (puzzlepart == 1) { 
        vector<int> cycles = {20, 60, 100, 140, 180, 220}; 
        return to_string(reg.getSumSignalStrengthAt(input, cycles)); 
    } else { // puzzlepart == 2 
        return reg.getCRToutput(input); 
    }
};