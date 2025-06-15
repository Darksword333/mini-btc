#include "block.hpp"
#include <sstream>
#include <cstdio>
#include <ctime>
#include <iostream>

Block::Block(int idx, const std::string& data, const std::string& prevHash)
    : index(idx), data(data), previousHash(prevHash)
{
    timestamp = static_cast<uint64_t>(std::time(nullptr));
    hash = computeHash();
}

int Block::getIndex() const {
    return index;
}

std::string Block::getHash() const {
    return hash;
}

// Fonction qui calcule un "hash" simplifié avec XOR bit à bit sur chaque caractère
std::string Block::computeHash() const {
    std::string fullData = std::to_string(index) + data + previousHash + std::to_string(timestamp);

    std::string hashHex;
    hashHex.reserve(fullData.size() * 2);

    for (size_t i = 0; i < fullData.size(); ++i) {
        uint8_t xored = fullData[i] ^ fullData[(i + 1) % fullData.size()];

        char buf[3]; // 2 pour les chiffres hex + 1 pour le '\0'
        std::snprintf(buf, sizeof(buf), "%02x", xored);

        hashHex.append(buf);
    }

    return hashHex;
}

void Block::print() const {
    std::cout << "Index: " << index << "\n"
              << "Data: " << data << "\n"
              << "Previous Hash: " << previousHash << "\n"
              << "Hash: " << hash << "\n"
              << "Timestamp: " << timestamp << "\n";
}