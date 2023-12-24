// Example.cpp
#include <iostream>
#include "UtilityFunctions.h"

int main() {
    int x = 10, y = 20;
    std::cout << "Before swapping: x = " << x << ", y = " << y << std::endl;
    swap(x, y);
    std::cout << "After swapping: x = " << x << ", y = " << y << std::endl;

    int maxVal = getMax(30, 50);
    std::cout << "Max value is: " << maxVal << std::endl;

    int minVal = getMin(30, 50);
    std::cout << "Min value is: " << minVal << std::endl;

    std::cout << "Is 16 a power of two? " << std::boolalpha << isPowerOfTwo(16) << std::endl;

    std::cout << "Absolute value of -5 is: " << abs(-5) << std::endl;

    std::cout << "Is 7 even? " << std::boolalpha << isEven(7) << std::endl;

    std::cout << "Is 'A' a digit? " << std::boolalpha << isDigit('A') << std::endl;

    std::cout << "Converted 'a' to uppercase: " << toUpperCase('a') << std::endl;

    return 0;
}
