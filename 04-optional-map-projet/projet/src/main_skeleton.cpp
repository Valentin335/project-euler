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
            break;  // EOF (Ctrl-D)
        }

        const auto tokens = stats::tokenize(line);

        if (tokens.empty()) {
            continue;
        }

        const std::string& cmd = tokens[0];

        try {
            if (cmd == "add") {
                std::vector<double> values = stats::parse_numbers(tokens, 1);

                for (double x : values) {
                    data.push_back(x);
                }
            }
            else if (cmd == "count") {
                std::cout << data.size() << "\n";
            }
            else if (cmd == "sum") {
                std::cout << stats::sum(data) << "\n";
            }
            else if (cmd == "mean") {
                std::cout << stats::mean(data) << "\n";
            }
            else if (cmd == "min") {
                std::cout << stats::min_value(data) << "\n";
            }
            else if (cmd == "max") {
                std::cout << stats::max_value(data) << "\n";
            }
            else if (cmd == "median") {
                std::cout << stats::median(data) << "\n";
            }
            else if (cmd == "sort") {
                bool ascending = true;

                if (tokens.size() >= 2) {
                    if (tokens[1] == "asc") {
                        ascending = true;
                    }
                    else if (tokens[1] == "desc") {
                        ascending = false;
                    }
                    else {
                        throw std::invalid_argument("Utilise sort asc ou sort desc");
                    }
                }

                stats::sort_in_place(data, ascending);
            }
            else if (cmd == "list") {
                for (double x : data) {
                    std::cout << x << " ";
                }
                std::cout << "\n";
            }
            else if (cmd == "clear") {
                data.clear();
            }
            else if (cmd == "help") {
                print_help();
            }
            else if (cmd == "quit") {
                return 0;
            }
            else {
                std::cerr << "Commande inconnue : " << cmd << "\n";
            }
        }
        catch (const std::exception& e) {
            std::cerr << "Erreur : " << e.what() << "\n";
        }
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


    return 0;
}
