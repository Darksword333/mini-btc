#ifndef BLOCKCHAIN_HPP
#define BLOCKCHAIN_HPP

#include "block.hpp"
#include "consensus.hpp"
#include "transaction.hpp"
#include <vector>

class Blockchain {
private:
    std::vector<Block> chain;
    std::vector<Transaction> mempool;

public:
    Blockchain(); // crée le bloc genesis
    void addBlock(const std::string& data);
    const Block& getLastBlock() const;
    void print() const;
    void addTransaction(const Transaction& tx);
    void minePendingTransactions(const std::string& minerAddress, size_t maxTx);
    double getBalance(const std::string& publicKey) const;
};
#endif // BLOCKCHAIN_HPP