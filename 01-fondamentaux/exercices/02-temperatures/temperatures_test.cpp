// Tests de l'exercice 02 (fournis). Ne pas modifier.
// Compile avec ton temperatures_skeleton.cpp (voir COMPILER.md du chapitre).
#include "check.hpp"
#include "temperatures.hpp"
#include <string>

// Comparaison de doubles « à epsilon près » : on ne teste jamais l'égalité
// stricte de deux flottants, à cause des arrondis. Ici on accepte un écart
// inférieur à 1e-9 dans les deux sens.
static bool approx(double a, double b) {
    return (a - b < 1e-9) && (b - a < 1e-9);
}

int main() {
    CHECK(approx(celsius_to_fahrenheit(0), 32));
    CHECK(approx(celsius_to_fahrenheit(100), 212));

    CHECK(approx(fahrenheit_to_celsius(32), 0));
    CHECK(approx(fahrenheit_to_celsius(212), 100));

    CHECK_EQ(std::string(water_state(-5)), std::string("solide"));
    CHECK_EQ(std::string(water_state(0)), std::string("solide"));
    CHECK_EQ(std::string(water_state(20)), std::string("liquide"));
    CHECK_EQ(std::string(water_state(99.9)), std::string("liquide"));
    CHECK_EQ(std::string(water_state(100)), std::string("gazeux"));
    CHECK_EQ(std::string(water_state(150)), std::string("gazeux"));

    return check::report();
}
