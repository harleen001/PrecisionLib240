#ifndef STL_ALGORITHMS_H
#define STL_ALGORITHMS_H

#include <algorithm>
#include <vector>

namespace STLAlgorithms {
    // Function to sort a vector using std::sort
    template<typename T>
    void sort(std::vector<T>& vec) {
        std::sort(vec.begin(), vec.end());
    }

    // Function to find an element in a vector using std::find
    template<typename T>
    typename std::vector<T>::iterator find(std::vector<T>& vec, const T& value) {
        return std::find(vec.begin(), vec.end(), value);
    }

    // Function to apply a transformation on elements of a vector using std::transform
    template<typename InputIterator, typename OutputIterator, typename UnaryOperation>
    OutputIterator transform(InputIterator first, InputIterator last, OutputIterator result, UnaryOperation op) {
        return std::transform(first, last, result, op);
    }
}

#endif // STL_ALGORITHMS_H
