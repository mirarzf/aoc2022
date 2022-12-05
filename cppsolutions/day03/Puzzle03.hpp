#ifndef DEF_PUZZLE03
#define DEF_PUZZLE03

#include <sstream>
#include <string>

class Puzzle03 { 
    protected: 
    std::string input; 

    public: 

    // Constructors 
    Puzzle03(); 
    Puzzle03(std::string newinput); 

    // Getters 
    int getPriority(char letter); 
    int getSolution(int puzzlepart); 
}; 

#endif 