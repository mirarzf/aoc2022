#include <string>

#include "Puzzle07.hpp"
#include "FolderPath.hpp"

using namespace std; 

// Useful functions 

// function for converting string to integer
long long unsigned int stringToInteger(string str) {
    long long unsigned int dec = 0;
    for (long long unsigned int i = 0; i < str.length(); i++) {
 
        // Since ASCII value of character from '0'
        // to '9' are contiguous. So if we subtract
        // '0' from ASCII value of a digit, we get
        // the integer value of the digit.
        dec = dec * 10 + (str[i] - '0');
    }
    return dec;
}


// Constructors 

Puzzle07::Puzzle07() : input("") {}; 

Puzzle07::Puzzle07(string newinput) { 
    input = newinput; 
}

// Getters 
string Puzzle07::getSolution(int puzzlepart) { 
    long long unsigned int sizesum = 0; 
    FolderPath currPath = FolderPath(); 
    vector<Directory*> allDir; 
    allDir.push_back(currPath.getCurrentDir()); 
    
    stringstream inputss(input); 
    string terLine; 
    getline(inputss, terLine); 

    while(inputss.good()) { 
        getline(inputss, terLine); 
        if (terLine[0] == '$' && terLine[2] == 'c') { 
            stringstream cmd(terLine); 
            string cmdline; 
            getline(cmd, cmdline, ' '); // cmdline = "$"
            getline(cmd, cmdline, ' '); // cmdline = "cd" 
            string dir; 
            getline(cmd, dir, ' '); 
            if (dir == "..") { 
                if (puzzlepart == 1) {
                    long long unsigned int size = currPath.getCurrentDir()->getSize(); 
                    if (size < 100000) { 
                        sizesum += size; 
                    }
                }
                currPath.backToParentDir(); 
            } else { 
                vector<Directory*> children = currPath.getCurrentDir()->getChildrenDir(); 
                long long unsigned int n = children.size(); 
                long long unsigned int i = 0; 
                while (i < n && children[i]->getName() != dir) { 
                    i++; 
                }
                currPath.goToChildDir(children[i]); 
            }
        } else if (terLine[0] != '$') { // reading a line of a ls command output 
            stringstream lsoutss(terLine); 
            string lsout; 
            getline(lsoutss, lsout, ' '); 
            string name; 
            getline(lsoutss, name, ' '); 
            if (lsout == "dir") { // add a child to current dir 
                Directory* child = new Directory(name); 
                currPath.addChildDir(child); 
                allDir.push_back(child); 
            } else { // add a file to current dir 
                File f = File(name, stringToInteger(lsout)); 
                currPath.addFile(f); 
            }
        }
    }

    if (puzzlepart == 2) { 
        long long unsigned int outerSize = allDir[0]->getSize(); 
        long long unsigned int minimumSpace = outerSize - 40000000; 
        long long unsigned int minimalDirSpace = outerSize; 
        for (Directory* dir : allDir) { 
            long long unsigned int dirsize = dir->getSize(); 
            if (dirsize < minimalDirSpace && dirsize > minimumSpace) { 
                minimalDirSpace = dirsize; 
                delete dir; 
            }
        }
        return to_string(minimalDirSpace); 
    }

    return to_string(sizesum);  
};