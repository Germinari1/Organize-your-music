/*-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= 
//* Author: Lucas Germinari Carreira
//* Date last updated: 04/28/2024
//* Description (class implementation): Implements the class Vinyl, which is a subclass of MusicArtifact.
//* Tested: no, 
//* Notes:
-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*/
#include "vinyl.h"
#include "musicArtifact.cpp"
#include "date.h"
#include <iostream>
#include <string>
#include "common.h"
#include "common.cpp"
#include <numeric>

// Constructor
Vinyl::Vinyl(std::string title, std::string artist, date releaseDate,
             std::string genre, double price, double duration, int conservation,
             double diameter, int rpm)
             : MusicArtifact(price, genre, duration, title, artist, releaseDate, conservation) {

  dDiameter = diameter;
  iRpm = rpm;
}
Vinyl::Vinyl() : MusicArtifact()
{
  iRpm = 0;
  dDiameter = 0.0;
}

// Getters
double Vinyl::getDiameter() {
  return dDiameter;
}

int Vinyl::getRPM() {
  return iRpm;
}

// Setters
void Vinyl::setDiameter(double diameter) {
  if(check_numeric_input(0,INT_MAX, diameter, "", "", false, true)){
    dDiameter = diameter;
  }
}

void Vinyl::setRPM(int rpm) {
  if(check_numeric_input(0,5, rpm, "", "", false, true)){
    iRpm = rpm;
  }
}

// Equality operator
bool Vinyl::operator==(const Vinyl& rhs) {
  bool membersEqual = true;

  membersEqual &= (this->sTitle == rhs.sTitle);
  membersEqual &= (this->sArtist == rhs.sArtist);
  membersEqual &= (this->dtRelease == rhs.dtRelease);
  membersEqual &= (this->sGenre == rhs.sGenre);
  membersEqual &= (this->dDuration == rhs.dDuration);
  membersEqual &= (this->dPrice == rhs.dPrice);
  membersEqual &= (this->iConservation == rhs.iConservation);

  membersEqual &= (this->dDiameter == rhs.dDiameter);
  membersEqual &= (this->iRpm == rhs.iRpm);

  return membersEqual;

}
//output operator
std::ostream& operator<<(std::ostream& os, const Vinyl& v) {

  date temp = date(v.dtRelease);

  os << "Title: " << v.sTitle<<std::endl;
  os << "Artist: " << v.sArtist<<std::endl;
  os << "Release Date: " << temp<<std::endl;

  os << "Genre: " << v.sGenre<<std::endl;
  os << "Duration: " << v.dDuration << " mins"<<std::endl;

  os << "Price: " << v.dPrice<<std::endl;
  os << "Conservation: " << v.iConservation<<std::endl;

  os << "Diameter: " << v.dDiameter << " inches"<<std::endl;
  os << "RPM: " << v.iRpm<<std::endl;

  return os;
}

// Stream insertion operator
std::istream& operator>>(std::istream& is, Vinyl& v) {
  std::cout << "Enter title: ";
  is >> v.sTitle;

  std::cout << "Enter artist: ";
  is >> v.sArtist;

  std::cout << "Enter release date (mm-d-yy): ";
  is >> v.dtRelease;

  is.ignore();
  std::string tempGenre;
  MusicGenre genre;
  std::cout<< "Available genres: "<<musicGenre << std::endl;
  std::cout << "Enter genre: ";
  std::getline(is, tempGenre);
  if(musicGenre.find(tempGenre) != std::string::npos){
    genre = stringToGenre[tempGenre];

    v.sGenre = genreToString[genre];
  }
  else{
    v.sGenre = "Unknown";
  }

  std::cout << "Enter duration: ";
  do{
  is >> v.dDuration;
  }while(!check_numeric_input(0, INT_MAX,v.dDuration, "", "", false, true ));

  std::cout << "Enter state of conservation (0 to 5): ";
  do{
  is >> v.iConservation;
  }while(!check_numeric_input(0, 5, v.iConservation, "", ""));

  std::cout << "Enter price: ";
  do{
  is >> v.dPrice;
  }while(!check_numeric_input(0,INT_MAX, v.dPrice, "", "", false, true));

  std::cout << "Enter diameter: ";
  do{
    is >> v.dDiameter;
  }while(!check_numeric_input(0,INT_MAX, v.dDiameter, "", "", false, true));

  std::cout << "Enter RPM: ";
  do{
  is >> v.iRpm;
  }while(!check_numeric_input(0,INT_MAX, v.iRpm, "", "", false, true));

  return is;
}