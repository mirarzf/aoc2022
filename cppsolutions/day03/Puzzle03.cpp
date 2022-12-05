#include <iostream>
#include <fstream> 
#include <sstream>
#include <string>
#include <vector>

#include "Puzzle03.hpp"
#include "Rucksack.hpp"
#include "GroupOfRucksacks.hpp"

using namespace std; 

// Constructors 

Puzzle03::Puzzle03() : input("") {}; 

Puzzle03::Puzzle03(string newinput) {
    input = newinput; 
} 

// Getters 
int Puzzle03::getPriority(char letter) { 
    int asciicode = int(letter); 
    if (asciicode >= 97 && asciicode <= 122) { // a to z 
        return asciicode-96; 
    } else if (asciicode >= 65 && asciicode <= 90) { // A to Z
        return asciicode-38; 
    } else {
        return 0; 
    }
}

int Puzzle03::getSolution(int puzzlepart) {
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