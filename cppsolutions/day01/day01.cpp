#include <fstream>
#include <iostream>
#include <sstream>
#include <string> 
#include <vector>
#include <bits/stdc++.h>

// INCLUDE HERE THE NECESSARY CLASSES 

using namespace std;

class Puzzle01 {
    private: 
    string input; 
    
    public: 
    // Constructors 
    Puzzle01() : input("") {}; 

    Puzzle01(string newinput) {
        input = newinput; 
    }

    // Getters 
    int getSolution(int puzzlepart) {
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
            return topcal[2]; 
        } else { 
            return topcal[0] + topcal[1] + topcal[2]; 
        }
    }
}; 


int main () { 
    /* Instantiation of the file */ 
    string filename; 
    cout << "Filename of the input in input folder: "; 
    cin >> filename; 
    filename = "../../input/" + filename; 
    cout << "Opening the file " << filename << "\n"; 

    /* Instantiate the puzzle class */
    ifstream file; 
    file.open(filename); 

    stringstream ss; 
    string line; 
    while (file.good()) { 
        getline(file, line);
        ss << line; 
        ss << "\n"; 
    } 
    file.close(); 
    
    Puzzle01 puzzle = Puzzle01(ss.str()); 

    cout << "Currently calculating the solution... \n"; 

    // Solution to puzzle 1 : 69883 
    cout << "The solution to part one is: " << puzzle.getSolution(1) << "\n"; 
    // Solution to puzzle 2 : 207576
    cout << "The solution to part two is: " << puzzle.getSolution(2) << "\n"; 

    cout << "Tap x and enter to close the program. \n";
    char wait;
    cin >> wait; 

    return 0; 
} 