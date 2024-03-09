#include <iostream>
#include <regex>

int main() {
    // Input regular expression pattern for date in YYYY-MM-DD format
    std::string pattern = R"(^\d{4}-\d{2}-\d{2}$)";

    // Create a regular expression object
    std::regex regexPattern(pattern);

    // Input string to match against
    std::string input;
    std::cout << "Enter a date in YYYY-MM-DD format to validate: ";
    std::getline(std::cin, input);

    // Check if the input string matches the regular expression
    if (std::regex_match(input, regexPattern)) {
        std::cout << "Valid date format.\n";
    } else {
        std::cout << "Invalid date format.\n";
    }

    return 0;
}
