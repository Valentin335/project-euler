# Exercice 02 — Conversions de température ★

**Difficulté :** ★☆☆☆☆
**Sections du cours :** 11 (fonctions), 3 (entrées / sorties)

## Objectif

Écrire trois petites fonctions autour des températures. On manipule des
`double` (et leurs pièges de comparaison) et on renvoie une chaîne C
(`const char*`) selon un seuil. L'occasion de revoir le passage de
paramètres par valeur et le `return` d'une fonction.

## Signatures imposées (`temperatures.hpp`)

```cpp
double celsius_to_fahrenheit(double c);   // Celsius  -> Fahrenheit
double fahrenheit_to_celsius(double f);   // Fahrenheit -> Celsius
const char* water_state(double celsius);  // état de l'eau à cette température
```

Pour `water_state` : `"solide"` si `celsius <= 0`, `"liquide"` si
`celsius < 100`, `"gazeux"` si `celsius >= 100`.

Tu complètes `temperatures_skeleton.cpp`. Ne touche pas au `.hpp`.

## Contraintes

- Aucune bibliothèque hors standard.
- Les conversions reposent sur les relations physiques entre les deux
  échelles : à toi de retrouver la formule (penser au point de congélation
  et au point d'ébullition de l'eau).
- Les tests comparent les `double` **à epsilon près** (fonction `approx`),
  pas par égalité stricte : on ne compare jamais deux flottants avec `==`.

## Cas de test (dans `temperatures_test.cpp`)

| Appel | Résultat attendu |
|-------|------------------|
| `celsius_to_fahrenheit(0)` | `32` |
| `celsius_to_fahrenheit(100)` | `212` |
| `fahrenheit_to_celsius(32)` | `0` |
| `fahrenheit_to_celsius(212)` | `100` |
| `water_state(-5)` | `"solide"` |
| `water_state(0)` | `"solide"` |
| `water_state(20)` | `"liquide"` |
| `water_state(99.9)` | `"liquide"` |
| `water_state(100)` | `"gazeux"` |
| `water_state(150)` | `"gazeux"` |

## Compiler & tester

```bash
g++ -std=c++20 -Wall -Wextra -Wpedantic -I ../.. temperatures_skeleton.cpp temperatures_test.cpp -o test && ./test
```
