# 03 — Moyenne ou rien ★

Renvoyer une statistique « ou rien » sur une liste qui peut être vide, en
combinant `std::optional` et les algorithmes de la STL (`std::accumulate`,
`std::sort`).

```cpp
#include <optional>
#include <vector>

std::optional<double> moyenne(const std::vector<double>& v);  // nullopt si vide
std::optional<double> mediane(std::vector<double> v);         // nullopt si vide
```

## Aide

`std::accumulate` (`<numeric>`) somme un intervalle. Démarre avec `0.0` (un
`double`) pour sommer en flottant et non en entier :

```cpp
#include <numeric>
double somme = std::accumulate(v.begin(), v.end(), 0.0);
```

`std::sort` (`<algorithm>`) trie sur place ; la médiane est alors l'élément
central (ou la moyenne des deux centraux si la taille est paire).

| Entrée                | Sortie    |
|-----------------------|-----------|
| `moyenne({2,4,6})`    | `4.0`     |
| `moyenne({})`         | `nullopt` |
| `mediane({3,1,2})`    | `2.0`     |
| `mediane({4,1,3,2})`  | `2.5`     |
| `mediane({})`         | `nullopt` |

```sh
g++ -std=c++20 -Wall -Wextra -Wpedantic -I ../.. moyenne_skeleton.cpp moyenne_test.cpp -o test
```
