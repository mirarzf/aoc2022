#include <vector>

#include "FolderPath.hpp"
#include "Directory.hpp"

using namespace std; 

// Constructors 
FolderPath::FolderPath() { 
    Directory* firstDir = new Directory(); 
    path = {firstDir}; 
}

// // Destructor 
// FolderPath::~FolderPath() { 
//     for (Directory* dir : path) { 
//         delete dir; 
//     }
//     path.clear(); 
// }

// Getters 
vector<Directory*> FolderPath::getPath() { 
    return path; 
}

Directory* FolderPath::getCurrentDir() { 
    return path.back(); 
}

string FolderPath::getCurrentDirName() { 
    return getCurrentDir()->getName(); 
}

// Setters 
void FolderPath::backToParentDir() { 
    path.pop_back(); 
}

void FolderPath::goToChildDir(Directory* child) { 
    path.push_back(child); 
}

void FolderPath::addChildDir(Directory* child) { 
    path.back()->addChildDir(child); 
}

void FolderPath::addFile(File file) { 
    path.back()->addFile(file); 
}