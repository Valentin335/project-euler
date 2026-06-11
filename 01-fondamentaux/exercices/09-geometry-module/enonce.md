# Module `geometry` (.hpp / .cpp) ★★★☆☆

**Difficulté :** 3/5

**Sections du cours visées :** 13 (headers / sources : séparer déclaration et définition) · 14 (namespaces)

## Objectif

Découper du code en **interface** (`.hpp`) et **implémentation** (`.cpp`),
et regrouper des fonctions dans un **namespace** `geom`.

Le header `geometry.hpp` te donne les *signatures* : tu n'y touches pas.
À toi d'écrire les *corps* des fonctions dans `geometry_skeleton.cpp`,
en **rouvrant** le namespace `geom`.

## Signatures imposées (dans `geometry.hpp`, namespace `geom`)

```cpp
namespace geom {
    double rectangle_area(double w, double h);
    double circle_area(double r);   // lance std::invalid_argument si r < 0
    double distance(double x1, double y1, double x2, double y2);
}
```

## Contraintes

- Tu **n'as pas le droit de modifier** `geometry.hpp` ni `geometry_test.cpp`.
- Tu écris tes définitions dans `geometry_skeleton.cpp`, **dans le namespace `geom`**.
- Pour `circle_area`, un rayon `r < 0` doit lancer `std::invalid_argument`
  (en-tête `<stdexcept>`). Un rayon nul est valide (aire 0).
- Pour la racine carrée de `distance`, utilise `std::sqrt` (`<cmath>`).
- Tu peux définir ta propre constante de PI ou utiliser celle de `<cmath>`.
- **Piège « multiple definition ».** Ne mets PAS le corps des fonctions
  *directement* dans `geometry.hpp`. Si tu définis une fonction (non
  `inline`) dans un header inclus par plusieurs `.cpp`, l'éditeur de
  liens voit le symbole **plusieurs fois** et plante avec une erreur
  `multiple definition of ...`. La règle simple : **déclaration** dans
  le `.hpp`, **définition** dans le `.cpp`. (Une fonction définie dans
  le header devrait être marquée `inline` — mais ici on s'entraîne
  justement à la séparation `.hpp` / `.cpp`.)

## Cas de test

| Appel                                   | Résultat attendu                          |
|-----------------------------------------|-------------------------------------------|
| `geom::rectangle_area(3, 4)`            | `≈ 12`                                     |
| `geom::circle_area(1)`                  | `≈ 3.14159265` (tolérance `1e-6`)         |
| `geom::circle_area(0)`                  | `≈ 0`                                      |
| `geom::circle_area(-1.0)`               | lance `std::invalid_argument`             |
| `geom::distance(0, 0, 3, 4)`            | `≈ 5`                                      |

## Compiler & tester

```sh
g++ -std=c++20 -Wall -Wextra -Wpedantic -I ../.. geometry_skeleton.cpp geometry_test.cpp -o test && ./test
```

Tant que les corps sont des bouchons, des tests échouent (code retour 1) :
c'est attendu. Quand tout passe, `./test` affiche `5/5 tests OK` et
renvoie 0.
