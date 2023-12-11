#ifndef SORTINGALGORITHMS_H
#define SORTINGALGORITHMS_H

#include <iostream>

// Function declarations
void bubbleSort(int arr[], int size);
void insertionSort(int arr[], int size);
void selectionSort(int arr[], int size);
void mergeSort(int arr[], int left, int right);
void quickSort(int arr[], int low, int high);
void heapify(int arr[], int size, int index);
void heapSort(int arr[], int size);
void cocktailSort(int arr[], int size);
void combSort(int arr[], int size);
void gnomeSort(int arr[], int size);
void cycleSort(int arr[], int size);

// Function implementations

void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void insertionSort(int arr[], int size) {
    for (int i = 1; i < size; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void selectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < size; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        std::swap(arr[minIndex], arr[i]);
    }
}

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int* L = new int[n1];
    int* R = new int[n2];

    for (int i = 0; i < n1; ++i) {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; ++j) {
        R[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            ++i;
        } else {
            arr[k] = R[j];
            ++j;
        }
        ++k;
    }

    while (i < n1) {
        arr[k] = L[i];
        ++i;
        ++k;
    }
    while (j < n2) {
        arr[k] = R[j];
        ++j;
        ++k;
    }

    delete[] L;
    delete[] R;
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; ++j) {
        if (arr[j] < pivot) {
            ++i;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void heapify(int arr[], int size, int index) {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < size && arr[left] > arr[largest]) {
        largest = left;
    }
    if (right < size && arr[right] > arr[largest]) {
        largest = right;
    }
    if (largest != index) {
        std::swap(arr[index], arr[largest]);
        heapify(arr, size, largest);
    }
}

void heapSort(int arr[], int size) {
    for (int i = size / 2 - 1; i >= 0; --i) {
        heapify(arr, size, i);
    }
    for (int i = size - 1; i >= 0; --i) {
        std::swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void cocktailSort(int arr[], int size) {
    bool swapped = true;
    int start = 0;
    int end = size - 1;

    while (swapped) {
        swapped = false;

        for (int i = start; i < end; ++i) {
            if (arr[i] > arr[i + 1]) {
                std::swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }

        if (!swapped) {
            break;
        }

        swapped = false;
        --end;

        for (int i = end - 1; i >= start; --i) {
            if (arr[i] > arr[i + 1]) {
                std::swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }
        ++start;
    }
}

void combSort(int arr[], int size) {
    int gap = size;
    float shrink = 1.3;
    bool swapped = true;

    while (gap > 1 || swapped) {
        if (gap > 1) {
            gap = int(gap / shrink);
        }

        swapped = false;
        for (int i = 0; i + gap < size; ++i) {
            if (arr[i] > arr[i + gap]) {
                std::swap(arr[i], arr[i + gap]);
                swapped = true;
            }
        }
    }
}

void gnomeSort(int arr[], int size) {
    int index = 0;

    while (index < size) {
        if (index == 0) {
            ++index;
        }
        if (arr[index] >= arr[index - 1]) {
            ++index;
        } else {
            std::swap(arr[index], arr[index - 1]);
            --index;
        }
    }
}

void cycleSort(int arr[], int size) {
    for (int cycleStart = 0; cycleStart < size - 1; ++cycleStart) {
        int item = arr[cycleStart];
        int pos = cycleStart;

        for (int i = cycleStart + 1; i < size; ++i) {
            if (arr[i] < item) {
                ++pos;
            }
        }

        if (pos == cycleStart) {
            continue;
        }

        while (item == arr[pos]) {
            ++pos;
        }

        if (pos != cycleStart) {
            std::swap(item, arr[pos]);

            while (pos != cycleStart) {
                pos = cycleStart;

                for (int i = cycleStart + 1; i < size; ++i) {
                    if (arr[i] < item) {
                        ++pos;
                    }
                }

                while (item == arr[pos]) {
                    ++pos;
                }

                if (item != arr[pos]) {
                    std::swap(item, arr[pos]);
                }
            }
        }
    }
}

#endif // SORTINGALGORITHMS_H
