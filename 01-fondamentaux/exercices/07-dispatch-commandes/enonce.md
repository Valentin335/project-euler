# 07 — Dispatch de commandes ★

Pratique le `switch` sur un `char` : selon la commande, renvoie une chaine décrivant l'action sur `n`.

```cpp
std::string apply_command(char cmd, int n);  // 'i'→"info n", 'd'→"double 2n", 'n'→"neg -n", autre→"inconnu"
```

## Aide

Un `switch` sur un `char` enchaine des `case` ; chaque branche renvoie sa chaine. Construis le texte avec `std::to_string`, qui convertit un nombre en `std::string` :

```cpp
#include <string>
switch (cmd) {
    case 'i': return "info " + std::to_string(n);
    default:  return "inconnu";
}
```

| Entrée | Sortie |
|---|---|
| `apply_command('i', 5)` | `"info 5"` |
| `apply_command('d', 5)` | `"double 10"` |
| `apply_command('n', 5)` | `"neg -5"` |
| `apply_command('x', 5)` | `"inconnu"` |

```sh
g++ -std=c++20 -Wall -Wextra -Wpedantic -I ../.. dispatch_skeleton.cpp dispatch_test.cpp -o test
```
