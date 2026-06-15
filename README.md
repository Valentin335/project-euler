# Formation C++ moderne

Une formation C++ par la pratique, en 18 chapitres. Chaque chapitre est
**sectionné** : le cours présente une brique (bibliothèque + fonctions utiles)
**avant** les exercices qui la pratiquent. Les exercices sont notés en étoiles
(★) avec tests de validation automatisés, et chaque chapitre se termine par un
**projet de synthèse**.

> **Règle d'or de la formation.** Aucun exercice n'exige un outil qui n'a pas
> été présenté avant — soit dans une section de cours d'un chapitre antérieur,
> soit dans une section `## Aide` de son propre énoncé. Tu dois toujours pouvoir
> écrire ta solution avec ce qu'on t'a montré.

## Progression

| #  | Chapitre | Thème |
|----|----------|-------|
| 01 | `01-fondamentaux/` | Compiler, typer, choisir : types, `static_cast`, `const`, références, fonctions/surcharge, contrôle, exceptions |
| 02 | `02-string-vector/` | `std::string` & `std::vector` au quotidien + organiser son code (`.hpp`/`.cpp`, namespaces, `<cctype>`) |
| 03 | `03-io-flux-parsing/` | Lire le monde : I/O, `getline`, `std::istringstream`, conversion `stoll`/`stod` |
| 04 | `04-optional-map-projet/` | `std::optional`, `std::map`, algos (survol) — **projet : mini-REPL stats** |
| 05 | `05-cmake-catch2/` | Build system (CMake) et tests (Catch2) |
| 06 | `06-memoire-pointeurs/` | Pointeurs, références, durée de vie, mémoire |
| 07 | `07-string-vector-profond/` | `std::string`/`std::vector` en profondeur (`string_view`, `reserve`, invalidation) |
| 08 | `08-conteneurs-stl/` | `map`, `set`, `unordered_*`, `tuple`, adaptateurs |
| 09 | `09-algorithmes-iterateurs/` | `<algorithm>`, `<numeric>`, itérateurs |
| 10 | `10-poo-classes-raii/` | Classes, RAII, règle de 0/3/5, opérateurs |
| 11 | `11-heritage-polymorphisme-echecs/` | Héritage, polymorphisme (projet : échecs) |
| 12 | `12-templates-generique/` | Templates, programmation générique |
| 13 | `13-smart-pointers-move/` | Smart pointers, sémantique de mouvement |
| 14 | `14-lambdas-foncteurs/` | Lambdas, foncteurs, `std::function` |
| 15 | `15-recursion/` | La pensée récursive (backtracking, mémoïsation) |
| 16 | `16-cpp20-ranges-concepts/` | C++20 : concepts, ranges, `variant`/`expected` |
| 17 | `17-concurrence-threads/` | Threads, mutex, atomics, `async` |
| 18 | `18-projet-final/` | Projet final intégrant tout |

Les chapitres 1 à 4 se compilent à la main (`g++` + harnais maison
`common/check.hpp`). CMake et Catch2 arrivent au chapitre 5.

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
