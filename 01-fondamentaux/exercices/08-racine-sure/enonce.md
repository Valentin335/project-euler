# 08 — Racine sûre ★

Compare deux styles de gestion d'erreur pour la racine carrée entière : le **code de retour** (`bool` + paramètre `out` par référence) et les **exceptions**.

```cpp
bool try_sqrt_int(int n, int& out);  // true + out=racine si carré parfait ; false sinon
int checked_sqrt_int(int n);          // racine ; throw std::domain_error si n<0, std::invalid_argument si pas un carré parfait
```

Pas besoin de `sqrt` flottant : une boucle `i * i <= n` suffit pour trouver (ou non) la racine entière.

## Aide

Le pattern **`bool` + `out&`** : la fonction renvoie un booléen de succès et écrit le résultat dans un paramètre passé par référence. L'appelant n'utilise `out` que si le retour est `true`.

```cpp
int r;
if (try_sqrt_int(9, r)) {
    // ici r vaut 3
} else {
    // 9 n'était pas un carré parfait (sinon mais ici si)
}
```

| Appel | Résultat |
|---|---|
| `try_sqrt_int(9, o)` | `true`, `o == 3` |
| `try_sqrt_int(10, o)` | `false` |
| `try_sqrt_int(-1, o)` | `false` |
| `checked_sqrt_int(16)` | `4` |
| `checked_sqrt_int(-1)` | lève `std::domain_error` |
| `checked_sqrt_int(10)` | lève `std::invalid_argument` |

```sh
g++ -std=c++20 -Wall -Wextra -Wpedantic -I ../.. racine_skeleton.cpp racine_test.cpp -o test && ./test
```
