# Compiler et tester — Chapitre 4

Comme aux chapitres précédents, **pas encore de CMake** : on compile à la main
avec `g++` et on teste avec le harnais maison `check.hpp`. (Le projet de
synthèse sera « cmakifié » au chapitre 5 — c'est justement le but de vivre
encore une fois la compilation manuelle.)

## Tester un exercice (avec squelette : 01, 03, 04)

Depuis le dossier d'un exercice (ex. `exercices/01-optionnel/`) :

```bash
g++ -std=c++20 -Wall -Wextra -Wpedantic -I ../.. \
    optionnel_skeleton.cpp optionnel_test.cpp -o test && ./test
```

Adapte le nom du `_skeleton.cpp` / `_test.cpp` selon l'exercice :

| Exercice | Commande |
|----------|----------|
| 01 — optionnel | `g++ -std=c++20 -Wall -Wextra -Wpedantic -I ../.. optionnel_skeleton.cpp optionnel_test.cpp -o test && ./test` |
| 03 — moyenne | `g++ -std=c++20 -Wall -Wextra -Wpedantic -I ../.. moyenne_skeleton.cpp moyenne_test.cpp -o test && ./test` |
| 04 — config | `g++ -std=c++20 -Wall -Wextra -Wpedantic -I ../.. config_skeleton.cpp config_test.cpp -o test && ./test` |

### Pourquoi `-I ../..` ?

Les fichiers de test font `#include "check.hpp"`. Ce header se trouve à la
**racine du chapitre** (`04-optional-map-projet/check.hpp`) ; depuis un dossier
d'exercice, elle est deux niveaux au-dessus, d'où `-I ../..`. Ce `check.hpp`
inclut à son tour `../common/check.hpp` (le vrai harnais, partagé par tous les
chapitres) — tu n'as donc qu'un seul `-I` à passer.

On compile **deux** fichiers : ton squelette (ta solution) **et** le fichier de
test fourni.

### Code retour

`./test` affiche un bilan (tests passés / échoués) et renvoie **0 si tout
passe**, 1 sinon. Le `&& ./test` n'exécute le binaire que si la compilation a
réussi. Pour voir le code retour explicitement : `./test ; echo $?`.

## Compiler l'exercice autonome (02 — compteur de mots)

Pas de header `check.hpp`, pas de fichier de test : un seul fichier que tu écris
toi-même, `main` compris. Crée `compteur.cpp` dans `exercices/02-compteur-mots/`,
puis :

```bash
g++ -std=c++20 -Wall -Wextra -Wpedantic compteur.cpp -o compteur && ./compteur
# tape du texte, puis Ctrl-D pour terminer l'entrée standard
```

Ici **pas de `-I ../..`** : aucun include du harnais. La validation est
manuelle (tu compares la sortie à ce qu'attend l'énoncé).

## Drapeaux expliqués

| Drapeau | Rôle |
|---------|------|
| `-std=c++20` | active le C++ moderne (`std::optional`, structured bindings, `contains`…) |
| `-Wall -Wextra -Wpedantic` | avertissements stricts — **lis-les** |
| `-I <dir>` | ajoute un dossier de recherche pour les `#include "..."` |
| `-o <nom>` | nomme l'exécutable produit |

## Drapeaux utiles pour débuguer (facultatif)

- `-g` : ajoute les infos de débogage (pour `gdb`).
- `-fsanitize=address,undefined` : détecte accès mémoire invalides et
  comportements indéfinis à l'exécution (par ex. déréférencer l'itérateur de
  `min_element` sur un conteneur vide, ou `*opt` sur un optional vide) :

```bash
g++ -std=c++20 -Wall -Wextra -Wpedantic -g -fsanitize=address,undefined \
    -I ../.. exo_skeleton.cpp exo_test.cpp -o test && ./test
```

## Le projet

Le projet de synthèse (`projet/`) a sa **propre** notice de compilation, avec
ses deux lignes `g++` (l'appli et les tests) : voir `projet/COMPILER.md`.
