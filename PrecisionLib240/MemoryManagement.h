#ifndef MEMORY_MANAGEMENT_H
#define MEMORY_MANAGEMENT_H

#include <iostream>
#include <cstdlib>

void* customMalloc(size_t size) {
    return std::malloc(size);
}

void customFree(void* ptr) {
    std::free(ptr);
}

void* customRealloc(void* ptr, size_t size) {
    return std::realloc(ptr, size);
}

int getTotalSystemMemory() {
    return 16'000; // Example value, replace with actual system memory size retrieval
}

int getAvailableMemory() {
    return 8'000; // Example value, replace with actual available memory retrieval
}

void* allocateContiguousMemory(size_t size) {
    return std::malloc(size);
}

void* allocateVirtualMemory(size_t size) {
    return std::malloc(size);
}

void deallocateMemory(void* ptr) {
    std::free(ptr);
}

void* allocateAlignedMemory(size_t size, size_t alignment) {
    const size_t totalSize = size + alignment - 1 + sizeof(void*);
    void* raw = std::malloc(totalSize);

    if (raw == nullptr) {
        return nullptr;
    }

    uintptr_t rawAddress = reinterpret_cast<uintptr_t>(raw) + alignment - 1 + sizeof(void*);
    void* aligned = reinterpret_cast<void*>(rawAddress - (rawAddress % alignment));

    (reinterpret_cast<void**>(aligned))[-1] = raw;
    return aligned;
}

void deallocateAlignedMemory(void* ptr) {
    if (ptr != nullptr) {
        std::free((reinterpret_cast<void**>(ptr))[-1]);
    }
}



void* allocateSharedMemory(size_t size, const char* name) {
    // Implementation for shared memory allocation
    return nullptr;
}

#endif /* MEMORY_MANAGEMENT_H */
