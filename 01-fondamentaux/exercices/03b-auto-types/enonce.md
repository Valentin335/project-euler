# Exercice 03b — Déclarations, auto, copie ou référence ★

**Difficulté :** ★☆☆☆☆
**Sections du cours :** « Types fondamentaux et auto », « Valeur ou référence »

## Objectif

Se remettre en tête le **typage statique** du C++ (chaque variable a un type
fixé à la compilation), comprendre ce que `auto` déduit, et — surtout —
distinguer **copie** et **référence** quand on déclare une variable.

## Rappel pédagogique

En C++, le compilateur connaît le type de chaque variable **avant** d'exécuter
le programme. `auto` ne supprime pas ce type : il demande juste de le **déduire**
à partir de la valeur d'initialisation. Le point délicat, c'est *copie ou
référence* :

```cpp
auto  x = quelque_chose;   // x est une COPIE indépendante.
auto& x = quelque_chose;   // x est une RÉFÉRENCE : un autre nom pour la
                           // même case mémoire. Modifier x modifie l'original.
```

Donc : pour **lire** une valeur, une copie (`auto`) suffit. Pour **modifier**
l'original en place, il faut une **référence** (`auto&`). À noter aussi que
`v[0]` sur un `std::vector` est déjà une référence sur le premier élément.

## Signatures imposées (`autotypes.hpp`)

```cpp
int premier_element(const std::vector<int>& v);  // renvoie v[0] ; throw std::out_of_range si v est vide
void incremente_premier(std::vector<int>& v);     // ajoute 1 au premier élément, en place ; throw std::out_of_range si vide
std::size_t taille(const std::string& s);         // longueur de s (illustre std::size_t et const&)
```

Tu complètes `autotypes_skeleton.cpp`. Ne touche pas au `.hpp`.

## Contraintes

- Bibliothèques imposées : `<vector>`, `<string>` et `<cstddef>` (déjà inclus
  par le `.hpp`), `<stdexcept>` pour l'exception.
- Aucune bibliothèque hors standard.
- `premier_element` et `taille` reçoivent une **référence constante** :
  interdiction de copier l'argument.
- `incremente_premier` modifie le vecteur **en place** : pas de valeur de
  retour, c'est le vecteur de l'appelant qui change. Une copie locale ne
  suffirait pas — il faut une **référence** vers le premier élément.
- Sur un conteneur **vide**, `premier_element` et `incremente_premier` doivent
  lever `std::out_of_range` (et surtout pas accéder à un élément inexistant).
- `taille` renvoie un `std::size_t` (le type que `std::string` utilise pour sa
  taille).

## Cas de test (dans `autotypes_test.cpp`)

| Appel | Résultat attendu |
|-------|------------------|
| `premier_element({7, 8, 9})` | `7` |
| `premier_element({})` | lève `std::out_of_range` |
| `incremente_premier(v)` avec `v == {4, 5}` | `v` devient `{5, 5}` |
| `incremente_premier(e)` avec `e == {}` | lève `std::out_of_range` |
| `taille("bonjour")` | `7` |
| `taille("")` | `0` |

## Compiler & tester

```bash
g++ -std=c++20 -Wall -Wextra -Wpedantic -I ../.. autotypes_skeleton.cpp autotypes_test.cpp -o test && ./test
```
