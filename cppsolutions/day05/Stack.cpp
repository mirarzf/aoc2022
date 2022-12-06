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

vector<char> Stack::getLast(int len) { 
    vector<char> ret; 
    int n = content.size(); 
    for (int i = 0; i < len; i++) { 
        ret.push_back(content[n-1-i]); 
    }
    return ret;
}

char Stack::getLastChar() { 
    return content.back(); 
}

// Setters 
void Stack::setContent(vector<char> newcontent) { 
    content = newcontent; 
}

void Stack::moveOut(int len) { 
    for (int i = 0; i < len; i++) { 
        content.pop_back(); 
    }
}

vector<char> Stack::getOut(int len) {
    vector<char> ret; 
    for (int i = 0; i < len; i++) { 
        ret.push_back(content.back()); 
        content.pop_back(); 
    }
    return ret; 
}