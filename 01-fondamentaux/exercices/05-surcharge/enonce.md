# 05 — Surcharge ★

Une même fonction `describe`, quatre surcharges : le compilateur choisit selon le type de l'argument.

```cpp
std::string describe(int n);                 // "entier 42"
std::string describe(double d);              // commence par "flottant "
std::string describe(const std::string& s);  // "texte: bonjour"
std::string describe(bool b);                // "booleen vrai" / "booleen faux"
```

## Outil

`std::to_string` convertit un nombre en texte. `std::format` (C++20, `<format>`)
fait des gabarits avec `{}`. Les **deux** marchent pour le `double`.

```cpp
#include <format>
std::string a = "entier " + std::to_string(42);  // "entier 42"
std::string b = std::format("flottant {}", 3.5); // "flottant 3.5"
```

Piège : `describe("x")` (littéral `const char*`) appelle la surcharge `bool`, pas `string`.

| Entrée | Sortie |
| --- | --- |
| `describe(42)` | `"entier 42"` |
| `describe(std::string("bonjour"))` | `"texte: bonjour"` |
| `describe(true)` | `"booleen vrai"` |
| `describe(3.5)` | commence par `"flottant"` |

```sh
g++ -std=c++20 -Wall -Wextra -Wpedantic -I ../.. describe_skeleton.cpp describe_test.cpp -o test && ./test
```
