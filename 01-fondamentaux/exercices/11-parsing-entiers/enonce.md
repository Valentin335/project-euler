# Exercice 11 — Parsing robuste d'entiers ★★★

**Difficulté :** ★★★☆☆
**Sections du cours :** 17 (gestion des erreurs / exceptions), 7 (`std::string`)

## Objectif

Lire des entiers depuis du texte, **sans jamais accepter une entrée malformée**.
C'est un problème classique et piégeux : une conversion qui « marche presque »
est souvent pire qu'une erreur franche. Tu vas écrire deux fonctions :

- `parse_int` convertit **une** chaîne en `long long`, mais **refuse** toute
  chaîne qui n'est pas un entier complet et valide (en lançant une exception).
- `parse_ints` découpe **une ligne** en plusieurs entiers séparés par des
  espaces.

L'enjeu caché : une conversion comme `std::stoll` est trop permissive par
défaut. Elle convertit la partie initiale et **s'arrête** au premier caractère
invalide. À toi de détecter ces cas.

## Signatures imposées (`parse_int.hpp`)

```cpp
long long parse_int(const std::string& s);              // throw std::invalid_argument si s n'est pas un entier complet valide
std::vector<long long> parse_ints(const std::string& line);   // entiers separes par espaces ; ignore espaces multiples ; "" -> {}
```

Tu complètes `parse_int_skeleton.cpp`. Ne touche pas au `.hpp`.

## Contraintes

- Aucune bibliothèque hors standard.
- `<string>`, `<vector>` et `<stdexcept>` sont inclus pour toi dans le `.hpp`.
- `parse_int` doit lancer **`std::invalid_argument`** (et seulement ce type)
  pour toute entrée invalide : chaîne vide `""`, espaces seuls `"  "`, ou
  caractères en trop comme `"12a"`.
- Regarde **`std::stoll`** (header `<string>`) : il convertit une chaîne en
  `long long`. Mais lis bien sa documentation — il accepte des chaînes qui ne
  sont **pas** entièrement numériques (par exemple `"12a"` lui donne `12`).
- Indice clé : `std::stoll` a un **deuxième paramètre** (un pointeur vers un
  index de sortie) qui te dit **combien de caractères ont été consommés**. Si
  tout n'a pas été consommé, la chaîne n'était pas un entier complet : c'est à
  toi de transformer ça en `std::invalid_argument`.
- `std::stoll` lance déjà `std::invalid_argument` quand il n'y a aucun chiffre
  à lire (cas `""` et `"  "`). Réfléchis à ce que tu dois faire pour le cas
  « entier suivi de caractères parasites ».
- Pour `parse_ints` : une ligne vide `""` donne un vecteur **vide**. Les
  espaces multiples entre deux nombres doivent être ignorés (`"1   2"` donne
  deux entiers, pas plus). Pense à un outil qui sait découper du texte en
  ignorant les blancs successifs.

## Cas de test (dans `parse_int_test.cpp`)

| Appel | Résultat attendu |
|-------|------------------|
| `parse_int("42")` | `42` |
| `parse_int("-7")` | `-7` |
| `parse_int("0")` | `0` |
| `parse_int("12a")` | lance `std::invalid_argument` |
| `parse_int("")` | lance `std::invalid_argument` |
| `parse_int("  ")` | lance `std::invalid_argument` |
| `parse_ints("1 2 3")` | `{1, 2, 3}` |
| `parse_ints("1   2")` | `{1, 2}` |
| `parse_ints("")` | `{}` |

## Compiler & tester

```bash
g++ -std=c++20 -Wall -Wextra -Wpedantic -I ../.. parse_int_skeleton.cpp parse_int_test.cpp -o test && ./test
```
