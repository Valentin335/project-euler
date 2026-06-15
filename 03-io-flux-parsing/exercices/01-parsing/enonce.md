# 01 — Parsing d'entiers ★★

Convertir une chaîne en entier en **vérifiant** qu'elle est entièrement
valide, puis découper une ligne en entiers séparés par des espaces.

```cpp
long long parse_int(const std::string& s);             // throw std::invalid_argument si pas un entier complet
std::vector<long long> parse_ints(const std::string& line);  // entiers séparés par espaces
```

## Outils

`std::stoll(s, &pos)` convertit le **début** de `s` et écrit dans `pos` le
nombre de caractères consommés. Pour exiger un entier *complet*, vérifie
`pos == s.size()` :

```cpp
std::size_t pos = 0;
long long n = std::stoll("12a", &pos);   // n == 12, pos == 2
if (pos != s.size()) /* reste des caractères -> invalide */;
// std::stoll lève déjà std::invalid_argument sur "" ou "abc"
```

`std::istringstream` (`<sstream>`) + `>>` découpe une ligne en mots et **saute
les espaces multiples** :

```cpp
std::istringstream flux("1   2");
std::string mot;
while (flux >> mot) { /* mot == "1" puis "2" */ }
```

| Entrée | Sortie |
| --- | --- |
| `parse_int("42")` | `42` |
| `parse_int("12a")` | lève `std::invalid_argument` |
| `parse_int("")` | lève `std::invalid_argument` |
| `parse_ints("1 2 3")` | `{1, 2, 3}` |
| `parse_ints("1   2")` | `{1, 2}` |
| `parse_ints("")` | `{}` |

```sh
g++ -std=c++20 -Wall -Wextra -Wpedantic -I ../.. parse_int_skeleton.cpp parse_int_test.cpp -o test && ./test
```
