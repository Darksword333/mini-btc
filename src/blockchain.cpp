#include "blockchain.hpp"
#include <iostream>

Blockchain::Blockchain() {
    // Bloc Genesis
    chain.emplace_back(0, "0");
}

void Blockchain::addBlock(const std::string& data) {
    const Block& prev = getLastBlock();
    chain.emplace_back(prev.getIndex() + 1, prev.getHash());
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

void Blockchain::minePendingTransactions(const std::string& minerAddress, size_t maxTx) {
    if (mempool.empty()) return;

    Block newBlock(getLastBlock().getIndex() + 1, getLastBlock().getHash());

    Transaction rewardTx("MINING", minerAddress, MINING_REWARD);
    newBlock.addTransaction(rewardTx);

    size_t txCount = 0;
    for (const Transaction& tx : mempool) {
        if (txCount >= maxTx) break;
        newBlock.addTransaction(tx);
        ++txCount;
    }

    newBlock.mineBlock(MINING_DIFFICULTY);
    chain.push_back(newBlock);

    mempool.erase(mempool.begin(), mempool.begin() + txCount);

    std::cout << "Bloc miné par " << minerAddress << " avec récompense de " << MINING_REWARD << "\n";
}