# Portée et somme par référence ⭐⭐☆☆☆

**Difficulté : 2/5**

**Sections du cours visées :** « Portée et durée de vie », « Valeur ou référence »

---

## Rappel pédagogique

En C++, chaque variable a une **portée** (la zone du code où son nom est
visible) et une **durée de vie** (la période pendant laquelle elle existe
réellement en mémoire).

- Une variable déclarée dans un bloc `{ ... }` **naît** à sa déclaration et
  **meurt** à l'accolade fermante. Après, son nom n'existe plus.
- Bonne pratique moderne : déclare tes variables **au plus près de leur
  usage** (et pas toutes en haut de la fonction). Une variable de boucle
  déclarée dans le `for` ne vit que le temps de la boucle.

Comment faire « sortir » un résultat d'une fonction ?

- **Par valeur** : la fonction renvoie une valeur (`return`). La variable
  locale meurt, mais sa valeur est **copiée** vers l'appelant. C'est le cas de
  `max_local` et `compte_dans_intervalle`.
- **Par référence** : on passe en paramètre une **référence** (`int& total`).
  La fonction écrit directement dans la variable de l'appelant, qui « voit » le
  changement même après le retour. C'est le cas de `accumule`, un
  **accumulateur** : on AJOUTE au total existant.

---

## Travail demandé

Implémente les trois fonctions dans `dureevie_skeleton.cpp` (les prototypes
sont figés dans `dureevie.hpp`, que tu **ne dois pas modifier**) :

```cpp
void accumule(const std::vector<int>& source, int& total);
int  max_local(const std::vector<int>& v);
int  compte_dans_intervalle(const std::vector<int>& v, int bas, int haut);
```

- `accumule` : **ajoute** la somme des éléments de `source` à `total`. `total`
  est passé **par référence** ; tu écris dedans, tu ne le réinitialises pas.
- `max_local` : renvoie le plus grand élément de `v`. Si `v` est **vide**, lève
  `std::out_of_range`.
- `compte_dans_intervalle` : renvoie le nombre d'éléments `x` de `v` vérifiant
  `bas <= x <= haut` (bornes **incluses**).

---

## Contraintes

- Respecte exactement les signatures imposées (n'y touche pas).
- `accumule` ne renvoie rien : son résultat sort **par la référence** `total`.
  Ne remets jamais `total` à zéro (c'est un accumulateur).
- `max_local` doit vérifier la **vacuité avant** de lire un élément (lire dans
  un vecteur vide est un comportement indéfini).
- Déclare tes variables **au plus près de leur usage** ; pense à la portée de
  ta variable de boucle.

---

## Cas de test

| Appel | Résultat attendu |
| --- | --- |
| `t = 100; accumule({1,2,3}, t)` | `t == 106` (100 + 1+2+3) |
| `t2 = 0; accumule({}, t2)` | `t2 == 0` (vide : inchangé) |
| `t3 = 5; accumule({10}, t3); accumule({20}, t3)` | `t3 == 35` (accumulation) |
| `max_local({3,7,2})` | `7` |
| `max_local({-5,-1,-9})` | `-1` |
| `max_local({})` | lève `std::out_of_range` |
| `compte_dans_intervalle({1,5,10,15}, 5, 12)` | `2` (5 et 10) |
| `compte_dans_intervalle({1,2,3}, 10, 20)` | `0` |

---

## Compiler & tester

Depuis le dossier de l'exercice :

```bash
g++ -std=c++20 -Wall -Wextra -Wpedantic -I ../.. dureevie_skeleton.cpp dureevie_test.cpp -o test && ./test
```

Tant que des tests échouent, retravaille `dureevie_skeleton.cpp`. Le bilan
affiche `TOUS LES TESTS PASSENT.` quand tu as fini.
