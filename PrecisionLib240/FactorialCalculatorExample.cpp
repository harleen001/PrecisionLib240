// main.cpp

#include <iostream>
#include "FactorialCalculator.h"

int main() {
    constexpr int num = 5; // Number whose factorial we want to compute

    // Compute factorial at compile time using template metaprogramming
    constexpr int factorial = Factorial<num>::value;

    std::cout << "Factorial of " << num << " is: " << factorial << std::endl;

    return 0;
}
