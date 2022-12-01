#ifndef DEF_DAY01
#define DEF_DAY01

#include <string>

#include "../Dailypuzzle.hpp"

class Day01 : public Dailypuzzle { 
    public: 

    // Constructors 

    Day01(std::string myfilename); 

    // Getters 
    virtual int getSolution(int puzzlepart); 
}; 

#endif