// Exercice 03b — Déclarations, auto, copie ou référence.
// Complète le corps des fonctions ci-dessous. Les signatures sont imposées
// par autotypes.hpp : ne les modifie pas.
//
// RAPPEL EXPRESS (à garder en tête en codant)
// -------------------------------------------
// En C++, chaque variable a un TYPE fixé à la compilation (typage statique).
// Le mot-clé `auto` ne supprime pas le type : il demande juste au compilateur
// de le DÉDUIRE à partir de la valeur d'initialisation.
//
//   auto  x = quelque_chose;   // x est une COPIE indépendante.
//   auto& x = quelque_chose;   // x est une RÉFÉRENCE : un autre nom pour la
//                              // même case mémoire. Modifier x modifie l'original.
//
// Toute la subtilité de cet exercice tient là-dedans : selon que tu veux
// seulement LIRE ou bien MODIFIER, tu choisis `auto` (copie) ou `auto&`
// (référence).
#include "autotypes.hpp"

#include <stdexcept>  // pour std::out_of_range (à toi de t'en servir)

int premier_element(const std::vector<int>& v) {
    (void)v;  // (à retirer quand tu utiliseras v)
    // TODO: renvoyer le premier élément de v, c'est-à-dire v[0].
    //
    // Ici tu veux juste LIRE une valeur et la renvoyer : une COPIE convient
    // parfaitement. Si tu passes par une variable intermédiaire, `auto` suffit
    //     auto x = v[0];   // x est un int, copie du premier élément.
    //
    // ATTENTION au cas vide : si v ne contient aucun élément, v[0] n'existe
    // pas (accès interdit). Avant de lire, vérifie la taille (v.empty() ou
    // v.size()) et, si v est vide, lève une std::out_of_range.
    return 0;  // corps bidon : à remplacer.
}

void incremente_premier(std::vector<int>& v) {
    (void)v;  // (à retirer quand tu utiliseras v)
    // TODO: ajouter 1 au PREMIER élément de v, en place (v est modifié chez
    // l'appelant). Il n'y a pas de valeur à renvoyer.
    //
    // POINT-CLÉ de l'exercice : ici il faut MODIFIER l'original, donc une copie
    // ne suffit PAS.
    //     auto  x = v[0];   // x est une COPIE : x += 1 ne touche pas v. (piège)
    //     auto& x = v[0];   // x est une RÉFÉRENCE vers v[0] : x += 1 modifie v.
    // Autre voie : v[0] est DÉJÀ une référence sur le premier élément, donc tu
    // peux aussi travailler directement dessus.
    //
    // Comme pour la fonction précédente : si v est vide, il n'y a pas de
    // premier élément à incrémenter → lève une std::out_of_range.
}

std::size_t taille(const std::string& s) {
    (void)s;  // (à retirer quand tu utiliseras s)
    // TODO: renvoyer la longueur de s, sans en faire de copie.
    //
    // s arrive en `const std::string&` : tu peux la LIRE mais pas la modifier,
    // et surtout aucune copie n'est faite à l'appel. Le type de retour est
    // std::size_t, l'entier non signé que std::string utilise pour sa taille
    // (c'est exactement ce que renvoie s.size()).
    return 0;  // corps bidon : à remplacer.
}
