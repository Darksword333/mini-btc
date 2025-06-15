#include "keypair.hpp"
#include <random>
#include <ctime>

KeyPair::KeyPair() {
    privateKey = generateRandomKey();
    publicKey = computeHash(); // derive la clé publique à partir de la clé privée
}

std::string KeyPair::generateRandomKey() {
    static const char charset[] = "0123456789" "ABCDEFGHIJKLMNOPQRSTUVWXYZ" "abcdefghijklmnopqrstuvwxyz";
    std::string result;
    std::default_random_engine rng(std::random_device{}());
    std::uniform_int_distribution<> dist(0, sizeof(charset) - 2);

    for (int i = 0; i < 32; ++i)
        result += charset[dist(rng)];

    return result;
}

const std::string& KeyPair::getPrivateKey() const {
    return privateKey;
}

const std::string& KeyPair::getPublicKey() const {
    return publicKey;
}

// Fonction qui calcule un "hash" simplifié avec XOR bit à bit sur chaque caractère
std::string KeyPair::computeHash() const {
    uint64_t time = static_cast<uint64_t>(std::time(nullptr));
    std::string fullData = privateKey + std::to_string(time);

    std::string hashHex;
    hashHex.reserve(fullData.size() * 2);

    for (size_t i = 0; i < fullData.size(); ++i) {
        uint8_t xored = fullData[i] ^ fullData[(i + 1) % fullData.size()];

        char buf[3]; // 2 pour les chiffres hex + 1 pour le '\0'
        std::snprintf(buf, sizeof(buf), "%02x", xored);

        hashHex.append(buf);
    }

    return hashHex;
}