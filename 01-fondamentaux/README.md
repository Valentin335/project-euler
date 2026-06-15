# Chapitre 1 — Fondamentaux : compiler, typer, choisir

Le cœur du langage C++ sans la STL avancée : types et `static_cast`, `const` et
références, fonctions et surcharge, structures de contrôle, et les deux styles
de gestion d'erreur (code de retour vs exceptions). On compile **à la main**
avec `g++` et on teste avec le harnais maison `check.hpp` — on vivra la « vie
sans build system » avant de découvrir CMake au chapitre 2.

## Le cours

Compile le support de cours puis lis-le **en premier** :

```bash
cd cours
latexmk -pdf cours.tex     # produit cours.pdf
# (ou, sans latexmk :)  pdflatex cours.tex
```

Lis `cours.pdf` avant d'attaquer les exercices : il introduit chaque notion
(compilation, types/overflow, `const`, valeur vs référence, fonctions/surcharge,
contrôle, gestion d'erreurs) que les exercices viennent ensuite mettre en
pratique.

## Les exercices

Huit exercices en difficulté croissante, dans `exercices/`. Tous fournissent un
squelette (`*_skeleton.cpp`) et un fichier de test (`*_test.cpp`) : **aucun
n'est autonome**, tu n'as jamais à écrire le `main` toi-même. Suis l'ordre du
tableau de haut en bas.

| #  | Exercice                | ★ | Thème                                              |
|----|-------------------------|---|---------------------------------------------------|
| 01 | Échauffement            | ★ | types, overflow, `static_cast`                    |
| 02 | Températures            | ★ | fonctions, division flottante (formules données)  |
| 03 | Valeur ou référence     | ★ | passage par copie vs `&`, modification en place   |
| 04 | Const et exceptions     | ★ | `const&`, `&`, `throw`                             |
| 05 | Surcharge               | ★ | surcharge de fonctions, choix selon le type       |
| 06 | FizzBuzz                | ★ | structures de contrôle, `to_string`               |
| 07 | Dispatch de commandes   | ★ | `switch` sur un `char`                             |
| 08 | Racine sûre             | ★ | code de retour (`out&`) vs exceptions             |

## Comment travailler

Pour chaque exercice (01 à 08) :

1. Lis `enonce.md` (court : objectif, signatures, outil/aide, cas de test).
2. Regarde les signatures imposées dans le `.hpp` (**ne le modifie pas**).
3. Complète le fichier `*_skeleton.cpp` (**ta solution**) — les commentaires
   `/* entrée → sortie */` te rappellent le contrat.
4. Compile et teste (voir `COMPILER.md`) ; le code de retour `0` signifie que
   tous les cas passent.
5. Quand tous les tests passent, dis-le **explicitement** — on pourra alors
   comparer avec le corrigé.

## Table de couverture (règle d'or)

Aucun outil n'est exigé sans avoir été présenté, soit par le cours de ce
chapitre (ou un chapitre antérieur), soit par une section `## Outil`/`## Aide`
locale à l'énoncé.

| Exercice                  | Outils exigés                                       | Source                                                     |
|---------------------------|-----------------------------------------------------|------------------------------------------------------------|
| 01 — Échauffement         | `static_cast`, types 64 bits                        | cours ch.1 §Types fondamentaux, overflow, `static_cast` + Aide locale (`## Outil`) |
| 02 — Températures         | `const char*`, division flottante                   | cours ch.1 §Types fondamentaux ; §Fonctions                |
| 03 — Valeur ou référence  | `T&` (référence), modification en place ; `std::vector` | cours ch.1 §Valeur ou référence ; `vector` : cours ch.2 §`std::vector` |
| 04 — Const et exceptions  | `const&`, `&`, `throw`/`std::invalid_argument` ; `std::string` | cours ch.1 §`const` ; §Valeur ou référence ; §Gestion d'erreurs + Aide locale (`## Outil`) ; `string` : cours ch.2 §`std::string` |
| 05 — Surcharge            | surcharge de fonctions ; `std::to_string`/`std::format` ; `std::string` | cours ch.1 §Fonctions (surcharge) + Aide locale (`## Outil`) ; `string` : cours ch.2 |
| 06 — FizzBuzz             | `%`, `if`/`for` ; `std::to_string` ; `std::vector`/`std::string` | cours ch.1 §Structures de contrôle + Aide locale (`## Outil`) ; `vector`/`string` : cours ch.2 |
| 07 — Dispatch de commandes| `switch` sur `char` ; `std::to_string` ; `std::string` | cours ch.1 §Structures de contrôle + Aide locale (`## Aide`) ; `string` : cours ch.2 |
| 08 — Racine sûre          | `out&`, `throw`/`std::domain_error`/`std::invalid_argument`, boucle | cours ch.1 §Gestion d'erreurs ; §Valeur ou référence + Aide locale (`## Aide`) |

> Note : `std::string` et `std::vector` sont le sujet propre du **chapitre 2**.
> Ici on ne s'en sert que de façon élémentaire (taille, accès, range-for,
> concaténation), juste assez pour exercer le cœur du langage ; leur étude
> détaillée vient au chapitre suivant.

## Le projet

Pas de gros projet dans ce chapitre : on travaille le langage seul. Le **projet
de synthèse** de cette première partie de la formation (un mini-REPL de
statistiques) arrive au **chapitre 4**, une fois les outils des chapitres 2 à 4
en main.

Les corrigés sont dans `solutions/`, à consulter **après** avoir réussi.
