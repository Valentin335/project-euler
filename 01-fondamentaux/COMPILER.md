# Compiler et tester — Chapitre 1

Au chapitre 1, **pas de CMake** : on compile à la main avec `g++` et on teste
avec le harnais maison `check.hpp`. C'est volontaire — on vit la « vie sans
build system » avant de découvrir CMake au chapitre 2.

## Tester un exercice

Depuis le dossier d'un exercice (ex. `exercices/01-echauffement/`) :

```bash
g++ -std=c++20 -Wall -Wextra -Wpedantic -I ../.. \
    echauffement_skeleton.cpp echauffement_test.cpp -o test && ./test
```

- On compile **deux** fichiers : ton squelette (ta solution) + le fichier de
  test fourni. Le `.hpp` est inclus par les deux, il n'apparaît pas sur la
  ligne de commande.
- `-I ../..` ajoute le dossier `01-fondamentaux/` aux chemins de recherche des
  `#include "..."`, ce qui permet au test de trouver `check.hpp` (placé à la
  racine du chapitre).
- Le programme affiche un bilan et **renvoie le code 0 si tous les cas passent**,
  1 sinon. Le `&& ./test` n'exécute le binaire que si la compilation a réussi ;
  tu peux vérifier le code de retour avec `echo $?`.

Adapte simplement le slug selon l'exercice :

```bash
# exemple pour 06-fizzbuzz
g++ -std=c++20 -Wall -Wextra -Wpedantic -I ../.. \
    fizzbuzz_skeleton.cpp fizzbuzz_test.cpp -o test && ./test
```

Les slugs des huit exercices : `echauffement`, `temperatures`, `valref`,
`constref`, `describe`, `fizzbuzz`, `dispatch`, `racine`.

## Drapeaux expliqués

| Drapeau                    | Rôle                                                         |
|----------------------------|-------------------------------------------------------------|
| `-std=c++20`               | active le C++ moderne (norme 2020)                          |
| `-Wall -Wextra -Wpedantic` | avertissements stricts — **lis-les**, ils signalent les pièges |
| `-I <dir>`                 | ajoute un dossier de recherche pour les `#include "..."`    |
| `-o <nom>`                 | nomme l'exécutable produit                                  |

Considère un warning comme une erreur : si `-Wall -Wextra -Wpedantic` se
plaint, corrige avant de continuer.

## Astuce : un Makefile minimal (optionnel)

Si retaper la ligne t'ennuie, dépose dans le dossier d'un exercice un petit
`Makefile` :

```make
test: *_skeleton.cpp *_test.cpp
	g++ -std=c++20 -Wall -Wextra -Wpedantic -I ../.. $^ -o test && ./test
```

puis lance `make`. (On formalisera tout ça proprement avec CMake au ch.2.)

## Débuguer (facultatif)

- `-g` : ajoute les infos de débogage (pour `gdb`).
- `-fsanitize=address,undefined` : détecte accès mémoire invalides et
  comportements indéfinis à l'exécution. Très instructif :

```bash
g++ -std=c++20 -Wall -Wextra -Wpedantic -g -fsanitize=address,undefined \
    -I ../.. echauffement_skeleton.cpp echauffement_test.cpp -o test && ./test
```
