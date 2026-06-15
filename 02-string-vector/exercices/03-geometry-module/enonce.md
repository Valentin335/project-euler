# 03 — Module géométrie ★★

Implémente trois fonctions de géométrie en séparant **déclaration** (`geometry.hpp`)
et **définition** (`geometry_skeleton.cpp`, en rouvrant `namespace geom`).

```cpp
namespace geom {
    double rectangle_area(double w, double h);
    double circle_area(double r);   // throw std::invalid_argument si r < 0
    double distance(double x1, double y1, double x2, double y2);
}
```

## Outil

`std::hypot(dx, dy)` (`<cmath>`) calcule `sqrt(dx*dx + dy*dy)` sans débordement intermédiaire :

```cpp
#include <cmath>
double dx = 3.0, dy = 4.0;
double d = std::hypot(dx, dy);  // 5.0
```

| Appel                       | Résultat                 |
|-----------------------------|--------------------------|
| `rectangle_area(3, 4)`      | `12`                     |
| `circle_area(1)`            | `≈ 3.14159`              |
| `circle_area(-1)`           | lève `std::invalid_argument` |
| `distance(0, 0, 3, 4)`      | `5`                      |

```sh
g++ -std=c++20 -Wall -Wextra -Wpedantic -I ../.. geometry_skeleton.cpp geometry_test.cpp -o test && ./test
```
