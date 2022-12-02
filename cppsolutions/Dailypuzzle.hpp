#ifndef DEF_DAILYPUZZLE
#define DEF_DAILYPUZZLE

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
    // virtual int getSolution(int puzzlepart) const; 
    int getSolution(int puzzlepart); 
}; 

#endif 