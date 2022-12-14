#include <fstream>
#include <iostream>
#include <sstream>
#include <string> 

// INCLUDE HERE THE NECESSARY CLASSES 
#include "Puzzle10.hpp"

using namespace std;

int main () { 
    /* Instantiation of the file */ 
    string filename; 
    cout << "Filename of the input in input folder: "; 
    cin >> filename; 
    filename = "../../input/" + filename; 
    cout << "Opening the file " << filename << "\n"; 
    
    ifstream file; 
    file.open(filename); 

    string line; 
    stringstream inputss; 
    while (file.good()) { 
        
        getline(file, line);
        inputss << line; 
        inputss << "\n"; 
    } 
    file.close(); 

    /* Instantiate the puzzle class */
    Puzzle10 puzzle = Puzzle10(inputss.str()); 

    cout << "Currently calculating the solution... \n"; 

    // Solution to puzzle 1 : 15680 
    cout << "The solution to part one is: " << puzzle.getSolution(1) << "\n"; 
    // Solution to puzzle 2 : ZFBFHGUP
    cout << "The solution to part two is: " << puzzle.getSolution(2) << "\n"; 

    cout << "Tap x and enter to close the program. \n";
    char wait;
    cin >> wait; 

    return 0; 
}