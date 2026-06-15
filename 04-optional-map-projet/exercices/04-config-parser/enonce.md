# 04 — Config parser ★★

Construire une `std::map<std::string, std::string>` à partir de lignes au format
`cle=valeur`. Une ligne sans `=` est ignorée ; sur une clé en double, la
dernière valeur l'emporte.

```cpp
#include <map>
#include <string>
#include <vector>

std::map<std::string, std::string> parse_config(const std::vector<std::string>& lignes);
```

## Aide

Pour découper une ligne `cle=valeur`, repère la position du `=` avec
`std::string::find`, puis sépare avec `substr` (revus au chapitre 2). `find`
renvoie `std::string::npos` quand le caractère est absent :

```cpp
const std::size_t pos = ligne.find('=');
if (pos == std::string::npos) {
    // pas de '=' : ligne à ignorer
}
const std::string cle = ligne.substr(0, pos);
const std::string val = ligne.substr(pos + 1);  // tout ce qui suit le '='
```

Côté `map`, `m[cle] = val` crée l'entrée si elle n'existe pas, sinon écrase
l'ancienne valeur : le comportement « la dernière gagne » est gratuit.

| Entrée                              | Sortie                          |
|-------------------------------------|---------------------------------|
| `parse_config({"a=1", "b=2"})`      | `{{"a","1"}, {"b","2"}}`         |
| `parse_config({"x=hello","x=world"})` | `["x"]` vaut `"world"`        |
| `parse_config({"bad"})`             | map vide                        |
| `parse_config({"k="})`              | `["k"]` vaut `""`               |
| `parse_config({})`                  | map vide                        |

```sh
g++ -std=c++20 -Wall -Wextra -Wpedantic -I ../.. config_skeleton.cpp config_test.cpp -o test
```
