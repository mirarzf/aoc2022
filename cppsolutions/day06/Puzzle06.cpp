#include <iostream>
#include <fstream> 
#include <sstream>
#include <string>

#include "Puzzle06.hpp"
#include "Packet.hpp"

using namespace std; 

// Constructors 

Puzzle06::Puzzle06() : input("") {}; 

Puzzle06::Puzzle06(string newinput) {
    input = newinput; 
} 

// Getters 

// int Puzzle06::getSolution(int puzzlepart) const {
// }; 

string Puzzle06::getSolution(int puzzlepart) {
    if (puzzlepart == 1) { 
        Packet packetstream = Packet(input, 4); 
        int i = packetstream.getLastIndexFirstMarker(); 
        return to_string(i+1); 
    } else { // puzzlepart == 2 
        Packet packetstream = Packet(input, 14); 
        int i = packetstream.getLastIndexFirstMarker(); 
        return to_string(i+1); 
    }
}