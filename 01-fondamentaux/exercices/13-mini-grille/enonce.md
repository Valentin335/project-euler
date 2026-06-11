# Mini-grille ★★★★☆

**Difficulté :** 4 / 5

**Sections du cours visées :** 8 (`std::vector`).

## Objectif

On passe à la deuxième dimension : une **grille** est un *vecteur de
vecteurs* d'entiers. C'est l'occasion d'apprivoiser les conteneurs
imbriqués de la bibliothèque standard et de manipuler des tailles avec
`std::size_t`.

Tu dois écrire trois fonctions :

- `make_grid` : **construire** une grille de dimensions données, remplie
  d'une valeur constante.
- `grid_sum` : calculer la **somme** de toutes les cases.
- `transpose` : renvoyer la **transposée** de la grille (les lignes
  deviennent les colonnes et inversement).

Pour t'aider, le `.hpp` définit un alias de type :

```cpp
using Grid = std::vector<std::vector<int>>;
```

## Signatures imposées

```cpp
Grid make_grid(std::size_t rows, std::size_t cols, int fill);
int grid_sum(const Grid& g);
Grid transpose(const Grid& g);   // suppose g rectangulaire
```

- `make_grid(2, 3, 0)` renvoie une grille à 2 lignes et 3 colonnes,
  toutes les cases valant `0`.
- `grid_sum` sur une grille **vide** renvoie `0`.
- `transpose` suppose que `g` est **rectangulaire** (toutes les lignes
  ont la même longueur). Si `g` a `r` lignes et `c` colonnes, le
  résultat a `c` lignes et `r` colonnes.

## Contraintes

- **Imposé :** inclure `<vector>` et `<cstddef>` (déjà fait dans
  `grille.hpp`).
- Utilise **`g.at()`** (accès avec vérification de borne) dans **au
  moins une** des fonctions, plutôt que l'opérateur `[]`.
- Utilise un **range-for imbriqué** (`for (const auto& ligne : g) { for
  (int x : ligne) { ... } }`) dans au moins une fonction.
- **Interdit :** l'en-tête `<algorithm>`. Tu écris les boucles
  toi-même.
- Attention aux **tailles** : `g.size()` est le nombre de lignes,
  `g[0].size()` (ou `g.at(0).size()`) le nombre de colonnes. Pense au
  cas où la grille est vide avant d'accéder à `g[0]`.

## Cas de test

| Appel | Résultat attendu |
|-------|------------------|
| `make_grid(2, 3, 0).size()` | `2` |
| `make_grid(2, 3, 0)[0].size()` | `3` |
| `make_grid(2, 3, 0)[0][0]` | `0` |
| `grid_sum({{1, 2}, {3, 4}})` | `10` |
| `grid_sum({})` | `0` |
| `transpose({{1, 2, 3}, {4, 5, 6}})` | `{{1, 4}, {2, 5}, {3, 6}}` |

## Compiler & tester

```bash
g++ -std=c++20 -Wall -Wextra -Wpedantic -I ../.. grille_skeleton.cpp grille_test.cpp -o test && ./test
```

Le programme affiche un bilan et renvoie `0` si tout passe, `1` sinon.
Tant que le squelette contient des bouchons, des tests échouent : c'est
normal, à toi de les faire passer.
