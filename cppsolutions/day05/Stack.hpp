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
    std::vector<char> getLast(int len); 

    // Setters 
    void setContent(std::vector<char> newcontent); 
    void moveOut(int len); 

    std::vector<char> getOut(int len); 
}; 

#endif 