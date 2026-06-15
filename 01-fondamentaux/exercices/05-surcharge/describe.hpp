#pragma once
// NE PAS MODIFIER — signatures imposées.
#include <string>

std::string describe(int n);                 // 42        → "entier 42"
std::string describe(double d);              // 3.5       → "flottant ..."
std::string describe(const std::string& s);  // "bonjour"  → "texte: bonjour"
std::string describe(bool b);                // true      → "booleen vrai"
