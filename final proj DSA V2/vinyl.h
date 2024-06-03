/*-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= 
//* Author: Lucas Germinari Carreira
//* Date last updated: 04/28/2024
//* Description (class definition): Defines the class Vinyl, which is a subclass of MusicArtifact and represents a vinyl disk.
//* Tested: no, 
//* Notes:
-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*/

#ifndef VINYL_H
#define VINYL_H

#include <iostream>
#include <string>
#include "musicArtifact.h"
#include "date.h"

class Vinyl : public MusicArtifact {

  private:
    double dDiameter;  
    int iRpm;

  public:
    
    Vinyl(std::string title, std::string artist, date releaseDate,  
          std::string genre, double price, double duration, int conservation,  
          double diameter, int rpm);
    Vinyl();
    
    double getDiameter();
    void setDiameter(double diameter);

    int getRPM(); 
    void setRPM(int rpm);

    bool operator==(const Vinyl& rhs);  

    friend std::istream& operator>>(std::istream& is, Vinyl& v);
    friend std::ostream& operator<<(std::ostream& os, const Vinyl& v);
};

#endif