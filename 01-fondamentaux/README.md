# Chapitre 1 — Rallumer la machine : C++ moderne en mains propres

> Durée estimée : **au moins une semaine** de travail.

Ce chapitre réactive tes réflexes C++ et installe les bonnes habitudes de toute
la formation : compilation propre, types et overflow, références, fonctions,
`.hpp`/`.cpp`, namespaces, RAII en survol, gestion d'erreurs.

## Le cours

Compile le support de cours :

```bash
cd cours
latexmk -pdf cours.tex     # produit cours.pdf
```

Lis `cours.pdf` en premier. Il couvre 17 sections, chacune reliée à un ou
plusieurs exercices.

## Les exercices

14 exercices en difficulté croissante (★ à ★★★★★), dans `exercices/` :

Les exercices `Nb` (ex. `02b`) sont des exercices **doux et très guidés**,
ajoutés pour reprendre en douceur après une pause loin du C++. Ils précèdent
l'exercice qui approfondit la même notion (c'est aussi l'ordre dans lequel
`ls` les affiche). Suis l'ordre du tableau de haut en bas.

| #  | Exercice | ★ | Thème |
|----|----------|---|-------|
| 01 | Échauffement arithmétique | ★ | types, overflow, `long long` |
| 02b | Valeur ou référence | ★ | **copie vs référence** (guidé) |
| 02 | Conversions de température | ★ | fonctions, retour de littéraux |
| 03b | Déclarations, `auto`, copie/réf | ★ | **`auto`, types statiques** (guidé) |
| 03 | const-correctness & références | ★★ | `const&`, `&`, exceptions |
| 04 | Échange & rotation | ★★ | références (sans `std::swap`) |
| 05 | Statistiques sur `vector` | ★★ | range-for, exceptions |
| 06b | Parcourir un `vector` | ★★ | **range-for : lire / modifier** (guidé) |
| 06 | Renversement & palindrome | ★★ | `std::string`, casse |
| 07 | Surcharge de `describe` | ★★ | résolution de surcharge |
| 08 | FizzBuzz paramétrable | ★★ | `std::string`, `std::vector` |
| 09b | Portée & somme par référence | ★★ | **durée de vie, accumulateur** (guidé) |
| 09 | Module `geometry` (.hpp/.cpp) | ★★★ | headers, namespaces, linker |
| 10 | Comptage & histogramme | ★★★ | `std::string`, tableaux |
| 11 | Parsing robuste d'entiers | ★★★ | `std::stoll`, validation |
| 12 | Optionnel | ★★★★ | `std::optional` |
| 13 | Mini-grille | ★★★★ | `vector<vector<int>>`, `at()` |
| 14 | RAII `ScopedAppender` | ★★★★★ | destructeur, `=delete` |

Pour chaque exercice :

1. Lis `enonce.md`.
2. Regarde les signatures imposées dans le `.hpp` (ne le modifie pas).
3. Complète le fichier `*_skeleton.cpp` (**ta solution**).
4. Compile et teste (voir `COMPILER.md`).
5. Quand tous les tests passent, dis-le — on pourra comparer avec le corrigé.

### Faire relire un exercice : `/review-exo`

Une fois ta solution écrite, tu peux lancer le skill de revue :

```
/review-exo 05-stats-vector
```

Il compile, lance la batterie de tests, et vérifie que tu respectes l'esprit du
cours (bibliothèques interdites, signatures, idiomes modernes). Il **ne te
donne jamais la solution** — il pointe ce qui cloche par des questions et des
indices.

## Le projet de synthèse

Dans `projet/` : un **mini-REPL de statistiques** qui combine toutes les notions
du chapitre. À faire une fois les exercices digérés. Il sert de pont vers le
chapitre 2 (on le « cmakifiera »).

## Règle d'or

C'est **toi** qui codes. L'assistant guide, explique, débugue avec toi — mais
n'écrit pas la solution à ta place. Les corrigés (`solutions/`) ne se regardent
qu'**après** avoir réussi.
