# Exercice 12 — Absence de valeur avec `std::optional` ★★★★

**Difficulté :** ★★★★☆
**Sections du cours :** 17 (gestion des erreurs / `std::optional`)

## Objectif

Apprendre à représenter **proprement l'absence de résultat**. Beaucoup de
fonctions peuvent « échouer » à produire une valeur : une recherche qui ne
trouve rien, une division par zéro... La tentation classique est de renvoyer
une **valeur sentinelle** (`-1`, `0`, la taille du conteneur...) pour signaler
ce cas. C'est fragile : le `-1` peut être confondu avec un vrai résultat, et
rien dans le type ne force l'appelant à vérifier.

`std::optional<T>` résout ça : la valeur est soit présente (et tu la lis avec
`.value()` ou `*`), soit **vide** (`std::nullopt`). L'appelant doit
explicitement tester `.has_value()` avant de lire.

Tu dois écrire :
- `index_of` : la position du **premier** élément égal à `target`, ou « rien »
  si `target` est absent.
- `safe_divide` : le quotient `a / b`, ou « rien » si `b == 0`.

## Signatures imposées (`optionnel.hpp`)

```cpp
std::optional<std::size_t> index_of(const std::vector<int>& v, int target);  // position du 1er target, ou nullopt
std::optional<int> safe_divide(int a, int b);                                 // a/b, ou nullopt si b==0
```

Tu complètes `optionnel_skeleton.cpp`. Ne touche pas au `.hpp`.

## Contraintes

- Aucune bibliothèque hors standard. `<optional>`, `<vector>` et `<cstddef>`
  (pour `std::size_t`) sont inclus pour toi dans le `.hpp`.
- **INTERDIT : signaler l'absence par une valeur sentinelle** comme `-1`, la
  taille du vecteur, ou tout autre « code magique ». L'absence se représente
  **uniquement** par `std::nullopt`.
- Pour une valeur présente : renvoie-la directement (la conversion vers
  `std::optional<T>` est implicite). Pour l'absence : renvoie `std::nullopt`.
- `index_of` doit renvoyer l'indice du **premier** élément correspondant.
- L'appelant lit le contenu avec `.has_value()` puis `.value()` (ou `*`).

## Cas de test (dans `optionnel_test.cpp`)

| Appel | Résultat attendu |
|-------|------------------|
| `index_of({10,20,30}, 20)` | a une valeur, et vaut `std::size_t{1}` |
| `index_of({1,2}, 9)` | vide (`std::nullopt`) |
| `safe_divide(10, 2)` | a une valeur, et vaut `5` |
| `safe_divide(1, 0)` | vide (`std::nullopt`) |

## Compiler & tester

```bash
g++ -std=c++20 -Wall -Wextra -Wpedantic -I ../.. optionnel_skeleton.cpp optionnel_test.cpp -o test && ./test
```
