#include <string> 
#include <vector> 
#include <sstream>

#include "Register.hpp"

using namespace std; 

// Constructors 

Register::Register() : value(1), clock(0) {}; 

// Getters 

int Register::getClock() { 
    return clock; 
}

int Register::getValue() { 
    return value; 
}

// Setters 
void Register::addX(int addxvalue) { 
    value += addxvalue; 
    clock += 2; 
}

void Register::noop() { 
    clock++; 
}

// Others 

long long int Register::getSumSignalStrengthAt(string input, vector<int> cycleTimes) { 
    long long unsigned cycleIndex = 0; 
    int cycleTime = cycleTimes[cycleIndex]; 
    long long int sumSigStrengths = 0; 
    int addxvalue = 0; 

    stringstream inputss(input); 
    string line; 
    while(inputss.good()) { 
        getline(inputss, line); 
        if (line[0] == 'a') { // Addx line 
            if (getClock()+2 >= cycleTime) { 
                sumSigStrengths += cycleTime*getValue(); 
                cycleIndex++; 
                cycleTime = cycleTimes[cycleIndex]; 
            }
            addxvalue = stoi(line.substr(5)); 
            addX(addxvalue); 
        } else { // noop line 
            if (getClock()+1 >= cycleTime) { 
                sumSigStrengths += cycleTime*getValue(); 
                cycleIndex++; 
                cycleTime = cycleTimes[cycleIndex]; 
            }
            noop(); 
        }
    }
    return sumSigStrengths; 
}

string Register::getCRToutput(string input) { 
    string CRT = "\n"; 
    int pixelpos = 0; 
    int xvalue = getValue(); 
    int addxvalue = 0; 

    stringstream inputss(input); 
    string line; 
    getline(inputss, line); 
    while(inputss.good() && line != "") { 
        if (line[0] == 'a') { // Addx line 
            xvalue = getValue(); 
            if (abs(pixelpos-xvalue) <= 1) {
                CRT = CRT + '#'; 
            } else {
                CRT = CRT + ' '; 
            }
            pixelpos++; 

            if (pixelpos == 40) { 
                CRT = CRT + '\n'; 
                pixelpos = 0; 
            }

            if (abs(pixelpos-xvalue) <= 1) {
                CRT = CRT + '#'; 
            } else {
                CRT = CRT + ' '; 
            }
            pixelpos++; 

            addxvalue = stoi(line.substr(5)); 
            addX(addxvalue); 
        } else { // noop line 
            xvalue = getValue(); 
            if (abs(pixelpos-xvalue) <= 1) {
                CRT = CRT + '#'; 
            } else {
                CRT = CRT + ' '; 
            }
            pixelpos++; 
            noop(); 
        }
        if (pixelpos == 40) { 
            CRT = CRT + '\n'; 
            pixelpos = 0; 
        }
        getline(inputss, line); 
    }
    return CRT; 
}