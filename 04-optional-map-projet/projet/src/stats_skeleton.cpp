// Projet de synthèse — implémentation des fonctions de stats.hpp.
// COMPLÈTE chaque fonction. Les corps ci-dessous sont des stubs bidon : ils
// compilent mais ne calculent rien de juste. À toi de jouer.
#include "stats.hpp"

#include <stdexcept>   // std::domain_error, std::invalid_argument (à utiliser)
#include <algorithm>
namespace stats {

double sum(const std::vector<double>& v) {
    // TODO: renvoyer la somme des éléments (range-for).
    double sum = 0;
    for (auto& x:v){
        sum += x;
    }
    return sum;
}

double mean(const std::vector<double>& v) {
    // TODO: throw std::domain_error si v est vide, sinon renvoyer la moyenne.
    if (v.empty()){
        throw std::domain_error("Division par zéro");
    }
    return sum(v)/v.size();
}

double min_value(const std::vector<double>& v) {
    // TODO: throw si vide, sinon renvoyer le plus petit élément.
    if (v.empty()){
        throw std::domain_error("Vide");
    }    
    double min = v[0];
    for (auto& x:v){
        if (min > x)    min = x;
    }
    return min;
}

double max_value(const std::vector<double>& v) {
    // TODO: throw si vide, sinon renvoyer le plus grand élément.
    if (v.empty()){
        throw std::domain_error("Vide");
    }    
    double max = v[0];
    for (auto& x:v){
        if (max < x)    max = x;
    }
    return max;
}

double median(std::vector<double> v) {
    if (v.empty()) {
        throw std::domain_error("Vide");
    }

    std::sort(v.begin(), v.end());

    const std::size_t n = v.size();
    const std::size_t mid = n / 2;

    if (n % 2 == 1) {
        return v[mid];
    }

    return (v[mid - 1] + v[mid]) / 2.0;
}

#include <vector>

void sort_in_place(std::vector<double>& v, bool ascending) {
    for (std::size_t i = 0; i < v.size(); ++i) {
        for (std::size_t j = i + 1; j < v.size(); ++j) {
            if (ascending) {
                if (v[j] < v[i]) {
                    double temp = v[i];
                    v[i] = v[j];
                    v[j] = temp;
                }
            } else {
                if (v[j] > v[i]) {
                    double temp = v[i];
                    v[i] = v[j];
                    v[j] = temp;
                }
            }
        }
    }
}

std::vector<std::string> tokenize(const std::string& line) {
    // TODO: découper line en mots séparés par des espaces.
    std::vector<std::string> v_string;
    if (line.empty()){
        return {};
    }
    std::string tmp = "";
    for (const char& x: line){
        if (x == ' '){
            if (tmp != ""){
                v_string.push_back(tmp);
                tmp = "";
            }
        }
        else{
            tmp = tmp + x;
        }
    }
    if (tmp != ""){
        v_string.push_back(tmp); 
    }

    return v_string;
}
double parse_int(const std::string& s) {
    // TODO: convertir s en long long et lancer std::invalid_argument si s
    // n'est pas un entier complet valide (ex : "12a", "", "  ").
    // Astuce : std::stoll fait une grande partie du travail, mais il accepte
    // les chaines qui COMMENCENT par un entier ("12a" donne 12). Tu dois
    // verifier que TOUTE la chaine a bien ete consommee.
    std::size_t pos = 0;
    double val = std::stod(s, &pos);
    if (pos != s.size()){
        throw std::invalid_argument("Pas un entier");
    }
    return val;
}

std::vector<double> parse_numbers(const std::vector<std::string>& tokens,
                                  std::size_t start) {
    // TODO: convertir tokens[start..] en double ; throw std::invalid_argument
    //       si un token n'est pas un nombre valide.
    std::vector<double> v;
    if (tokens.empty()){
        throw std::invalid_argument("chaine vide");
    }
    for (int i=start,size=tokens.size();i<size;i++){
        v.push_back(parse_int(tokens[i]));
    }

    return v;
}

}