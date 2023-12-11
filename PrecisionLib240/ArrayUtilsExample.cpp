#include <iostream>
#include "ArrayUtils.h"

int main() {
    const int size = 5;
    int arr[size] = {5, 2, 9, 1, 7};

    // Using functions from ArrayUtils.h
    std::cout << "Max: " << findMax(arr, size) << std::endl;
    std::cout << "Min: " << findMin(arr, size) << std::endl;

    // Use other functions similarly...

    return 0;
}
