# Échange & rotation ★★☆☆☆

**Difficulté :** 2 / 5

**Sections du cours visées :** 6 (références)

## Objectif

Manipuler des variables *par référence* pour les modifier en place. Tu vas
réimplémenter, à la main, deux opérations classiques :

1. `swap_ints` : échanger les valeurs de deux entiers.
2. `rotate_left` : faire tourner trois entiers vers la gauche, c'est-à-dire
   `(a, b, c)` devient `(b, c, a)`.

Toute la difficulté pédagogique est là : comme tu reçois des **références**
(`int&`), les modifications que tu fais à l'intérieur de la fonction doivent
se voir *à l'extérieur*, chez l'appelant. Si rien ne change après l'appel,
c'est que tu travailles sur des copies — relis la section sur les références.

## Signatures imposées

```cpp
void swap_ints(int& a, int& b);
void rotate_left(int& a, int& b, int& c);   // (a, b, c) -> (b, c, a)
```

## Contraintes

- **Interdit :** `std::swap` et `std::exchange`. Le but est précisément de
  réécrire l'échange toi-même pour comprendre le mécanisme (typiquement avec
  une variable temporaire). Utiliser ces fonctions de la bibliothèque
  standard est considéré comme hors-sujet ici.
- Aucune autre bibliothèque n'est nécessaire : pas de `#include` particulier
  dans ton `.cpp` au-delà du `.hpp` fourni.

## Cas de test

| Appel | Avant | Après attendu |
|-------|-------|---------------|
| `swap_ints(a, b)` | `a = 1, b = 2` | `a = 2, b = 1` |
| `rotate_left(x, y, z)` | `x = 1, y = 2, z = 3` | `x = 2, y = 3, z = 1` |
| `rotate_left` × 3 | `(1, 2, 3)` | `(1, 2, 3)` (retour à l'identique) |

Le dernier cas teste une propriété intéressante : appliquer trois fois de
suite une rotation gauche sur trois éléments redonne la configuration de
départ.

## Compiler & tester

```bash
g++ -std=c++20 -Wall -Wextra -Wpedantic -I /home/valentin/Documents/project\ euler/01-fondamentaux rotation_skeleton.cpp rotation_test.cpp -o test && ./test
```
