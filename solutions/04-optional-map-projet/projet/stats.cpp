// Corrigé de référence — projet « mini-REPL de statistiques ».
// Version idiomatique : on s'appuie sur <algorithm> et <numeric> plutôt que
// de réécrire les boucles à la main. Compare avec ta version pour repérer les
// endroits où la STL fait le travail à ta place.
//
// (Le projet, contrairement à l'exercice 05, n'interdit aucune bibliothèque.)
#include "stats.hpp"

#include <algorithm>   // std::sort, std::min_element, std::max_element
#include <numeric>     // std::accumulate
#include <sstream>     // std::istringstream
#include <stdexcept>
#include <string>
#include <vector>

namespace stats {

// std::accumulate : somme idiomatique d'une plage. Le 0.0 (double) impose le
// type de l'accumulateur — mettre 0 (int) ferait une somme entière, piège classique.
double sum(const std::vector<double>& v) {
    return std::accumulate(v.begin(), v.end(), 0.0);
}

double mean(const std::vector<double>& v) {
    if (v.empty()) {
        throw std::domain_error("moyenne d'un ensemble vide");
    }
    // v.size() est un size_t ; sum(v) est un double, donc la division est
    // flottante (le double « gagne »). Pas besoin de cast ici.
    return sum(v) / static_cast<double>(v.size());
}

// std::min_element / std::max_element renvoient un ITÉRATEUR sur l'élément ;
// on le déréférence avec * pour obtenir la valeur.
double min_value(const std::vector<double>& v) {
    if (v.empty()) {
        throw std::domain_error("min d'un ensemble vide");
    }
    return *std::min_element(v.begin(), v.end());
}

double max_value(const std::vector<double>& v) {
    if (v.empty()) {
        throw std::domain_error("max d'un ensemble vide");
    }
    return *std::max_element(v.begin(), v.end());
}

// Paramètre pris PAR VALEUR (copie) à dessein : on trie la copie locale sans
// toucher la liste de l'appelant.
double median(std::vector<double> v) {
    if (v.empty()) {
        throw std::domain_error("médiane d'un ensemble vide");
    }
    std::sort(v.begin(), v.end());
    const std::size_t n = v.size();
    const std::size_t mid = n / 2;
    if (n % 2 == 1) {
        return v[mid];                       // taille impaire : l'élément central
    }
    return (v[mid - 1] + v[mid]) / 2.0;      // taille paire : moyenne des deux centraux
}

// std::sort avec un comparateur choisi selon le sens voulu.
void sort_in_place(std::vector<double>& v, bool ascending) {
    if (ascending) {
        std::sort(v.begin(), v.end());                       // < par défaut : croissant
    } else {
        std::sort(v.begin(), v.end(), std::greater<double>{}); // > : décroissant
    }
}

// std::istringstream + operator>> : l'idiome le plus simple pour découper une
// ligne en mots séparés par des espaces. Le flux ignore automatiquement les
// espaces multiples et les bords ; une ligne vide donne zéro mot.
std::vector<std::string> tokenize(const std::string& line) {
    std::istringstream iss(line);
    std::vector<std::string> tokens;
    std::string mot;
    while (iss >> mot) {
        tokens.push_back(mot);
    }
    return tokens;
}

// Convertit les tokens à partir de `start`. std::stod lit un double et, via
// pos, indique combien de caractères ont été consommés : si ce n'est pas toute
// la chaîne, c'est que le token contient des caractères parasites -> invalide.
std::vector<double> parse_numbers(const std::vector<std::string>& tokens,
                                  std::size_t start) {
    std::vector<double> nombres;
    for (std::size_t i = start; i < tokens.size(); ++i) {
        std::size_t pos = 0;
        const double valeur = std::stod(tokens[i], &pos);
        if (pos != tokens[i].size()) {
            throw std::invalid_argument("nombre invalide : " + tokens[i]);
        }
        nombres.push_back(valeur);
    }
    return nombres;
}

}  // namespace stats
