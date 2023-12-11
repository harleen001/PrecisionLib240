#ifndef ARRAYUTILS_H
#define ARRAYUTILS_H

#include <iostream>

// Function declarations
int findMax(int arr[], int size);
int findMin(int arr[], int size);
void reverseArray(int arr[], int size);
void sortArray(int arr[], int size);
bool isArraySorted(int arr[], int size);
void mergeArrays(int arr1[], int size1, int arr2[], int size2, int result[]);
void removeDuplicates(int arr[], int &size);
void rotateArrayLeft(int arr[], int size, int rotations);
void rotateArrayRight(int arr[], int size, int rotations);
bool isArrayEqual(int arr1[], int size1, int arr2[], int size2);

// Function implementations

int findMax(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int findMin(int arr[], int size) {
    int min = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

void reverseArray(int arr[], int size) {
    int start = 0;
    int end = size - 1;
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

void sortArray(int arr[], int size) {
    // Implement sorting algorithm (e.g., bubble sort, quicksort, etc.)
    // Sorting logic goes here
}

bool isArraySorted(int arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        if (arr[i] > arr[i + 1]) {
            return false;
        }
    }
    return true;
}

void mergeArrays(int arr1[], int size1, int arr2[], int size2, int result[]) {
    int i = 0, j = 0, k = 0;
    while (i < size1 && j < size2) {
        if (arr1[i] <= arr2[j]) {
            result[k++] = arr1[i++];
        } else {
            result[k++] = arr2[j++];
        }
    }
    while (i < size1) {
        result[k++] = arr1[i++];
    }
    while (j < size2) {
        result[k++] = arr2[j++];
    }
}

void removeDuplicates(int arr[], int &size) {
    if (size <= 1) {
        return;
    }

    int j = 0;
    for (int i = 0; i < size - 1; ++i) {
        if (arr[i] != arr[i + 1]) {
            arr[j++] = arr[i];
        }
    }
    arr[j++] = arr[size - 1];
    size = j;
}

void rotateArrayLeft(int arr[], int size, int rotations) {
    rotations %= size;
    for (int i = 0; i < rotations; ++i) {
        int temp = arr[0];
        for (int j = 0; j < size - 1; ++j) {
            arr[j] = arr[j + 1];
        }
        arr[size - 1] = temp;
    }
}

void rotateArrayRight(int arr[], int size, int rotations) {
    rotations %= size;
    for (int i = 0; i < rotations; ++i) {
        int temp = arr[size - 1];
        for (int j = size - 1; j > 0; --j) {
            arr[j] = arr[j - 1];
        }
        arr[0] = temp;
    }
}

bool isArrayEqual(int arr1[], int size1, int arr2[], int size2) {
    if (size1 != size2) {
        return false;
    }

    for (int i = 0; i < size1; ++i) {
        if (arr1[i] != arr2[i]) {
            return false;
        }
    }
    return true;
}

#endif // ARRAYUTILS_H
