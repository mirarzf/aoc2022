#include <sstream>
#include <string>
#include <vector>

#include "Directory.hpp"
#include "File.hpp"

using namespace std; 

// Constructors 

Directory::Directory() { 
    dirname = "/"; 
    allFiles = {}; 
    childrenDir = {}; 
} 

Directory::Directory(string newname) { 
    dirname = newname; 
    allFiles = {}; 
    childrenDir = {}; 
}

// Destructor 
Directory::~Directory() { 
    for (Directory* dir: childrenDir) { 
        delete dir; 
    }
}

// Getters 

string Directory::getName() { 
    return dirname; 
}

vector<File> Directory::getAllFiles() { 
    return allFiles; 
}

vector<Directory*> Directory::getChildrenDir() { 
    return childrenDir; 
}

long long unsigned int Directory::getFoldersSize() { 
    long long unsigned int size = 0; 
    for (Directory* dir : childrenDir) { 
        size += dir->getSize(); 
    }
    return size; 
}

long long unsigned int Directory::getSize() { 
    long long unsigned int size = 0; 
    size += getFoldersSize(); 
    for (File f : allFiles) {
        size += f.getSize(); 
    }
    return size; 
}

// Setters 

void Directory::addChildDir(Directory* child) { 
    childrenDir.push_back(child); 
}

void Directory::addFile(File file) {
    allFiles.push_back(file); 
}