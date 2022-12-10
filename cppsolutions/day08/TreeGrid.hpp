#ifndef DEF_TREEGRID
#define DEF_TREEGRID

#include <string> 
#include <vector> 

class TreeGrid { 
    private: 
    int nrow, ncol; 
    std::vector<int> grid = {}; 
    std::vector<bool> visGrid = {}; 

    public: 
    // Constructors 
    TreeGrid(std::string intput); 
    
    // Getters 
    int getNrow(); 
    int getNcol(); 
    int getTreeAt(int i, int j); 
    bool getVisionAt(int i, int j); 
    int getNbVisibleTrees(); 

    std::pair<int, int> getIndex(std::string side, int linei, int i); 

    std::vector<bool> getVisionFromSide(std::string side, int linei); 
    std::vector<bool> getVisionFromRow(int rowi); 
    std::vector<bool> getVisionFromCol(int coli);
    
    int distToNextVisible(int i, int j, std::string side); 

    int getScenicScoreAt(int i, int j); 
    int getHighestScenicScore(); 
    
    // Setters 

    void updateVision(); 

}; 

#endif 