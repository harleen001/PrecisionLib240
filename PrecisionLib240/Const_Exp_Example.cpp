#include <iostream>
#include "Const_Exp.h"

int main() {
    constexpr ConstexprExample ce;

    // Calculate factorial of 5 at compile-time
    constexpr int factorialOf5 = ce.factorial(5);
    std::cout << "Factorial of 5: " << factorialOf5 << std::endl;

    // Check if 7 is prime at compile-time
    constexpr bool is7Prime = ce.isPrime(7);
    std::cout << "Is 7 prime? " << (is7Prime ? "Yes" : "No") << std::endl;

    // Check if 10 is prime at compile-time
    constexpr bool is10Prime = ce.isPrime(10);
    std::cout << "Is 10 prime? " << (is10Prime ? "Yes" : "No") << std::endl;

    return 0;
}
