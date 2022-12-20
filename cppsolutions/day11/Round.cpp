#include <string>
#include <vector>
#include <sstream>

#include "Round.hpp"
#include "Monkey.hpp"

using namespace std; 

// Useful functions 

long long unsigned int euclide(long long unsigned int a, long long unsigned int b ) { 
    // We make the assumption that a is superior to b 
    long long unsigned int c = a; 
    long long unsigned int d = b; 
    long long unsigned int r = a % b; 
    if (r == 0) { 
        return b; 
    }
    while (r != 0) { 
        c = d; 
        d = r; 
        r = c % d; 
    }
    return d; 
}; 

// Constructors 

Round::Round() { 
    Monkey* uniqueMonkey = new Monkey(); 
    monkeys = {uniqueMonkey}; 
    items = {1}; 
    monkeyIndex = {0}; 
    inspectionCounters = {0}; 
    commonMultiple = 1; 
}

Round::Round(string newinput) {
    monkeys = {}; 
    inspectionCounters = {}; 
    items = {}; 
    monkeyIndex = {}; 
    long long unsigned int currMonkey = 0; 
    stringstream inputss(newinput); 
    string line; 
    stringstream monkeyInput; 
    commonMultiple = 1; 
    vector<int> currDivTest; 
    while (inputss) { 
        getline(inputss, line); 
        monkeyInput << line; 
        monkeyInput << "\n"; 
        if (line == "") {  
            Monkey* monkeyptr = new Monkey(monkeyInput.str()); 
            monkeys.push_back(monkeyptr); 
            long long unsigned int nbStartItems = monkeyptr->getNbOfStartingItems(); 
            for (long long unsigned int i = 0; i < nbStartItems; i++) { 
                items.push_back(monkeyptr->getStartingItem(i)); 
                monkeyIndex.push_back(currMonkey); 
            }
            inspectionCounters.push_back(0); 
            currMonkey++; 
            monkeyInput.str(""); 
            currDivTest.push_back(monkeyptr->getDivisorTest()); 
        }
    }
    long long unsigned int d = currDivTest[0]; 
    for (long long unsigned int i = 0; i < currDivTest.size(); i++) { 
        if (d > currDivTest[i]) { 
            d = euclide(d, currDivTest[i]); 
        } else { // currDivTest[i] >= d 
            d = euclide(currDivTest[i], d); 
        }
    }
    
    for (long long unsigned int i = 0; i < currDivTest.size(); i++) { 
        commonMultiple *= currDivTest[i]; 
    } 
    commonMultiple /= d; 
}

// Destructor 

Round::~Round() { 
    for (Monkey* monkey: monkeys) { 
        delete monkey; 
    }
}

// Getters 

vector<long long unsigned int> Round::getInspectionCounters() { 
    return inspectionCounters; 
}

// Others 

void Round::doRound(int puzzlepart) { 
    long long unsigned int n = monkeys.size(); 
    long long unsigned int nItems = items.size(); 
    long long unsigned int worry = 0; 

    for (long long unsigned int i = 0; i < n; i++) { 
        for (long long unsigned int j = 0; j < nItems; j++) { 
            if (monkeyIndex[j] == i) { 
                worry = items[j]; 
                worry = monkeys[i]->getNewWorry(worry); 
                inspectionCounters[i]++;
                if (puzzlepart == 1) {
                    // Divide worry by 3 and approximate to closer integer 
                    worry /= 3; 
                } else { 
                    // Keep your worry levels at a manageable level 
                    worry = worry % commonMultiple; 
                }
                monkeyIndex[j] = monkeys[i]->getNextMonkey(worry);
                items[j] = worry; 
            }
        }
    }
}