/*-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= 
//* Author: Lucas Germinari Carreira
//* Date last updated: 04/28/2024
//* Description (class definition): Defines the class MusicArtifact, which represents a generic music artifact and works as base class for other classes (such as
//*                                 Vinyl, CD, etc).
//* Tested: no, 
//* Notes:
-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*/

#pragma once

#include <iostream>
#include <string>
#include "date.h"
#include <climits>
//#include "date.cpp"
#include "myMap.h"

class MusicArtifactV2 {

  protected:
    std::string sTitle;
    std::string sArtist;
    date dtRelease;  
    std::string sGenre;
    double dDuration;
    double dPrice;
    int iConservation;

  public:
    MusicArtifactV2(double price, std::string genre, double duration,  
                  std::string title, std::string artist, date releaseDate, int conservation);
    MusicArtifactV2();
    
    double getPrice();
    void setPrice(double price);
    
    std::string getGenre();
    void setGenre(std::string genre);
    
    double getDuration();
    void setDuration(double duration);
    
    std::string getTitle() const;
    void setTitle(std::string title);

    std::string getArtist();
    void setArtist(std::string artist);
    
    date getReleaseDate();
    void setReleaseDate(date releaseDate);
    
    void setConservation(int conservation);
    int getConservation();

    enum MusicGenre { Rock, Pop, HipHop, RnB, Country, Jazz, Blues, Classical, Metal, Punk, Reggae, Folk, Techno, House, Trance, Dubstep, Latin, Salsa, Samba, Kpop, Jpop, Indie, Alternative, Grunge, Soul, Funk, Gospel, Broadway, Soundtrack, World };
    
    MapV1<MusicGenre, std::string> genreToString;
    MapV1<std::string, MusicGenre> stringToGenre;

    
    /* IF USED LATER, THOSE MUST BE VIRTUAL 
    bool operator==(const MusicArtifact& rhs);
    friend std::ostream& operator<<(std::ostream& os, const MusicArtifact& ma);
    friend std::istream& operator>>(std::istream& is, MusicArtifact& ma);
    */
};

