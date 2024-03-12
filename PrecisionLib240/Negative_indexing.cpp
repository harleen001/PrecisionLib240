#include <iostream>
#include "Negative_indexing.h"

int main() {
    NegativeIndexingVector<int> myVector;

    // Adding elements to the vector
    for (int i = 0; i < 5; ++i) {
        myVector.push_back(i * 10);
    }

    // Accessing elements using negative indexing
    for (int i = -3; i <= 2; ++i) {
        try {
            std::cout << "Element at index " << i << ": " << myVector[i] << std::endl;
        } catch (const std::out_of_range& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }

    return 0;
}
