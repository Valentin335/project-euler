# Parcourir un vector (range-for) ★★☆☆☆

**Difficulté :** 2 / 5

**Sections du cours visées :** « Parcourir un conteneur » (boucle
`range-based for`), notion de `const auto&` pour lire et `auto&` pour
modifier en place.

## Objectif

On apprend ici à **parcourir** un `std::vector<int>` avec la boucle
moderne `range-based for`, sans manipuler d'indices à la main. Tu écris
trois petites fonctions :

- `somme` : additionner tous les éléments (parcours en **lecture**),
- `mettre_au_carre` : remplacer chaque élément par son carré, **en
  place** (parcours en **modification**),
- `compte_pairs` : compter combien d'éléments sont pairs (parcours en
  **lecture**).

## Rappel de la notion

La boucle `range-for` parcourt tous les éléments d'un conteneur, un par
un, sans que tu aies à gérer un indice `i` ni la taille :

```cpp
for (auto x : v) {
    // x est une COPIE de chaque élément
}
```

Deux variantes très importantes selon ce que tu veux faire :

- **Lire sans copier** : `for (const auto& x : v)`. Le `&` évite la
  copie (utile si les éléments sont gros), et le `const` dit « je ne
  modifie pas ». C'est ce qu'on veut pour `somme` et `compte_pairs`.
- **Modifier en place** : `for (auto& x : v) x = ...;`. Ici `x` est une
  **référence** vers l'élément réel du vecteur : lui affecter une
  nouvelle valeur change directement le contenu de `v`. C'est ce qu'il
  faut pour `mettre_au_carre`.

Retiens la règle : `const auto&` pour **lire**, `auto&` pour
**modifier**.

## Signatures imposées

```cpp
int somme(const std::vector<int>& v);          // somme des éléments
void mettre_au_carre(std::vector<int>& v);      // chaque élément -> son carré, EN PLACE
int compte_pairs(const std::vector<int>& v);    // nombre d'éléments pairs
```

## Contraintes

- Parcours le vecteur avec une boucle **range-for**, pas avec un indice
  `for (std::size_t i = 0; ...)`.
- `somme` et `compte_pairs` ne modifient pas `v` : parcours en
  `const auto&` (le `v` est d'ailleurs reçu en `const`, ce qui te
  l'impose).
- `mettre_au_carre` modifie `v` **sur place** (pas de nouveau vecteur
  renvoyé) : parcours en `auto&`.
- `somme` sur un vecteur **vide** vaut `0` ; `compte_pairs` sur un
  vecteur **vide** vaut `0`.
- Rappel : un entier `x` est pair si `x % 2 == 0` (vrai aussi pour les
  négatifs : `-4 % 2 == 0`).

## Cas de test

| Appel | Résultat attendu |
|-------|------------------|
| `somme({1, 2, 3, 4})` | `10` |
| `somme({})` | `0` |
| `somme({-2, 2})` | `0` |
| `mettre_au_carre(v)` avec `v = {1, 2, 3}` | `v` devient `{1, 4, 9}` |
| `mettre_au_carre(n)` avec `n = {-3}` | `n` devient `{9}` |
| `compte_pairs({1, 2, 3, 4, 5, 6})` | `3` |
| `compte_pairs({1, 3, 5})` | `0` |
| `compte_pairs({})` | `0` |

## Compiler & tester

```bash
g++ -std=c++20 -Wall -Wextra -Wpedantic -I ../.. parcours_skeleton.cpp parcours_test.cpp -o test && ./test
```

Le programme affiche un bilan et renvoie `0` si tout passe, `1` sinon.
Tant que le squelette contient des bouchons, des tests échouent : c'est
normal, à toi de les faire passer.
