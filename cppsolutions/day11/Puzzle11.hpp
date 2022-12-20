#ifndef DEF_PUZZLE11
#define DEF_PUZZLE11

#include "Monkey.hpp"

class Puzzle11 { 
    private: 
    std::string input; 

    public: 

    // Constructors 
    Puzzle11(); 
    Puzzle11(std::string newinput); 

    // Getters
    // virtual int getSolution(int puzzlepart) const; 
    long long unsigned int getSolution(int puzzlepart); 


}; 

#endif 