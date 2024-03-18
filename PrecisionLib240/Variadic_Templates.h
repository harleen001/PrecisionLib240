#ifndef VARIADIC_TEMPLATES_EXAMPLE_H
#define VARIADIC_TEMPLATES_EXAMPLE_H

#include <iostream>

// Base case for recursive template function
void print() {
    std::cout << std::endl; // Print newline when no arguments are left
}

// Recursive template function to print variable number of arguments
template<typename T, typename... Args>
void print(T first, Args... args) {
    std::cout << first << " "; // Print the first argument
    print(args...); // Recursively call print with remaining arguments
}

#endif // VARIADIC_TEMPLATES_EXAMPLE_H
