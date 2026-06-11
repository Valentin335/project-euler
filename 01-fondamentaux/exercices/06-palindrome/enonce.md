# Exercice 06 — Renversement & palindrome ★★

**Difficulté :** ★★☆☆☆
**Sections du cours :** 7 (`std::string`), 9 (boucle range-for)

## Objectif

Manipuler des chaînes de caractères : d'abord **inverser** une chaîne, puis
décider si une chaîne est un **palindrome** (elle se lit pareil dans les deux
sens). L'enjeu caché : **normaliser** le texte avant de comparer — on veut
ignorer la casse (majuscules/minuscules) et les espaces.

## Signatures imposées (`palindrome.hpp`)

```cpp
std::string reverse(const std::string& s);
bool is_palindrome(const std::string& s);   // insensible à la casse, ignore les espaces ; ASCII uniquement
```

Tu complètes `palindrome_skeleton.cpp`. Ne touche pas au `.hpp`.

## Contraintes

- Aucune bibliothèque hors standard.
- `<string>` est inclus pour toi dans le `.hpp`.
- Pour comparer des lettres sans tenir compte de la casse, regarde
  `std::tolower` (header `<cctype>`). Attention : `std::tolower` attend un
  argument qui ne soit pas un `char` négatif — on reste en **ASCII**, donc pas
  de piège ici, mais c'est une bonne habitude à connaître.
- `is_palindrome` doit ignorer **les espaces** et **la casse**. Une chaîne vide
  est un palindrome (rien à comparer).
- La boucle range-for (`for (char c : s)`) est idéale pour parcourir une chaîne.

## Cas de test (dans `palindrome_test.cpp`)

| Appel | Résultat attendu |
|-------|------------------|
| `reverse("abc")` | `"cba"` |
| `reverse("")` | `""` |
| `reverse("a")` | `"a"` |
| `is_palindrome("kayak")` | `true` |
| `is_palindrome("hello")` | `false` |
| `is_palindrome("Kayak")` | `true` |
| `is_palindrome("A man a plan a canal Panama")` | `true` |
| `is_palindrome("")` | `true` |

## Compiler & tester

```bash
g++ -std=c++20 -Wall -Wextra -Wpedantic -I ../.. palindrome_skeleton.cpp palindrome_test.cpp -o test && ./test
```
