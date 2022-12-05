#ifndef DEF_PAIRELVES
#define DEF_PAIRELVES

#include <utility>
#include <string> 

class PairElves { 
    private: 
    std::pair<int, int> assignment1; 
    std::pair<int, int> assignment2; 

    public: 
    // Constructors 
    PairElves(); 
    PairElves(std::string input); 

    // Getters 
    std::pair<int, int> getAssignment(int assignNb); 
    bool completeOverlap(); 
    bool overlap(); 
}; 

#endif 