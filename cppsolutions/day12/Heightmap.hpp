#ifndef DEF_HEIGHTMAP 
#define DEF_HEIGHTMAP 

#include <vector> 
#include <string> 

class Heightmap {
    private: 
    int nrow, ncol; 
    std::vector<int> heights; 
    std::pair<int, int> start, end; 
    int distances[nrow][ncol]; 
    std::pair<int, int> predecessors[nrow][ncol]; 

    public: 
    // Constructors 
    Heightmap(std::string input); 

    // Getters 
    std::pair<int, int> getStart(); 
    std::pair<int, int> getEnd(); 
    std::vector<std::pair<int, int>> getNeighbours(int i, int j); 
    std::pair<int, int> getPredecessor(int i, int j); 

    // Setters 
    void updateDistancesAround(int i, int j); 
    void Dijkstra(); 
}; 

#endif