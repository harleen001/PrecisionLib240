#ifndef SMART_POINTERS_H
#define SMART_POINTERS_H

#include <iostream>
#include <memory>

class MyClass {
public:
    MyClass(int value) : data(value) {
        std::cout << "Constructor. Data: " << data << std::endl;
    }

    ~MyClass() {
        std::cout << "Destructor. Data: " << data << std::endl;
    }

    void printData() const {
        std::cout << "Data: " << data << std::endl;
    }

private:
    int data;
};

#endif // SMART_POINTERS_H
