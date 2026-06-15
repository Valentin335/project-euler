# Compiler et tester — Chapitre 2

Comme au chapitre 1, **pas de CMake** : on compile à la main avec `g++` et on
teste avec le harnais maison `check.hpp`. On formalisera CMake plus tard ; ici,
on reste proche de la « vie sans build system » pour bien voir ce qui se passe.

## Tester un exercice

Depuis le dossier d'un exercice (ex. `exercices/02-palindrome/`) :

```bash
g++ -std=c++20 -Wall -Wextra -Wpedantic -I ../.. \
    palindrome_skeleton.cpp palindrome_test.cpp -o test && ./test
```

- On compile **deux** fichiers : ton squelette (ta solution) + le fichier de
  test fourni.
- `-I ../..` ajoute la **racine du chapitre** (`02-string-vector/`) aux chemins
  de recherche des `#include "..."` : c'est là que se trouve `check.hpp`, que
  les fichiers de test incluent.
- `&& ./test` ne lance l'exécutable que si la compilation a réussi.
- Le programme affiche un bilan et renvoie le **code retour `0` si tout passe**,
  `1` sinon. Vérifie-le avec `echo $?` après l'exécution si besoin.

Adapte le `<slug>` selon l'exercice. La ligne générique :

```bash
g++ -std=c++20 -Wall -Wextra -Wpedantic -I ../.. \
    <slug>_skeleton.cpp <slug>_test.cpp -o test && ./test
```

Slugs par exercice : `parcours`, `palindrome`, `geometry`, `histogram`,
`grille`, `strtools`, `split`. Chaque énoncé rappelle la ligne exacte en bas
de page.

## Drapeaux expliqués

| Drapeau | Rôle |
|---------|------|
| `-std=c++20` | active le C++ moderne |
| `-Wall -Wextra -Wpedantic` | avertissements stricts — **lis-les** |
| `-I <dir>` | ajoute un dossier de recherche pour les `#include "..."` |
| `-o <nom>` | nomme l'exécutable produit |

## Cas particulier : l'exercice 03 (module géométrie)

L'exercice 03 sépare déclaration (`geometry.hpp`) et définition
(`geometry_skeleton.cpp`). La ligne de compilation reste la même : on passe
le `.cpp` de la solution et le `.cpp` de test, et le `.hpp` est tiré par les
`#include`. Pas besoin de compiler le `.hpp` à part.

```bash
g++ -std=c++20 -Wall -Wextra -Wpedantic -I ../.. \
    geometry_skeleton.cpp geometry_test.cpp -o test && ./test
```

## Astuce : un Makefile rapide (optionnel)

Si retaper la ligne t'ennuie, pose dans le dossier d'un exercice un petit
`Makefile` :

```make
test: *_skeleton.cpp *_test.cpp
	g++ -std=c++20 -Wall -Wextra -Wpedantic -I ../.. $^ -o test && ./test
```

puis lance `make`.

## Drapeaux utiles pour débuguer (facultatif)

- `-g` : ajoute les infos de débogage (pour `gdb`).
- `-fsanitize=address,undefined` : détecte accès mémoire invalides et
  comportements indéfinis à l'exécution. Très instructif sur les accès
  `vector`/`string` hors bornes et les `char` négatifs passés à `<cctype>` :

```bash
g++ -std=c++20 -Wall -Wextra -Wpedantic -g -fsanitize=address,undefined \
    -I ../.. <slug>_skeleton.cpp <slug>_test.cpp -o test && ./test
```
