#ifndef BLOCKCHAIN_HPP
#define BLOCKCHAIN_HPP

#include "block.hpp"
#include <vector>

class Blockchain {
private:
    std::vector<Block> chain;

public:
    Blockchain(); // crée le bloc genesis
    void addBlock(const std::string& data);
    const Block& getLastBlock() const;
    void print() const;
};
#endif // BLOCKCHAIN_HPP