#include <string>
#include <vector>
#include <sstream>

#include "Puzzle11.hpp"
#include "Monkey.hpp"

using namespace std; 

// Useful functions 


// Constructors 

Puzzle11::Puzzle11() { 
    input = ""; 
    Monkey* uniqueMonkey = new Monkey(); 
    monkeys = {uniqueMonkey}; 
    items = {1}; 
    monkeyIndex = {0}; 
    inspectionCounters = {0}; 
} 

Puzzle11::Puzzle11(string newinput) { 
    input = newinput; 
    monkeys = {}; 
    inspectionCounters = {}; 
    items = {}; 
    monkeyIndex = {}; 
    int currMonkey = 0; 
    stringstream inputss(newinput); 
    string line; 
    stringstream monkeyInput; 
    bool endMonkeyInput = false; 
    while (inputss) { 
        while (!endMonkeyInput) { 
            getline(inputss, line); 
            monkeyInput << line; 
            if (line == "\n") { 
                endMonkeyInput = true; 
            }
        }
        Monkey* monkeyptr = new Monkey(monkeyInput.str()); 
        monkeys.push_back(monkeyptr); 
        int nbStartItems = monkeyptr->getNbOfStartingItems(); 
        for (int i = 0; i < nbStartItems; i++) { 
            items.push_back(monkeyptr->getStartingItem(i)); 
            monkeyIndex.push_back(currMonkey); 
        }
        inspectionCounters.push_back(0); 
        currMonkey++; 
        endMonkeyInput = false; 
    }

}

Puzzle11::~Puzzle11() { 
    for (Monkey* monkey: monkeys) { 
        delete monkey; 
    }
}

// Getters 
string Puzzle11::getSolution(int puzzlepart) { 
    for (int roundNb = 0; roundNb < 20; roundNb++ ) { 
        round(); 
    }
    return "0"; 
};

// Others 

void Puzzle11::round() { 
    int n = monkeys.size(); 
    int nItems = items.size(); 
    int worry = 0; 

    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < nItems; j++) { 
            if (monkeyIndex[j] == i) { 
                worry = monkeys[i]->getNewWorry(items[j]); 
                // Divide worry by 3 and approximate to closer integer 
                if (worry % 3 == 2) { 
                    worry = worry / 3 + 1; 
                } else { 
                    worry = worry / 3; 
                }
                monkeyIndex[j] = monkeys[i]->getNextMonkey(worry);
            }
        }
    }
}