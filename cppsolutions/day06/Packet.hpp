#ifndef DEF_PACKET
#define DEF_PACKET 

#include<string>

class Packet {
    private: 
    std::string stream; 
    int lenmarker; 

    public: 
    // Constructors 
    Packet(); 
    Packet(std::string newstream, int newlenmarker); 

    // Getters 
    std::string getPossibleMarker(int beginIndex); 
    int getLastIndexFirstMarker(); 

    // Other methods 
    bool isAllDifferent(std::string packet); 
}; 

#endif