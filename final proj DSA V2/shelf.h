/*-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= 
//* Author: Lucas Germinari Carreira
//* Date last updated: 04/28/2024
//* Description (class definition): Defines the class Shelf, which is responsible for storing the CD and Vinyl collections.
//* Tested: no, 
//* Notes:
-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*/

#include <iostream>
#include <string>
#include "vinyl.h"
#include "CD.h"
#include <vector>
#include <utility>
#include <cstddef>
#include "myVector.h"
//#include "avlBT.h"
#include "myQueueLL.h"
#include "hashTableV2.h"

#ifndef SHELF_H
#define SHELF_H

class Shelf {

private:
  //functor to encapsulate hash function
  /*struct QueueSizeHashFunc {
    size_t operator()(const QueueLL<CD>& q) const {
            size_t hashValue = 0;
            // Use the size of the queue as part of the hash value
            hashValue = std::hash<size_t>()(q.size());  
            return hashValue;
        }
  };*/
  MyVector<CD> cdCollection;
  MyVector<Vinyl> vinylCollection;
  double dTotalValue;
  double dCDValue;
  double dVinylValue;
  //HashTableV2<QueueLL<CD>, QueueSizeHashFunc> cdHashTable;

public:
  

  // Display collections 
  void displayCollection(bool cds, bool vinyls);
  void displayCDCollection();
  void displayVinylCollection();

  // Export and import collection 
  void exportCollectionToFile(bool cd, bool vinyl);
  std::vector<std::vector<std::pair<std::string, std::string>>> parseCollectionFile(const std::string& file_path);
  void loadCollectionFromFile(const std::vector<std::vector<std::pair<std::string, std::string>>>& data);
  date stringToDate(const std::string& dateStr);

  // Add items
  void addCD(CD& cd);
  void addVinyl(Vinyl& vinyl);  

  //get items
  CD* getCDItem(int elementId);
  Vinyl* getVinylItem(int elementId);

  // Remove items
  void removeCD(int index);
  void removeVinyl(int index);

  //edits items
  void editCD(int iItemIndex, int iActionIndex);
  void editVinyl(int iItemIndex, int iActionIndex);

  // Get value
  double getTotalValue();
  double getCDValue();
  double getVinylValue();

  //get collection sizes
  int getCollectionSize(char collectionIdentifier);

};

#endif