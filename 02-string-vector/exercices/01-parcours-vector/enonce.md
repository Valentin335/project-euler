# 01 — Parcours de vector ★

Parcourir un `std::vector<int>` pour lire et pour modifier en place.

```cpp
#include <vector>
int somme(const std::vector<int>& v);
void mettre_au_carre(std::vector<int>& v);   // chaque élément → son carré, en place
int compte_pairs(const std::vector<int>& v);
int max_value(const std::vector<int>& v);    // throw std::invalid_argument si vide
```

## Outil

Range-for : `const auto&` pour LIRE, `auto&` pour MODIFIER en place.

```cpp
for (const auto& x : v) total += x;   // lecture
for (auto& x : v) x *= 2;             // modification en place
```

| Appel | Résultat |
|---|---|
| `somme({1,2,3,4})` | `10` |
| `somme({})` | `0` |
| `mettre_au_carre({1,2,3})` | `{1,4,9}` |
| `compte_pairs({1,2,3,4})` | `2` |
| `max_value({3,-1,2})` | `3` |
| `max_value({})` | lève `std::invalid_argument` |

```sh
g++ -std=c++20 -Wall -Wextra -Wpedantic -I ../.. parcours_skeleton.cpp parcours_test.cpp -o test
```
