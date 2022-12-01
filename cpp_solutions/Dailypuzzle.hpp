#ifndef DEF_DAILYPUZZLE
#define DEF_DAILYPUZZLE

#include <sstream>
#include <string>

class Dailypuzzle { 
    private: 
    // std::stringstream inputss; 
    std::string filename; 
    int day; 

    public: 

    // Constructors 
    Dailypuzzle(std::string myfilename, int myday); 

    // Getters 
    int getSolution(int puzzlepart); 
    std::string getFilename(); 
    std::stringstream getStringstreamFromFile(); 
}; 

#endif 