# 04 — Const et exceptions ★

Manipule une `std::string` via références : `const&` pour lire sans copie, `&` pour modifier en place, et signale l'erreur avec une exception.

```cpp
std::size_t length(const std::string& s);  // taille, sans copie
char first_char(const std::string& s);      // 1er char ; throw std::invalid_argument si vide
void append_excl(std::string& s);           // ajoute " !" en place
```

## Outil

`throw` lance une exception ; le harnais la rattrape avec `CHECK_THROWS` (inclure `<stdexcept>`).

```cpp
#include <stdexcept>
if (s.empty())
    throw std::invalid_argument("vide");
```

| Appel | Résultat |
|---|---|
| `length("hello")` | `5` |
| `first_char("abc")` | `'a'` |
| `first_char("")` | lève `std::invalid_argument` |
| `append_excl(s)` sur `"ok"` | `s == "ok !"` |

```sh
g++ -std=c++20 -Wall -Wextra -Wpedantic -I ../.. constref_skeleton.cpp constref_test.cpp -o test && ./test
```
