// main.cpp

#include <iostream>
#include "NumberTypeChecker.h"

int main() {
    constexpr int num = 5; // Number to check

    // Check if the number is even using template metaprogramming
    constexpr bool isEven = IsEven<num>::value;

    if (isEven) {
        std::cout << num << " is even." << std::endl;
    } else {
        std::cout << num << " is odd." << std::endl;
    }

    return 0;
}
