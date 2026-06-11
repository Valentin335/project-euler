// =====================================================================
//  parcours_skeleton.cpp — À TOI DE JOUER
//
//  Implémente les trois fonctions déclarées dans parcours.hpp.
//  Les corps ci-dessous sont des bouchons (placeholders) : ils
//  compilent mais renvoient des valeurs neutres et ne touchent à rien.
//  Remplace chaque TODO par ta vraie implémentation.
//
//  Mémo de la boucle range-for :
//    - pour LIRE sans copier  : for (const auto& x : v)
//    - pour MODIFIER en place : for (auto& x : v) x = ... ;
// =====================================================================

#include "parcours.hpp"

int somme(const std::vector<int>& v)
{
    (void)v;  // bouchon : empêche le warning « paramètre non utilisé »
    // TODO: déclarer un accumulateur (un int) initialisé à 0.
    // TODO: parcourir v en LECTURE avec for (const auto& x : v).
    // TODO: à chaque tour, ajouter x à l'accumulateur.
    // TODO: renvoyer l'accumulateur (pour {} il vaut bien 0).
    return 0;
}

void mettre_au_carre(std::vector<int>& v)
{
    (void)v;  // bouchon : empêche le warning « paramètre non utilisé »
    // TODO: parcourir v en MODIFICATION avec for (auto& x : v).
    //       Ici x est une RÉFÉRENCE vers l'élément réel : lui affecter
    //       une valeur change directement le contenu de v.
    // TODO: remplacer x par son carré (x multiplié par lui-même).
    // Rappel : on ne crée PAS de nouveau vecteur, et on ne renvoie rien.
}

int compte_pairs(const std::vector<int>& v)
{
    (void)v;  // bouchon : empêche le warning « paramètre non utilisé »
    // TODO: déclarer un compteur (un int) initialisé à 0.
    // TODO: parcourir v en LECTURE avec for (const auto& x : v).
    // TODO: tester si x est pair (indice : le reste de x par 2 vaut 0)
    //       et, si oui, incrémenter le compteur.
    // TODO: renvoyer le compteur.
    return 0;
}
