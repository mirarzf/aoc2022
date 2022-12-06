#include <string>
#include <sstream>
#include <vector>
#include <bits/stdc++.h>

#include "Puzzle01.hpp"

using namespace std; 

// Constructors 
Puzzle01::Puzzle01() : input("") {}; 

Puzzle01::Puzzle01(string newinput) {
    input = newinput; 
}

// Getters 
string Puzzle01::getSolution(int puzzlepart) {
    stringstream ss(input); 
    string row; 
    vector<int> topcal(3, 0); 
    int calsum = 0; 
    while (ss.good()) { 
        getline(ss, row); 
        if (row.empty()) {
            if (topcal[0] < calsum) {
                topcal[0] = calsum; 
                sort(topcal.begin(), topcal.end()); 
            }
            calsum = 0; 
        } else { 
            calsum += stoi(row); 
        }
    }
    if (puzzlepart == 1) {
        return to_string(topcal[2]); 
    } else { 
        return to_string(topcal[0] + topcal[1] + topcal[2]); 
    }
}