#include "check.hpp"

#include "describe.hpp"

int main() {
    CHECK_EQ(describe(42), std::string("entier 42"));
    CHECK_EQ(describe(std::string("bonjour")), std::string("texte: bonjour"));
    CHECK_EQ(describe(true), std::string("booleen vrai"));
    CHECK_EQ(describe(false), std::string("booleen faux"));

    // describe(double) : on vérifie juste le préfixe (format libre ensuite).
    CHECK(describe(3.5).rfind("flottant", 0) == 0);

    return check::report();
}
