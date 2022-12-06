#include <string>
#include <sstream>
#include <map>

using namespace std; 

#include "Packet.hpp"

// Constructors 
Packet::Packet() : stream(""), lenmarker(4) {}; 

Packet::Packet(string newstream, int newlenmarker) { 
    stream = newstream; 
    lenmarker = newlenmarker; 
}

// Getters 
string Packet::getPossibleMarker(int beginIndex) { 
    string retstring = ""; 
    for (int i = 0; i < lenmarker; i++) { 
        retstring += stream[beginIndex+i]; 
    }
    return retstring; 
}

int Packet::getLastIndexFirstMarker() { 
    string packet; 
    int n = stream.size(); 
    for (int i = 0; i < n-lenmarker; i++) { 
        packet = getPossibleMarker(i); 
        if (isAllDifferent(packet)) { 
            return i+lenmarker-1; 
        }
    }
    return n-1; 
}

// Other methods 

bool Packet::isAllDifferent(string packet) { 
    map<char, int> packetChar = {}; 
    for (int i = 0; i < lenmarker; i++) { 
        if (packetChar.count(packet[i]) == 0) { 
            packetChar.insert({packet[i], 1}); 
        } else { 
            return false; 
        }
    }
    return true; 
}

