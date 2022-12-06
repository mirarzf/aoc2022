#ifndef DEF_PUZZLE06
#define DEF_PUZZLE06

#include <sstream>
#include <string>

class Puzzle06 { 
    protected: 
    std::string input; 

    public: 

    // Constructors 
    Puzzle06(); 
    Puzzle06(std::string newinput); 

    // Getters 
    // virtual int getSolution(int puzzlepart) const; 
    std::string getSolution(int puzzlepart); 
}; 

#endif 