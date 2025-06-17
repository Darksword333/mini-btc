#ifndef BLOCKCHAIN_HPP
#define BLOCKCHAIN_HPP

#include "block.hpp"
#include "transaction.hpp"
#include <vector>

class Blockchain {
private:
    std::vector<Block> chain;

public:
    Blockchain(); // crée le bloc genesis
    void addBlock(const std::string& data);
    const Block& getLastBlock() const;
    void print() const;
    void addTransaction(const Transaction& tx);
};
#endif // BLOCKCHAIN_HPP