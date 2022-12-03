#ifndef DEF_DAILYPUZZLE03
#define DEF_DAILYPUZZLE03

#include <sstream>
#include <string>

class Dailypuzzle { 
    protected: 
    std::string input; 

    public: 

    // Constructors 
    Dailypuzzle(); 
    Dailypuzzle(std::string newinput); 

    // Getters 
    int getPriority(char letter); 
    int getSolution(int puzzlepart); 
}; 

#endif 