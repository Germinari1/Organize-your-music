#include <iostream>
#include <string>
#include "myMap_v2.h"

int main() {
    // Test with int keys and string values
    Map<int, std::string> intToString = {
        {1, "one"},
        {2, "two"},
        {3, "three"}
    };

    std::cout << "intToString Map:" << std::endl;
    std::cout << "Size: " << intToString.getSize() << std::endl;
    std::cout << "Value for key 2: " << intToString[2] << std::endl;
    std::cout << "Contains key 3: " << intToString.contain_key(3) << std::endl;
    std::cout << "Contains value 'four': " << intToString.contains_value("four") << std::endl;

    // Test with char keys and double values
    Map<char, double> charToDouble = {
        {'a', 1.2},
        {'b', 3.4},
        {'c', 5.6}
    };

    std::cout << "\ncharToDouble Map:" << std::endl;
    std::cout << "Size: " << charToDouble.getSize() << std::endl;
    std::cout << "Value for key 'b': " << charToDouble['b'] << std::endl;
    std::cout << "Contains key 'c': " << charToDouble.contain_key('c') << std::endl;
    std::cout << "Contains value 7.8: " << charToDouble.contains_value(7.8) << std::endl;

    // Test with std::string keys and a custom class value
    class MyClass {
    public:
        int value;
        MyClass(int val) : value(val) {}
        bool operator==(const MyClass& other) const {
        return value == other.value;
    }
    };

    Map<std::string, MyClass> stringToMyClass = {
        {"obj1", MyClass(10)},
        {"obj2", MyClass(20)},
        {"obj3", MyClass(30)}
    };

    std::cout << "\nstringToMyClass Map:" << std::endl;
    std::cout << "Size: " << stringToMyClass.getSize() << std::endl;
    std::cout << "Value for key 'obj2': " << stringToMyClass["obj2"].value << std::endl;
    std::cout << "Contains key 'obj3': " << stringToMyClass.contain_key("obj3") << std::endl;
    MyClass temp(40);
    std::cout << "Contains value " << temp.value << ": " << stringToMyClass.contains_value(temp) << std::endl;

    return 0;
}