#include <vector>
#include <string>
#include <sstream>

#include "Monkey.hpp"

using namespace std; 

// function for converting string to integer
int stringToInteger(string str) {
    int dec = 0;
    for (long long unsigned int i = 0; i < str.length(); i++) {
 
        // Since ASCII value of character from '0'
        // to '9' are contiguous. So if we subtract
        // '0' from ASCII value of a digit, we get
        // the integer value of the digit.
        if (str[i] != ' ') { 
            int digit = str[i] - '0';
            dec = dec * 10 + digit;
        }
    }
    return dec;
}

Monkey::Monkey() { 
    startingItems = {}; 
    operation = "old * old"; 
    divisionTest = 1; 
    monkeyFalse = 0; 
    monkeyTrue = 1;
}

Monkey::Monkey(string stringInput) { 
    stringstream inputss(stringInput); 
    string line; 
    getline(inputss, line); 

    // Get the starting items 
    getline(inputss, line); 
    string items = line.substr(18); 
    stringstream itemsss(items); 
    startingItems = {}; 
    string item; 
    getline(itemsss, item, ','); 
    while (itemsss && item != "") { 
        startingItems.push_back(stringToInteger(item)); 
        getline(itemsss, item, ','); 
    }

    // Get operation 
    getline(inputss, line); 
    operation = line.substr(13); 

    // Get test 
    getline(inputss, line); 
    string test = line.substr(21); 
    divisionTest = stringToInteger(test); 

    // Get test result true 
    getline(inputss, line); 
    string monkeyToThrow = line.substr(29); 
    monkeyTrue = stringToInteger(monkeyToThrow); 
    getline(inputss, line); 
    monkeyToThrow = line.substr(30); 
    monkeyFalse = stringToInteger(monkeyToThrow); 
}

// Getters 
long long unsigned int Monkey::getNbOfStartingItems() { 
    return startingItems.size(); 
}

long long unsigned int Monkey::getStartingItem(long long unsigned int i) { 
    return startingItems[i]; 
}

long long unsigned int Monkey::getDivisorTest() { 
    return divisionTest; 
}

// Setters 

// Others 
long long unsigned int Monkey::getNewWorry(long long unsigned int worry) { 
    char op = operation[10]; 
    string term = operation.substr(12); 
    long long unsigned int term2; 
    if (term == "old") { 
        term2 = worry; 
    } else { // term != "old", term is a number 
        term2 = stringToInteger(term); 
    }

    if (op == '*') {
        return worry * term2; 
    } else { // op == '+' 
        return worry + term2; 
    }
}

bool Monkey::testWorry(long long unsigned int worry) { 
    return (worry % divisionTest == 0); 
}

long long unsigned int Monkey::getNextMonkey(long long unsigned int worry) { 
    if (testWorry(worry)) { 
        return monkeyTrue; 
    } else { 
        return monkeyFalse; 
    }
}