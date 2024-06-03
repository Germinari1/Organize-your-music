/*-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= 
//* Author: Lucas Germinari Carreira
//* Date last updated: 04/28/2024
//* Description (class Implementation): Implements the class MusicArtifact 
//* Tested: no, 
//* Notes:
-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*/
#pragma once

//HEADER FILES
//#include "musicArtifact.h"
#include <iostream>
#include <string>
#include "common.h"
#include "date.h"
#include <climits>
//#include "date.cpp"
#include "myMap.h"

class MusicArtifact {

  protected:
    std::string sTitle;
    std::string sArtist;
    date dtRelease;  
    std::string sGenre;
    double dDuration;
    double dPrice;
    int iConservation;

  public:
    MusicArtifact(double price, std::string genre, double duration,  
                  std::string title, std::string artist, date releaseDate, int conservation) {
        dPrice = price;
        sGenre = genre;
        dDuration = duration;
        sTitle = title;
        sArtist = artist;
        dtRelease = releaseDate;
        iConservation = conservation;
    }

    MusicArtifact() {}
    
    double getPrice() { return dPrice; }
    void setPrice(double price) { dPrice = price; }
    
    std::string getGenre() { return sGenre; }
    void setGenre(std::string genre) { sGenre = genre; }
    
    double getDuration() { return dDuration; }
    void setDuration(double duration) { dDuration = duration; }
    
    std::string getTitle() const { return sTitle; }
    void setTitle(std::string title) { sTitle = title; }

    std::string getArtist() { return sArtist; }
    void setArtist(std::string artist) { sArtist = artist; }
    
    date getReleaseDate() { return dtRelease; }
    void setReleaseDate(date releaseDate) { dtRelease = releaseDate; }
    
    void setConservation(int conservation) { iConservation = conservation; }
    int getConservation() { return iConservation; }

    

    /* IF IF USED LATER, THOSE MUST BE VIRTUAL 
    bool operator==(const MusicArtifact& rhs);
    friend std::ostream& operator<<(std::ostream& os, const MusicArtifact& ma);
    friend std::istream& operator>>(std::istream& is, MusicArtifact& ma);
    */
};
