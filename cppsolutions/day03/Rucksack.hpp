#ifndef DEF_RUCKSACK
#define DEF_RUCKSACK

#include <string>

class Rucksack { 
    private: 
    int nbOfItems; 
    std::string content; 

    public: 
    // Constructors 
    Rucksack(); 
    Rucksack(std::string newcontent); 

    // Getters 
    int getNbOfItems(); 
    std::string getContent(); 
    char getDoubledLetter(); 
}; 

#endif