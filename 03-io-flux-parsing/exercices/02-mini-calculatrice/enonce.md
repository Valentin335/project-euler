# 02 — Mini-calculatrice (tu écris tout le programme) ★★

Premier exercice **100 % autonome** : pas de squelette, pas de tests fournis,
pas de signatures imposées. **Tu écris le programme complet**, `main` compris.

## But

Lire des lignes au clavier, chacune de la forme `nombre opérateur nombre`
(ex. `3 + 4`), et afficher le résultat. Le programme s'arrête sur `quit` ou en
fin d'entrée (Ctrl-D).

## Comportement attendu

| Entrée | Sortie |
|--------|--------|
| `3 + 4` | `7` |
| `10 - 2.5` | `7.5` |
| `6 * 7` | `42` |
| `8 / 0` | un message d'erreur (division par zéro), le programme continue |
| `bonjour` | un message d'erreur, le programme continue |
| `quit` | le programme s'arrête |

Opérateurs à gérer : `+`, `-`, `*`, `/`. Les nombres sont des `double`.

## Outils utiles (revus aux exercices précédents)

- `std::getline(std::cin, ligne)` pour lire une ligne.
- `std::istringstream` (`<sstream>`) pour découper `ligne` :
  ```cpp
  std::istringstream flux(ligne);
  double a, b;
  char op;
  if (flux >> a >> op >> b) { /* lecture réussie */ }
  ```
  L'opérateur `>>` lit et convertit directement (`double`, puis `char`, puis
  `double`), et saute les espaces. S'il échoue, l'entrée est mal formée.

## Conseils

- Structure : une boucle `while` qui lit une ligne, la parse, calcule, affiche.
- Une fonction `double applique(double a, char op, double b)` rendrait le `main`
  plus clair (à toi de voir).
- Gère la division par zéro et les lignes mal formées **sans crasher** (message
  sur `std::cerr`, on continue).

## Compiler

```bash
g++ -std=c++20 -Wall -Wextra -Wpedantic calculatrice.cpp -o calc && ./calc
```

Crée un fichier `calculatrice.cpp` dans ce dossier et code-le entièrement.
Quand il marche, compare avec le corrigé dans `solutions/`.
