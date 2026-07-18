#pragma once

#ifndef COMMAND_INJECTION_H
#define COMMAND_INJECTION_H

#include <string>

void execute_command(const std::string &user_input);
void execute_command_safe(const std::string &user_input);

#endif // COMMAND_INJECTION_H