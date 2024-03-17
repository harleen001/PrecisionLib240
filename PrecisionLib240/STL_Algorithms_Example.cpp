#include <iostream>
#include "STL_Algorithms.h"

int main() {
    std::vector<int> numbers = {5, 2, 7, 3, 1, 6, 4};

    // Sorting the vector
    STLAlgorithms::sort(numbers);

    std::cout << "Sorted numbers: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Finding an element
    int value = 3;
    auto it = STLAlgorithms::find(numbers, value);
    if (it != numbers.end()) {
        std::cout << "Found " << value << " at position " << (it - numbers.begin()) << std::endl;
    } else {
        std::cout << "Could not find " << value << std::endl;
    }

    // Transforming elements
    std::vector<int> doubledNumbers;
    STLAlgorithms::transform(numbers.begin(), numbers.end(), std::back_inserter(doubledNumbers), [](int n) { return n * 2; });

    std::cout << "Doubled numbers: ";
    for (int num : doubledNumbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
