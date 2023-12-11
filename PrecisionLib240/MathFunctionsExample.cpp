#include <iostream>
#include "MathFunctions.h"

int main() {
    int num;
    std::cout << "Enter a number: ";
    std::cin >> num;

    // Test the functions
    std::cout << "Factorial: " << factorial(num) << std::endl;

    std::cout << "Is prime? " << (isPrime(num) ? "Yes" : "No") << std::endl;

    int a, b;
    std::cout << "Enter two numbers for GCD and LCM calculation: ";
    std::cin >> a >> b;
    std::cout << "GCD: " << gcd(a, b) << std::endl;
    std::cout << "LCM: " << lcm(a, b) << std::endl;

    double base;
    int exponent;
    std::cout << "Enter base and exponent for power calculation: ";
    std::cin >> base >> exponent;
    std::cout << "Power: " << calculatePower(base, exponent) << std::endl;

    std::cout << "Square of " << num << ": " << calculateSquare(num) << std::endl;

    std::cout << "Square root of " << num << ": " << calculateSquareRoot(num) << std::endl;

    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    std::cout << "Average: " << calculateAverage(arr, size) << std::endl;

    int min, max;
    std::cout << "Enter min and max for random number generation: ";
    std::cin >> min >> max;
    std::cout << "Random number between " << min << " and " << max << ": " << generateRandomNumber(min, max) << std::endl;

    std::cout << "Closest power of two to " << num << ": " << findClosestPowerOfTwo(num) << std::endl;

    return 0;
}
