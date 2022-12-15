#ifndef DEF_MONKEY
#define DEF_MONKEY 

#include <vector>
#include <string>

class Monkey { 
    private: 
    std::vector<int> startingItems; 
    std::string operation; 
    int divisionTest; 
    int monkeyFalse; 
    int monkeyTrue; 
    int inspectionCounter; 

    public: 
    // Constructors 
    Monkey(); 
    Monkey(std::string stringInput); 

    // Getters 
    int getNbOfStartingItems(); 
    int getStartingItem(int i); 
    int getNbOfInspections(); 

    // Setters 
    void updateIC(); 

    // Others 
    int getNewWorry(int worry); 
    int testWorry(int worry); 
    int getNextMonkey(int worry); 

}; 

#endif 