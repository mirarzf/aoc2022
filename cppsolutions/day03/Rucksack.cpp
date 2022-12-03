#include <string>
#include <map> 

#include "Rucksack.hpp"

using namespace std; 

// Constructors 
Rucksack::Rucksack() : nbOfItems(0), content("") {}; 

Rucksack::Rucksack(string newcontent) {
    content = newcontent; 
    nbOfItems = newcontent.size(); 
}

// Getters 
int Rucksack::getNbOfItems() { 
    return nbOfItems; 
}

string Rucksack::getContent() { 
    return content; 
}

char Rucksack::getDoubledLetter() { 
    // Check everything in the first compartment 
    map<char, int> contentMap; 
    int n = nbOfItems / 2; 
    for (int i = 0; i < n; i++) { 
        contentMap.insert({ content[i], 1 }); 
    }; 

    // Check in second compartment if element is already in first compartment 
    for (int i = n; i < nbOfItems; i++) { 
        if (contentMap.find(content[i]) != contentMap.end()) { 
            return content[i]; 
        }
    }

    return ' '; 
}