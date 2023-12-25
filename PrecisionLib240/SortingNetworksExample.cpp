#include "SortingNetworks.h"

void printArray(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    const int size = 10;
    int arr[size] = {5, 2, 9, 1, 5, 6, 3, 7, 8, 4};

    std::cout << "Original array: ";
    printArray(arr, size);

    SortingNetworks::bitonicSort(arr, size, true);
    std::cout << "Bitonic sorted array: ";
    printArray(arr, size);

    SortingNetworks::oddEvenMergeSort(arr, size, true);
    std::cout << "Odd-Even Merge sorted array: ";
    printArray(arr, size);

    SortingNetworks::bogoSort(arr, size, true);
    std::cout << "Bogo sorted array: ";
    printArray(arr, size);

    SortingNetworks::pancakeSort(arr, size, true);
    std::cout << "Pancake sorted array: ";
    printArray(arr, size);

    SortingNetworks::stoogeSort(arr, size, true);
    std::cout << "Stooge sorted array: ";
    printArray(arr, size);

   

    return 0;
}
