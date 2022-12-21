#include <string>

#include "Puzzle12.hpp"
#include "Heightmap.hpp"

using namespace std; 

// Useful functions 


// Constructors 

Puzzle12::Puzzle12() { 
    input = ""; 
} 

Puzzle12::Puzzle12(string newinput) { 
    input = newinput; 
}

// Getters 
string Puzzle12::getSolution(int puzzlepart) { 
    Heightmap heightsgrid = Heightmap(input); 
    heightsgrid.Dijkstra(); 
    if (puzzlepart == 1) {
        return to_string(heightsgrid.getLenPath(heightsgrid.getStart())); 
    } else { // puzzlepart == 2 
        vector<pair<int, int>> lowestPoints = heightsgrid.getLowestElevationPoints(); 
        int minimumSteps = heightsgrid.getSize(); 
        for (pair<int, int> lowpoint: lowestPoints) { 
            int steps = heightsgrid.getLenPath(lowpoint); 
            if (minimumSteps > steps) { 
                minimumSteps = steps; 
            }
        }
        return to_string(minimumSteps); 
    }
};