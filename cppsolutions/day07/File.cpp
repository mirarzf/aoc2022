#include <string>

#include "File.hpp"

using namespace std; 

// Constructors  

File::File() : filename(""), size(0) {}; 

File::File(string newfilename, long long unsigned int newsize) { 
    filename = newfilename; 
    size = newsize; 
}

// Getters 

string File::getFilename() { 
    return filename; 
}

long long unsigned int File::getSize() { 
    return size; 
}