#include <vector>
#include <string>
#include <sstream>

#include "PilesOfStacks.hpp"

using namespace std; 

// Useful functions 
bool isACapitalLetter(char c) { 
    int i = c; 
    if (i >= 65 && i <= 90) {
        return true; 
    }
    return false; 
}; 

// function for converting string to integer
int stringToInteger(string str) {
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

    getline(inputss, row); 
    int n = row.length();
    int nbOfStacks = (n-3)/4+1; 
    vector<vector<char>> temp(nbOfStacks, vector<char> {}); 
    inputss.str(""); 
    inputss << input; 

    while (inputss.good()) {
        getline(inputss, row); 
        if (row[0] != 'm' && !row.empty()) {
            for (int i = 0; i < nbOfStacks; i++) {
                int j = i*4+1; 
                if (isACapitalLetter(row[j])) {
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

string PilesOfStacks::getLastOfStacks() { 
    int n = getNbOfStacks(); 
    string lastOfStacks = ""; 
    for (int i = 0; i < n; i++) { 
        lastOfStacks += content[i].getLastChar(); 
    }
    return lastOfStacks; 
}

// Setters 
void PilesOfStacks::move(string instruct, int puzzlepart) { 
    stringstream ss(instruct); 
    string instructPart; 
    vector<int> instructArray; 
    int part = 0; 
    while (ss.good()) { 
        getline(ss, instructPart, ' '); 
        if (part % 2 == 1) { 
            instructArray.push_back(stringToInteger(instructPart)-1); 
        }
        part++; 
    }
    instructArray[0]++; 
    Stack toStack = getStack(instructArray[2]);  

    vector<char> moving = content[instructArray[1]].getOut(instructArray[0]); 
    vector<char> newToStack = toStack.getContent(); 
    for (int i = 0; i < instructArray[0]; i++) { 
        if (puzzlepart == 1) { 
            newToStack.push_back(moving[i]); 
        } else { // puzzlepart == 2 
            newToStack.push_back(moving[instructArray[0]-1-i]); 
        }
    }
    content[instructArray[2]].setContent(newToStack); 
}

void PilesOfStacks::moveAll(int puzzlepart) {
    for (string instr: instructions) {
        move(instr, puzzlepart); 
    }
}