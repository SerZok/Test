// CWE-78: Недостаточная нейтрализация специальных элементов в OS-команде
#include "command_injection.h"
#include <cstdlib>
#include <iostream>

void execute_command(const std::string &user_input)
{
    // Уязвимость: пользовательский ввод напрямую в system()
    std::string command = "echo " + user_input;
    system(command.c_str()); // ПЛОХО: возможна инъекция команд
}

// Безопасная версия (хотя system() всё равно не рекомендуется)
void execute_command_safe(const std::string &user_input)
{
    // Валидация ввода (упрощённый пример)
    for (char c : user_input)
    {
        if (!isalnum(c) && c != ' ' && c != '.' && c != '-')
        {
            std::cerr << "Неверный ввод" << std::endl;
            return;
        }
    }
    std::string command = "echo " + user_input;
    system(command.c_str());
}