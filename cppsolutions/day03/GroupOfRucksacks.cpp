#include <vector>
#include <string>
#include <map> 
#include <iostream>

#include "Rucksack.hpp"
#include "GroupOfRucksacks.hpp"

using namespace std; 

// Constructors 
GroupOfRucksacks::GroupOfRucksacks() : rucksacks({Rucksack(), Rucksack(), Rucksack()}) {}; 

GroupOfRucksacks::GroupOfRucksacks(vector<Rucksack> newrucksacks) {
    rucksacks = newrucksacks; 
}

// Getters 
Rucksack GroupOfRucksacks::getRucksack(int number) { 
    return rucksacks[number]; 
}

char GroupOfRucksacks::getBadge() { 
    map<char, vector<int>> contentMap; 
    for (int number = 0; number < 3; number++) { 
        Rucksack rucksack = rucksacks[number]; 
        int nbOfItems = rucksack.getNbOfItems(); 
        string rcontent = rucksack.getContent(); 
        for (int i = 0; i < nbOfItems; i++) { 
            char key = rcontent[i]; 
            if (contentMap.count(key) == 0) { 
                contentMap.insert({key, {number}}); 
            } else if (contentMap[key].back() == number-1) {
                contentMap[key].push_back(number); 
                if (contentMap[key].size() == 3) { 
                    return key; 
                }
            } 
        }
    }
    return '0'; 
}