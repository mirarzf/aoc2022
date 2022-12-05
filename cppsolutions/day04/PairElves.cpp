#include <string>
#include <utility>
#include <sstream>

#include "PairElves.hpp"

using namespace std; 

// Useful functions 

// function for converting string to integer
int stringTointeger(string str) {
    int dec = 0;
    for (int i = 0; i < str.length(); i++) {
 
        // Since ASCII value of character from '0'
        // to '9' are contiguous. So if we subtract
        // '0' from ASCII value of a digit, we get
        // the integer value of the digit.
        dec = dec * 10 + (str[i] - '0');
    }
    return dec;
}

// Constructors 

PairElves::PairElves() : assignment1({0,1}), assignment2({0,1}) {}; 

PairElves::PairElves(string input) { 
    stringstream inputss(input); 
    string assign; 
    int i = 0; 
    int assignArray[4]; 
    while(getline(inputss, assign, ',')){ // Separate both assignments 
       stringstream ss(assign);
        while(getline(ss, assign, '-')){
             // Get the beginning section and then the second section 
             assignArray[i] = stringTointeger(assign); 
             i++; 
        }
   }
    assignment1 = {assignArray[0], assignArray[1]}; 
    assignment2 = {assignArray[2], assignArray[3]}; 
}

// Getters 

pair<int, int> PairElves::getAssignment(int assignNb) { 
    if (assignNb == 1) { 
        return assignment1; 
    } else if (assignNb == 2) { 
        return assignment2; 
    } else { 
        return pair<int, int> {0,0}; 
    }
}

bool PairElves::completeOverlap() { 
    pair<int, int> assign1 = getAssignment(1); 
    pair<int, int> assign2 = getAssignment(2); 

    if (assign1.first == assign2.first) { 
        return true; 
    } else if (assign1.first < assign2.first) {
        return assign1.second >= assign2.second; 
    } else { // assign1.first > assign2.first 
        return assign1.second <= assign2.second; 
    }
}

bool PairElves::overlap() { 
    pair<int, int> assign1 = getAssignment(1); 
    pair<int, int> assign2 = getAssignment(2); 

    if (assign1.first == assign2.first) { 
        return true; 
    } else if (assign1.first < assign2.first) { 
        return assign1.second >= assign2.first; 
    } else { // assign1.first > assign2.first 
        return assign2.second >= assign1.first; 
    }
}