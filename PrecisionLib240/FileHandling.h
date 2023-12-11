#ifndef FILEHANDLING_H
#define FILEHANDLING_H

#include <iostream>
#include <fstream>
#include <cstring>

// Function declarations
bool fileExists(const char* filename);
bool createFile(const char* filename);
bool deleteFile(const char* filename);
int getFileSize(const char* filename);
void readFromFile(const char* filename, char* buffer, int bufferSize);
void writeToFile(const char* filename, const char* data);
void appendToFile(const char* filename, const char* data);
void copyFile(const char* sourceFilename, const char* destinationFilename);
void moveFile(const char* sourceFilename, const char* destinationFilename);
bool renameFile(const char* oldFilename, const char* newFilename);

// Function implementations
bool fileExists(const char* filename) {
    std::ifstream file(filename);
    return file.good();
}

bool createFile(const char* filename) {
    std::ofstream file(filename);
    return file.is_open();
}

bool deleteFile(const char* filename) {
    if (std::remove(filename) != 0) {
        return false;
    }
    return true;
}

int getFileSize(const char* filename) {
    std::ifstream file(filename, std::ifstream::ate | std::ifstream::binary);
    return file.tellg();
}

void readFromFile(const char* filename, char* buffer, int bufferSize) {
    std::ifstream file(filename);
    if (file.is_open()) {
        file.read(buffer, bufferSize - 1);
        buffer[file.gcount()] = '\0';
        file.close();
    }
}

void writeToFile(const char* filename, const char* data) {
    std::ofstream file(filename);
    if (file.is_open()) {
        file << data;
        file.close();
    }
}

void appendToFile(const char* filename, const char* data) {
    std::ofstream file(filename, std::ios::app);
    if (file.is_open()) {
        file << data;
        file.close();
    }
}

void copyFile(const char* sourceFilename, const char* destinationFilename) {
    std::ifstream source(sourceFilename, std::ios::binary);
    std::ofstream destination(destinationFilename, std::ios::binary);

    if (source.is_open() && destination.is_open()) {
        destination << source.rdbuf();
        source.close();
        destination.close();
    }
}

void moveFile(const char* sourceFilename, const char* destinationFilename) {
    if (rename(sourceFilename, destinationFilename) != 0) {
        std::cerr << "Error: Unable to move file." << std::endl;
    }
}

bool renameFile(const char* oldFilename, const char* newFilename) {
    if (std::rename(oldFilename, newFilename) != 0) {
        return false;
    }
    return true;
}

#endif // FILEHANDLING_H
