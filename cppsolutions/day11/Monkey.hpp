#ifndef DEF_MONKEY
#define DEF_MONKEY 

#include <vector>
#include <string>

class Monkey { 
    private: 
    std::vector<long long unsigned int> startingItems; 
    std::string operation; 
    long long unsigned int divisionTest; 
    long long unsigned int monkeyFalse; 
    long long unsigned int monkeyTrue; 

    public: 
    // Constructors 
    Monkey(); 
    Monkey(std::string stringInput); 

    // Getters 
    long long unsigned int getNbOfStartingItems(); 
    long long unsigned int getStartingItem(long long unsigned int i); 
    long long unsigned int getDivisorTest(); 

    // Setters 

    // Others 
    long long unsigned int getNewWorry(long long unsigned int worry); 
    bool testWorry(long long unsigned int worry); 
    long long unsigned int getNextMonkey(long long unsigned int worry); 

}; 

#endif 