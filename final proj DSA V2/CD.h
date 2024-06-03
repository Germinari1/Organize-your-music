/*-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= 
//* Author: Lucas Germinari Carreira
//* Date last updated: 04/28/2024
//* Description (class definition): Defines the class CD, which is a subclass of MusicArtifact and represents a CD.
//* Tested: no, 
//* Notes:
-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*/

#ifndef CD_H
#define CD_H

#include "musicArtifact.h"
#include "date.h"
#include <iostream>
#include <string>

class CD : public MusicArtifact {

private:
  std::string sDiscFormat;

public:

  // Constructor
  CD(std::string title, std::string artist, date releaseDate,
      std::string genre, double price, double duration, int conservation,
      std::string discFormat);

  // Default constructor
  CD();

  // Getters
  std::string getDiscFormat();

  // Setters
  void setDiscFormat(std::string discFormat);

  // Overloaded operators
  bool operator==(const CD& rhs);
  friend std::istream& operator>>(std::istream& is, CD& cd);
  friend std::ostream& operator<<(std::ostream& os, const CD& v);
};

#endif