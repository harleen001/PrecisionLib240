// UtilityFunctions.h
#pragma once

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int getMax(int a, int b) {
    return (a > b) ? a : b;
}

int getMin(int a, int b) {
    return (a < b) ? a : b;
}

bool isPowerOfTwo(int num) {
    return (num > 0) && ((num & (num - 1)) == 0);
}

int abs(int num) {
    return (num < 0) ? -num : num;
}

bool isEven(int num) {
    return (num % 2 == 0);
}

bool isOdd(int num) {
    return (num % 2 != 0);
}

bool isAlpha(char ch) {
    return ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'));
}

bool isDigit(char ch) {
    return (ch >= '0' && ch <= '9');
}

char toUpperCase(char ch) {
    if (ch >= 'a' && ch <= 'z') {
        return ch - ('a' - 'A');
    }
    return ch;
}
