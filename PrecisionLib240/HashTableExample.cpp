// Example.cpp
#include <iostream>
#include "HashTable.h"

int main() {
    HashTable table;
    createHashTable(table, 10);

    insertIntoHashTable(table, 5, 50);
    insertIntoHashTable(table, 15, 150);
    insertIntoHashTable(table, 25, 250);

    int value;
    if (searchInHashTable(table, 15, value)) {
        std::cout << "Value found: " << value << std::endl;
    } else {
        std::cout << "Value not found!" << std::endl;
    }

    removeFromHashTable(table, 5);

    std::cout << "Table size: " << getHashTableSize(table) << std::endl;
    std::cout << "Table capacity: " << getHashTableCapacity(table) << std::endl;
    std::cout << "Is table empty? " << (isHashTableEmpty(table) ? "Yes" : "No") << std::endl;

    std::cout << "Load factor: " << getLoadFactor(table) << std::endl;

    resizeHashTable(table, 5);

    return 0;
}
