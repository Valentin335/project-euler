// Tests de l'exercice 11 (fournis). Ne pas modifier.
// Compile avec ton parse_int_skeleton.cpp (voir enonce.md).
#include "check.hpp"
#include "parse_int.hpp"

#include <string>
#include <vector>
#include <stdexcept>

int main() {
    // parse_int : entiers valides.
    CHECK_EQ(parse_int("42"), 42LL);
    CHECK_EQ(parse_int("-7"), -7LL);
    CHECK_EQ(parse_int("0"), 0LL);

    // parse_int : entrees invalides -> std::invalid_argument.
    CHECK_THROWS(parse_int(std::string("12a")), std::invalid_argument);
    CHECK_THROWS(parse_int(std::string("")), std::invalid_argument);
    CHECK_THROWS(parse_int(std::string("  ")), std::invalid_argument);

    // -- Cas limites ajoutes : parse_int -------------------------------------
    // Signe plus explicite : std::stoll accepte un '+' en tete, donc "+42"
    // est un entier complet et valide -> 42.
    CHECK_EQ(parse_int("+42"), 42LL);
    // Zeros en tete : ils sont absorbes, "007" vaut 7 (et non un octal).
    CHECK_EQ(parse_int("007"), 7LL);
    // Valeur qui DEPASSE un int 32 bits mais tient dans un long long.
    // C'est tout l'interet de renvoyer un long long.
    CHECK_EQ(parse_int("2147483648"), 2147483648LL);
    // "3.14" : stoll lit "3" puis s'arrete sur '.'. La chaine n'est pas
    // entierement consommee -> entree invalide.
    CHECK_THROWS(parse_int(std::string("3.14")), std::invalid_argument);
    // Espace AU MILIEU : "4 2" n'est pas UN entier (stoll s'arrete a l'espace).
    // Attention : c'est parse_int (un seul entier attendu), pas parse_ints.
    CHECK_THROWS(parse_int(std::string("4 2")), std::invalid_argument);

    // parse_ints : decoupage par espaces.
    CHECK_EQ(parse_ints("1 2 3"), (std::vector<long long>{1, 2, 3}));
    CHECK_EQ(parse_ints("1   2"), (std::vector<long long>{1, 2}));
    CHECK_EQ(parse_ints(""), (std::vector<long long>{}));

    // -- Cas limites ajoutes : parse_ints ------------------------------------
    // Espaces en tete ET en fin : ils doivent etre ignores, pas produire
    // d'entiers fantomes -> {1, 2}.
    CHECK_EQ(parse_ints("  1  2  "), (std::vector<long long>{1, 2}));
    // Entiers negatifs separes par un espace : le signe '-' fait partie du
    // token -> {-3, -4}.
    CHECK_EQ(parse_ints("-3 -4"), (std::vector<long long>{-3, -4}));

    return check::report();
}
