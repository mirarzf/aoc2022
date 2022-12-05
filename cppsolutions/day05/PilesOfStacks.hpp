#ifndef DEF_PILESOFSTACKS
#define DEF_PILESOFSTACKS 

#include <string> 
#include <vector>

#include "Stack.hpp"

class PilesOfStacks { 
    private: 
    std::vector<Stack> content;  
    std::vector<std::string> instructions; 

    public: 
    // Constructors 
    PilesOfStacks(); 
    PilesOfStacks(std::string input); 

    // Getters 
    std::vector<Stack> getContent(); 
    std::vector<std::string> getInstructions(); 
    Stack getStack(int stackNb); 
    int getNbOfStacks(); 

    // Setters 
    void move(std::string instruct); 
    void moveAll(); 
}; 

#endif 