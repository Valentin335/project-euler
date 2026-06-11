# Exercice 08 — FizzBuzz paramétrable ★★

**Difficulté :** ★★☆☆☆
**Sections du cours :** 7 (`std::string`), 8 (`std::vector`), 10 (structures de contrôle)

## Objectif

Le grand classique **FizzBuzz**, revisité pour pratiquer trois briques de base
ensemble : les **chaînes**, les **vecteurs** et le **contrôle de flux** (`if` /
boucle).

Tu écris deux fonctions :

- `fizzbuzz_term(n)` renvoie le « terme » associé à un entier :
  - `"Fizz"` si `n` est multiple de 3,
  - `"Buzz"` si `n` est multiple de 5,
  - `"FizzBuzz"` si `n` est multiple de 15 (donc de 3 **et** de 5),
  - sinon le nombre lui-même, **converti en texte** (ex. `7` → `"7"`).
- `fizzbuzz_range(from, to)` renvoie le `std::vector<std::string>` de tous les
  termes de `from` à `to` **inclus**.

L'enjeu caché : l'**ordre des tests**. Un multiple de 15 est aussi un multiple
de 3 et de 5 — réfléchis bien à la façon de traiter ce cas pour ne pas renvoyer
`"Fizz"` au lieu de `"FizzBuzz"`.

## Signatures imposées (`fizzbuzz.hpp`)

```cpp
std::string fizzbuzz_term(int n);                          // "Fizz" / "Buzz" / "FizzBuzz" / le nombre en texte
std::vector<std::string> fizzbuzz_range(int from, int to); // termes de from à to inclus
```

Tu complètes `fizzbuzz_skeleton.cpp`. Ne touche pas au `.hpp`.

## Contraintes

- Aucune bibliothèque hors standard.
- `<string>` et `<vector>` sont inclus pour toi dans le `.hpp`.
- Pour convertir un `int` en `std::string`, utilise **`std::to_string(n)`**.
- L'opérateur **modulo** `%` donne le reste d'une division entière : `n % 3 == 0`
  signifie « `n` est divisible par 3 ».
- Pour remplir le vecteur, une boucle (`for`) et `push_back` suffisent. On
  suppose `from <= to` (sinon le vecteur peut être vide).

## Cas de test (dans `fizzbuzz_test.cpp`)

| Appel | Résultat attendu |
|-------|------------------|
| `fizzbuzz_term(3)` | `"Fizz"` |
| `fizzbuzz_term(5)` | `"Buzz"` |
| `fizzbuzz_term(15)` | `"FizzBuzz"` |
| `fizzbuzz_term(7)` | `"7"` |
| `fizzbuzz_term(1)` | `"1"` |
| `fizzbuzz_range(1, 5)` | `{"1", "2", "Fizz", "4", "Buzz"}` |

## Compiler & tester

```bash
g++ -std=c++20 -Wall -Wextra -Wpedantic -I ../.. fizzbuzz_skeleton.cpp fizzbuzz_test.cpp -o test && ./test
```
