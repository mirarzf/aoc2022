#include <vector>
#include <string> 
#include <sstream>

#include "Heightmap.hpp"

using namespace std; 

// Constructors 
Heightmap::Heightmap(string input) { 
    stringstream inputss(input); 
    string row = "begin"; 
    heights = {}; 
    nrow = 0; 
    predecessors = {}; 
    while (inputss && row != "") {
        getline(inputss, row); 
        if (nrow == 0) { 
            ncol = row.size(); 
        }
        for (int j = 0; j < ncol; j++) {
            int charInt = row[j]; 
            if (row[j] == 'S') { 
                charInt = 97; 
                heights.push_back(charInt); 
                start = {nrow, j}; 
            } else if (row[j] == 'E') {
                charInt = 122; 
                heights.push_back(charInt); 
                end = {nrow, j}; 
            } else { 
                heights.push_back(charInt); 
            }
            predecessors.push_back(make_pair(nrow,j)); 
        }
        nrow++; 
    }
    int N = nrow*ncol; 
    vector<int> dist(N, N); 
    distances = dist; 
}

// Getters 
pair<int, int> Heightmap::getStart() { 
    return start; 
}

pair<int, int> Heightmap::getEnd() { 
    return end; 
}

int Heightmap::getSize() { 
    return nrow*ncol; 
}

pair<int, int> Heightmap::getPredecessor(int i, int j) { 
    return predecessors[i*ncol+j]; 
}

int Heightmap::getLenPath(pair<int,int> startPoint) { 
    return distances[startPoint.first*ncol+startPoint.second]; 
}

vector<pair<int, int>> Heightmap::getLowestElevationPoints() { 
    vector<pair<int, int>> lowestPoints = {}; 
    int charLowest = 'a'; 
    for (int i = 0; i < nrow; i++) { 
        for (int j = 0; j < ncol; j++) { 
            if (heights[i*ncol+j] == charLowest) { 
                lowestPoints.push_back(make_pair(i,j)); 
            }
        }
    }
    return lowestPoints; 
}

// Setters 

void Heightmap::Dijkstra() {  
    int N = nrow*ncol; 
    vector<bool> toBeVisited(N, false); 
    vector<pair<int, int>> nextToVisit = {}; 
    int indexToVisit = 0; 
    int i = end.first; 
    int j = end.second; 
    distances[i*ncol+j] = 0;

    bool inBounds = false; // Condition so that the neighbour exists 
    bool isTheSamePair = false; // Condition so that (i1, j1) != (i, j)
    bool isReachable = false; // Condition so that the neighbour is attainable 
    while (indexToVisit < N) { 

        for (int i1 = i-1; i1 < i+2; i1++) { 
            for (int j1 = j-1; j1 < j+2; j1++) { 
                // Check if (i1, j1) is a neighbour 
                inBounds = i1 > -1 && i1 < nrow && j1 > -1 && j1 < ncol && (i1 == i|| j1 == j); 
                isTheSamePair = i1 == i && j1 == j; 
                if (inBounds && !isTheSamePair) { 
                    isReachable = heights[i*ncol+j] - heights[i1*ncol+j1] < 2; 
                }

                if (isReachable) { 
                    // Check if we have to update the distance of neighbour (i1, j1)
                    if (distances[i1*ncol+j1] >= distances[i*ncol+j]+1) { 
                        distances[i1*ncol+j1] = distances[i*ncol+j]+1; 
                        predecessors[i1*ncol+j1] = make_pair(i, j); 
                    }

                    // Check if this neighbour has already been visited 
                    // Or if it scheduled to be visited 
                    // If not, add it to the queue of neighbours to visit 
                    if (!toBeVisited[i1*ncol+j1]) {
                        nextToVisit.push_back(make_pair(i1, j1)); 
                        toBeVisited[i1*ncol+j1] = true; 
                    }

                    isReachable = false; 
                }
            }
        }

        pair<int, int> toVisit = nextToVisit[indexToVisit]; 
        i = toVisit.first; 
        j = toVisit.second; 
        indexToVisit++; 
    }
}