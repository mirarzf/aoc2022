#include <vector>
#include <string>
#include <sstream>
#include <map>
// #include <cstdio>

#include "Rope.hpp"

using namespace std; 

// Constructors 
Rope::Rope() {
    nbOfKnots = 2; 
    knots = {}; 
    for (int i = 0; i < nbOfKnots; i++) { 
        knots.push_back(make_pair(0,0));
    }
    tailpos[knots[nbOfKnots-1]] = 1;  
}

Rope::Rope(string inputMoves, int howManyKnots) { 
    nbOfKnots = howManyKnots; 
    knots = {}; 
    for (int i = 0; i < nbOfKnots; i++) { 
        knots.push_back(make_pair(0,0));
    }
    tailpos[knots[nbOfKnots-1]] = 1;  
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

pair<int, int> Rope::getNextMove(pair<int, int> newheadpos, pair<int, int> tail) { 
    int hi = newheadpos.first; 
    int hj = newheadpos.second; 
    int ti = tail.first; 
    int tj = tail.second; 

    if (abs(hi-ti) == 2 and abs(hj-tj) == 0) { 
        // Same column, different rows
        return make_pair(ti+(hi-ti)/2, tj); 
    } else if (abs(hi-ti) == 0 and abs(hj-tj) == 2) { 
        // Same row, different columns 
        return make_pair(ti, tj+(hj-tj)/2); 
    } else if (abs(hi-ti) == 2 and abs(hj-tj) == 1) { 
        // Diagonal, adjacent columns 
        return make_pair(ti+(hi-ti)/2, tj+(hj-tj)); 
    } else if (abs(hi-ti) == 1 and abs(hj-tj) == 2) { 
        // Diagonal, adjacent rows 
        return make_pair(ti+(hi-ti), tj+(hj-tj)/2); 
    } else if (abs(hi-ti) == 2 and abs(hj-tj) == 2) { 
        // Diagonal, nothing adjacent 
        return make_pair(ti+(hi-ti)/2, tj+(hj-tj)/2); 
    } 

    return make_pair(0,0); 
}

bool Rope::isTAdjacentTo(int i,  int j, pair<int, int> tail) { 
    if (abs(i-tail.first) <= 1 && abs(j-tail.second) <= 1) { 
        return true; 
    }
    return false; 
}

long long unsigned int Rope::getNumberOfVisitedPositions() { 
    long long unsigned int score = 0; 
    for (auto it = tailpos.begin(); it != tailpos.end(); it++) {
        score++;
    }
 
    return score; 
}

// Setters 
void Rope::moveHeadTo(char direction) { 
    vector<pair<int,int>> newpos; 
    // Calculate the new position of the first head 
    int i = knots[0].first; 
    int j = knots[0].second; 
    
    if (direction == 'L') { 
        // Going Left 
        j--; 
    } else if (direction == 'R') { 
        // Going Right 
        j++; 
    } else if (direction == 'D') { 
        // Going Down 
        i--; 
    } else if (direction == 'U') { 
        // Going Up 
        i++; 
    } 
    
    newpos.push_back(pair<int,int>({i,j})); 

    // Move other knots accordingly 
    for (int k = 1; k < nbOfKnots; k++) { 
        i = newpos.back().first; 
        j = newpos.back().second; 
         
        // Update the knot's position if it is 
        // no longer following the previous knot 
        // if it is not adjacent to its future position
        if (!isTAdjacentTo(i, j, knots[k])) { 
            pair<int, int> newpostuple = getNextMove({i,j}, knots[k]); 

            if (k == nbOfKnots-1) { 
                // Update the tail positions history 
                tailpos[newpostuple] = 1; 
            } 
            newpos.push_back(newpostuple); 
        } else { 
            // The position of the knot doesn't change 
            newpos.push_back(knots[k]); 
        }
    }

    // Now update knots with the actual new positions 
    knots = newpos; 
}

void Rope::move(string moves) { 
    char direction = moves[0]; 
    int numberOfMoving = stoi(moves.substr(2)); 
    for (int ind = 0; ind < numberOfMoving; ind++) { 
        moveHeadTo(direction); 
    }
}