#ifndef MOVE_SEMANTICS_H
#define MOVE_SEMANTICS_H

#include <iostream>

class Resource {
private:
    int* data;

public:
    Resource() : data(nullptr) {}
    explicit Resource(int val) : data(new int(val)) {}
    
    // Move constructor
    Resource(Resource&& other) noexcept : data(other.data) {
        other.data = nullptr; // Reset the source object
    }
    
    // Move assignment operator
    Resource& operator=(Resource&& other) noexcept {
        if (this != &other) {
            delete data; // Release existing resource
            data = other.data;
            other.data = nullptr; // Reset the source object
        }
        return *this;
    }
    
    // Destructor
    ~Resource() {
        delete data;
    }

    int getValue() const {
        return (data != nullptr) ? *data : 0;
    }
};

#endif // MOVE_SEMANTICS_H
