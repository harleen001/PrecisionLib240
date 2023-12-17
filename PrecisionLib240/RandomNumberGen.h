#include <iostream>
#include <ctime> // Include for seeding random number generator
#include "RandomNumberGen.h" // Include the header file

int main() {
    // Seed the random number generator
    unsigned int seedValue = static_cast<unsigned int>(time(0));
    seedRandomGenerator(seedValue);

    // Generate random integers
    int randomInt = generateRandomInt(1, 100);
    std::cout << "Random Integer between 1 and 100: " << randomInt << std::endl;

    // Generate random double
    double randomDouble = generateRandomDouble(10.5, 20.5);
    std::cout << "Random Double between 10.5 and 20.5: " << randomDouble << std::endl;

    // Generate a random boolean
    bool randomBool = generateRandomBoolean();
    std::cout << "Random Boolean: " << (randomBool ? "true" : "false") << std::endl;

    // Generate a random character
    char randomChar = generateRandomChar();
    std::cout << "Random Character: " << randomChar << std::endl;

    // Generate a random string
    char randomString[10];
    generateRandomString(randomString, 9);
    std::cout << "Random String: " << randomString << std::endl;

    // Generate random number in a specific range with a step
    int randomInRange = generateRandomInRange(1, 20, 3);
    std::cout << "Random Number between 1 and 20 with step 3: " << randomInRange << std::endl;

    // Generate a random number following a Gaussian distribution
    double mean = 10.0, stddev = 2.0;
    double gaussianRandom = generateGaussianRandom(mean, stddev);
    std::cout << "Random Number from Gaussian Distribution (mean=10, stddev=2): " << gaussianRandom << std::endl;

    // Generate a random prime number
    int randomPrime = generateRandomPrime(50, 100);
    std::cout << "Random Prime Number between 50 and 100: " << randomPrime << std::endl;

    // Generate a random number following the Fibonacci sequence
    int randomFibonacci = generateFibonacciRandom(10, 100);
    std::cout << "Random Number from Fibonacci Sequence between 10 and 100: " << randomFibonacci << std::endl;

    return 0;
}
