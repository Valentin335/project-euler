# 02 — Palindrome ★

Inverser une chaîne, puis détecter un palindrome en ignorant la casse et les espaces (ASCII).

```cpp
std::string reverse(const std::string& s);
bool is_palindrome(const std::string& s);  // ignore casse et espaces, ASCII
```

## Outil

`rbegin`/`rend` : itérateurs qui parcourent à l'envers. `std::tolower` (`<cctype>`)
prend un `int` ; protège-le avec `static_cast<unsigned char>`.

```cpp
std::string s = "Abc";
std::string r(s.rbegin(), s.rend());            // "cbA"
char c = static_cast<char>(std::tolower(
             static_cast<unsigned char>('A')));  // 'a'
```

| Entrée | Sortie |
| --- | --- |
| `reverse("abc")` | `"cba"` |
| `is_palindrome("kayak")` | `true` |
| `is_palindrome("Kayak")` | `true` |
| `is_palindrome("hello")` | `false` |
| `is_palindrome("")` | `true` |

```sh
g++ -std=c++20 -Wall -Wextra -Wpedantic -I ../.. palindrome_skeleton.cpp palindrome_test.cpp -o test && ./test
```
