# 06 — String toolkit ★

Trois petits outils sur `std::string` pour manipuler casse, espaces et préfixes (ASCII).

```cpp
std::string to_upper(const std::string& s);
std::string trim(const std::string& s);
bool starts_with(const std::string& s, const std::string& prefix);
```

## Aide

`std::toupper` (`<cctype>`) prend un `int` : protège-le avec `static_cast<unsigned char>`.
Pour `trim`, `find_first_not_of`/`find_last_not_of` repèrent les bornes utiles, et
`substr(pos, len)` extrait la tranche. `find_first_not_of` renvoie `std::string::npos`
si la chaîne ne contient que des espaces.

```cpp
std::string s = "  hi  ";
std::size_t a = s.find_first_not_of(' ');   // 2
std::size_t b = s.find_last_not_of(' ');    // 3
std::string milieu = s.substr(a, b - a + 1);  // "hi"
```

| Entrée | Sortie |
| --- | --- |
| `to_upper("aBc")` | `"ABC"` |
| `trim("  hi  ")` | `"hi"` |
| `trim("x")` | `"x"` |
| `trim("   ")` | `""` |
| `starts_with("hello", "he")` | `true` |
| `starts_with("hello", "lo")` | `false` |
| `starts_with("hi", "")` | `true` |

```sh
g++ -std=c++20 -Wall -Wextra -Wpedantic -I ../.. strtools_skeleton.cpp strtools_test.cpp -o test && ./test
```
