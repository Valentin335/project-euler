# Formation C++ moderne

Une formation C++ par la pratique, en ~15 chapitres et ~260 exercices. Chaque
chapitre couvre un thème, propose des exercices notés de 1 à 5 étoiles (★) avec
tests de validation automatisés, et se termine par un **gros projet de
synthèse**.

## Progression

| #  | Chapitre | Thème |
|----|----------|-------|
| 01 | `01-fondamentaux/` | C++ moderne : bonnes pratiques, types, références, fonctions |
| 02 | `02-cmake-catch2/` | Build system (CMake) et tests (Catch2) |
| 03 | `03-memoire-pointeurs/` | Pointeurs, références, durée de vie, mémoire |
| 04 | `04-string-vector/` | `std::string` et `std::vector` en profondeur |
| 05 | `05-conteneurs-stl/` | `map`, `set`, `unordered_*`, `tuple`, adaptateurs |
| 06 | `06-algorithmes-iterateurs/` | `<algorithm>`, `<numeric>`, itérateurs |
| 07 | `07-poo-classes-raii/` | Classes, RAII, règle de 0/3/5, opérateurs |
| 08 | `08-heritage-polymorphisme-echecs/` | Héritage, polymorphisme (projet : échecs) |
| 09 | `09-templates-generique/` | Templates, programmation générique |
| 10 | `10-smart-pointers-move/` | Smart pointers, sémantique de mouvement |
| 11 | `11-lambdas-foncteurs/` | Lambdas, foncteurs, `std::function` |
| 12 | `12-recursion/` | La pensée récursive (backtracking, mémoïsation) |
| 13 | `13-cpp20-ranges-concepts/` | C++20 : concepts, ranges, `optional`/`variant`/`expected` |
| 14 | `14-concurrence-threads/` | Threads, mutex, atomics, `async` |
| 15 | `15-projet-final/` | Projet final intégrant tout |

## Comment travailler un chapitre

Chaque chapitre contient :

- `cours/cours.tex` → compile en `cours.pdf` (le support de cours à lire) ;
- `exercices/NN-slug/` : un dossier par exercice avec
  - `enonce.md` : l'énoncé, la difficulté (★), les contraintes,
  - `*.hpp` : les signatures imposées (ne pas modifier),
  - `*_skeleton.cpp` : **le fichier à compléter** (ta solution),
  - `*_test.cpp` : les tests de validation (fournis) ;
- `projet/` : le gros projet de synthèse.

Les corrigés vivent à part dans `solutions/` et ne sont à consulter
qu'**après** avoir résolu l'exercice.

## Outils nécessaires

- **g++ 13+** (ou clang équivalent) avec support C++20.
- **CMake 3.28+** (à partir du chapitre 2).
- **TeX Live** (`pdflatex` / `latexmk`) pour compiler les cours.

## Compiler un cours (LaTeX → PDF)

```bash
cd 01-fondamentaux/cours
latexmk -pdf cours.tex      # produit cours.pdf
# ou : pdflatex cours.tex
```

## Compiler et tester un exercice (chapitre 1 — g++ à la main)

Le chapitre 1 se compile manuellement avec un mini-harnais de test maison
(`common/check.hpp`). Voir `01-fondamentaux/COMPILER.md`. Exemple :

```bash
cd 01-fondamentaux/exercices/01-echauffement
g++ -std=c++20 -Wall -Wextra -Wpedantic -I ../../../common \
    echauffement_skeleton.cpp echauffement_test.cpp -o test && ./test
```

## Compiler et tester (chapitre 2 et suivants — CMake + Catch2)

```bash
cmake -S . -B build
cmake --build build
ctest --test-dir build
```
