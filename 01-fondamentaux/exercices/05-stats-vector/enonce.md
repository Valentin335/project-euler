# Statistiques sur vector ★★☆☆☆

**Difficulté :** 2 / 5

**Sections du cours visées :** 8 (`std::vector`), 9 (boucle `range-for`),
17 (signaler les erreurs avec les exceptions).

## Objectif

On manipule pour la première fois un conteneur de la bibliothèque
standard : `std::vector<int>`. Tu dois écrire trois fonctions qui
calculent des statistiques de base sur un vecteur d'entiers :

- la **somme** de ses éléments,
- la **moyenne** arithmétique,
- la plus grande **valeur**.

Au passage, tu apprends à **refuser une entrée invalide** : un vecteur
vide n'a ni moyenne ni maximum bien définis. Dans ces cas, on **lève une
exception** plutôt que de renvoyer une valeur fausse.

## Signatures imposées

```cpp
int sum(const std::vector<int>& v);
double mean(const std::vector<int>& v);     // throw std::invalid_argument si v vide
int max_value(const std::vector<int>& v);   // throw std::invalid_argument si v vide
```

- `sum` sur un vecteur **vide** renvoie `0` (la somme « vide » vaut 0).
- `mean` et `max_value` sur un vecteur **vide** doivent lever
  `std::invalid_argument` (inclus via `<stdexcept>`).

## Contraintes

- **Interdit :** l'en-tête `<algorithm>` (pas de `std::accumulate`,
  `std::max_element`, etc.). Tu écris les boucles toi-même.
- **Imposé :** inclure `<vector>` (déjà fait dans `stats_vec.hpp`) et,
  pour lever les exceptions, `<stdexcept>` dans ton `.cpp`.
- Parcours le vecteur avec une boucle **range-for** (`for (int x : v)`).
- Attention au **type** dans `mean` : diviser deux entiers donne une
  division entière. Réfléchis à où placer le `double`.

## Cas de test

| Appel | Résultat attendu |
|-------|------------------|
| `sum({1, 2, 3, 4})` | `10` |
| `sum({})` | `0` |
| `sum({-5, 5})` | `0` |
| `mean({2, 4})` | `≈ 3.0` |
| `mean({})` | lève `std::invalid_argument` |
| `max_value({-5, -2, -9})` | `-2` |
| `max_value({3, 1, 2})` | `3` |
| `max_value({})` | lève `std::invalid_argument` |

## Compiler & tester

```bash
g++ -std=c++20 -Wall -Wextra -Wpedantic -I ../.. stats_vec_skeleton.cpp stats_vec_test.cpp -o test && ./test
```

Le programme affiche un bilan et renvoie `0` si tout passe, `1` sinon.
Tant que le squelette contient des bouchons, des tests échouent : c'est
normal, à toi de les faire passer.
