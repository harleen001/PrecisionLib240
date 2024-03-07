#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include  "sha.h"

std::string sha256(const std::string& input) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, input.c_str(), input.length());
    SHA256_Final(hash, &sha256);

    std::stringstream ss;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        ss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
    }

    return ss.str();
}

std::string buildMerkleTree(const std::vector<std::string>& data) {
    std::vector<std::vector<std::string>> levels;
    levels.push_back(data);

    while (levels.back().size() > 1) {
        std::vector<std::string> currentLevel;
        for (size_t i = 0; i < levels.back().size(); i += 2) {
            std::string concatHash = levels.back()[i];
            if (i + 1 < levels.back().size()) {
                concatHash += levels.back()[i + 1];
            }
            currentLevel.push_back(sha256(concatHash));
        }
        levels.push_back(currentLevel);
    }

    return levels.back()[0];
}

int main() {
    std::vector<std::string> userInputs;
    int numBlocks;

    std::cout << "Enter the number of data blocks: ";
    std::cin >> numBlocks;

    std::cout << "Enter data for each block:\n";
    for (int i = 0; i < numBlocks; ++i) {
        std::string data;
        std::cout << "Block " << i + 1 << ": ";
        std::cin >> data;
        userInputs.push_back(sha256(data));
    }

    std::string rootHash = buildMerkleTree(userInputs);

    std::cout << "\nMerkle Tree Root Hash: " << rootHash << std::endl;

    return 0;
}
