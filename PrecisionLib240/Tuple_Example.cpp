#include <iostream>
#include "Tuple.h"

int main() {
    // Create a Tuple with int, double, and string values entered by the user
    int intValue;
    double doubleValue;
    std::string stringValue;

    std::cout << "Enter an integer value: ";
    std::cin >> intValue;

    std::cout << "Enter a double value: ";
    std::cin >> doubleValue;

    std::cout << "Enter a string value: ";
    std::cin >> stringValue;

    Tuple<int, double, std::string> myTuple(intValue, doubleValue, stringValue);

    // Retrieve and print values from the Tuple
    std::cout << "Integer value: " << myTuple.get() << std::endl;
    std::cout << "Double value: " << myTuple.Tuple<double, std::string>::get() << std::endl;
    std::cout << "String value: " << myTuple.Tuple<std::string>::get() << std::endl;

    return 0;
}
