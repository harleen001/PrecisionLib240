#ifndef STL_ALGORITHMS_WITH_RAII_H
#define STL_ALGORITHMS_WITH_RAII_H

#include <algorithm>
#include <fstream>
#include <vector>
#include <stdexcept>

namespace STLAlgorithmsWithRAII {
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

    // RAII wrapper for file handling
    class FileWrapper {
    private:
        std::fstream file;

    public:
        // Constructor opens the file
        FileWrapper(const std::string& filename) : file(filename) {
            if (!file.is_open()) {
                throw std::runtime_error("Failed to open file");
            }
        }

        // Destructor closes the file
        ~FileWrapper() {
            if (file.is_open()) {
                file.close();
            }
        }

        // Function to get the file stream
        std::fstream& getStream() {
            return file;
        }
    };
}

#endif // STL_ALGORITHMS_WITH_RAII_H
