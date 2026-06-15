#pragma once
// NE PAS MODIFIER : signatures imposées.
#include <stdexcept>

bool try_sqrt_int(int n, int& out);  // n, out -> true + out=racine si n>=0 et carré parfait ; false sinon (code retour)
int checked_sqrt_int(int n);          // n -> racine entière ; throw std::domain_error si n<0, std::invalid_argument si pas un carré parfait
