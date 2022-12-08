#ifndef DEF_FILE
#define DEF_FILE

#include <string>

class File {
    private: 
    std::string filename; 
    long long unsigned int size; 

    public: 
    // Constructors 
    File(); 
    File(std::string newfilename, long long unsigned int newsize); 

    // Getters 
    std::string getFilename(); 
    long long unsigned int getSize(); 
}; 

#endif 