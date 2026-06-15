// Corrigé de référence — exercice 14 « mini-calculatrice ».
// Programme complet (main inclus). Idiome clé : std::istringstream + >> pour
// parser « nombre opérateur nombre », et une fonction dédiée au calcul.
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

// Applique l'opérateur op à a et b. Lève std::invalid_argument si l'opérateur
// est inconnu, ou std::domain_error pour une division par zéro.
double applique(double a, char op, double b) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/':
            if (b == 0) {
                throw std::domain_error("division par zéro");
            }
            return a / b;
        default:
            throw std::invalid_argument("opérateur inconnu");
    }
}

int main() {
    std::string ligne;
    while (std::getline(std::cin, ligne)) {
        if (ligne == "quit") {
            break;
        }

        std::istringstream flux(ligne);
        double a = 0.0;
        double b = 0.0;
        char op = 0;

        // >> lit et convertit : un double, un char, un double. Échoue si la
        // ligne n'a pas cette forme.
        if (!(flux >> a >> op >> b)) {
            std::cerr << "Erreur : ligne mal formée (attendu : nombre op nombre)\n";
            continue;
        }

        try {
            std::cout << applique(a, op, b) << "\n";
        } catch (const std::exception& e) {
            std::cerr << "Erreur : " << e.what() << "\n";
        }
    }
    return 0;
}
