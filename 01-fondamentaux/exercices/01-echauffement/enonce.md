# Exercice 01 — Échauffement arithmétique ★

**Difficulté :** ★☆☆☆☆
**Sections du cours :** 2 (structure), 4 (types & overflow), 11 (fonctions)

## Objectif

Trois fonctions élémentaires pour se remettre en jambes. L'enjeu caché :
**le débordement d'entier**.

## Signatures imposées (`echauffement.hpp`)

```cpp
int square(int x);          // x au carré
long long sum_to(int n);    // 1 + 2 + ... + n   (on suppose n >= 0)
bool is_even(int x);        // x est-il pair ?
```

Tu complètes `echauffement_skeleton.cpp`. Ne touche pas au `.hpp`.

## Contraintes

- Aucune bibliothèque hors standard.
- `sum_to` doit gérer `n` jusqu'à `100000` **sans overflow**. Réfléchis : quelle
  est la valeur de `sum_to(100000)` ? Tient-elle dans un `int` ? D'où le type de
  retour `long long`. (Et attention : `int * int` se calcule en `int`…)

## Cas de test (dans `echauffement_test.cpp`)

| Appel | Résultat attendu |
|-------|------------------|
| `square(5)` | `25` |
| `square(-3)` | `9` |
| `sum_to(0)` | `0` |
| `sum_to(1)` | `1` |
| `sum_to(100)` | `5050` |
| `sum_to(100000)` | `5000050000` |
| `is_even(0)` | `true` |
| `is_even(7)` | `false` |
| `is_even(-4)` | `true` |

## Compiler & tester

```bash
g++ -std=c++20 -Wall -Wextra -Wpedantic -I ../.. \
    echauffement_skeleton.cpp echauffement_test.cpp -o test && ./test
```
