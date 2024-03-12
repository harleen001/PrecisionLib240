#ifndef NEGATIVE_INDEXING_H
#define NEGATIVE_INDEXING_H

#include <vector>
#include <stdexcept>

template <typename T>
class NegativeIndexingVector {
private:
    std::vector<T> data;

public:
    // Constructor
    NegativeIndexingVector() {}

    // Function to add an element to the vector
    void push_back(const T& value) {
        data.push_back(value);
    }

    // Function to access elements using negative indexing
    T& operator[](int index) {
        if (index >= 0) {
            return data[index];
        } else {
            int positiveIndex = data.size() + index;
            if (positiveIndex >= 0 && positiveIndex < data.size()) {
                return data[positiveIndex];
            } else {
                throw std::out_of_range("Index out of range");
            }
        }
    }

    // Function to get the size of the vector
    size_t size() const {
        return data.size();
    }
};

#endif // NEGATIVE_INDEXING_H
