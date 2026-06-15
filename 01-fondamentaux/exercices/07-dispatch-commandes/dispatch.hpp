#pragma once
// NE PAS MODIFIER : signatures imposées.
#include <string>

// cmd, n → "info n" ('i'), "double 2n" ('d'), "neg -n" ('n'), sinon "inconnu".
std::string apply_command(char cmd, int n);
