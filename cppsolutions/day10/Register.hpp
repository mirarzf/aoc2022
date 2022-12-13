#ifndef DEF_REGISTER 
#define DEF_REGISTER

#include <string>
#include <vector> 

class Register {
    private: 
    int value; 
    int clock; 

    public: 
    // Constructors 
    Register(); 

    // Getters 
    int getClock(); 
    int getValue(); 

    // Setters 
    void addX(int addxvalue); 
    void noop(); 

    // Others 
    long long int getSumSignalStrengthAt(std::string input, std::vector<int> cycleTimes);
    std::string getCRToutput(std::string input);  
}; 

#endif 