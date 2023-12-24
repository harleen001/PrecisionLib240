// HashTable.h
#pragma once
#include <vector>
#include <list>
#include <utility>

struct HashTable {
    std::vector<std::list<std::pair<int, int>>> buckets;
    int size;
};

void createHashTable(HashTable& table, int size) {
    table.size = size;
    table.buckets.resize(size);
}

size_t customHashFunction(int key, int size) {
    return key % size;
}

void insertIntoHashTable(HashTable& table, int key, int value) {
    size_t index = customHashFunction(key, table.size);
    table.buckets[index].push_back({key, value});
}

bool searchInHashTable(const HashTable& table, int key, int& value) {
    size_t index = customHashFunction(key, table.size);
    for (const auto& pair : table.buckets[index]) {
        if (pair.first == key) {
            value = pair.second;
            return true;
        }
    }
    return false;
}

void removeFromHashTable(HashTable& table, int key) {
    size_t index = customHashFunction(key, table.size);
    auto& bucket = table.buckets[index];
    bucket.remove_if([&](const std::pair<int, int>& pair) { return pair.first == key; });
}

void clearHashTable(HashTable& table) {
    for (auto& bucket : table.buckets) {
        bucket.clear();
    }
}

int getHashTableSize(const HashTable& table) {
    return table.size;
}

int getHashTableCapacity(const HashTable& table) {
    return table.buckets.size();
}

bool isHashTableEmpty(const HashTable& table) {
    for (const auto& bucket : table.buckets) {
        if (!bucket.empty()) {
            return false;
        }
    }
    return true;
}

void resizeHashTable(HashTable& table, int newSize) {
    HashTable newTable;
    createHashTable(newTable, newSize);
    for (const auto& bucket : table.buckets) {
        for (const auto& pair : bucket) {
            insertIntoHashTable(newTable, pair.first, pair.second);
        }
    }
    table = newTable;
}

float getLoadFactor(const HashTable& table) {
    int items = 0;
    for (const auto& bucket : table.buckets) {
        items += bucket.size();
    }
    return static_cast<float>(items) / table.buckets.size();
}
