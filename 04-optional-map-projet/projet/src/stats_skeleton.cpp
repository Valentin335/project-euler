// Projet de synthèse — implémentation des fonctions de stats.hpp.
// COMPLÈTE chaque fonction. Les corps ci-dessous sont des stubs bidon : ils
// compilent mais ne calculent rien de juste. À toi de jouer.
#include "stats.hpp"

#include <stdexcept>   // std::domain_error, std::invalid_argument (à utiliser)

namespace stats {

double sum(const std::vector<double>& v) {
    // TODO: renvoyer la somme des éléments.
    (void)v;
    return 0.0;
}

double mean(const std::vector<double>& v) {
    // TODO: throw std::domain_error si v est vide, sinon renvoyer la moyenne.
    (void)v;
    return 0.0;
}

double min_value(const std::vector<double>& v) {
    // TODO: throw si vide, sinon renvoyer le plus petit élément.
    (void)v;
    return 0.0;
}

double max_value(const std::vector<double>& v) {
    // TODO: throw si vide, sinon renvoyer le plus grand élément.
    (void)v;
    return 0.0;
}

double median(std::vector<double> v) {
    // TODO: throw si vide ; trier la copie locale ; renvoyer la médiane
    //       (moyenne des deux centraux si taille paire).
    (void)v;
    return 0.0;
}

void sort_in_place(std::vector<double>& v, bool ascending) {
    // TODO: trier v en place (croissant si ascending, décroissant sinon).
    (void)v;
    (void)ascending;
}

std::vector<std::string> tokenize(const std::string& line) {
    // TODO: découper line en mots séparés par des espaces.
    (void)line;
    return {};
}

std::vector<double> parse_numbers(const std::vector<std::string>& tokens,
                                  std::size_t start) {
    // TODO: convertir tokens[start..] en double ; throw std::invalid_argument
    //       si un token n'est pas un nombre valide.
    (void)tokens;
    (void)start;
    return {};
}

}  // namespace stats
