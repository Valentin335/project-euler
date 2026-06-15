# Compiler le projet — Mini-REPL de statistiques

Deux choses à compiler : **l'application** (le REPL) et **les tests**.

Le harnais `check.hpp` est dans `01-fondamentaux/`, soit le dossier parent de
`projet/` (`..`). Le header `stats.hpp` est dans `include/`.

## 1. Compiler et lancer les tests

Depuis le dossier `projet/` :

```bash
g++ -std=c++20 -Wall -Wextra -Wpedantic -I include -I .. src/stats_skeleton.cpp tests/stats_test.cpp -o run_tests && ./run_tests
```

- `-I include` : pour trouver `stats.hpp`.
- `-I ..` : pour trouver `check.hpp` (dans `01-fondamentaux/`).
- On compile `stats_skeleton.cpp` (tes fonctions) + `stats_test.cpp` (les tests).
- `run_tests` renvoie 0 si tout passe, 1 sinon.

## 2. Compiler et lancer l'application

```bash
g++ -std=c++20 -Wall -Wextra -Wpedantic -I include src/stats_skeleton.cpp src/main_skeleton.cpp -o stats_repl && ./stats_repl
```

- On compile `stats_skeleton.cpp` (tes fonctions) + `main_skeleton.cpp` (le REPL).
- **Pas** de `stats_test.cpp` ici (sinon deux `main`).

## Tu trouves ça pénible ?

Deux lignes longues, à retaper, et tout se recompile à chaque changement même
si tu n'as touché qu'un fichier. **C'est exactement le problème que CMake
résout** — rendez-vous au chapitre 2, où ce projet sera le point de départ.
