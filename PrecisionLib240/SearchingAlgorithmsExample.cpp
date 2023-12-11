#include <iostream>
#include <cmath>
#include "SearchingAlgorithms.h"

void printResult(int result, int key) {
    if (result != -1) {
        std::cout << "Element found at index " << result << " for key " << key << std::endl;
    } else {
        std::cout << "Element not found for key " << key << std::endl;
    }
}

int main() {
    const int size = 10;
    int arr[size] = {10, 23, 45, 50, 56, 77, 82, 95, 100, 110};
    int key = 56;

    // Linear Search
    int linearResult = linearSearch(arr, size, key);
    printResult(linearResult, key);

    // Binary Search (Requires sorted array)
    int sortedArr[size] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int binaryResult = binarySearch(sortedArr, size, key);
    printResult(binaryResult, key);

    // Interpolation Search (Requires sorted array)
    int interpolationResult = interpolationSearch(sortedArr, size, key);
    printResult(interpolationResult, key);

    // Jump Search (Requires sorted array)
    int jumpResult = jumpSearch(sortedArr, size, key);
    printResult(jumpResult, key);

    // Exponential Search (Requires sorted array)
    int exponentialResult = exponentialSearch(sortedArr, size, key);
    printResult(exponentialResult, key);

    // Fibonacci Search (Requires sorted array)
    int fibonacciResult = fibonacciSearch(sortedArr, size, key);
    printResult(fibonacciResult, key);

    // Ternary Search (Requires sorted array)
    int ternaryResult = ternarySearch(sortedArr, 0, size - 1, key);
    printResult(ternaryResult, key);

    // Hashing example
    const int hashTableSize = 10;
    int hashTable[hashTableSize];
    std::fill_n(hashTable, hashTableSize, -1);
    hashTable[4] = 40;
    hashTable[7] = 77;
    hashTable[9] = 95;

    // Linear Probing
    int linearProbingResult = linearProbing(hashTable, hashTableSize, 77);
    printResult(linearProbingResult, 77);

    // Quadratic Probing
    int quadraticProbingResult = quadraticProbing(hashTable, hashTableSize, 95);
    printResult(quadraticProbingResult, 95);

    // Double Hashing
    int doubleHashingResult = doubleHashing(hashTable, hashTableSize, 40);
    printResult(doubleHashingResult, 40);

    return 0;
}
