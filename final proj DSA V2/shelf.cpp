/*-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= 
//* Author: Lucas Germinari Carreira
//* Date last updated: 04/28/2024
//* Description (class implementation): Implements the class Shelf, which is responsible for storing the CD and Vinyl collections.
//* Tested: no, 
//* Notes:
-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*/

#include "shelf.h"
#include "CD.h"
#include "vinyl.h"
#include "musicArtifact.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <cctype>
#include <sstream>
#include <map>
#include <utility>


//enum used by parsing function
enum CollectionType { CD_COLLECTION, VINYL_COLLECTION };


// Display entire collection
void Shelf::displayCollection(bool cds, bool vinyls) {
  if(cds == true){
    displayCDCollection();
  }

  if(vinyls == true){
    displayVinylCollection();
  }

  //display general information
  std::cout<<"\nCD collection) Size: "<<getCollectionSize('c') <<" || Total CD value: "<<getCDValue()<<std::endl;
  std::cout<<"Vinyl collection) Size: "<<getCollectionSize('v') <<" || Total vinyl value: "<<getVinylValue()<<std::endl;
  std::cout<<"Total collection) Size: "<<getCollectionSize('v') + getCollectionSize('c') <<" || Total value: "<<getTotalValue()<<std::endl;
}

// Display CDs
void Shelf::displayCDCollection() {

  std::cout << "CD Collection: \n";
  for(int i=0; i<cdCollection.get_size(); i++) {
    std::cout <<i+1<<". "<< cdCollection.at(i).getTitle() << "\n";
  }

  //filler if collection is empty
  if(cdCollection.empty()){
    std::cout<<"This collection is empty.\n\n";
  }
}

// Display Vinyls
void Shelf::displayVinylCollection() {

  std::cout << "Vinyl Collection: \n";
  for(int i=0; i<vinylCollection.get_size(); i++) {
    std::cout <<i+1<<". "<< vinylCollection.at(i).getTitle() << "\n";
  }

  //filler is collection is empty
  if(vinylCollection.empty()){
    std::cout<<"This collection is empty.\n\n";
  }
}

CD* Shelf::getCDItem(int elementId){
  //check vector boundaries
  if(!(elementId>cdCollection.get_size() || elementId<0)){
    return &cdCollection.at(elementId);
  }
  else{
    return nullptr;
  }
}

Vinyl* Shelf::getVinylItem(int elementId){
  //check vector boundaries
  if(!(elementId>vinylCollection.get_size() || elementId<0)){
    return &vinylCollection.at(elementId);
  }
  else{
    return nullptr;
  }
}

//get size of collection
int Shelf::getCollectionSize(char collectionIdentifier){
  if(collectionIdentifier == 'c'){
    return cdCollection.get_size();
  }
  else {
    return vinylCollection.get_size();
  }
}
//export collection a file
void Shelf::exportCollectionToFile(bool cd, bool vinyl)
{
  ////// Export the user's collection to a text file (both, only CDs, or only Vinyls)

  //string to be printed
  std::string cdCollectionHeader =
  "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=\n"
                            "YOUR CD COLLECTION\n"
  "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=";
  std::string vinylCollectionHeader =
  "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=\n"
                            "YOUR VINYL COLLECTION\n"
  "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=";

  //set up file output stream
  std::ofstream outFile("exported_collection.txt");

  //write user's collections to file
  //CD
  if(cd==true){
    outFile << cdCollectionHeader<<std::endl;
    for(int i=0; i<cdCollection.get_size(); i++){
      outFile << i+1 << ")\n" << cdCollection.at(i)<<std::endl;
    }
  }

  //Vinyls
  if(vinyl==true){
    outFile << vinylCollectionHeader <<std::endl;
    for(int i=0; i<vinylCollection.get_size(); i++){
      outFile << i+1 << ")\n" << vinylCollection.at(i)<<std::endl;
    }
  }

  //close file
  outFile.close();
}


date Shelf::stringToDate(const std::string& dateStr) {
    ///// Converts a string representation of a date to a date object
    std::vector<int> parts;
    std::stringstream ss(dateStr);
    std::string token;

    // Split the string by the '-' delimiter
    while (std::getline(ss, token, '-')) {
        parts.push_back(std::stoi(token));
    }

    // Ensure that the string format is correct (YYYY-MM-DD)
    if (parts.size() != 3) {
        // Handle invalid date format
        return date(1, 1, 1970); // Return a default date (e.g., January 1, 1970)
    }

    // Extract year, month, and day from the vector
    int year = parts[0];
    int month = parts[1];
    int day = parts[2];

    // Create and return the date object
    return date(month, day, year);
}


