# 01 — Valeur ou rien ★

Renvoyer « une valeur ou rien » sans valeur sentinelle, grâce à `std::optional`.

```cpp
#include <optional>
#include <vector>
#include <cstddef>

std::optional<std::size_t> index_of(const std::vector<int>& v, int target);
std::optional<int> safe_divide(int a, int b);  // nullopt si b == 0
```

## Outil

`std::optional<T>` (`<optional>`) : « un `T` ou rien ».

```cpp
std::optional<int> f(bool ok) {
    if (!ok) return std::nullopt;  // rien
    return 42;                     // une valeur
}
auto r = f(true);
if (r.has_value()) use(r.value());
```

| Entrée                  | Sortie    |
|-------------------------|-----------|
| `index_of({10,20,30},20)` | `1`     |
| `index_of({1,2},9)`     | `nullopt` |
| `safe_divide(10,2)`     | `5`       |
| `safe_divide(1,0)`      | `nullopt` |

```sh
g++ -std=c++20 -Wall -Wextra -Wpedantic -I ../.. optionnel_skeleton.cpp optionnel_test.cpp -o test
```
