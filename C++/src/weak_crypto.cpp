// CWE-327: Использование небезопасного криптографического алгоритма
#include "weak_crypto.h"
#include <iostream>

#ifdef HAS_OPENSSL
#include <openssl/md5.h>
#include <openssl/des.h>
#endif

std::string hash_password_weak(const std::string &password)
{
#ifdef HAS_OPENSSL
    // Уязвимость: использование MD5 для хеширования паролей
    unsigned char digest[MD5_DIGEST_LENGTH];
    MD5(reinterpret_cast<const unsigned char *>(password.c_str()),
        password.length(), digest);

    char output[33];
    for (int i = 0; i < 16; i++)
    {
        sprintf(output + (i * 2), "%02x", digest[i]);
    }
    return std::string(output); // ПЛОХО: MD5 небезопасен
#else
    return "md5_hash_placeholder";
#endif
}

std::string encrypt_data_weak(const std::string &data, const std::string &key)
{
    // Упрощённый пример: DES с ECB режимом (небезопасно)
    // В реальности нужно использовать AES с CBC/GCM
    std::cout << "Шифрование с помощью DES (слабо)" << std::endl;
    return "encrypted_placeholder"; // ПЛОХО: DES устарел
}