#include "transaction.hpp"
#include "picosha2.h"
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

std::string Transaction::computeHash() const {
    std::string fullData = fromPublicKey+ toPublicKey + std::to_string(amount) + std::to_string(timestamp);
    return picosha2::hash256_hex_string(fullData);
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