# 01 — Échauffement ★

Trois petites fonctions pour reprendre la main. Aucune boucle nécessaire.

```cpp
int square(int x);        // x → x au carré
long long sum_to(int n);  // n → 1+2+...+n (gère n jusqu'à 100000 sans overflow)
bool is_even(int x);      // x → vrai si x est pair
```

## Outil

`static_cast` convertit explicitement un type en un autre. Ici, pour que le
produit `n*(n+1)` se calcule en 64 bits (et non en `int` qui déborderait) :

```cpp
int n = 100000;
long long r = static_cast<long long>(n) * (n + 1);  // pas d'overflow
```

| Entrée            | Sortie       |
|-------------------|--------------|
| `square(5)`       | `25`         |
| `square(-3)`      | `9`          |
| `sum_to(0)`       | `0`          |
| `sum_to(100)`     | `5050`       |
| `sum_to(100000)`  | `5000050000` |
| `is_even(0)`      | `true`       |
| `is_even(7)`      | `false`      |

```sh
g++ -std=c++20 -Wall -Wextra -Wpedantic -I ../.. echauffement_skeleton.cpp echauffement_test.cpp -o test && ./test
```
