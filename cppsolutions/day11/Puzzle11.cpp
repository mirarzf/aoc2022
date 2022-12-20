#include <string>

#include "Puzzle11.hpp"
#include "Round.hpp"

using namespace std; 

// Useful functions 


// Constructors 

Puzzle11::Puzzle11() { 
    input = ""; 
} 

Puzzle11::Puzzle11(string newinput) { 
    input = newinput; 
}

// Getters 
long long unsigned int Puzzle11::getSolution(int puzzlepart) { 
    Round round = Round(input); 
    if (puzzlepart == 1) { 
        for (int roundNb = 0; roundNb < 20; roundNb++ ) { 
            round.doRound(puzzlepart); 
        }
    } else { // puzzlepart == 2 
        for (int roundNb = 0; roundNb < 10000; roundNb++ ) { 
            round.doRound(puzzlepart); 
        }
    }
    vector<long long unsigned int> inspectionCounters = round.getInspectionCounters(); 
    long long unsigned int maxi1 = 0; 
    long long unsigned int maxi2 = 0; 
    long long unsigned int n = inspectionCounters.size(); 
    for (long long unsigned int i = 0; i < n; i++) { 
        if (inspectionCounters[i] >= maxi1) { 
            maxi2 = maxi1; 
            maxi1 = inspectionCounters[i]; 
        } else if (inspectionCounters[i] > maxi2) { 
            maxi2 = inspectionCounters[i]; 
        }
    }
    return maxi1*maxi2; 
};