#include <iostream>
#include <regex>

int main() {
    // Input regular expression pattern for URL validation
    std::string pattern = "^(https?://)?[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}(?:/[^\\s]*)?$";

    // Create a regular expression object
    std::regex regexPattern(pattern);

    // Input string to match against
    std::string input;
    std::cout << "Enter a URL to validate: ";
    std::getline(std::cin, input);

    // Check if the input string matches the regular expression
    if (std::regex_match(input, regexPattern)) {
        std::cout << "Valid URL.\n";
    } else {
        std::cout << "Invalid URL.\n";
    }

    return 0;
}
