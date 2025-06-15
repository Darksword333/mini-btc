#include "blockchain.hpp"
#include <iostream>

Blockchain::Blockchain() {
    // Bloc Genesis : index 0, data = "Genesis", previous hash = "0"
    chain.emplace_back(0, "Genesis Block", "0");
}

void Blockchain::addBlock(const std::string& data) {
    const Block& prev = getLastBlock();
    chain.emplace_back(prev.getIndex() + 1, data, prev.getHash());
}

const Block& Blockchain::getLastBlock() const {
    return chain.back();
}

void Blockchain::print() const {
    for (const Block& block : chain) {
        std::cout << "----------------------\n";
        block.print();
    }
}
