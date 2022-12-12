#ifndef DEF_ROPE
#define DEF_ROPE

#include <string>
#include <vector>
#include <map>

class Rope { 
    private: 
    std::pair<int, int> head; 
    std::pair<int, int> tail; 
    std::map<std::pair<int, int>, int> knotspos; 

    public: 
    // Constructors 
    Rope(); 
    Rope(std::string inputMoves); 

    // Getters 
    std::pair<int, int> getHead(); 
    std::pair<int, int> getTail(); 
    bool isTAdjacentTo(int i, int j); 

    std::vector<int> getVisitedPositions(); 
    long long unsigned int getNumberOfVisitedPositions(); 

    // Setters 
    void moveHeadTo(int i, int j); 
    void move(std::string moves); 
}; 

#endif 