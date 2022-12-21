#ifndef DEF_PUZZLE12
#define DEF_PUZZLE12

class Puzzle12 { 
    private: 
    std::string input; 

    public: 

    // Constructors 
    Puzzle12(); 
    Puzzle12(std::string newinput); 

    // Getters
    // virtual int getSolution(int puzzlepart) const; 
    std::string getSolution(int puzzlepart); 


}; 

#endif 