// Projet de synthèse — boucle REPL (Read-Eval-Print Loop).
// COMPLÈTE la boucle ci-dessous : lis une ligne, découpe-la avec
// stats::tokenize, identifie la commande (premier token), exécute-la, et
// recommence. Gère les erreurs sans crasher (try/catch, messages sur cerr).
//
// Ce fichier n'est PAS testé automatiquement (interaction utilisateur). Ce sont
// les fonctions de stats.hpp (testées par tests/stats_test.cpp) qui valident
// ton travail. Mais un REPL qui marche, c'est satisfaisant — fais-le tourner !
#include "stats.hpp"

#include <iostream>
#include <string>
#include <vector>

namespace {

void print_help() {
    std::cout <<
        "Commandes : add x [y...], count, sum, mean, min, max, median,\n"
        "            sort [asc|desc], list, clear, help, quit\n";
}

}  // namespace

int main() {
    std::vector<double> data;
    std::string line;

    print_help();

    while (true) {
        std::cout << "> ";
        if (!std::getline(std::cin, line)) {
            break;  // EOF (Ctrl-D) : on quitte proprement.
        }

        // TODO:
        //  1. const auto tokens = stats::tokenize(line);
        //  2. si tokens est vide, continue;
        //  3. const std::string& cmd = tokens[0];
        //  4. dispatch sur cmd ("add", "sum", "mean", ... , "quit") en
        //     appelant les fonctions de stats::.
        //  5. entoure les appels qui peuvent lever (mean, median, parse_numbers,
        //     ...) d'un try/catch et affiche l'erreur sur std::cerr sans quitter.
        //  6. "quit" -> return 0;  commande inconnue -> message sur cerr.
    }

    return 0;
}
