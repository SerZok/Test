// CWE-120: Копирование в буфер без проверки размера входных данных
#include "buffer_overflow.h"
#include <cstring>
#include <iostream>

void process_user_input(const char *input)
{
    char buffer[64];
    // Уязвимость: нет проверки длины input перед копированием
    strcpy(buffer, input); // ПЛОХО: может переполнить buffer
    std::cout << "Обработано: " << buffer << std::endl;
}

// Безопасная версия для сравнения (проверка на ложные срабатывания)
void process_user_input_safe(const char *input)
{
    char buffer[64];
    strncpy(buffer, input, sizeof(buffer) - 1);
    buffer[sizeof(buffer) - 1] = '\0';
    std::cout << "Обработано (безопасно): " << buffer << std::endl;
}