void Shelf::loadCollectionFromFile(const std::vector<std::vector<std::pair<std::string, std::string>>>& data) {
    for (int i = 0; i < data.size(); i++) {
            if (data[i][7].first == "Disc Format") {
                // Get values for CDs
                std::string title = data[i][0].second;
                std::string artist = data[i][1].second;
                date releaseDate = stringToDate(data[i][2].second);
                std::string genre = data[i][3].second;
                double duration = std::stod(data[i][4].second.substr(0, data[i][4].second.find(" ")));
                double price = std::stod(data[i][5].second);
                int conservation = std::stoi(data[i][6].second);
                std::string discFormat = data[i][7].second;

                // Create CD object and append to cdCollection
                CD cd(title, artist, releaseDate, genre, price, duration, conservation, discFormat);
                addCD(cd);
            } else {
                // Get values for Vinyls
                std::string title = data[i][0].second;
                std::string artist = data[i][1].second;
                date releaseDate = stringToDate(data[i][2].second);
                std::string genre = data[i][3].second;
                double duration = std::stod(data[i][4].second.substr(0, data[i][4].second.find(" ")));
                double price = std::stod(data[i][5].second);
                int conservation = std::stoi(data[i][6].second);
                double diameter = std::stod(data[i][7].second.substr(0, data[i][7].second.find(" ")));
                int rpm = std::stoi(data[i][8].second);

                // Create Vinyl object and append to vinylCollection
                Vinyl vinyl(title, artist, releaseDate, genre, price, duration, conservation, diameter, rpm);
                addVinyl(vinyl);
            }
    }
}


//Load collection from file
std::vector<std::vector<std::pair<std::string, std::string>>> Shelf::parseCollectionFile(const std::string& file_path) {
    ////// Parses a file of exported collection data, returning a vector of vectors tha contain the data attributes for CDs and vinyls

    //set up filestream, vectors to received data, and boolen indicators
    std::ifstream file(file_path);
    std::vector<std::vector<std::pair<std::string, std::string>>> data;
    std::vector<std::pair<std::string, std::string>> entry;
    bool is_cd_section = false;
    bool is_vinyl_section = false;

    //open file and parse it
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            if (line.find("YOUR CD COLLECTION") != std::string::npos) {
                is_cd_section = true;
                is_vinyl_section = false;
            } else if (line.find("YOUR VINYL COLLECTION") != std::string::npos) {
                is_cd_section = false;
                is_vinyl_section = true;
            } else if (line.empty()) {
                if (!entry.empty()) {
                    if (is_cd_section || is_vinyl_section) {
                        data.push_back(entry);
                    }
                    entry.clear();
                }
            } else {
                size_t pos = line.find(": ");
                if (pos != std::string::npos) {
                    std::string key = line.substr(0, pos);
                    std::string value = line.substr(pos + 2);
                    if (is_cd_section || is_vinyl_section) {
                        entry.push_back(std::make_pair(key, value));
                    }
                }
            }
        }
        if (!entry.empty()) {
            data.push_back(entry);
        }
        file.close();
    } else {
        std::cerr << "Unable to open file: " << file_path << std::endl;
    }

    //return parsed data
    return data;
}
// Edit CD item
void Shelf::editCD(int iItemIndex, int iActionIndex) {

  CD& cd = cdCollection[iItemIndex];

  std::string input;
  double dInput;
  date d;

  switch (iActionIndex) {

    //cancel
    case 0:
      return;
      break;

    //title
    case 1:
      std::cin.ignore();
      std::cout << "Enter new title: ";
      std::getline(std::cin, input);
      cd.setTitle(input);
      break;

    // Artist
    case 2:
      std::cin.ignore();
      std::cout << "Enter new artist: ";
      std::getline(std::cin, input);
      cd.setArtist(input);
      break;

    // Release Date
    case 3:
      std::cout << "Enter new release date: ";
      //date d;
      std::cin >> d;
      cd.setReleaseDate(d);
      break;

    // Genre
    case 4:
      std::cin.ignore();
      std::cout << "Enter new genre: ";
      std::getline(std::cin, input);
      cd.setGenre(input);
      break;

    // Price
    case 6:
      //double price;
      //dCDValue -= cd.getPrice();
      //dTotalValue -= cd.getPrice();
      std::cout << "Enter new price: ";
      std::cin >> dInput;
      cd.setPrice(dInput);
      //dCDValue += cd.getPrice();
      //dTotalValue += cd.getPrice();
      break;

    // Duration
    case 5:
      //double duration;
      std::cout << "Enter new duration: ";
      std::cin >> dInput;
      cd.setDuration(dInput);
      break;

    // Conservation
    case 7:
      //int conservation;
      std::cout << "Enter conservation (0-5): ";
      std::cin >> dInput;
      cd.setConservation(dInput);
      break;

    // Disc format
    case 8:
      std::cin.ignore();
      std::cout << "Enter new disc format: ";
      std::getline(std::cin, input);
      cd.setDiscFormat(input);
      break;

    // Invalid option
    default:
      std::cout << "Invalid option" << std::endl;
  }
}

