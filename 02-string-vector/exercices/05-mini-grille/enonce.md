# 05 — Mini-grille ★★

Manipuler une grille 2D (`vector<vector<int>>`) : construction, somme, transposée.

```cpp
using Grid = std::vector<std::vector<int>>;
Grid make_grid(std::size_t rows, std::size_t cols, int fill);
int grid_sum(const Grid& g);
Grid transpose(const Grid& g);  // resultat(i,j) = g(j,i)
```

## Outil

Construction imbriquée et accès 2D :

```cpp
Grid g(rows, std::vector<int>(cols, fill)); // rows lignes de cols valeurs
int x = g.at(i).at(j);                       // accès (ligne i, colonne j)
// ATTENTION : g(i,j) n'existe pas ; (i,j) est l'opérateur virgule = i,j -> j !
for (const auto& ligne : g)                  // range-for : parcours lecture
    for (int v : ligne) { /* ... */ }
```

| Entrée | Sortie |
| --- | --- |
| `make_grid(2,3,0)` | `{{0,0,0},{0,0,0}}` |
| `grid_sum({{1,2},{3,4}})` | `10` |
| `transpose({{1,2,3},{4,5,6}})` | `{{1,4},{2,5},{3,6}}` |
| `transpose({})` | `{}` |

```sh
g++ -std=c++20 -Wall -Wextra -Wpedantic -I ../.. grille_skeleton.cpp grille_test.cpp -o test
```
