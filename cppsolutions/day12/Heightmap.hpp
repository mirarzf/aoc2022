#ifndef DEF_HEIGHTMAP 
#define DEF_HEIGHTMAP 

#include <vector> 
#include <string> 

class Heightmap {
    private: 
    int nrow, ncol; 
    std::vector<int> heights; 
    std::vector<int> distances; 
    std::pair<int, int> start, end; 
    std::vector<std::pair<int, int>> predecessors; 

    public: 
    // Constructors 
    Heightmap(std::string input); 

    // Getters 
    std::pair<int, int> getStart(); 
    std::pair<int, int> getEnd(); 
    int getSize(); 
    std::pair<int, int> getPredecessor(int i, int j); 
    int getLenPath(std::pair<int, int> startPoint); 
    std::vector<std::pair<int, int>> getLowestElevationPoints(); 

    // Setters 
    void Dijkstra(); 
}; 

#endif