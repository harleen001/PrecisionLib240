#ifndef SORTING_NETWORKS_H
#define SORTING_NETWORKS_H

#include <iostream>
#include <algorithm>

class SortingNetworks {
public:
    // Bitonic Sort
    static void bitonicSort(int arr[], int size, bool ascending) {
        bitonicSortRecursive(arr, 0, size, ascending);
    }

private:
    // Helper functions for Bitonic Sort
    static void bitonicMerge(int arr[], int low, int count, bool ascending) {
        if (count > 1) {
            int mid = count / 2;
            for (int i = low; i < low + mid; ++i) {
                if ((arr[i] > arr[i + mid]) == ascending) {
                    std::swap(arr[i], arr[i + mid]);
                }
            }
            bitonicMerge(arr, low, mid, ascending);
            bitonicMerge(arr, low + mid, mid, ascending);
        }
    }

    static void bitonicSortRecursive(int arr[], int low, int count, bool ascending) {
        if (count > 1) {
            int mid = count / 2;
            bitonicSortRecursive(arr, low, mid, !ascending);
            bitonicSortRecursive(arr, low + mid, mid, ascending);
            bitonicMerge(arr, low, count, ascending);
        }
    }

public:
    // Odd-Even Merge Sort
    static void oddEvenMergeSort(int arr[], int size, bool ascending) {
        oddEvenMergeSortRecursive(arr, 0, size - 1, ascending);
    }

private:
    // Helper functions for Odd-Even Merge Sort
    static void oddEvenMerge(int arr[], int left, int mid, int right, bool ascending) {
        int n1 = mid - left + 1;
        int n2 = right - mid;

        int L[n1], R[n2];

        for (int i = 0; i < n1; i++)
            L[i] = arr[left + i];
        for (int j = 0; j < n2; j++)
            R[j] = arr[mid + 1 + j];

        int i = 0, j = 0, k = left;
        while (i < n1 && j < n2) {
            if ((L[i] <= R[j]) == ascending) {
                arr[k++] = L[i++];
            } else {
                arr[k++] = R[j++];
            }
        }

        while (i < n1) {
            arr[k++] = L[i++];
        }

        while (j < n2) {
            arr[k++] = R[j++];
        }
    }

    static void oddEvenMergeSortRecursive(int arr[], int left, int right, bool ascending) {
        if (left < right) {
            int mid = left + (right - left) / 2;

            oddEvenMergeSortRecursive(arr, left, mid, ascending);
            oddEvenMergeSortRecursive(arr, mid + 1, right, ascending);

            oddEvenMerge(arr, left, mid, right, ascending);
        }
    }

public:
    // Bogo Sort
    static void bogoSort(int arr[], int size, bool ascending) {
        while (!std::is_sorted(arr, arr + size)) {
            std::random_shuffle(arr, arr + size);
        }
    }

    // Pancake Sort, Stooge Sort, Sleep Sort, Cycle Sort, Cocktail Sort, Gnome Sort...
    // Implementation for other sorting algorithms would go here
};
public:
    // Pancake Sort
    static void pancakeSort(int arr[], int size, bool ascending) {
        for (int curr_size = size; curr_size > 1; --curr_size) {
            int max_index = getMaxIndex(arr, curr_size);
            if (max_index != curr_size - 1) {
                flip(arr, max_index);
                flip(arr, curr_size - 1);
            }
        }
    }

    static int getMaxIndex(int arr[], int n) {
        int max_index = 0;
        for (int i = 0; i < n; ++i) {
            if (arr[i] > arr[max_index]) {
                max_index = i;
            }
        }
        return max_index;
    }

    static void flip(int arr[], int i) {
        int start = 0;
        while (start < i) {
            std::swap(arr[start], arr[i]);
            start++;
            i--;
        }
    }

public:
    // Stooge Sort
    static void stoogeSort(int arr[], int size, bool ascending) {
        stoogeSortRecursive(arr, 0, size - 1, ascending);
    }

private:
    // Helper functions for Stooge Sort
    static void stoogeSortRecursive(int arr[], int low, int high, bool ascending) {
        if (low >= high) {
            return;
        }

        if ((arr[low] > arr[high]) == ascending) {
            std::swap(arr[low], arr[high]);
        }

        if (high - low + 1 > 2) {
            int t = (high - low + 1) / 3;
            stoogeSortRecursive(arr, low, high - t, ascending);
            stoogeSortRecursive(arr, low + t, high, ascending);
            stoogeSortRecursive(arr, low, high - t, ascending);
        }
    }
public:
    // Cycle Sort
    static void cycleSort(int arr[], int size, bool ascending) {
        for (int cycle_start = 0; cycle_start < size - 1; ++cycle_start) {
            int item = arr[cycle_start];
            int pos = cycle_start;

            for (int i = cycle_start + 1; i < size; ++i) {
                if ((arr[i] < item) == ascending) {
                    ++pos;
                }
            }

            if (pos == cycle_start) {
                continue;
            }

            while (item == arr[pos]) {
                ++pos;
            }

            if (pos != cycle_start) {
                std::swap(item, arr[pos]);
            }

            while (pos != cycle_start) {
                pos = cycle_start;
                for (int i = cycle_start + 1; i < size; ++i) {
                    if ((arr[i] < item) == ascending) {
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

public:
    // Cocktail Sort
    static void cocktailSort(int arr[], int size, bool ascending) {
        bool swapped = true;
        int start = 0;
        int end = size - 1;

        while (swapped) {
            swapped = false;

            for (int i = start; i < end; ++i) {
                if ((arr[i] > arr[i + 1]) == ascending) {
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
                if ((arr[i] > arr[i + 1]) == ascending) {
                    std::swap(arr[i], arr[i + 1]);
                    swapped = true;
                }
            }

            ++start;
        }
    }

public:
    // Gnome Sort
    static void gnomeSort(int arr[], int size, bool ascending) {
        int index = 0;

        while (index < size) {
            if (index == 0) {
                ++index;
            }

            if (((arr[index] >= arr[index - 1]) == ascending)) {
                ++index;
            } else {
                std::swap(arr[index], arr[index - 1]);
                --index;
            }
        }
    }

#endif // SORTING_NETWORKS_H
