# Chapitre 2 — `string` & `vector` au quotidien, et organiser son code

`std::string` et `std::vector` en usage courant : parcours (range-for,
itérateurs en survol, `rbegin`/`rend` en boîte noire), classification de
caractères avec `<cctype>`, premiers pas dans `<algorithm>`, et l'organisation
du code (`.hpp`/`.cpp`, namespaces, RAII en survol).

## Le cours

Compile le support de cours :

```bash
cd cours
latexmk -pdf cours.tex     # produit cours.pdf
```

Lis `cours.pdf` **en premier**. Il couvre, dans l'ordre : `std::string` en
pratique, `std::vector` en pratique, parcourir un conteneur, classifier un
caractère avec `<cctype>`, découvrir `<algorithm>` en douceur, headers
(`.hpp`) vs sources (`.cpp`), namespaces, et RAII en survol.

## Les exercices

7 exercices, dans `exercices/`, à faire dans l'ordre du tableau. Chaque énoncé
introduit, quand c'est utile, le ou les **outils** dont tu auras besoin
(`rbegin`, `std::count`, `find`/`substr`, `std::hypot`…) avec un mini-exemple.

| #  | Exercice          | ★   | Thème                                            |
|----|-------------------|-----|--------------------------------------------------|
| 01 | Parcours de vector | ★   | range-for lire/modifier, `throw`                |
| 02 | Palindrome        | ★   | `rbegin`/`rend`, `<cctype>` (`tolower`)          |
| 03 | Module géométrie  | ★★  | `.hpp`/`.cpp`, `namespace geom`, `std::hypot`    |
| 04 | Histogramme       | ★   | `std::count`, `<cctype>`, indice `c - 'a'`       |
| 05 | Mini-grille       | ★★  | `vector<vector<int>>`, accès 2D, transposée      |
| 06 | String toolkit    | ★   | `<cctype>`, `find_first_not_of`/`substr`, casse  |
| 07 | Split maison      | ★   | `find`/`substr`/`npos`, champs vides conservés   |

Tous les exercices fournissent un `.hpp` (signatures imposées), un
`*_skeleton.cpp` (ta solution) et un `*_test.cpp` (tests fournis). Aucun
exercice n'est autonome à ce chapitre : tu ne réécris jamais le `main`.

## Comment travailler

Pour chaque exercice :

1. Lis `enonce.md` (objectif, signatures, outil/aide, cas de test).
2. Regarde les signatures imposées dans le `.hpp` (ne le modifie pas).
3. Complète le fichier `*_skeleton.cpp` (**ta solution**) — les commentaires
   `/* entrée → sortie */` rappellent le contrat.
4. Compile et teste (voir `COMPILER.md`). Le code retour `0` = tout passe.
5. Quand tous les tests passent, dis-le — on pourra comparer avec le corrigé.

### Faire relire un exercice : `/review-exo`

Une fois ta solution écrite, tu peux lancer le skill de revue :

```
/review-exo 02-palindrome
```

Il compile, lance la batterie de tests et vérifie que tu respectes l'esprit du
cours (bibliothèques interdites, signatures, idiomes modernes). Il **ne te
donne jamais la solution**.

## Table de couverture (règle d'or)

Aucun outil n'est exigé sans avoir été présenté avant. Pour chaque exercice,
voici les outils STL non triviaux requis et leur source — un chapitre
antérieur, le cours de ce chapitre, ou l'aide locale de l'énoncé.

| Exercice | Outils exigés | Source |
|----------|---------------|--------|
| 01 Parcours de vector | range-for `const auto&` / `auto&` (lire/modifier en place) | cours ch.2 §Parcourir un conteneur |
|  | `throw std::invalid_argument` | cours ch.1 §Gestion d'erreurs |
| 02 Palindrome | `rbegin`/`rend`, construction `string(it, it)` | cours ch.2 §Parcourir un conteneur |
|  | `std::tolower` (`<cctype>`), `static_cast<unsigned char>` | cours ch.2 §Classifier un caractère ; `static_cast` cours ch.1 §types |
| 03 Module géométrie | `.hpp`/`.cpp`, déclaration vs définition | cours ch.2 §headers (`.hpp`) vs sources (`.cpp`) |
|  | `namespace geom` (rouvrir un namespace) | cours ch.2 §Namespaces |
|  | `std::hypot` (`<cmath>`) | Aide locale (§Outil) |
|  | `throw std::invalid_argument` | cours ch.1 §Gestion d'erreurs |
| 04 Histogramme | `std::count` (`<algorithm>`) | cours ch.2 §Découvrir `<algorithm>` en douceur |
|  | `std::tolower`/`std::isalpha` (`<cctype>`), `static_cast<unsigned char>` | cours ch.2 §Classifier un caractère |
|  | indice `c - 'a'` (0..25) | Aide locale (§Outil) |
| 05 Mini-grille | `std::vector<std::vector<int>>`, `.at(i).at(j)` | cours ch.2 §`std::vector` en pratique |
|  | construction imbriquée 2D et piège de l'opérateur virgule | Aide locale (§Outil) |
| 06 String toolkit | `std::toupper` (`<cctype>`), `static_cast<unsigned char>` | cours ch.2 §Classifier un caractère |
|  | `find_first_not_of`/`find_last_not_of`, `substr`, `npos` | Aide locale (§Aide) |
| 07 Split maison | `find(sep, pos)`, `substr(pos, len)`, `npos` | cours ch.2 §`std::string` en pratique + Aide locale (§Aide) |

> `std::hypot` (`<cmath>`) n'est couvert par aucun cours : il est présenté
> directement dans la section **## Outil** de l'énoncé 03, ce qui suffit.

Les corrigés sont dans `solutions/`, à consulter **après** avoir réussi.
