#ifndef DEF_PUZZLE04
#define DEF_PUZZLE04

#include <sstream>
#include <string>

class Puzzle04 { 
    protected: 
    std::string input; 

    public: 

    // Constructors 
    Puzzle04(); 
    Puzzle04(std::string newinput); 

    // Getters 
    int getSolution(int puzzlepart); 
}; 

#endif 