#ifndef DEF_RPS
#define DEF_RPS

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
    int getSolution(int puzzlepart); 
    
    // Others 
    int getRoundResult(std::string opponent, std::string yourself); 
    int getRoundResult2(std::string opponent, std::string result); 
}; 

#endif 