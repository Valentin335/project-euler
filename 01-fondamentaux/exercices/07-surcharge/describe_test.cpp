// Tests de l'exercice 07 (fournis). Ne pas modifier.
// Compile avec ton describe_skeleton.cpp (voir COMPILER.md du chapitre).
#include "check.hpp"
#include "describe.hpp"

#include <string>

int main() {
    // Surcharge int.
    CHECK(describe(42) == std::string("entier 42"));

    // Surcharge const std::string&. On passe explicitement un std::string
    // pour viser cette surcharge (et non la surcharge bool, voir l'enonce).
    CHECK(describe(std::string("bonjour")) == std::string("texte: bonjour"));

    // Surcharge bool.
    CHECK(describe(true) == std::string("booleen vrai"));
    CHECK(describe(false) == std::string("booleen faux"));

    // Surcharge double : on verifie seulement le prefixe "flottant".
    std::string d = describe(3.5);
    CHECK(d.rfind("flottant", 0) == 0);

    return check::report();
}
