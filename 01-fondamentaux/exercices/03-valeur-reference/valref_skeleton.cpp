#include "valref.hpp"

void double_par_copie(int x) {
    /* x (copie) → modification locale invisible dehors */
    return;
}

void double_par_reference(int& x) {
    /* x (référence) → x devient 2*x chez l'appelant */
    x = 2*x;
    return;
}

void ajoute_a_tous(std::vector<int>& v, int delta) {
    /* v (référence) → chaque élément += delta, en place */
    (void)v;
    (void)delta;
    for (auto& x: v){
        x += delta;
    }
    return;
}
