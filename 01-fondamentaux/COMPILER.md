# Compiler et tester — Chapitre 1

Au chapitre 1, **pas de CMake** : on compile à la main avec `g++` et on teste
avec le harnais maison `check.hpp`. C'est volontaire — on vivra la « vie sans
build system » avant de découvrir CMake au chapitre 2.

## Tester un exercice

Depuis le dossier d'un exercice (ex. `exercices/01-echauffement/`) :

```bash
g++ -std=c++20 -Wall -Wextra -Wpedantic -I ../.. \
    echauffement_skeleton.cpp echauffement_test.cpp -o test && ./test
```

- `-I ../..` permet de trouver `check.hpp` (situé dans `01-fondamentaux/`).
- On compile **deux** fichiers : ton squelette (ta solution) + le fichier de
  test fourni.
- Le programme affiche un bilan ; il renvoie le code 0 si tout passe, 1 sinon.

Adapte le nom du fichier `_skeleton.cpp` selon l'exercice (`temperatures_skeleton.cpp`, etc.).

## Astuce : un Makefile rapide (optionnel)

Si retaper la ligne t'ennuie, tu peux poser dans le dossier d'un exercice un
petit `Makefile` :

```make
test: *_skeleton.cpp *_test.cpp
	g++ -std=c++20 -Wall -Wextra -Wpedantic -I ../.. $^ -o test && ./test
```

puis lancer `make`. (On formalisera tout ça proprement avec CMake au ch.2.)

## Drapeaux expliqués

| Drapeau | Rôle |
|---------|------|
| `-std=c++20` | active le C++ moderne |
| `-Wall -Wextra -Wpedantic` | avertissements stricts — **lis-les** |
| `-I <dir>` | ajoute un dossier de recherche pour les `#include "..."` |
| `-o <nom>` | nomme l'exécutable produit |

## Drapeaux utiles pour débuguer (facultatif)

- `-g` : ajoute les infos de débogage (pour `gdb`).
- `-fsanitize=address,undefined` : détecte accès mémoire invalides et
  comportements indéfinis à l'exécution. Très instructif :

```bash
g++ -std=c++20 -Wall -Wextra -Wpedantic -g -fsanitize=address,undefined \
    -I ../.. exo_skeleton.cpp exo_test.cpp -o test && ./test
```
