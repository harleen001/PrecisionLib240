#include <iostream>
#include "ErrorHandling.h"

int main() {
    // Example usage of error handling functions
    handleInvalidInputError("Invalid input provided");
    handleFileOpenError("example.txt");
    handleFileReadError("example.txt");
    handleFileWriteError("example.txt");
    handleMemoryAllocationError();
    handleNetworkError(404);
    handleDatabaseError(500);
    handleThreadCreationError();
    handleAssertionFailure("x > 5");
    handleUnexpectedError();

    return 0;
}
