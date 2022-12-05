#include <vector>
#include <string>

#include "Stack.hpp"

using namespace std; 

// Constructors 
Stack::Stack() : content({}) {}; 

Stack::Stack(vector<char> invertedcontent) {
    int n = invertedcontent.size(); 
    for (int i = 0; i < n; i++) { 
        content.push_back(invertedcontent.back()); 
        invertedcontent.pop_back(); 
    }
}

// Getters 
vector<char> Stack::getContent() { 
    return content; 
}

// Setters 
void Stack::setContent(vector<char> newcontent) { 
    content = newcontent; 
}