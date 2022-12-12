#ifndef DEF_ROPE
#define DEF_ROPE

#include <string>
#include <vector>
#include <map>

class Rope { 
    private: 
    std::map<std::pair<int, int>, int> tailpos; 
    int nbOfKnots; 
    std::vector<std::pair<int, int>> knots; 

    std::pair<int, int> getNextMove(std::pair<int, int> newheadpos, std::pair<int,int> tail); 

    public: 
    // Constructors 
    Rope(); 
    Rope(std::string inputMoves, int howManyKnots); 

    // Getters 
    bool isTAdjacentTo(int i, int j, std::pair<int, int> tail); 

    long long unsigned int getNumberOfVisitedPositions(); 

    // Setters 
    void moveHeadTo(char direction); 
    void move(std::string moves); 
}; 

#endif 