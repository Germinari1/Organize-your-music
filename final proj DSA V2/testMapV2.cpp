#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "myMap_V2.h"

int main() {
    // Test constructor and initialization list
    std::cout << "Testing constructor and initialization list..." << std::endl;
    MapV2<std::string, int> map1 = {{"apple", 1}, {"banana", 2}, {"cherry", 3}};
    return 0;
}