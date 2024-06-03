/*-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= 
//* Author: Lucas Germinari Carreira
//* Date last updated: 04/28/2024
//* Description (class implementation): Implements the class CD, which is a subclass of MusicArtifact and represents a CD.
//* Tested: no, 
//* Notes:
-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*/

#include "CD.h"
#include "musicArtifact.cpp"
#include "date.h"
#include <iostream>
#include <string>
#include "common.h"
//#include "common.cpp"


// Constructor
CD::CD(std::string title, std::string artist, date releaseDate,
       std::string genre, double price, double duration, int conservation,
       std::string discFormat)
       : MusicArtifact(price, genre, duration, title, artist, releaseDate, conservation) {

    sDiscFormat = discFormat;
}

// Default Constructor
CD::CD() : MusicArtifact() {
    sDiscFormat = "Unknown";
}

// Getters
std::string CD::getDiscFormat() {
    return sDiscFormat;
}

// Setters
void CD::setDiscFormat(std::string discFormat) {
    sDiscFormat = discFormat;
}

// Equality operator
bool CD::operator==(const CD& rhs) {

  bool equal = true;

  equal &= sTitle == rhs.sTitle;
  equal &= sArtist == rhs.sArtist;
  equal &= dtRelease == rhs.dtRelease;
  equal &= sGenre == rhs.sGenre;
  equal &= dDuration == rhs.dDuration;
  equal &= dPrice == rhs.dPrice;
  equal &= iConservation == rhs.iConservation;
  equal &= sDiscFormat == rhs.sDiscFormat;

  return equal;
}

// Output operator
std::ostream& operator<<(std::ostream& os, const CD& c) {

    date temp = date(c.dtRelease);

    os << "Title: " << c.sTitle<<std::endl;
    os << "Artist: " << c.sArtist<<std::endl;
    os << "Release Date: " << temp<<std::endl;

    os << "Genre: " << c.sGenre<<std::endl;
    os << "Duration: " << c.dDuration << " mins"<<std::endl;

    os << "Price: " << c.dPrice<<std::endl;
    os << "Conservation: " << c.iConservation<<std::endl;

    os << "Disc Format: " << c.sDiscFormat<<std::endl;

    
    
    return os;
}

std::istream& operator>>(std::istream& is, CD& c) {

  std::cout << "Enter title: ";
  std::getline(is, c.sTitle);

  std::cout << "Enter artist: ";
  std::getline(is, c.sArtist);

  std::cout << "Enter release date (mm-dd-yy): ";
  is >> c.dtRelease;

  is.ignore();
  std::string tempGenre;
  MusicGenre genre;
  std::cout<< "Available genres: "<<musicGenre << std::endl;
  std::cout << "Enter genre: ";
  std::getline(is, tempGenre);
  if(musicGenre.find(tempGenre) != std::string::npos){
    genre = stringToGenre[tempGenre];

    c.sGenre = genreToString[genre];
  }
  else{
    c.sGenre = "Unknown";
  }

  std::cout << "Enter duration: ";
  do{
    is >> c.dDuration;
  }while(!check_numeric_input(0, INT_MAX,c.dDuration, "", "", false, true ));

  std::cout << "Enter state of conservation (0 to 5): ";
  do{
    is >> c.iConservation;
  }while(!check_numeric_input(0, 5, c.iConservation, "", "", false, false));

  std::cout << "Enter price: ";
  do{
    is >> c.dPrice;
  }while(!check_numeric_input(0,INT_MAX, c.dPrice, "", "", false, true));

  is.ignore();
  std::cout << "Enter disc format: ";
  std::getline(is, c.sDiscFormat);


  return is;
}

// Input operator
/*std::istream& operator>>(std::istream& is, CD& c) {

  std::cout << "Enter title: ";
  is >> c.sTitle;

  std::cout << "Enter artist: ";
  is >> c.sArtist;

  std::cout << "Enter release date (mm-d-yy): ";
  is >> c.dtRelease;

  std::cout << "Enter genre: ";
  is >> c.sGenre;

  std::cout << "Enter duration: ";
  do{
  is >> c.dDuration;
  }while(!check_numeric_input(0, MAX_INT,c.dDuration, "", "", false, true ));

  std::cout << "Enter state of conservation (0 to 5): ";
  do{
  is >> c.iConservation;
  }while(!check_numeric_input(0, 5, c.iConservation, "", "", false, false));

  std::cout << "Enter price: ";
  do{
  is >> c.dPrice;
  }while(!check_numeric_input(0,MAX_INT, c.dPrice, "", "", false, true));

 std::cout << "Enter disc format: ";
  is >> c.sDiscFormat;

  return is;
}*/