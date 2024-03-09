#include <iostream>
#include <regex>

int main() {
    // Input regular expression pattern
    std::string pattern = "^[a-zA-Z0-9._%+-]+@gmail\\.com$";

    // Create a regular expression object
    std::regex regexPattern(pattern);

    // Input string to match against
    std::string input;
    std::cout << "Enter an email address to validate: ";
    std::getline(std::cin, input);

    // Check if the input string matches the regular expression
    if (std::regex_match(input, regexPattern)) {
        std::cout << "Valid email address.\n";
    } else {
        std::cout << "Invalid email address.\n";
    }

    return 0;
}
