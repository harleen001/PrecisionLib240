#include <iostream>
#include <regex>

int main() {
    // Input regular expression pattern for a strong password
    std::string pattern = "^(?=.*[a-z])(?=.*[A-Z])(?=.*\\d)(?=.*[!@#$%^&*])[A-Za-z\\d!@#$%^&*]{8,}$";

    // Double the backslashes within the regex pattern
    std::regex regexPattern(pattern);

    // Input string to match against
    std::string input;
    std::cout << "Enter a password to validate: ";
    std::getline(std::cin, input);

    // Check if the input string matches the regular expression
    if (std::regex_match(input, regexPattern)) {
        std::cout << "Valid password.\n";
    } else {
        std::cout << "Invalid password.\n";
    }

    return 0;
}
