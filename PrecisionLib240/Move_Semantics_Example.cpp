#include <iostream>
#include "move_semantics.h"

int main() {
    // Create a resource object
    Resource originalResource(100);
    std::cout << "Original Resource Value: " << originalResource.getValue() << std::endl;

    // Transfer ownership using move constructor
    Resource transferredResource = std::move(originalResource);
    std::cout << "Transferred Resource Value: " << transferredResource.getValue() << std::endl;

    // Try accessing the original resource after transfer
    std::cout << "Original Resource Value after transfer: " << originalResource.getValue() << std::endl;

    // Create another resource object
    Resource newResource(200);
    std::cout << "New Resource Value: " << newResource.getValue() << std::endl;

    // Transfer ownership using move assignment operator
    newResource = std::move(transferredResource);
    std::cout << "New Resource Value after transfer: " << newResource.getValue() << std::endl;

    return 0;
}
