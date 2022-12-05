#ifndef DEF_PUZZLE05
#define DEF_PUZZLE05

#include <sstream>
#include <string>

class Puzzle05 { 
    protected: 
    std::string input; 

    public: 

    // Constructors 
    Puzzle05(); 
    Puzzle05(std::string newinput); 

    // Getters 
    // virtual int getSolution(int puzzlepart) const; 
    std::string getSolution(int puzzlepart); 
}; 

#endif 