#ifndef DEF_ROUND
#define DEF_ROUND

#include <string>
#include <vector>
#include <sstream>

#include "Monkey.hpp"

class Round { 
    private: 
    std::vector<Monkey*> monkeys; 
    std::vector<long long unsigned int> items; 
    std::vector<long long unsigned int> monkeyIndex; 
    std::vector<long long unsigned int> inspectionCounters; 
    long long unsigned int commonMultiple; 

    public: 
    // Constructors
    Round(); 
    Round(std::string newinput); 

    // Destructor 
    ~Round(); 

    // Getters 
    std::vector<long long unsigned int> getInspectionCounters(); 

    // Setters 
    void doRound(int puzzlepart); 
}; 

#endif 