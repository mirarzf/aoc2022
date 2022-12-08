#ifndef DEF_PUZZLE07
#define DEF_PUZZLE07


class Puzzle07 { 
    private: 
    std::string input; 

    public: 

    // Constructors 
    Puzzle07(); 
    Puzzle07(std::string newinput); 

    // Getters 
    // virtual int getSolution(int puzzlepart) const; 
    std::string getSolution(int puzzlepart); 
}; 

#endif 