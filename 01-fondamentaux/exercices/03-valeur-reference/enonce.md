# 03 — Valeur ou référence ★

Comprendre la différence entre passer un argument **par copie** et **par référence** : seul le second laisse modifier la variable de l'appelant.

```cpp
void double_par_copie(int x);                        // x reçu par copie → aucun effet dehors
void double_par_reference(int& x);                   // x reçu par référence → double la variable de l'appelant
void ajoute_a_tous(std::vector<int>& v, int delta);  // v par référence → +delta à chaque élément, en place
```

| Entrée                          | Sortie        |
| ------------------------------- | ------------- |
| `a = 5; double_par_copie(a)`    | `a = 5`       |
| `b = 5; double_par_reference(b)`| `b = 10`      |
| `v = {1,2,3}; ajoute_a_tous(v,10)` | `{11,12,13}` |

```
g++ -std=c++20 -Wall -Wextra -Wpedantic -I ../.. valref_skeleton.cpp valref_test.cpp -o test && ./test
```
