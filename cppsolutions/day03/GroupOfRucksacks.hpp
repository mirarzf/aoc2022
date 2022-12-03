#ifndef DEF_GROUPRUCKSACK
#define DEF_GROUPRUCKSACK

#include <string>
#include <vector> 

#include "Rucksack.hpp"

class GroupOfRucksacks { 
    private: 
    std::vector<Rucksack> rucksacks; 

    public: 
    // Constructors 
    GroupOfRucksacks(); 
    GroupOfRucksacks(std::vector<Rucksack> newrucksacks); 

    // Getters 
    Rucksack getRucksack(int number); 
    char getBadge(); 
}; 

#endif