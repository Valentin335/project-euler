// Corrigé de référence — « Valeur ou référence ».
#include "valref.hpp"

void double_par_copie(int x) {
    x *= 2;  // modifie la copie locale : invisible chez l'appelant
}

void double_par_reference(int& x) {
    x *= 2;  // modifie directement la variable de l'appelant
}

void ajoute_a_tous(std::vector<int>& v, int delta) {
    for (auto& e : v) {  // auto& : référence sur chaque élément → modification en place
        e += delta;
    }
}
