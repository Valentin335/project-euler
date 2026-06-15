# 03 — Tokenize ★

Découper une ligne en **mots** séparés par des espaces. Les espaces multiples
sont **avalés** (aucun champ vide), et une ligne vide ou blanche donne `{}`.

```cpp
std::vector<std::string> tokenize(const std::string& line);  // mots séparés par espaces ; espaces multiples ignorés ; "" -> {}
```

## Aide

`std::istringstream` (`<sstream>`) + `>>` extrait les mots un à un et **saute
les espaces multiples** automatiquement :

```cpp
std::istringstream flux("a   b");
std::string mot;
while (flux >> mot) { /* mot == "a" puis "b" */ }
```

| Entrée | Sortie |
| --- | --- |
| `tokenize("a b c")` | `{"a", "b", "c"}` |
| `tokenize("a   b")` | `{"a", "b"}` |
| `tokenize("  x  ")` | `{"x"}` |
| `tokenize("")` | `{}` |
| `tokenize("   ")` | `{}` |

```sh
g++ -std=c++20 -Wall -Wextra -Wpedantic -I ../.. tokenize_skeleton.cpp tokenize_test.cpp -o test && ./test
```
