#include "blockchain.hpp"

int main(void){
    Blockchain blockchain;

    // Ajout de quelques blocs
    blockchain.addBlock("Transaction A -> B: 10 BTC");
    blockchain.addBlock("Transaction B -> C: 5 BTC");
    blockchain.addBlock("Transaction C -> A: 2 BTC");

    // Affichage de la chaîne de blocs
    blockchain.print();

    return 0;
}