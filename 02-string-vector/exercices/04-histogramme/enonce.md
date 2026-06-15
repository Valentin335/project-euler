# 04 — Histogramme de caractères ★

Compter des caractères dans une chaîne, puis bâtir un histogramme des 26 lettres
(casse ignorée, non-lettres ignorées).

```cpp
int count_char(const std::string& s, char c);          // (s, c) → nombre d'occurrences de c dans s
std::vector<int> char_histogram(const std::string& s);  // s → 26 cases a..z (casse ignorée, non-lettres ignorées)
```

## Outil

`std::count` (`<algorithm>`) compte les occurrences sur un intervalle. Pour
classer une lettre, normalise avec `std::tolower`/`std::isalpha` (`<cctype>`),
en castant en `unsigned char` (sinon UB sur les `char` négatifs), puis indice
`c - 'a'` :

```cpp
int n = std::count(s.begin(), s.end(), 'a');         // occurrences de 'a'
unsigned char uc = static_cast<unsigned char>(ch);
if (std::isalpha(uc)) {
    int i = std::tolower(uc) - 'a';                  // 0..25
}
```

| Entrée                       | Sortie                     |
|------------------------------|----------------------------|
| `count_char("banana", 'a')`  | `3`                        |
| `count_char("banana", 'z')`  | `0`                        |
| `char_histogram("aAbB!")[0]` | `2`                        |
| `char_histogram("aAbB!")[1]` | `2`                        |
| `char_histogram("aAbB!")[2]` | `0`                        |
| `char_histogram("aAbB!").size()` | `26`                   |

```sh
g++ -std=c++20 -Wall -Wextra -Wpedantic -I ../.. histogram_skeleton.cpp histogram_test.cpp -o test && ./test
```
