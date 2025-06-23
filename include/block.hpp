#ifndef BLOCK_HPP
#define BLOCK_HPP

#include <string>
#include <cstdint>

struct Block {
    int index;                     // Position du bloc dans la chaîne
    std::string data;             // Données du bloc
    std::string previousHash;     // Hash du bloc précédent
    std::string hash;             // Hash actuel
    uint64_t timestamp;            // Epoch time du bloc
    uint64_t nonce;                 // Nonce pour le calcul du hash

    Block(int idx, const std::string& data, const std::string& prevHash);

    std::string computeHash() const;
    void mineBlock(int difficulty);
    void print() const;

    int getIndex() const;
    std::string getHash() const;
};

#endif // BLOCK_HPP