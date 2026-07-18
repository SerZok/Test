#ifndef WEAK_CRYPTO_H
#define WEAK_CRYPTO_H

#include <string>

std::string hash_password_weak(const std::string &password);
std::string encrypt_data_weak(const std::string &data, const std::string &key);

#endif // WEAK_CRYPTO_H