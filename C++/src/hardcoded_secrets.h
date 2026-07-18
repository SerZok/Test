#ifndef HARDCODED_SECRETS_H
#define HARDCODED_SECRETS_H

#include <string>

bool authenticate(const std::string &user, const std::string &password);
std::string get_api_key();

#endif // HARDCODED_SECRETS_H