#include <iostream>
#include <ctime>
#include <cstdlib>
#include "SortingAlgorithms.h"

void printArray(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    const int size = 10;
    int arr[size];

    // Generate random numbers for the array
    srand(time(nullptr));
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 100; // Random numbers between 0 and 99
    }

    std::cout << "Original array: ";
    printArray(arr, size);

    // Sort the array using different sorting algorithms
    bubbleSort(arr, size);
    std::cout << "Sorted array (Bubble Sort): ";
    printArray(arr, size);

    insertionSort(arr, size);
    std::cout << "Sorted array (Insertion Sort): ";
    printArray(arr, size);

    selectionSort(arr, size);
    std::cout << "Sorted array (Selection Sort): ";
    printArray(arr, size);

    int arrMerge[size];
    std::copy(arr, arr + size, arrMerge);
    mergeSort(arrMerge, 0, size - 1);
    std::cout << "Sorted array (Merge Sort): ";
    printArray(arrMerge, size);

    int arrQuick[size];
    std::copy(arr, arr + size, arrQuick);
    quickSort(arrQuick, 0, size - 1);
    std::cout << "Sorted array (Quick Sort): ";
    printArray(arrQuick, size);

    int arrHeap[size];
    std::copy(arr, arr + size, arrHeap);
    heapSort(arrHeap, size);
    std::cout << "Sorted array (Heap Sort): ";
    printArray(arrHeap, size);

    int arrCocktail[size];
    std::copy(arr, arr + size, arrCocktail);
    cocktailSort(arrCocktail, size);
    std::cout << "Sorted array (Cocktail Sort): ";
    printArray(arrCocktail, size);

    int arrComb[size];
    std::copy(arr, arr + size, arrComb);
    combSort(arrComb, size);
    std::cout << "Sorted array (Comb Sort): ";
    printArray(arrComb, size);

    int arrGnome[size];
    std::copy(arr, arr + size, arrGnome);
    gnomeSort(arrGnome, size);
    std::cout << "Sorted array (Gnome Sort): ";
    printArray(arrGnome, size);

    int arrCycle[size];
    std::copy(arr, arr + size, arrCycle);
    cycleSort(arrCycle, size);
    std::cout << "Sorted array (Cycle Sort): ";
    printArray(arrCycle, size);

    return 0;
}
