#ifndef DEF_FOLDERPATH
#define DEF_FOLDERPATH

#include <string>
#include <vector>

#include "Directory.hpp"

class FolderPath { 
    private: 
    std::vector<Directory*> path; 

    public: 

    // Constructors 
    FolderPath(); 

    // // Destructor 
    // ~FolderPath(); 

    // Getters 
    std::vector<Directory*> getPath(); 
    Directory* getCurrentDir(); 
    std::string getCurrentDirName(); 

    // Setters 
    void backToParentDir(); 
    void goToChildDir(Directory* child); 
    void addChildDir(Directory* child); 
    void addFile(File file); 
}; 

#endif 