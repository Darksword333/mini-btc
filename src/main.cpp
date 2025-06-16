#include "blockchain.hpp"
#include "transaction.hpp"
#include "keypair.hpp"

int main(void){
    Blockchain blockchain;
    KeyPair key1;
    KeyPair key2;

    std::string from = key1.getPublicKey();
    std::string to = key2.getPublicKey();

    Transaction tx(from, to, 10.0);
    std::string txData = "Transaction " + from + " -> " + to + " : 10 BTC";

    blockchain.addBlock(txData);

    tx.print();
    blockchain.print();

    return 0;
}
