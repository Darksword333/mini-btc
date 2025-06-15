#ifndef TRANSACTION_HPP
#define TRANSACTION_HPP

#include <string>
#include <cstdint>

class Transaction {
public:
    Transaction(const std::string& from, const std::string& to, double amount);

    std::string getFrom() const;
    std::string getTo() const;
    double getAmount() const;
    uint64_t getTimestamp() const;
    std::string getHash() const;
    void print() const;

private:
    std::string fromPublicKey;
    std::string toPublicKey;
    double amount;
    uint64_t timestamp;
    std::string hash;

    std::string computeHash() const;
};

#endif // TRANSACTION_HPP
