#ifndef KEYPAIR_HPP
#define KEYPAIR_HPP

#include <string>

class KeyPair {
private:

    std::string privateKey;
    std::string publicKey;
    std::string generateRandomKey();
    std::string computeHash() const;

public:

    KeyPair();

    const std::string& getPrivateKey() const;
    const std::string& getPublicKey() const;

};
#endif // KEYPAIR_HPP