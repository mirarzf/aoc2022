#ifndef DEF_PUZZLE10
#define DEF_PUZZLE10

class Puzzle10 { 
    private: 
    std::string input; 

    public: 

    // Constructors 
    Puzzle10(); 
    Puzzle10(std::string newinput); 

    // Getters 
    // virtual int getSolution(int puzzlepart) const; 
    std::string getSolution(int puzzlepart); 
}; 

#endif 