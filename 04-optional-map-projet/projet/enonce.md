# Projet de synthèse — Mini-REPL de statistiques ★★★★

**Difficulté :** ★★★★☆
**Prérequis :** avoir digéré les exercices 01 à 14.

Un programme console interactif (un **REPL** : *Read-Eval-Print Loop*) qui
maintient une liste de nombres et exécute des commandes dessus. Il combine
**toutes** les notions du chapitre : I/O, `std::string`, `std::vector`,
range-for, fonctions, surcharge, `const`-correctness, namespaces,
headers/sources, gestion d'erreurs.

## Comportement attendu

Le programme lit des commandes **ligne par ligne** sur l'entrée standard et
opère sur une liste de `double` maintenue en mémoire.

| Commande | Effet |
|----------|-------|
| `add x [y z ...]` | Ajoute un ou plusieurs nombres à la liste. |
| `count` | Affiche le nombre d'éléments. |
| `sum` | Affiche la somme. |
| `mean` | Affiche la moyenne (erreur claire si liste vide). |
| `min` / `max` | Affiche le min / max (erreur si vide). |
| `median` | Affiche la médiane. |
| `sort [asc\|desc]` | Trie la liste (asc par défaut) et la réaffiche. |
| `list` | Affiche tous les nombres. |
| `clear` | Vide la liste. |
| `help` | Affiche l'aide. |
| `quit` (ou EOF / Ctrl-D) | Quitte le programme (code 0). |

**Robustesse :** une commande inconnue ou un nombre mal formé affiche un message
sur `std::cerr` et le programme **continue** (il ne crashe jamais). Dans
`add 1 abc 2`, les valeurs valides sont ajoutées et l'invalide signalée.

## Architecture imposée

```
projet/
├── include/stats.hpp     <- signatures imposées (ne pas modifier)
├── src/stats_skeleton.cpp <- TU COMPLÈTES les fonctions de stats.hpp
├── src/main_skeleton.cpp  <- TU COMPLÈTES la boucle REPL
├── tests/stats_test.cpp   <- tests fournis (testent stats.hpp, pas le REPL)
└── COMPILER.md
```

## Signatures imposées (`include/stats.hpp`, `namespace stats`)

```cpp
namespace stats {
    double sum(const std::vector<double>& v);
    double mean(const std::vector<double>& v);        // throw std::domain_error si vide
    double min_value(const std::vector<double>& v);   // throw std::domain_error si vide
    double max_value(const std::vector<double>& v);   // throw std::domain_error si vide
    double median(std::vector<double> v);             // copie volontaire (tri local) ; throw si vide
    void   sort_in_place(std::vector<double>& v, bool ascending = true);

    std::vector<std::string> tokenize(const std::string& line);
    std::vector<double> parse_numbers(const std::vector<std::string>& tokens,
                                      std::size_t start);   // throw std::invalid_argument si token non numérique
}
```

> Remarque sur `median` : le paramètre est passé **par valeur** (copie) à
> dessein — tu peux trier la copie locale sans modifier la liste de l'appelant.
> Pour une liste de taille paire, la médiane est la moyenne des deux valeurs
> centrales.

La **boucle REPL** vit dans `main_skeleton.cpp`. Elle n'est pas testée
automatiquement (interaction) ; ce sont les fonctions de `stats.hpp` qui le
sont.

## Tester

Les fonctions de `stats.hpp` sont testées par `tests/stats_test.cpp` (harnais
maison). Voir `COMPILER.md` pour les deux lignes de compilation (l'appli et les
tests).

Cas de test (extrait) :

| Appel | Attendu |
|-------|---------|
| `sum({1,2,3,4})` | `10` |
| `sum({})` | `0` |
| `mean({2,4,6})` | `4` |
| `mean({})` | lève `std::domain_error` |
| `min_value({3,-1,2})` | `-1` |
| `max_value({3,-1,2})` | `3` |
| `median({3,1,2})` | `2` |
| `median({4,1,3,2})` | `2.5` |
| `median({})` | lève `std::domain_error` |
| `sort_in_place(v)` sur `{3,1,2}` | `{1,2,3}` |
| `sort_in_place(v,false)` sur `{3,1,2}` | `{3,2,1}` |
| `tokenize("add 1 2 3")` | `{"add","1","2","3"}` |
| `tokenize("   ")` | `{}` |
| `parse_numbers({"add","1","2.5"}, 1)` | `{1.0, 2.5}` |
| `parse_numbers({"x"}, 0)` | lève `std::invalid_argument` |

## Pont vers le chapitre 2

Tu vas devoir taper **deux** longues lignes `g++` à la main (une pour l'appli,
une pour les tests) et tout recompiler à chaque changement. Garde cette douleur
en tête : au chapitre 2, on reprendra **ce même projet** et on le « cmakifiera »
(une bibliothèque `stats`, un exécutable `stats_repl`, des tests migrés vers
Catch2, lancés par `ctest`). Tu sentiras alors tout l'intérêt d'un *build
system*.
