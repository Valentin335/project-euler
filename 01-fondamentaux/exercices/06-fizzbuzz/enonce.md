# 06 — FizzBuzz ★

Renvoie le terme FizzBuzz d'un entier, puis la liste sur un intervalle.

```cpp
std::string fizzbuzz_term(int n);                          // Fizz/Buzz/FizzBuzz/nombre
std::vector<std::string> fizzbuzz_range(int from, int to);  // from..to inclus
```

## Outil

`std::to_string` convertit un nombre en texte :

```cpp
#include <string>
std::string s = std::to_string(42); // "42"
```

| Entrée | Sortie |
|---|---|
| `fizzbuzz_term(3)` | `"Fizz"` |
| `fizzbuzz_term(5)` | `"Buzz"` |
| `fizzbuzz_term(15)` | `"FizzBuzz"` |
| `fizzbuzz_term(7)` | `"7"` |
| `fizzbuzz_range(1, 5)` | `{"1","2","Fizz","4","Buzz"}` |

```sh
g++ -std=c++20 -Wall -Wextra -Wpedantic -I ../.. fizzbuzz_skeleton.cpp fizzbuzz_test.cpp -o test
```
