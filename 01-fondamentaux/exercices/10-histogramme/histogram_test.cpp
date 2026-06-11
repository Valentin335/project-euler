// =====================================================================
//  histogram_test.cpp — Tests fournis (NE PAS MODIFIER)
//
//  Compile-le avec ton histogram_skeleton.cpp pour vérifier ta
//  solution. Tant que les corps sont des bouchons, des tests échouent :
//  c'est normal. Ton but est de tous les faire passer.
// =====================================================================

#include "check.hpp"
#include "histogram.hpp"

#include <string>
#include <vector>
#include <cstddef>   // std::size_t

int main()
{
    // --- count_char --------------------------------------------------
    CHECK_EQ(count_char("banana", 'a'), 3);
    CHECK_EQ(count_char("xyz", 'a'), 0);
    CHECK_EQ(count_char("", 'a'), 0);

    // --- count_char : cas limites ------------------------------------
    // Doublons consecutifs : les trois 'a' doivent etre comptes.
    CHECK_EQ(count_char("aaa", 'a'), 3);
    // count_char compare le CHAR EXACT : il est sensible a la casse.
    // Dans "Aa", seul le 'a' minuscule correspond a 'a' : on attend 1.
    CHECK_EQ(count_char("Aa", 'a'), 1);
    // Symetrie : dans "Aa", un seul 'A' majuscule correspond a 'A'.
    CHECK_EQ(count_char("Aa", 'A'), 1);

    // --- char_histogram ----------------------------------------------
    auto h = char_histogram("aAbB!");
    CHECK_EQ(h.size(), std::size_t{26});
    CHECK_EQ(h[0], 2);   // 'a' et 'A'
    CHECK_EQ(h[1], 2);   // 'b' et 'B'
    CHECK_EQ(h[2], 0);   // 'c' : absent

    // --- char_histogram : cas limites --------------------------------
    // Chaine vide : un histogramme de taille 26 entierement a zero.
    auto vide = char_histogram("");
    CHECK_EQ(vide.size(), std::size_t{26});
    for (std::size_t i = 0; i < vide.size(); ++i) {
        CHECK_EQ(vide[i], 0);
    }

    // Phrase melangee (casse + ponctuation + espace ignores).
    // "Hello, World!" en minuscules : h,e,l,l,o,w,o,r,l,d.
    auto hw = char_histogram("Hello, World!");
    CHECK_EQ(hw.size(), std::size_t{26});
    // Verification de l'indexation : 'a' == indice 0, donc 'x' == 'x'-'a'.
    CHECK_EQ(hw['h' - 'a'], 1);   // un seul 'h' (le 'H' majuscule)
    CHECK_EQ(hw['e' - 'a'], 1);   // un seul 'e'
    CHECK_EQ(hw['l' - 'a'], 3);   // trois 'l'
    CHECK_EQ(hw['o' - 'a'], 2);   // deux 'o'
    CHECK_EQ(hw['w' - 'a'], 1);   // un 'w' (le 'W' majuscule)
    CHECK_EQ(hw['r' - 'a'], 1);   // un 'r'
    CHECK_EQ(hw['d' - 'a'], 1);   // un 'd'
    CHECK_EQ(hw['a' - 'a'], 0);   // aucun 'a' : la case 0 reste a zero

    // Chiffres et symboles ignores : seules les lettres comptent.
    auto mix = char_histogram("a1b2c3");
    CHECK_EQ(mix['a' - 'a'], 1);
    CHECK_EQ(mix['b' - 'a'], 1);
    CHECK_EQ(mix['c' - 'a'], 1);

    return check::report();
}
