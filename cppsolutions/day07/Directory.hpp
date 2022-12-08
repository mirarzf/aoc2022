#ifndef DEF_DIRECTORY
#define DEF_DIRECTORY

#include <sstream>
#include <string>
#include <vector>

#include "File.hpp"

class Directory { 
    private: 
    std::string dirname; 
    std::vector<File> allFiles; 
    std::vector<Directory*> childrenDir; 

    public: 

    // Constructors 
    Directory();  
    Directory(std::string newname);  

    // Destructor 
    ~Directory(); 

    // Getters 
    std::string getName(); 
    std::vector<File> getAllFiles(); 
    std::vector<Directory*> getChildrenDir(); 
    long long unsigned int getFoldersSize(); 
    long long unsigned int getSize(); 

    // Setters 
    void addChildDir(Directory* child); 
    void addFile(File file); 
}; 

#endif 