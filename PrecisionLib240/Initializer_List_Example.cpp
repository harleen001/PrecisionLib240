#include <iostream>
#include <vector>
#include <set>
#include "Initializer_List.h"

int main() {
    // Initialize a vector
    InitializerList<int> vectorInitializer({1, 2, 3, 4, 5});
    std::vector<int> myVector;
    vectorInitializer.initialize(myVector);

    // Print the vector
    std::cout << "Vector: ";
    for (const auto& elem : myVector) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    // Initialize a set
    InitializerList<char> setInitializer({'a', 'b', 'c', 'd', 'e'});
    std::set<char> mySet;
    setInitializer.initialize(mySet);

    // Print the set
    std::cout << "Set: ";
    for (const auto& elem : mySet) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    return 0;
}
