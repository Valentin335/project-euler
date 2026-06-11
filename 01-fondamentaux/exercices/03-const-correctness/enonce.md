# Exercice 03 — const-correctness & références ★★

**Difficulté :** ★★☆☆☆
**Sections du cours :** 5 (const), 6 (références), 17 (erreurs)

## Objectif

Manipuler des `std::string` **sans copie inutile** grâce aux références, et
distinguer les deux intentions que le type d'un paramètre exprime :

- `const std::string& s` → « je lis `s`, je ne le modifie pas, et je ne le
  recopie pas ».
- `std::string& s` → « je modifie `s` directement, chez l'appelant ».

On en profite pour signaler une entrée invalide avec une **exception**
(`std::invalid_argument`) plutôt que de renvoyer une valeur bidon.

## Signatures imposées (`constref.hpp`)

```cpp
std::size_t length(const std::string& s);  // taille, sans copie
char first_char(const std::string& s);      // 1er caractère ; throw std::invalid_argument si s est vide
void append_excl(std::string& s);           // ajoute " !" à la fin de s, en place
```

Tu complètes `constref_skeleton.cpp`. Ne touche pas au `.hpp`.

## Contraintes

- Bibliothèques imposées : `<string>` et `<cstddef>` (déjà inclus par le `.hpp`),
  `<stdexcept>` pour l'exception.
- Aucune bibliothèque hors standard.
- `length` et `first_char` reçoivent une **référence constante** : interdiction
  de copier la chaîne. Le type de retour `std::size_t` est celui que `std::string`
  utilise pour sa taille.
- `append_excl` modifie la chaîne **en place** : pas de valeur de retour, c'est la
  chaîne de l'appelant qui change.
- `first_char` sur une chaîne **vide** doit lever `std::invalid_argument`
  (et surtout pas accéder à un caractère qui n'existe pas).

## Cas de test (dans `constref_test.cpp`)

| Appel | Résultat attendu |
|-------|------------------|
| `length("hello")` | `5` |
| `length("")` | `0` |
| `first_char("abc")` | `'a'` |
| `first_char("")` | lève `std::invalid_argument` |
| `append_excl(s)` avec `s == "ok"` | `s` devient `"ok !"` |

## Compiler & tester

```bash
g++ -std=c++20 -Wall -Wextra -Wpedantic -I ../.. constref_skeleton.cpp constref_test.cpp -o test && ./test
```
