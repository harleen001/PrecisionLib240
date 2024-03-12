#include "smart_pointers.h"

int main() {
    // Using std::unique_ptr
    std::unique_ptr<MyClass> uniquePtr = std::make_unique<MyClass>(42);
    uniquePtr->printData();  // Accessing object through unique_ptr

    // Using std::shared_ptr
    std::shared_ptr<MyClass> sharedPtr1 = std::make_shared<MyClass>(10);
    std::shared_ptr<MyClass> sharedPtr2 = sharedPtr1;  // Shared ownership
    sharedPtr1->printData();
    sharedPtr2->printData();

    // Using std::weak_ptr
    std::weak_ptr<MyClass> weakPtr = sharedPtr1;  // Weak reference to sharedPtr1
    std::shared_ptr<MyClass> sharedPtr3 = weakPtr.lock();  // Convert weak_ptr to shared_ptr
    if (sharedPtr3) {
        sharedPtr3->printData();
    } else {
        std::cout << "Object has been deleted." << std::endl;
    }

    // Automatic memory management when smart pointers go out of scope

    return 0;
}
