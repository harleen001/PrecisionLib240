#include <iostream>
#include "MemoryManagement.h"

int main() {
    // Example usage of memory management functions
    void* ptr1 = customMalloc(100 * sizeof(int));
    customFree(ptr1);

    int totalMemory = getTotalSystemMemory();
    int availableMemory = getAvailableMemory();

    std::cout << "Total system memory: " << totalMemory << " MB" << std::endl;
    std::cout << "Available memory: " << availableMemory << " MB" << std::endl;

    void* contiguousMemory = allocateContiguousMemory(500);
    deallocateMemory(contiguousMemory);

    void* virtualMemory = allocateVirtualMemory(800);
    deallocateMemory(virtualMemory);

    void* alignedMemory = allocateAlignedMemory(100, 16);
    deallocateMemory(alignedMemory);

    void* sharedMemory = allocateSharedMemory(1000, "sharedMemoryName");
    deallocateMemory(sharedMemory);

    return 0;
}
