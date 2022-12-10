#ifndef DEF_PUZZLE08
#define DEF_PUZZLE08

#include "TreeGrid.hpp"

class Puzzle08 { 
    private: 
    std::string input; 

    public: 

    // Constructors 
    Puzzle08(); 
    Puzzle08(std::string newinput); 

    // Getters 
    // virtual int getSolution(int puzzlepart) const; 
    std::string getSolution(int puzzlepart); 
}; 

#endif 