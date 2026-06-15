// Corrigé de référence — exercice 15 « compteur de mots ».
// Programme complet (main inclus). Idiome clé : std::map<std::string,int> qui
// compte ET trie les mots par ordre alphabétique automatiquement.
#include <iostream>
#include <map>
#include <string>

int main() {
    std::map<std::string, int> compte;
    std::string mot;
    int total = 0;

    // std::cin >> mot saute espaces et sauts de ligne : on lit tous les mots
    // du texte, jusqu'à la fin d'entrée (Ctrl-D).
    while (std::cin >> mot) {
        ++compte[mot];   // crée l'entrée à 0 si absente, puis incrémente
        ++total;
    }

    std::cout << "Total : " << total << " mots\n";
    std::cout << "Distincts : " << compte.size() << "\n";

    // Parcourir une std::map la donne déjà triée par clé (ordre alphabétique).
    // Structured bindings [m, n] : m = le mot, n = son compte.
    for (const auto& [m, n] : compte) {
        std::cout << m << " : " << n << "\n";
    }
    return 0;
}
