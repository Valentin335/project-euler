#pragma once
// Signatures imposées de l'exercice 07. NE PAS MODIFIER ce fichier.
#include <string>

std::string describe(int n);                 // "entier 42"
std::string describe(double d);              // commence par "flottant "
std::string describe(const std::string& s);  // "texte: bonjour"
std::string describe(bool b);                // "booleen vrai" ou "booleen faux"
