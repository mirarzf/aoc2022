#ifndef DEF_PUZZLE02
#define DEF_PUZZLE02

#include <sstream>
#include <string>

class Puzzle02 { 
    protected: 
    std::string input; 

    public: 

    // Constructors 
    Puzzle02(); 
    Puzzle02(std::string newinput); 

    // Getters 
    int getSolution(int puzzlepart); 
    
    // Others 
    int getRoundResult(std::string opponent, std::string yourself); 
    int getRoundResult2(std::string opponent, std::string result); 
}; 

#endif 