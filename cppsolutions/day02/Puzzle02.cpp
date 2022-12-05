#include <iostream>
#include <fstream> 
#include <sstream>
#include <string>

#include "Puzzle02.hpp"

using namespace std; 

// Useful functions 
int getValueAssociatedToMove(std::string letter) { 
    if (letter == "A" || letter == "X") { // Rock 
        return 1; 
    } else if (letter == "B" || letter == "Y") { // Paper 
        return 2; 
    } else if (letter == "C" || letter == "Z") { // Scissors 
        return 3; 
    } else { 
        return 0; 
    }
}

int getValueAssociatedToResult(std::string letter) { 
    if (letter == "X") { // Loss 
        return 0; 
    } else if (letter == "Y") { // Draw 
        return 3; 
    } else if (letter == "Z") { // Win 
        return 6; 
    } else { 
        return 0; 
    }
}

// Constructors 

Puzzle02::Puzzle02() : input("") {}; 

Puzzle02::Puzzle02(string newinput) {
    input = newinput; 
} 

// Getters 

int Puzzle02::getSolution(int puzzlepart) {
    int score = 0; 

    stringstream inputss(input); 
    string row; 
    while (inputss.good()) { 
        getline(inputss, row); 
        stringstream ss(row); 
        string opponent; 
        getline(ss, opponent, ' '); 
        
        string second; 
        getline(ss, second); 
        
        if (puzzlepart == 1) {
            score += getRoundResult(opponent, second); 
        } else if (puzzlepart == 2) { 
            score += getRoundResult2(opponent, second); 
        } 
    }
    return score; 
}

int Puzzle02::getRoundResult(string opponent, string yourself) {
    int opp = getValueAssociatedToMove(opponent); 
    int yself = getValueAssociatedToMove(yourself); 

    if (opp == 0 || yself == 0) {
        return 0; 
    } else if (opp - yself == 0) { // Draw 
        return yself + 3; 
    } else if ((yself - opp) % 3 == 1) { // Win 
        return yself + 6; 
    } else { // Loss 
        return yself; 
    }
}

int Puzzle02::getRoundResult2(string opponent, string result) { 
    int opp = getValueAssociatedToMove(opponent); 
    int res = getValueAssociatedToResult(result); 

    if (opp == 0) {
        return 0; 
    } else if (res == 3) { // Draw 
        return opp + 3; 
    } else if (res == 6) { // Win 
        int ret = (opp % 3) + 1;  
        return ret + 6; 
    } else { // Loss 
        if (opp == 1) { 
            return 3; 
        } else { 
            return opp-1; 
        }
    }
}