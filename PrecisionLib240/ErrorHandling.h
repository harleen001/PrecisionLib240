#ifndef ERROR_HANDLING_H
#define ERROR_HANDLING_H

#include <iostream>

void handleInvalidInputError(const char* message) {
    std::cerr << "Invalid input error: " << message << std::endl;
}

void handleFileOpenError(const char* filename) {
    std::cerr << "Failed to open file: " << filename << std::endl;
}

void handleFileReadError(const char* filename) {
    std::cerr << "Failed to read from file: " << filename << std::endl;
}

void handleFileWriteError(const char* filename) {
    std::cerr << "Failed to write to file: " << filename << std::endl;
}

void handleMemoryAllocationError() {
    std::cerr << "Memory allocation error" << std::endl;
}

void handleNetworkError(int errorCode) {
    std::cerr << "Network error with code: " << errorCode << std::endl;
}

void handleDatabaseError(int errorCode) {
    std::cerr << "Database error with code: " << errorCode << std::endl;
}

void handleThreadCreationError() {
    std::cerr << "Thread creation error" << std::endl;
}

void handleAssertionFailure(const char* expression) {
    std::cerr << "Assertion failed: " << expression << std::endl;
}

void handleUnexpectedError() {
    std::cerr << "An unexpected error occurred" << std::endl;
}

#endif /* ERROR_HANDLING_H */
