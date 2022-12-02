#ifndef DEF_DAILYPUZZLE
#define DEF_DAILYPUZZLE

#include <sstream>
#include <string>

class Dailypuzzle { 
    protected: 
    std::string filename; 

    public: 

    // Constructors 
    Dailypuzzle(); 
    Dailypuzzle(std::string myfilename); 

    // Getters 
    virtual int getSolution(int puzzlepart) const; 
    std::string getFilename(); 
    std::stringstream getStringstreamFromFile(); 
}; 

#endif 