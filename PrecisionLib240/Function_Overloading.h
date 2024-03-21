#ifndef FUNCTION_OVERLOADING_H
#define FUNCTION_OVERLOADING_H

#include <iostream>

class FunctionOverloading {
public:
    // Function to add two integers
    int add(int a, int b) {
        return a + b;
    }

    // Function to add three integers
    int add(int a, int b, int c) {
        return a + b + c;
    }

    // Function to add two floating-point numbers
    float add(float a, float b) {
        return a + b;
    }

    // Function to concatenate two strings
    std::string concatenate(std::string str1, std::string str2) {
        return str1 + str2;
    }
};

#endif // FUNCTION_OVERLOADING_H
