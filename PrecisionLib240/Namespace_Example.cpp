#include <iostream>
#include <string>
#include "Namespace.h"

int main() {
    // Create namespaces for integers and strings
    Namespace<int> intNamespace = {
        { "one", 1 },
        { "two", 2 },
        { "three", 3 }
    };

    Namespace<std::string> strNamespace = {
        { "alpha", "A" },
        { "beta", "B" },
        { "gamma", "C" }
    };

    // Print all identifiers and their corresponding values
    intNamespace.printAll();
    strNamespace.printAll();

    // Retrieve values using identifiers
    try {
        int value = intNamespace.getValue("two");
        std::cout << "Value of 'two' in intNamespace: " << value << '\n';
    } catch (const std::invalid_argument& e) {
        std::cerr << e.what() << '\n';
    }

    try {
        std::string value = strNamespace.getValue("beta");
        std::cout << "Value of 'beta' in strNamespace: " << value << '\n';
    } catch (const std::invalid_argument& e) {
        std::cerr << e.what() << '\n';
    }

    // Get all identifiers in the namespace
    std::cout << "All identifiers in intNamespace:\n";
    for (const auto& id : intNamespace.getAllIdentifiers()) {
        std::cout << id << '\n';
    }

    return 0;
}
