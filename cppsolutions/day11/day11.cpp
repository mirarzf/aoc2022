#include <fstream>
#include <iostream>
#include <sstream>
#include <string> 

// INCLUDE HERE THE NECESSARY CLASSES 
#include "Puzzle11.hpp"

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
    Puzzle11 puzzle = Puzzle11(inputss.str()); 

    cout << "Currently calculating the solution... \n"; 

    // Solution to puzzle 1 : answer1 
    cout << "The solution to part one is: " << puzzle.getSolution(1) << "\n"; 
    // Solution to puzzle 2 : answer2
    cout << "The solution to part two is: " << puzzle.getSolution(2) << "\n"; 

    cout << "Tap x and enter to close the program. \n";
    char wait;
    cin >> wait; 

    return 0; 
}