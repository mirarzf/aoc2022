#include <vector>
#include <string>
#include <sstream>
// #include <cstdio>

#include "Rope.hpp"

using namespace std; 

// Constructors 
Rope::Rope() { 
    ncol = 1; 
    nrow = 1; 
    mincol = 0; 
    minrow = 0; 
    head = {0,0}; 
    tail = {0,0}; 
    knotspos = {tail}; 
}

Rope::Rope(string inputMoves) { 
    ncol = 1; 
    nrow = 1;  
    mincol = 0; 
    minrow = 0; 
    head = {0,0}; 
    tail = {0,0}; 
    knotspos = {tail}; 
    stringstream moveSS(inputMoves); 
    string row; 
    while (moveSS) { 
        getline(moveSS, row); 
        if (row != "") {
            move(row); 
        }
    }
}


// Getters 

pair<int, int> Rope::getHead() { 
    return head; 
}

pair<int, int> Rope::getTail() { 
    return tail; 
}

bool Rope::isTAdjacentTo(int i,  int j) { 
    if (abs(i-tail.first) > 1 || abs(j-tail.second) > 1) { 
        return false; 
    }
    return true; 
}


vector<int> Rope::getVisitedPositions() { 
    int nlength = nrow*ncol; 
    vector<int> gridPos(nlength, 0); 
    int index = 0; 
    for (pair<int, int> pos : knotspos) { 
        index = (pos.first-minrow) * ncol + (pos.second-mincol); 
        gridPos[index]++; 
    }
    return gridPos; 
}

long long unsigned int Rope::getNumberOfVisitedPositions() { 
    long long unsigned int score = 0; 
    vector<int> gridPos = getVisitedPositions(); 
    for (int nbVisits: gridPos) { 
        if (nbVisits > 0) { 
            score++; 
        }
    }
    return score; 
}

// Setters 
void Rope::moveHeadTo(int i, int j) { 
    // Update nrow, ncol, minrow and mincol if needed 
    if (i == nrow) { 
        nrow++; 
    } else if (i < minrow) { 
        nrow++; 
        minrow = i; 
    } 
    
    if (j == ncol) { 
        ncol++; 
    } else if (j < mincol) { 
        ncol++; 
        mincol = j; 
    }

    // Move Tail accordingly 
    // Check if the tail is still adjacent 
    // If yes, tail need not be moved 
    // Else, it needs to change according head move 
    // And position should be added to history knotspos 
    if (!isTAdjacentTo(i, j)) { 
        tail = pair<int, int>(head); 
        knotspos.push_back(tail); 
    } 

    // Update head (we needed the old data to update tail)
    head = {i, j}; 
}

void Rope::move(string moves) { 
    char direction = moves[0]; 
    int numberOfMoving = stoi(moves.substr(2)); 
    for (int ind = 0; ind < numberOfMoving; ind++) { 
        if (direction == 'R') { 
            moveHeadTo(head.first, head.second+1); 
        } else if (direction == 'L') { 
            moveHeadTo(head.first, head.second-1); 
        } else if (direction == 'U') { 
            moveHeadTo(head.first-1, head.second); 
        } else if (direction == 'D') { 
            moveHeadTo(head.first+1, head.second); 
        } 
    }
}