#include "transaction.hpp"
#include <sstream>
#include <cstdio>
#include <ctime>
#include <iostream>

std::string Transaction::getFrom() const {
    return fromPublicKey;
}

std::string Transaction::getTo() const {
    return toPublicKey;
}

double Transaction::getAmount() const {
    return amount;
}

uint64_t Transaction::getTimestamp() const {
    return timestamp;
}

std::string Transaction::getHash() const{
    return hash;
}

// Fonction qui calcule un "hash" simplifié avec XOR bit à bit sur chaque caractère
std::string Transaction::computeHash() const {
    std::string fullData = fromPublicKey+ toPublicKey + std::to_string(amount) + std::to_string(timestamp);

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

void Transaction::print() const {
    std::cout << "From: " << fromPublicKey << "\n"
              << "To: " << toPublicKey << "\n"
              << "Amount: " << amount << "\n"
              << "Hash: " << hash << "\n"
              << "Timestamp: " << timestamp << "\n";
}

Transaction::Transaction(const std::string& from, const std::string& to, double amount)
    : fromPublicKey(from), toPublicKey(to), amount(amount)
{
    timestamp = static_cast<uint64_t>(std::time(nullptr));
    hash = computeHash();
}