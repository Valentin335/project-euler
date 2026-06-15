# 07 — Split maison ★

Découper une chaîne sur un séparateur, **sans `istringstream`** (réservé au
chapitre 3), uniquement avec `find` et `substr`. Les champs vides sont
**conservés** : `"a,,b"` donne trois champs, et `""` donne un seul champ vide.

```cpp
std::vector<std::string> split(const std::string& s, char sep);  // (s, sep) → champs séparés par sep, vides conservés ; "" → {""}
```

## Aide

`s.find(sep, pos)` cherche `sep` à partir de l'indice `pos` et renvoie sa
position, ou `std::string::npos` s'il n'y en a plus. `s.substr(pos, len)`
extrait `len` caractères à partir de `pos` :

```cpp
std::string s = "a,b";
std::size_t p = s.find(',', 0);   // p == 1
std::string champ = s.substr(0, p);  // "a"  (de l'indice 0, longueur 1)
std::size_t q = s.find(',', p + 1);  // npos : plus de séparateur
```

| Entrée                | Sortie              |
|-----------------------|---------------------|
| `split("a,b,c", ',')` | `{"a", "b", "c"}`   |
| `split("a,,b", ',')`  | `{"a", "", "b"}`    |
| `split("", ',')`      | `{""}`              |
| `split("abc", ',')`   | `{"abc"}`           |
| `split(",x", ',')`    | `{"", "x"}`         |

```sh
g++ -std=c++20 -Wall -Wextra -Wpedantic -I ../.. split_skeleton.cpp split_test.cpp -o test && ./test
```
