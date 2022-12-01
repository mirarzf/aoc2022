#include <iostream>
#include <sstream>
#include <string> 

#include "cpp_solutions/Dailypuzzle.hpp"

using namespace std;


int main () { 
    /* Instantiation of the file */ 
    string myfilename; 
    cout << "Filename of the input: "; 
    cin >> myfilename; 
    int myday; 
    cout << "Day of the problem: "; 
    cin >> myday; 

    /* Instantiate the puzzle class */

    Dailypuzzle puzzle = Dailypuzzle(myfilename, myday); 
    cout << "Currently calculating the solution... \n"; 

    // Solution to puzzle 1
    cout << "The solution to part one is " << puzzle.getSolution(1) << ". \n"; 
    // Solution to puzzle 2
    cout << "The solution to part two is " << puzzle.getSolution(2) << ". \n"; 

    cout << "Tap x and enter to close the program. \n";
    char wait;
    cin >> wait; 
    cin.ignore(); 

    return 0; 
}