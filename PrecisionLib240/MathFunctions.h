#ifndef MATHFUNCTIONS_H
#define MATHFUNCTIONS_H

#include <cmath>
#include <cstdlib>
#include <ctime>

// Function declarations
int factorial(int n);
bool isPrime(int num);
int gcd(int a, int b);
int lcm(int a, int b);
double calculatePower(double base, int exponent);
int calculateSquare(int num);
double calculateSquareRoot(double num);
double calculateAverage(int arr[], int size);
int generateRandomNumber(int min, int max);
int findClosestPowerOfTwo(int num);

// Function implementations
int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i <= sqrt(num); ++i) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

double calculatePower(double base, int exponent) {
    return pow(base, exponent);
}

int calculateSquare(int num) {
    return num * num;
}

double calculateSquareRoot(double num) {
    return sqrt(num);
}

double calculateAverage(int arr[], int size) {
    double sum = 0.0;
    for (int i = 0; i < size; ++i) {
        sum += arr[i];
    }
    return sum / size;
}

int generateRandomNumber(int min, int max) {
    static bool initialized = false;
    if (!initialized) {
        srand(time(nullptr));
        initialized = true;
    }
    return min + rand() % (max - min + 1);
}

int findClosestPowerOfTwo(int num) {
    int closestPower = 1;
    while (closestPower < num) {
        closestPower <<= 1;
    }
    return closestPower;
}

#endif // MATHFUNCTIONS_H
