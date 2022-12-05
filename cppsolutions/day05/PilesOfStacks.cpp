#include <vector>
#include <string>
#include <sstream>

#include "PilesOfStacks.hpp"

using namespace std; 

// Useful functions 
bool isALetter(char c) { 
    int i = c; 
    if (i >= 65 && i <= 90) {
        return true; 
    }
    return false; 
}; 

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
PilesOfStacks::PilesOfStacks() : content({}), instructions({"move 0 from 1 to 2"}) {}; 

PilesOfStacks::PilesOfStacks(string input) { 
    stringstream inputss(input); 
    string row; 
    instructions = {}; 

    inputss >> row; 
    int n = row.length();
    int nbOfStacks = (n-3)/4; 
    vector<vector<char>> temp(nbOfStacks); 
    inputss.str(""); 
    inputss << input; 
    string instruct; 

    while (inputss.good()) {
        if (row[0] != 'm' && !row.empty()) {
            for (int i = 0; i < nbOfStacks; i++) {
                int j = i*4+1; 
                if (isALetter(row[j])) {
                    temp[i].push_back(row[j]); 
                }
            }
        } else if (!row.empty()) { 
            instructions.push_back(row); 
        }
    }

    content = {}; 
    for (int i = 0; i < nbOfStacks; i++ ) {
        Stack newStack = Stack(temp[i]); 
        content.push_back(newStack); 
    }
}

// Getters 
vector<Stack> PilesOfStacks::getContent() { 
    return content; 
}; 

vector<string> PilesOfStacks::getInstructions() { 
    return instructions; 
}

Stack PilesOfStacks::getStack(int stackNb) { 
    return content[stackNb]; 
}

int PilesOfStacks::getNbOfStacks() { 
    return content.size(); 
}

// Setters 
void PilesOfStacks::move(string instruct) { 
    stringstream ss(instruct); 
    string instructPart; 
    vector<int> instructArray; 
    while (ss.good()) { 
        getline(ss, instructPart, ' '); 
        if (!isALetter(instructPart[0])) { 
            instructArray.push_back(stringTointeger(instructPart)-1); 
        }
    }
    Stack toStack = getStack(instructArray[2]);  

    vector<char> moving = content[instructArray[1]].getOut(instructArray[0]); 
    vector<char> newToStack = toStack.getContent(); 
    for (char c: moving) {
        newToStack.push_back(c); 
    }
    content[instructArray[2]].setContent(newToStack); 
}

void PilesOfStacks::moveAll() {
    for (string instr: instructions) {
        move(instr); 
    }
}