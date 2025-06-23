#include "blockchain.hpp"
#include "transaction.hpp"
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

void Blockchain::addTransaction(const Transaction& tx) {
    mempool.push_back(tx);
    std::cout << "Transaction ajoutée : From " << tx.getFrom()
              << " To " << tx.getTo()
              << " Amount: " << tx.getAmount() << "\n";
}

void Blockchain::minePendingTransactions(size_t maxTx) {
    if (mempool.empty()) return;
    size_t txCount = std::min(TRANSACTION_PER_BLOCK, mempool.size());
    std::string data;
    for (size_t i = 0; i < txCount; ++i) {
        const Transaction& tx = mempool[i];
        data += "Transaction: From: " + tx.getFrom()
              + " To: " + tx.getTo()
              + " Amount: " + std::to_string(tx.getAmount()) + "\n";
    }
    int newIndex = chain.size();
    std::string previousHash = chain.back().getHash();
    Block newBlock(newIndex, data, previousHash);
    newBlock.mineBlock(MINING_DIFFICULTY);
    chain.push_back(newBlock);
    mempool.erase(mempool.begin(), mempool.begin() + txCount);
}
