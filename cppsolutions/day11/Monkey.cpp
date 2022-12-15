#include <vector>
#include <string>
#include <sstream>

#include "Monkey.hpp"

using namespace std; 

Monkey::Monkey() { 
    startingItems = {}; 
    operation = "old * old"; 
    divisionTest = 1; 
    monkeyFalse = 0; 
    monkeyTrue = 1; 
    inspectionCounter = 0; 
}

Monkey::Monkey(string stringInput) { 
    stringstream inputss(stringInput); 
    string line; 

    // Get the starting items 
    getline(inputss, line); 
    string items = line.substr(18); 
    stringstream itemsss(items); 
    startingItems = {}; 
    while (itemsss) { 
        string item; 
        getline(itemsss, item, ','); 
        startingItems.push_back(stoi(item)); 
    }

    // Get operation 
    getline(inputss, line); 
    operation = line.substr(13); 

    // Get test 
    getline(inputss, line); 
    string test = line.substr(21); 
    divisionTest = stoi(test); 

    // Get test result true 
    getline(inputss, line); 
    string monkeyToThrow = line.substr(29); 
    monkeyTrue = stoi(monkeyToThrow); 
    getline(inputss, line); 
    monkeyToThrow = line.substr(30); 
    monkeyFalse = stoi(monkeyToThrow); 

    // Initialize inspectionCounter 
    inspectionCounter = 0; 
}

// Getters 
int Monkey::getNbOfStartingItems() { 
    return startingItems.size(); 
}

int Monkey::getStartingItem(int i) { 
    return startingItems[i]; 
}

int Monkey::getNbOfInspections() { 
    return inspectionCounter; 
}

// Setters 
void Monkey::updateIC() { 
    inspectionCounter++; 
}

// Others 
int Monkey::getNewWorry(int worry) { 
    char op = operation[10]; 
    string term = operation.substr(12); 
    int term2; 
    if (term == "old") { 
        term2 = worry; 
    } else { // term != "old", term is a number 
        term2 = stoi(term); 
    }

    if (op == '*') {
        return worry * term2; 
    } else { // op == '+' 
        return worry + term2; 
    }
}

int Monkey::testWorry(int worry) { 
    return (worry % divisionTest == 0); 
}

int Monkey::getNextMonkey(int worry) { 
    if (testWorry(worry)) { 
        return monkeyTrue; 
    } else { 
        return monkeyFalse; 
    }
}