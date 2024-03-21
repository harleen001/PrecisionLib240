#include <iostream>
#include "Function_Overloading.h"

int main() {
    FunctionOverloading fo;

    // Example 1: Adding two integers
    int sum1 = fo.add(10, 20);
    std::cout << "Sum of 10 and 20: " << sum1 << std::endl;

    // Example 2: Adding three integers
    int sum2 = fo.add(10, 20, 30);
    std::cout << "Sum of 10, 20, and 30: " << sum2 << std::endl;

    // Example 3: Adding two floating-point numbers
    float sum3 = fo.add(1.5f, 2.5f);
    std::cout << "Sum of 1.5 and 2.5: " << sum3 << std::endl;

    // Example 4: Concatenating two strings
    std::string result = fo.concatenate("Hello, ", "world!");
    std::cout << "Concatenated string: " << result << std::endl;

    return 0;
}
