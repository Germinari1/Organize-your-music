/*-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
//* Author: Lucas Germinari Carreira
//* Last modification date: 04/15/2024
//* Description (testing file): the avlBT_V2 (AVL tree with user-provided comparison criteria)
//* Tested: no, 
//* Notes:
    - This version supports custom comparators
-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*/

#include <iostream>
#include <string>
#include <functional>
#include "avlBT_V2.h"

// Custom comparator for strings (case-insensitive comparison)
struct StringCaseInsensitiveComparator {
    bool operator()(const std::string& a, const std::string& b) const {
        std::string lowerA = a;
        std::string lowerB = b;
        std::transform(lowerA.begin(), lowerA.end(), lowerA.begin(), ::tolower);
        std::transform(lowerB.begin(), lowerB.end(), lowerB.begin(), ::tolower);
        return lowerA < lowerB;
    }
};

int main() {
    // Create an AVL tree for strings with a case-insensitive comparator
    AVLTree<std::string, StringCaseInsensitiveComparator> stringTree;

    // Insert elements (case-insensitive)
    stringTree.insert("Apple");
    stringTree.insert("Banana");
    stringTree.insert("Cherry");
    stringTree.insert("Date");
    stringTree.insert("Elderberry");
    stringTree.insert("FIG");
    stringTree.insert("grape");

    // Expected output: The tree should be balanced and contain all the inserted elements
    // regardless of their case

    // Print the tree in inorder traversal
    std::cout << "Inorder Traversal: ";
    stringTree.inOrder();
    std::cout << "\n";
    // Expected output: Apple Banana Cherry Date Elderberry FIG grape

    // Search for elements (case-insensitive)
    std::cout << "Searching for 'Apple': " << stringTree.search("Apple") << std::endl;
    // Expected output: Searching for 'Apple': 1 (true)
    std::cout << "Searching for 'banana': " << stringTree.search("banana") << std::endl;
    // Expected output: Searching for 'banana': 1 (true)
    std::cout << "Searching for 'Orange': " << stringTree.search("Orange") << std::endl;
    // Expected output: Searching for 'Orange': 0 (false)

    // Remove elements (case-insensitive)
    stringTree.remove("Banana");
    stringTree.remove("GRAPE");

    // Expected output: The tree should still be balanced and contain the remaining elements
    // after the removals

    // Print the tree after removals
    std::cout << "\nTree after removals:\n";
    std::cout << "Inorder Traversal: ";
    stringTree.inOrder();
    std::cout << "\n";
    // Expected output: Apple Cherry Date Elderberry FIG

    return 0;
}