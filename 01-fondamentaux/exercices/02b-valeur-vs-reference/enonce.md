# Exercice 02b — Valeur ou référence ★

**Difficulté :** ★☆☆☆☆
**Sections du cours :** « Valeur ou référence » (la distinction centrale),
11 (fonctions)

## Objectif

Sentir, dans les doigts, la différence entre **passage par valeur** et
**passage par référence** en C++. C'est l'un des réflexes les plus
importants quand on revient de Python, où le comportement est différent.

## Rappel de la notion

En C++, **par défaut, on passe les arguments PAR COPIE**. Quand tu écris
`void f(int x)`, la fonction reçoit son **propre exemplaire** de la valeur.
Tout ce qu'elle fait à `x` reste chez elle : la variable de l'appelant n'est
pas touchée.

Pour qu'une fonction puisse **modifier la variable de l'appelant**, on passe
**par référence** avec un `&` : `void f(int& x)`. Une référence `T&` est un
**alias**, c'est-à-dire un autre nom pour la **même** variable. Modifier la
référence, c'est modifier l'original.

Le même principe vaut pour les conteneurs : `std::vector<int>& v` est un
alias du vector de l'appelant (pas une copie). On peut donc le modifier
**en place**, et c'est aussi plus efficace (on évite de recopier tout le
vector).

Petit piège bonus, utile pour la 3e fonction : dans une boucle
`for (int e : v)`, `e` est une **copie** de l'élément. Pour modifier
l'élément dans le vector, il faut une **référence** sur l'élément.

## Signatures imposées (`valref.hpp`)

```cpp
void double_par_copie(int x);              // reçoit une copie : ne change RIEN chez l'appelant
void double_par_reference(int& x);         // reçoit une référence : double la variable de l'appelant
void ajoute_a_tous(std::vector<int>& v, int delta);  // ajoute delta à chaque élément, en place
```

Tu complètes `valref_skeleton.cpp`. Ne touche pas au `.hpp`.

## Contraintes

- Aucune bibliothèque hors standard.
- `double_par_copie` : **rien à coder**, le squelette est déjà complet. Son
  rôle est de te montrer qu'une modification d'un paramètre passé par copie
  n'a **aucun effet** à l'extérieur.
- `double_par_reference` : double la variable de l'appelant via la référence.
- `ajoute_a_tous` : ajoute `delta` à **chaque** élément, **en place**, sans
  recréer ni copier le vector. Doit fonctionner aussi sur un vector **vide**.

## Cas de test (dans `valref_test.cpp`)

| Appel | Effet attendu |
|-------|---------------|
| `int a = 5; double_par_copie(a);` | `a == 5` (inchangé : copie) |
| `int b = 5; double_par_reference(b);` | `b == 10` (doublé : référence) |
| `std::vector<int> v{1,2,3}; ajoute_a_tous(v, 10);` | `v == {11, 12, 13}` |
| `std::vector<int> w{}; ajoute_a_tous(w, 5);` | `w == {}` (vide, sans planter) |

## Compiler & tester

```bash
g++ -std=c++20 -Wall -Wextra -Wpedantic -I ../.. valref_skeleton.cpp valref_test.cpp -o test && ./test
```
