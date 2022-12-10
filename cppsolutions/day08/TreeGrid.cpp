#include <string> 
#include <sstream>

#include "TreeGrid.hpp"

using namespace std; 

TreeGrid::TreeGrid(string input) { 
    stringstream inputss(input); 
    nrow = 0; 
    string row; 
    while (inputss) { 
        getline(inputss, row); 
        for (char c: row) { 
            grid.push_back(c - '0'); 
            visGrid.push_back(true); 
        }
        if (!row.empty()) { 
            nrow++; 
        }
    }
    ncol = grid.size() / nrow; 
    updateVision(); 
}

int TreeGrid::getNrow() { 
    return nrow; 
}

int TreeGrid::getNcol() { 
    return ncol; 
}

int TreeGrid::getTreeAt(int i, int j) { 
    return grid[nrow*i + j]; 
}

bool TreeGrid::getVisionAt(int i, int j) { 
    return visGrid[nrow*i + j]; 
}

int TreeGrid::getNbVisibleTrees() { 
    int visibleTrees = 0; 
    for (int i = 0; i < visGrid.size(); i++) { 
        if (visGrid[i]) { 
            visibleTrees++; 
        }
    }
    return visibleTrees; 
}

pair<int, int> TreeGrid::getIndex(string side, int linei, int i) { 
    if (side == "left" || side == "right") { 
        return {linei, i}; 
    } else { // side == "up" || side == "down"
        return {i, linei}; 
    }
}

vector<bool> TreeGrid::getVisionFromSide(string side, int linei) { 
    int nline; 
    if (side == "left" || side == "right") { 
        nline = ncol; 
    } else { // side == "up" || side == "down"
        nline = nrow; 
    }
    
    vector<bool> visionFromSide(nline, true); 
    if (side == "left" || side == "up") { 
        pair<int, int> index = getIndex(side, linei, 0);  
        int previousTree = getTreeAt(index.first, index.second); 
        int currTree = 0; 
        for (int i = 1; i < nline; i++) { 
            index = getIndex(side, linei, i); 
            currTree = getTreeAt(index.first, index.second); 
            if (previousTree >= currTree) { 
                visionFromSide[i] = false; 
            } else { // currTree > previousTree
                previousTree = currTree; 
            }
        }

    } else { // side == "right" || side == "down"
        pair<int, int> index = getIndex(side, linei, nline-1);  
        int previousTree = getTreeAt(index.first, index.second); 
        int currTree = 0; 
        for (int i = nline-2; i > 0; i--) { 
            index = getIndex(side, linei, i); 
            currTree = getTreeAt(index.first, index.second); 
            if (previousTree >= currTree) { 
                visionFromSide[i] = false; 
            } else { // currTree > previousTree 
                previousTree = currTree; 
            }
        }
    }

    return visionFromSide; 
}

vector<bool> TreeGrid::getVisionFromRow(int rowi) { 
    vector<bool> visionFromLeft = getVisionFromSide("left", rowi); 
    vector<bool> visionFromRight = getVisionFromSide("right", rowi); 

    vector<bool> visionFromRow(ncol, true); 
    for (int i = 0; i < ncol; i++) { 
        visionFromRow[i] = visionFromLeft[i] || visionFromRight[i]; 
    }

    return visionFromRow; 
}

vector<bool> TreeGrid::getVisionFromCol(int coli) { 
    vector<bool> visionFromUp = getVisionFromSide("up", coli); 
    vector<bool> visionFromDown = getVisionFromSide("down", coli); 

    vector<bool> visionFromCol(nrow, true); 
    for (int i = 0; i < nrow; i++) { 
        visionFromCol[i] = visionFromUp[i] || visionFromDown[i]; 
    }

    return visionFromCol; 
}

int TreeGrid::distToNextVisible(int i, int j, string side) { 
    int maxi = getTreeAt(i, j); 
    int ret = 0; 
    
    if (side == "left") { 
        for (int k = j-1; k > -1; k--) { 
            int comptree = getTreeAt(i, k); 
            if (comptree >= maxi || k == 0) { 
                return j-k; 
            }
        }
        ret = j; 
        return ret; 
    } else if (side == "right") { 
        for (int k = j+1; k < ncol; k++) {
            int comptree = getTreeAt(i, k); 
            if (comptree >= maxi || k == ncol-1) { 
                return k-j; 
            }
        }
        ret = ncol-j; 
        return ret; 
    } else if (side == "up") { 
        for (int k = i-1; k > -1; k--) { 
            int comptree = getTreeAt(k, j); 
            if (comptree >= maxi || k == 0) { 
                return i-k; 
            }
        }
        ret = i; 
        return ret; 
    } else if (side == "down") { 
        for (int k = i+1; k < nrow; k++) { 
            int comptree = getTreeAt(k, j); 
            if (comptree >= maxi || k == nrow-1) { 
                return k-i; 
            }
        }
        ret = nrow-i; 
        return ret; 
    }
    return ret; 
}

int TreeGrid::getScenicScoreAt(int i, int j) { 
    int score = 1; 
    int scoreL = distToNextVisible(i, j, "left"); 
    int scoreR = distToNextVisible(i, j, "right"); 
    int scoreU = distToNextVisible(i, j, "up"); 
    int scoreD = distToNextVisible(i, j, "down"); 
    score = scoreL * scoreR * scoreU * scoreD; 
    return score; 
}

int TreeGrid::getHighestScenicScore() { 
    int maxScore = 0; 
    int currScore = 0; 
    for (int i = 1; i < nrow-1; i++) { 
        for (int j = 1; j < ncol-1; j++) { 
            currScore = getScenicScoreAt(i, j); 
            if (currScore > maxScore) { 
                maxScore = currScore; 
            }
        }
    }
    return maxScore; 
}


// Setters 

void TreeGrid::updateVision() { 
    vector<bool> visionFromRow, visionFromCol; 

    for (int i = 0; i < nrow; i++) { 
        visionFromRow = getVisionFromRow(i); 
        for (int j = 0; j < ncol; j++) { 
            visGrid[i*nrow+j] = visionFromRow[j]; 
        }
    }

    for (int j = 0; j < ncol; j++) { 
        visionFromCol = getVisionFromCol(j); 
        for (int i = 0; i < nrow; i++) { 
            visGrid[i*nrow+j] = visGrid[i*nrow+j] || visionFromCol[i]; 
        }
    }
}  