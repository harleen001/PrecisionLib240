#include <iostream>
#include <regex>

int main() {
    // Input regular expression pattern for U.S. phone number
    std::string pattern = R"(^\d{3}[-\s]?\d{3}[-\s]?\d{4}$)";

    // Create a regular expression object
    std::regex regexPattern(pattern);

    // Input string to match against
    std::string input;
    std::cout << "Enter a U.S. phone number to validate: ";
    std::getline(std::cin, input);

    // Check if the input string matches the regular expression
    if (std::regex_match(input, regexPattern)) {
        std::cout << "Valid U.S. phone number.\n";
    } else {
        std::cout << "Invalid U.S. phone number.\n";
    }

    return 0;
}
