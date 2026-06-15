# Compiler et tester — Chapitre 3

Comme au chapitre 1, on compile **à la main** avec `g++` et on teste avec le
harnais maison `check.hpp` (situé à la racine du chapitre, `03-io-flux-parsing/`).
Pas de CMake ici.

## Tester un exercice à squelette (01, 03)

Depuis le dossier de l'exercice (ex. `exercices/01-parsing/`) :

```bash
g++ -std=c++20 -Wall -Wextra -Wpedantic -I ../.. \
    parse_int_skeleton.cpp parse_int_test.cpp -o test && ./test
```

- `-I ../..` ajoute la racine du chapitre aux chemins de recherche, ce qui
  permet à `*_test.cpp` de trouver `check.hpp`.
- On compile **deux** fichiers : ton squelette (ta solution) + le fichier de
  test fourni.
- Le programme affiche un bilan et renvoie le **code 0 si tout passe**, 1
  sinon (tu peux vérifier avec `echo $?` juste après).

Adapte les noms de fichiers selon l'exercice. Pour le 03 :

```bash
g++ -std=c++20 -Wall -Wextra -Wpedantic -I ../.. \
    tokenize_skeleton.cpp tokenize_test.cpp -o test && ./test
```

## Compiler l'exercice autonome (02)

L'exercice 02 (mini-calculatrice) n'a ni squelette ni test : tu écris tout le
programme dans un fichier que tu crées toi-même (`calculatrice.cpp`). Pas de
`check.hpp`, donc pas de `-I ../..`. On obtient un vrai exécutable qu'on lance
et qu'on teste **à la main** (au clavier) :

```bash
g++ -std=c++20 -Wall -Wextra -Wpedantic calculatrice.cpp -o calc && ./calc
```

Tape des lignes comme `3 + 4`, `10 - 2.5`, `8 / 0`, `bonjour`, puis `quit`
(ou Ctrl-D) pour quitter.

## Astuce : un Makefile rapide (optionnel)

Si retaper la ligne t'ennuie, pose dans le dossier d'un exercice à squelette
un petit `Makefile` :

```make
test: *_skeleton.cpp *_test.cpp
	g++ -std=c++20 -Wall -Wextra -Wpedantic -I ../.. $^ -o test && ./test
```

puis lance `make`.

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
  comportements indéfinis à l'exécution :

```bash
g++ -std=c++20 -Wall -Wextra -Wpedantic -g -fsanitize=address,undefined \
    -I ../.. parse_int_skeleton.cpp parse_int_test.cpp -o test && ./test
```
