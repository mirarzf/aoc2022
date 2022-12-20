#include <vector>
#include <string> 
#include <sstream>

#include "Heightmap.hpp"

using namespace std; 

// Constructors 
Heightmap::Heightmap(string input) { 
    stringstream inputss(input); 
    string row = "begin"; 
    while (inputss && row != "") {
        getline(inputss, row); 
        nrow = row.size();  
        for (int i = 0; i < nrow; i++) {
            if (row[i] == 'S') { 
                heights.push_back('a'-'0'); 
            }
        }
    }
}

// Getters 


// Setters 