void Shelf::editVinyl(int iItemIndex, int iActionIndex) {

  Vinyl& vinyl = vinylCollection[iItemIndex];

  std::string input;
  double dInput;
  date d;

  switch (iActionIndex) {

    // Title
    case 0:
      return;
      break;
    case 1:
      std::cin.ignore();
      std::cout << "Enter new title: ";
      std::getline(std::cin, input);
      vinyl.setTitle(input);
      break;

    // Artist
    case 2:
      std::cin.ignore();
      std::cout << "Enter new artist: ";
      std::getline(std::cin, input);
      vinyl.setArtist(input);
      break;

    // Release Date
    case 3:
      std::cout << "Enter new release date: ";
      std::cin >> d;
      vinyl.setReleaseDate(d);
      break;

    // Genre
    case 4:
      std::cin.ignore();
      std::cout << "Enter new genre: ";
      std::getline(std::cin, input);
      vinyl.setGenre(input);
      break;

    // Price
    case 6:
      //dVinylValue -= vinyl.getPrice();
      //dTotalValue -= vinyl.getPrice();
      std::cout << "Enter new price: ";
      std::cin >> dInput;
      vinyl.setPrice(dInput);
      //dVinylValue += vinyl.getPrice();
      //dTotalValue += vinyl.getPrice();
      break;

    // Duration
    case 5:
      std::cout << "Enter new duration: ";
      std::cin >> dInput;
      vinyl.setDuration(dInput);
      break;

    // Conservation
    case 7:
      std::cout << "Enter new conservation (0-5): ";
      std::cin >> dInput;
      vinyl.setConservation(dInput);
      break;

    // Diameter
    case 8:
      std::cout << "Enter new diameter: ";
      std::cin >> dInput;
      vinyl.setDiameter(dInput);
      break;

    // RPM
    case 9:
      //int rpm;
      std::cout << "Enter new RPM: ";
      std::cin >> dInput;
      vinyl.setRPM(dInput);
      break;

    default:
      std::cout << "Invalid option\n";
  }
}


// Add CD
void Shelf::addCD(CD& cd) {

  cdCollection.push_back(cd);

  // Update cd value
  //dCDValue += cd.getPrice();

  // Update total value
  //dTotalValue += cd.getPrice();
}

// Add Vinyl
void Shelf::addVinyl( Vinyl& vinyl) {

  vinylCollection.push_back(vinyl);

  // Update vinyl value
  //dVinylValue += vinyl.getPrice();

  // Update total value
  //dTotalValue += vinyl.getPrice();
}

// Remove CD
void Shelf::removeCD(int index) {

  if(index-1 < cdCollection.get_size()) {

    CD& cd = cdCollection[index-1];

    // Update values
    //dCDValue -= cd.getPrice();
    //dTotalValue -= cd.getPrice();

    // Remove from vector
    cdCollection.erase(cdCollection.begin() + index-1);
  }
}

// Remove Vinyl
void Shelf::removeVinyl(int index) {

  if(index -1 < vinylCollection.get_size()) {

    Vinyl& vinyl = vinylCollection[index-1];

    // Update values
    //dVinylValue -= vinyl.getPrice();
    //dTotalValue -= vinyl.getPrice();

    // Remove
    vinylCollection.erase(vinylCollection.begin() + index-1);
  }
}

// Get total value
double Shelf::getTotalValue() {
  double cd_val = getCDValue();
  double vinyl_val = getVinylValue();

  double total_val = cd_val+vinyl_val;

  return total_val;

}

// Get CD value
double Shelf::getCDValue() {

  //iterateve over cds and sum values
  dCDValue = 0;
  for(CD cd: cdCollection){
    dCDValue += cd.getPrice();
  }

  return dCDValue;
}

// Get vinyl value
double Shelf::getVinylValue() {
  dVinylValue = 0;
  for(Vinyl v: vinylCollection){
    dVinylValue += v.getPrice();
  }

  return dVinylValue;
}