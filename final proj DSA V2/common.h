/*-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= 
//* Author: Lucas Germinari Carreira
//* Date last updated: 04/28/2024
//* Description (utility file): Defines the common functions used in the project, such as input validation. 
//* Tested: yes, passed 
//* Notes:
-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*/
#ifndef COMMON_H
#define COMMON_H


#include <iostream>
#include <string>
#include <numeric>
#include <limits>
#include "myMap_v2.h"


enum MusicGenre { Rock, Pop, HipHop, RnB, Country, Jazz, Blues, Classical, Metal, Punk, Reggae, Folk, Techno, House, Trance, Dubstep, Latin, Salsa, Samba, Kpop, Jpop, Indie, Alternative, Grunge, Soul, Funk, Gospel, Broadway, Soundtrack, World };
    
MapV2<MusicGenre, std::string> genreToString = {
      {MusicGenre::Rock, "Rock"},
      {MusicGenre::Pop, "Pop"},
      {MusicGenre::HipHop, "Hip Hop"},
      {MusicGenre::RnB, "R&B"},
      {MusicGenre::Country, "Country"},
      {MusicGenre::Jazz, "Jazz"},
      {MusicGenre::Blues, "Blues"},
      {MusicGenre::Classical, "Classical"},
      {MusicGenre::Metal, "Metal"},
      {MusicGenre::Punk, "Punk"},
      {MusicGenre::Reggae, "Reggae"},
      {MusicGenre::Folk, "Folk"},
      {MusicGenre::Techno, "Techno"},
      {MusicGenre::House, "House"},
      {MusicGenre::Trance, "Trance"},
      {MusicGenre::Dubstep, "Dubstep"},
      {MusicGenre::Latin, "Latin"},
      {MusicGenre::Salsa, "Salsa"},
      {MusicGenre::Samba, "Samba"},
      {MusicGenre::Kpop, "K-pop"},
      {MusicGenre::Jpop, "J-pop"},
      {MusicGenre::Indie, "Indie"},
      {MusicGenre::Alternative, "Alternative"},
      {MusicGenre::Grunge, "Grunge"},
      {MusicGenre::Soul, "Soul"},
      {MusicGenre::Funk, "Funk"},
      {MusicGenre::Gospel, "Gospel"},
      {MusicGenre::Broadway, "Broadway"},
      {MusicGenre::Soundtrack, "Soundtrack"},
      {MusicGenre::World, "World"}
    };

MapV2<std::string, MusicGenre> stringToGenre = {
      {"Rock", MusicGenre::Rock},
      {"Pop", MusicGenre::Pop},
      {"Hip Hop", MusicGenre::HipHop},
      {"R&B", MusicGenre::RnB},
      {"Country", MusicGenre::Country},
      {"Jazz", MusicGenre::Jazz},
      {"Blues", MusicGenre::Blues},
      {"Classical", MusicGenre::Classical},
      {"Metal", MusicGenre::Metal},
      {"Punk", MusicGenre::Punk},
      {"Reggae", MusicGenre::Reggae},
      {"Folk", MusicGenre::Folk},
      {"Techno", MusicGenre::Techno},
      {"House", MusicGenre::House},
      {"Trance", MusicGenre::Trance},
      {"Dubstep", MusicGenre::Dubstep},
      {"Latin", MusicGenre::Latin},
      {"Salsa", MusicGenre::Salsa},
      {"Samba", MusicGenre::Samba},
      {"K-pop", MusicGenre::Kpop},
      {"J-pop", MusicGenre::Jpop},
      {"Indie", MusicGenre::Indie},
      {"Alternative", MusicGenre::Alternative},
      {"Grunge", MusicGenre::Grunge},
      {"Soul", MusicGenre::Soul},
      {"Funk", MusicGenre::Funk},
      {"Gospel", MusicGenre::Gospel},
      {"Broadway", MusicGenre::Broadway},
      {"Soundtrack", MusicGenre::Soundtrack},
      {"World", MusicGenre::World}
    };

const std::string musicGenre = "Rock, Pop, HipHop, RnB, Country, Jazz, Blues, Classical, Metal, Punk, Reggae, Folk, Techno, House, Trance, Dubstep, Latin, Salsa, Samba, Kpop, Jpop, Indie, Alternative, Grunge, Soul, Funk, Gospel, Broadway, Soundtrack, World";

void reset_input_stream();

bool check_string_input(std::string);

bool check_numeric_input(int min, int max,int input, std::string msg_1, std::string msg_2, bool, bool);

#endif