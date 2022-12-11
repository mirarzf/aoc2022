#ifndef DEF_PUZZLE09
#define DEF_PUZZLE09

class Puzzle09 { 
    private: 
    std::string input; 

    public: 

    // Constructors 
    Puzzle09(); 
    Puzzle09(std::string newinput); 

    // Getters 
    // virtual int getSolution(int puzzlepart) const; 
    std::string getSolution(int puzzlepart); 
}; 

#endif 