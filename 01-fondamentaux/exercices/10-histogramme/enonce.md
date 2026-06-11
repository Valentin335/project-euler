# Comptage & histogramme ★★★☆☆

**Difficulté :** 3 / 5

**Sections du cours visées :** 7 (`std::string`), 8 (`std::vector`),
9 (boucle `range-for`).

## Objectif

On combine pour la première fois une chaine de caractères et un
conteneur. Tu dois écrire deux fonctions :

- `count_char` : compte combien de fois un caractère donné apparait dans
  une chaine.
- `char_histogram` : construit l'**histogramme** des 26 lettres de
  l'alphabet présentes dans une chaine.

L'histogramme est un `std::vector<int>` de **taille 26** : la case
d'indice `0` compte les `a`, la case `1` les `b`, ..., la case `25` les
`z`. La **casse est ignorée** (`'A'` compte comme `'a'`) et tout
caractère qui n'est pas une lettre de l'alphabet (chiffre, espace,
ponctuation...) est **ignoré**.

## Signatures imposées

```cpp
int count_char(const std::string& s, char c);
std::vector<int> char_histogram(const std::string& s);  // taille 26 ; indice 0=a..25=z ; ignore casse et non-lettres
```

## Contraintes

- **Imposé :** inclure `<string>` et `<vector>` (déjà fait dans
  `histogram.hpp`).
- Parcours la chaine avec une boucle **range-for** (`for (char ch : s)`).
- Pense aux fonctions de `<cctype>` : `std::tolower` (passer en
  minuscule) et `std::isalpha` (tester si c'est une lettre). Attention,
  ces fonctions attendent un `unsigned char` : convertis ton caractère
  avant de les appeler.
- Pour trouver l'indice d'une lettre minuscule, souviens-toi que les
  lettres se suivent dans la table des caractères : `'a'` est juste avant
  `'b'`, etc.

## Cas de test

| Appel | Résultat attendu |
|-------|------------------|
| `count_char("banana", 'a')` | `3` |
| `count_char("xyz", 'a')` | `0` |
| `count_char("", 'a')` | `0` |
| `char_histogram("aAbB!").size()` | `26` |
| `char_histogram("aAbB!")[0]` | `2` (les `a`/`A`) |
| `char_histogram("aAbB!")[1]` | `2` (les `b`/`B`) |
| `char_histogram("aAbB!")[2]` | `0` (aucun `c`) |

## Compiler & tester

```bash
g++ -std=c++20 -Wall -Wextra -Wpedantic -I ../.. histogram_skeleton.cpp histogram_test.cpp -o test && ./test
```

Le programme affiche un bilan et renvoie `0` si tout passe, `1` sinon.
Tant que le squelette contient des bouchons, des tests échouent : c'est
normal, à toi de les faire passer.
