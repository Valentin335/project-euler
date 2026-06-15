# 02 — Températures ★

Convertis entre Celsius et Fahrenheit, et déduis l'état de l'eau à une température donnée.

```cpp
double celsius_to_fahrenheit(double c);
double fahrenheit_to_celsius(double f);
const char* water_state(double celsius);  // <=0 "solide", <100 "liquide", >=100 "gazeux"
```

Formules : `F = C * 9/5 + 32` et `C = (F - 32) * 5/9`.
Utilise des littéraux `double` (`9.0/5.0`, `5.0/9.0`) pour éviter la division entière.

| Appel | Résultat |
|---|---|
| `celsius_to_fahrenheit(0)` | `32` |
| `celsius_to_fahrenheit(100)` | `212` |
| `fahrenheit_to_celsius(212)` | `100` |
| `water_state(-5)` | `"solide"` |
| `water_state(20)` | `"liquide"` |
| `water_state(100)` | `"gazeux"` |

```sh
g++ -std=c++20 -Wall -Wextra -Wpedantic -I ../.. temperatures_skeleton.cpp temperatures_test.cpp -o test && ./test
```
