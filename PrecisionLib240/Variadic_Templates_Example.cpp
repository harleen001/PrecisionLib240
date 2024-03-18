#include <iostream>
#include "variadic_templates_example.h"

int main() {
    // Print integers
    std::cout << "Print integers: ";
    print(1, 2, 3, 4, 5);
    
    // Print strings
    std::cout << "Print strings: ";
    print("Hello", "world", "from", "variadic", "templates");
    
    // Print mixed types
    std::cout << "Print mixed types: ";
    print(10, "is", "a", "number");
    
    return 0;
}
