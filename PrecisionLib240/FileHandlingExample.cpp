#include <iostream>
#include "FileHandling.h"

int main() {
    const char* filename = "test.txt";
    const char* data = "Hello, this is a test.";

    // Test the functions
    if (createFile(filename)) {
        std::cout << "File created successfully." << std::endl;
    } else {
        std::cout << "Failed to create file." << std::endl;
    }

    if (fileExists(filename)) {
        std::cout << "File exists." << std::endl;
    } else {
        std::cout << "File doesn't exist." << std::endl;
    }

    writeToFile(filename, data);

    int fileSize = getFileSize(filename);
    std::cout << "File size: " << fileSize << " bytes." << std::endl;

    char buffer[100];
    readFromFile(filename, buffer, sizeof(buffer));
    std::cout << "File content: " << buffer << std::endl;

    const char* newData = " Appended data.";
    appendToFile(filename, newData);

    char newBuffer[100];
    readFromFile(filename, newBuffer, sizeof(newBuffer));
    std::cout << "Updated file content: " << newBuffer << std::endl;

    const char* newFilename = "new_test.txt";
    copyFile(filename, newFilename);

    moveFile(newFilename, "moved_test.txt");

    if (renameFile("moved_test.txt", "renamed_test.txt")) {
        std::cout << "File renamed successfully." << std::endl;
    } else {
        std::cout << "Failed to rename file." << std::endl;
    }

    if (deleteFile("renamed_test.txt")) {
        std::cout << "File deleted successfully." << std::endl;
    } else {
        std::cout << "Failed to delete file." << std::endl;
    }

    return 0;
}
