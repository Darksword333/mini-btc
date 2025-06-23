#include "blockchain.hpp"
#include "transaction.hpp"
#include "keypair.hpp"

#include <iostream>

int main() {
    std::cout << "=== Initialisation de la Blockchain ===\n";

    Blockchain blockchain;

    std::cout << "\n=== Génération de deux paires de clés ===\n";
    KeyPair key1;
    KeyPair key2;

    std::string key1Public = key1.getPublicKey();
    std::string key2Public = key2.getPublicKey();

    std::cout << "Clé publique 1 : " << key1Public << "\n";
    std::cout << "Clé publique 2 : " << key2Public << "\n";

    std::cout << "\n=== Création de transactions ===\n";
    Transaction tx1(key1Public, key2Public, 10.0);
    Transaction tx2(key2Public, key1Public, 3.5);

    blockchain.addTransaction(tx1);
    blockchain.addTransaction(tx2);

    std::cout << "\n=== Minage des transactions ===\n";
    blockchain.minePendingTransactions();

    std::cout << "\n=== État actuel de la Blockchain ===\n";
    blockchain.print();

    return 0;
}
