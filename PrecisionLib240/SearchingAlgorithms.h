#ifndef SEARCHINGALGORITHMS_H
#define SEARCHINGALGORITHMS_H
#include <cmath>
// Function declarations
int linearSearch(const int arr[], int size, int key);
int binarySearch(const int arr[], int size, int key);
int interpolationSearch(const int arr[], int size, int key);
int jumpSearch(const int arr[], int size, int key);
int exponentialSearch(const int arr[], int size, int key);
int fibonacciSearch(const int arr[], int size, int key);
int ternarySearch(const int arr[], int size, int key);
int linearProbing(int hashTable[], int size, int key);
int quadraticProbing(int hashTable[], int size, int key);
int doubleHashing(int hashTable[], int size, int key);

// Function implementations

int linearSearch(const int arr[], int size, int key) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1; // Element not found
}

int binarySearch(const int arr[], int size, int key) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == key) {
            return mid;
        }

        if (arr[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1; // Element not found
}

int interpolationSearch(const int arr[], int size, int key) {
    int left = 0;
    int right = size - 1;

    while (left <= right && key >= arr[left] && key <= arr[right]) {
        if (left == right) {
            if (arr[left] == key) {
                return left;
            }
            return -1; // Element not found
        }

        int pos = left + ((key - arr[left]) * (right - left) / (arr[right] - arr[left]));

        if (arr[pos] == key) {
            return pos;
        }

        if (arr[pos] < key) {
            left = pos + 1;
        } else {
            right = pos - 1;
        }
    }
    return -1; // Element not found
}

int jumpSearch(const int arr[], int size, int key) {
    int step = sqrt(size);
    int prev = 0;

    while (arr[min(step, size) - 1] < key) {
        prev = step;
        step += sqrt(size);
        if (prev >= size) {
            return -1; // Element not found
        }
    }

    while (arr[prev] < key) {
        ++prev;
        if (prev == min(step, size)) {
            return -1; // Element not found
        }
    }

    if (arr[prev] == key) {
        return prev;
    }

    return -1; // Element not found
}

int exponentialSearch(const int arr[], int size, int key) {
    if (arr[0] == key) {
        return 0;
    }

    int i = 1;
    while (i < size && arr[i] <= key) {
        i *= 2;
    }

    return binarySearch(arr, i / 2, min(i, size), key);
}

int fibonacciSearch(const int arr[], int size, int key) {
    int fib2 = 0;
    int fib1 = 1;
    int fib = fib1 + fib2;

    while (fib < size) {
        fib2 = fib1;
        fib1 = fib;
        fib = fib1 + fib2;
    }

    int offset = -1;

    while (fib > 1) {
        int i = min(offset + fib2, size - 1);

        if (arr[i] < key) {
            fib = fib1;
            fib1 = fib2;
            fib2 = fib - fib1;
            offset = i;
        } else if (arr[i] > key) {
            fib = fib2;
            fib1 = fib1 - fib2;
            fib2 = fib - fib1;
        } else {
            return i;
        }
    }

    if (fib1 == 1 && arr[offset + 1] == key) {
        return offset + 1;
    }

    return -1; // Element not found
}

int ternarySearch(const int arr[], int left, int right, int key) {
    if (right >= left) {
        int mid1 = left + (right - left) / 3;
        int mid2 = mid1 + (right - left) / 3;

        if (arr[mid1] == key) {
            return mid1;
        }

        if (arr[mid2] == key) {
            return mid2;
        }

        if (key < arr[mid1]) {
            return ternarySearch(arr, left, mid1 - 1, key);
        } else if (key > arr[mid2]) {
            return ternarySearch(arr, mid2 + 1, right, key);
        } else {
            return ternarySearch(arr, mid1 + 1, mid2 - 1, key);
        }
    }
    return -1; // Element not found
}

int linearProbing(int hashTable[], int size, int key) {
    int index = key % size;

    while (hashTable[index] != -1) {
        if (hashTable[index] == key) {
            return index;
        }
        index = (index + 1) % size;
    }

    return -1; // Element not found
}

int quadraticProbing(int hashTable[], int size, int key) {
    int index = key % size;
    int i = 0;

    while (hashTable[(index + i * i) % size] != -1) {
        if (hashTable[(index + i * i) % size] == key) {
            return (index + i * i) % size;
        }
        ++i;
    }

    return -1; // Element not found
}

int doubleHashing(int hashTable[], int size, int key) {
    int index = key % size;
    int hash2 = 7 - (key % 7);
    int i = 0;

    while (hashTable[(index + i * hash2) % size] != -1) {
        if (hashTable[(index + i * hash2) % size] == key) {
            return (index + i * hash2) % size;
        }
        ++i;
    }

    return -1; // Element not found
}

#endif // SEARCHINGALGORITHMS_H
