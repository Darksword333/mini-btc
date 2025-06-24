#include "block.hpp"
#include "picosha2.h"
#include <sstream>
#include <cstdio>
#include <ctime>
#include <iostream>

Block::Block(int idx, const std::string& prevHash)
    : index(idx), previousHash(prevHash)
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

std::string Block::computeHash() const {
    std::string fullData = std::to_string(index) + previousHash + std::to_string(timestamp) + std::to_string(nonce);
    return picosha2::hash256_hex_string(fullData);
}

void Block::mineBlock(int difficulty) {
    nonce = 0;
    while (true) {
        hash = computeHash();
        bool valid = true;
        for (int i = 0; i < difficulty; ++i) {
            if (hash[i] != '0') {
                valid = false;
                break;
            }
        }
        if (valid) break;
        ++nonce;
    }
    std::cout << "Block mined: " << hash << " (nonce = " << nonce << ")\n";
}

void Block::addTransaction(const Transaction& tx) {
    transactions.push_back(tx);
}

void Block::print() const {
    std::cout << "Index: " << index << "\n"
              << "Previous Hash: " << previousHash << "\n"
              << "Transactions:\n";
    for (const auto& tx : transactions) {
        std::cout << "  From: " << tx.getFrom()
                  << ", To: " << tx.getTo()
                  << ", Amount: " << tx.getAmount() << "\n";
    }
    std::cout << "Hash: " << hash << "\n"
              << "Timestamp: " << timestamp << "\n";
}