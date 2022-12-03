#include <iostream>
#include <fstream> 
#include <sstream>
#include <string>
#include <vector>

#include "Dailypuzzle.hpp"
#include "Rucksack.hpp"
#include "GroupOfRucksacks.hpp"

using namespace std; 

// Constructors 

Dailypuzzle::Dailypuzzle() : input("") {}; 

Dailypuzzle::Dailypuzzle(string newinput) {
    input = newinput; 
} 

// Getters 
int Dailypuzzle::getPriority(char letter) { 
    int value = int(letter); 
    if (value >= 97 && value <= 122) { 
        return value-96; 
    } else if (value >= 65 && value <= 90) { 
        return value-38; 
    } else {
        return 0; 
    }
}

int Dailypuzzle::getSolution(int puzzlepart) {
    stringstream inputss(input); 
    string row; 
    int score = 0; 
    int groupNb = 0; 
    vector<Rucksack> newrucksacks; 
    while (inputss.good()) { 
        getline(inputss, row); 
        Rucksack thisRucksack = Rucksack(row); 
        if (puzzlepart == 1) { 
            char letter = thisRucksack.getDoubledLetter(); 
            score += getPriority(letter); 
        } 
        if (puzzlepart == 2) {
            newrucksacks.push_back(thisRucksack); 
            if (groupNb % 3 == 2) { 
                GroupOfRucksacks theseRucksacks = GroupOfRucksacks(newrucksacks); 
                char letter = theseRucksacks.getBadge(); 
                score += getPriority(letter); 
                newrucksacks = {}; 
            }
        } 
        groupNb++; 
    }
    return score; 
}