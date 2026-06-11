// ===========================================================================
// dureevie_skeleton.cpp — À TOI DE JOUER.
//
// Remplace les corps « bidon » ci-dessous par tes implémentations.
// Pour l'instant chaque fonction renvoie une valeur neutre : le programme
// compile, mais les tests ÉCHOUENT (c'est normal au départ).
//
// Idée centrale du chapitre : PORTÉE et DURÉE DE VIE.
//   - Une variable n'existe que dans le bloc { ... } où elle est déclarée :
//     dès la fin du bloc, elle « meurt » et son nom n'existe plus.
//   - Conseil d'idiome C++ moderne : déclare tes variables AU PLUS PRÈS de
//     leur usage (pas tout en haut de la fonction comme en vieux C). Une
//     variable de boucle déclarée dans le for() ne vit que pendant la boucle.
//   - Pour qu'un résultat « survive » à un appel de fonction, on le passe par
//     RÉFÉRENCE (int& total) : tu écris dans la variable de l'APPELANT.
// ===========================================================================

#include "dureevie.hpp"

#include <stdexcept>  // pour std::out_of_range

// ---------------------------------------------------------------------------
// accumule : AJOUTE la somme de `source` à `total`.
//
// Rappel : `total` est une RÉFÉRENCE (int&). Ce n'est pas une copie : quand tu
// écris `total += ...`, tu modifies directement la variable de l'appelant. La
// fonction ne renvoie rien (void) — le « résultat » sort par la référence.
//
// Démarche conseillée (petits pas) :
//   1. Parcours les éléments de `source` (un for-range `for (int x : source)`
//      est idéal et lisible).
//   2. Pour chaque élément, ajoute sa valeur à `total`.
//   3. Si `source` est vide, la boucle ne tourne pas : `total` reste tel quel.
//      C'est exactement le comportement voulu (rien à ajouter).
//
// ATTENTION : tu ne dois PAS remettre `total` à zéro au début. On AJOUTE à ce
// qui s'y trouve déjà (c'est un accumulateur, pas une affectation).
//
// N'introduis pas de variable de somme intermédiaire si tu n'en as pas besoin :
// `total` EST déjà l'accumulateur. Une variable locale temporaire mourrait à la
// fin de la fonction de toute façon.
// ---------------------------------------------------------------------------
void accumule(const std::vector<int>& source, int& total) {
    (void)source;  // TODO: parcourir source et ajouter chaque élément à total
    (void)total;   // TODO: total est une référence — écris dedans, ne le réinitialise pas
    // TODO: aucune valeur à renvoyer (void) ; le résultat « sort » par total.
}

// ---------------------------------------------------------------------------
// max_local : renvoie le plus grand élément de `v`.
//
// Cas particulier d'abord : si `v` est VIDE, il n'y a pas de maximum. On le
// signale en levant une exception :
//       throw std::out_of_range("...message...");
//   (Pense à vérifier la vacuité AVANT de lire un élément ; lire v[0] sur un
//   vecteur vide est un comportement indéfini.)
//
// Sinon, démarche conseillée :
//   1. Choisis un « champion » initial : le premier élément v[0] (légitime,
//      le vecteur n'est pas vide ici) ou v.front().
//   2. Parcours les éléments suivants ; si tu en trouves un plus grand, il
//      devient le nouveau champion.
//   3. Le champion déclaré dans cette fonction vit jusqu'au `return` : sa
//      valeur est COPIÉE vers l'appelant au moment du return, donc pas de
//      souci de durée de vie.
//
// Rappel portée : la variable de boucle `for (int x : v)` n'existe que dans la
// boucle ; ton champion, lui, doit être déclaré AVANT la boucle pour survivre
// d'une itération à l'autre.
// ---------------------------------------------------------------------------
int max_local(const std::vector<int>& v) {
    (void)v;  // TODO: si v est vide -> throw std::out_of_range(...)
    // TODO: sinon, déclare un champion initial puis parcours v pour le maximum.
    return 0;
}

// ---------------------------------------------------------------------------
// compte_dans_intervalle : nombre d'éléments x avec bas <= x <= haut.
//
// Démarche conseillée :
//   1. Déclare un compteur local initialisé à 0 (déclare-le juste avant la
//      boucle : au plus près de son usage).
//   2. Parcours `v` ; pour chaque élément, teste la double condition
//      bas <= x ET x <= haut (en C++ on l'écrit `bas <= x && x <= haut`).
//   3. Si la condition est vraie, incrémente le compteur.
//   4. Renvoie le compteur.
//
// Note durée de vie : ce compteur est LOCAL ; il disparaît à la fin de la
// fonction, mais sa valeur est renvoyée (copiée) par le `return`. C'est la
// façon « par valeur » de rendre un résultat — à comparer avec `accumule` qui,
// lui, écrit dans une référence.
// ---------------------------------------------------------------------------
int compte_dans_intervalle(const std::vector<int>& v, int bas, int haut) {
    (void)v;     // TODO: parcourir v
    (void)bas;   // TODO: tester bas <= x && x <= haut
    (void)haut;
    return 0;    // TODO: renvoyer le nombre d'éléments dans l'intervalle
}
