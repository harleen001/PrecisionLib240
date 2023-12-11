#include <iostream>
#include "StringOps.h"

int main() {
    const int maxSize = 100;
    char str[maxSize];
    std::cout << "Enter a string: ";
    std::cin.getline(str, maxSize);

    // Test the functions
    std::cout << "String length: " << stringLength(str) << std::endl;

    char copyStr[maxSize];
    stringCopy(copyStr, str);
    std::cout << "Copied string: " << copyStr << std::endl;

    std::cout << "Comparing strings: " << stringCompare(str, copyStr) << std::endl;

    char concatStr[maxSize];
    stringConcatenate(concatStr, str);
    std::cout << "Concatenated string: " << concatStr << std::endl;

    std::cout << "Is the string a palindrome? " << (isPalindrome(str) ? "Yes" : "No") << std::endl;

    reverseString(str);
    std::cout << "Reversed string: " << str << std::endl;

    char ch;
    std::cout << "Enter a character to count its occurrences in the string: ";
    std::cin >> ch;
    std::cout << "Number of occurrences of '" << ch << "': " << countOccurrences(str, ch) << std::endl;

    std::cout << "Converted to lowercase: " << convertToLowercase(str) << std::endl;
    std::cout << "Converted to uppercase: " << convertToUppercase(str) << std::endl;

    std::cout << "String without spaces: " << removeSpaces(str) << std::endl;

    return 0;
}
