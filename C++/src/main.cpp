#include <iostream>
#include "buffer_overflow.h"
#include "command_injection.h"
#include "use_after_free.h"
#include "weak_crypto.h"
#include "hardcoded_secrets.h"

int main()
{
    std::cout << "=== Тест-суйт для проверки безопасности ===" << std::endl;

    // Тест переполнения буфера
    std::cout << "\n1. Тестирование переполнения буфера..." << std::endl;
    process_user_input("short_input");
    process_user_input_safe("short_input");

    // Тест инъекции команд
    std::cout << "\n2. Тестирование инъекции команд..." << std::endl;
    execute_command("test");
    execute_command_safe("test");

    // Тест use-after-free
    std::cout << "\n3. Тестирование use-after-free..." << std::endl;
    Data *d = create_data(10);
    process_data(d);

    // Тест слабой криптографии
    std::cout << "\n4. Тестирование слабой криптографии..." << std::endl;
    std::string hash = hash_password_weak("password123");
    std::cout << "MD5 hash: " << hash << std::endl;
    encrypt_data_weak("sensitive_data", "key");

    // Тест захардкоженных секретов
    std::cout << "\n5. Тестирование захардкоженных секретов..." << std::endl;
    bool auth = authenticate("admin", "SuperSecretPassword123!");
    std::cout << "Результат аутентификации: " << (auth ? "успех" : "неудача") << std::endl;
    std::cout << "API ключ: " << get_api_key() << std::endl;

    return 0;
}