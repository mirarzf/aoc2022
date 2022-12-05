#ifndef DEF_STACK
#define DEF_STACK 

#include <string> 
#include <vector>

class Stack { 
    private: 
    std::vector<char> content;  

    public: 
    // Constructors 
    Stack(); 
    Stack(std::vector<char> invertedcontent); 

    // Getters 
    std::vector<char> getContent(); 

    // Setters 
    void setContent(std::vector<char> newcontent); 
}; 

#endif 