// CWE-798: Использование захардкоженных учётных данных
#include "hardcoded_secrets.h"

// Уязвимость: захардкоженные учётные данные
const std::string DB_PASSWORD = "SuperSecretPassword123!";
const char *API_KEY = "AKIAIOSFODNN7EXAMPLE"; // Формат AWS-ключа
const std::string PRIVATE_KEY = "-----BEGIN RSA PRIVATE KEY-----\nMIIEpAIBAAKCAQEA0Z3VS5JJcds3xfn/ygWyF8PbnGy...";

bool authenticate(const std::string &user, const std::string &password)
{
    // Уязвимость: сравнение с захардкоженным паролем
    if (user == "admin" && password == "SuperSecretPassword123!")
    {
        return true;
    }
    return false;
}

std::string get_api_key()
{
    return API_KEY; // ПЛОХО: возврат захардкоженного ключа
}