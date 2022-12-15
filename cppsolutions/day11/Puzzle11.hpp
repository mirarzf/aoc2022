#ifndef DEF_PUZZLE11
#define DEF_PUZZLE11

#include "Monkey.hpp"

class Puzzle11 { 
    private: 
    std::string input; 
    std::vector<Monkey*> monkeys;
    std::vector<int> inspectionCounters; 
    std::vector<int> items; 
    std::vector<int> monkeyIndex; 

    public: 

    // Constructors 
    Puzzle11(); 
    Puzzle11(std::string newinput); 

    // Destructor 
    ~Puzzle11(); 

    // Getters
    // virtual int getSolution(int puzzlepart) const; 
    std::string getSolution(int puzzlepart); 

    // Others 
    void round(); 

}; 

#endif 