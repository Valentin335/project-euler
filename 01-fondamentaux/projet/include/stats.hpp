#pragma once
// Signatures imposées du projet de synthèse (mini-REPL de statistiques).
// NE PAS MODIFIER ce fichier : tu implémentes ces fonctions dans
// src/stats_skeleton.cpp.

#include <cstddef>
#include <string>
#include <vector>

namespace stats {

// --- Calculs statistiques ---------------------------------------------------
double sum(const std::vector<double>& v);
double mean(const std::vector<double>& v);        // throw std::domain_error si v est vide
double min_value(const std::vector<double>& v);   // throw std::domain_error si v est vide
double max_value(const std::vector<double>& v);   // throw std::domain_error si v est vide

// Médiane. Le paramètre est passé PAR VALEUR (copie) à dessein : tu peux trier
// la copie locale sans toucher à la liste de l'appelant.
// Liste de taille paire -> moyenne des deux valeurs centrales.
// throw std::domain_error si v est vide.
double median(std::vector<double> v);

// Trie v en place, croissant par défaut.
void sort_in_place(std::vector<double>& v, bool ascending = true);

// --- Analyse de la ligne de commande ---------------------------------------
// Découpe une ligne en mots (séparés par des espaces). Les espaces multiples
// sont ignorés ; une ligne vide ou blanche donne un vecteur vide.
std::vector<std::string> tokenize(const std::string& line);

// Convertit en nombres les tokens à partir de l'indice `start`.
// throw std::invalid_argument si un token n'est pas un nombre valide.
std::vector<double> parse_numbers(const std::vector<std::string>& tokens,
                                  std::size_t start);

}  // namespace stats
