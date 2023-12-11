#ifndef STRINGOPS_H
#define STRINGOPS_H

#include <cstring>
#include <cctype>

// Function declarations
int stringLength(const char* str);
void stringCopy(char* destination, const char* source);
int stringCompare(const char* str1, const char* str2);
void stringConcatenate(char* destination, const char* source);
bool isPalindrome(const char* str);
void reverseString(char* str);
int countOccurrences(const char* str, char ch);
char* convertToLowercase(char* str);
char* convertToUppercase(char* str);
char* removeSpaces(char* str);

// Function implementations
int stringLength(const char* str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

void stringCopy(char* destination, const char* source) {
    while (*source != '\0') {
        *destination = *source;
        destination++;
        source++;
    }
    *destination = '\0';
}

int stringCompare(const char* str1, const char* str2) {
    while (*str1 == *str2) {
        if (*str1 == '\0')
            return 0;
        str1++;
        str2++;
    }
    return *str1 - *str2;
}

void stringConcatenate(char* destination, const char* source) {
    while (*destination != '\0') {
        destination++;
    }
    while (*source != '\0') {
        *destination = *source;
        destination++;
        source++;
    }
    *destination = '\0';
}

bool isPalindrome(const char* str) {
    int length = stringLength(str);
    for (int i = 0; i < length / 2; i++) {
        if (str[i] != str[length - i - 1]) {
            return false;
        }
    }
    return true;
}

void reverseString(char* str) {
    int length = stringLength(str);
    int start = 0;
    int end = length - 1;
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

int countOccurrences(const char* str, char ch) {
    int count = 0;
    while (*str != '\0') {
        if (*str == ch) {
            count++;
        }
        str++;
    }
    return count;
}

char* convertToLowercase(char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = std::tolower(str[i]);
    }
    return str;
}

char* convertToUppercase(char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = std::toupper(str[i]);
    }
    return str;
}

char* removeSpaces(char* str) {
    int count = 0;
    for (int i = 0; str[i]; i++) {
        if (str[i] != ' ') {
            str[count++] = str[i];
        }
    }
    str[count] = '\0';
    return str;
}

#endif // STRINGOPS_H
