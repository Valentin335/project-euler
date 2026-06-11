#pragma once
// =====================================================================
// rotation.hpp — signatures imposées de l'exercice "Échange & rotation".
// NE PAS MODIFIER ce fichier : il fixe le contrat que tes fonctions
// doivent respecter. Tu implémentes le corps dans rotation_skeleton.cpp.
// =====================================================================

// Échange les valeurs de a et b (par référence).
// Interdit : std::swap, std::exchange.
void swap_ints(int& a, int& b);

// Fait tourner les trois entiers vers la gauche : (a, b, c) -> (b, c, a).
// Interdit : std::swap, std::exchange.
void rotate_left(int& a, int& b, int& c);
