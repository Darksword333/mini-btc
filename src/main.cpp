#include "blockchain.hpp"
#include "transaction.hpp"
#include "keypair.hpp"

int main() {
    Blockchain blockchain;
    KeyPair key1;
    KeyPair key2;

    Transaction tx(key1.getPublicKey(), key2.getPublicKey(), 10.0);
    blockchain.addTransaction(tx);

    blockchain.print();

    return 0;
}

