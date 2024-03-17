#include <iostream>
#include <vector>
#include "RAII.h"

int main() {
    using namespace STLAlgorithmsWithRAII;

    try {
        // RAII ensures proper file handling
        FileWrapper file("data.txt"); //Include File name you want to open

        std::vector<int> numbers;

        // Reading numbers from file
        int num;
        while (file.getStream() >> num) {
            numbers.push_back(num);
        }

        // Sorting the vector
        sort(numbers);

        std::cout << "Sorted numbers: ";
        for (int num : numbers) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    } catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
