# Exercice 07 — Surcharge de describe ★★

**Difficulté :** ★★☆☆☆
**Sections du cours :** 11 (surcharge de fonctions)

## Objectif

Écrire **quatre fonctions portant le même nom** `describe`, qui ne diffèrent
que par le type de leur paramètre. C'est la **surcharge** : le compilateur
choisit la « bonne » version en fonction du type de l'argument que tu passes.

L'enjeu caché de l'exercice : comprendre **comment le compilateur résout une
surcharge**, et pourquoi un appel apparemment évident peut partir sur la
mauvaise version.

## Signatures imposées (`describe.hpp`)

```cpp
std::string describe(int n);                 // "entier 42"
std::string describe(double d);              // commence par "flottant "
std::string describe(const std::string& s);  // "texte: bonjour"
std::string describe(bool b);                // "booleen vrai" ou "booleen faux"
```

Tu complètes `describe_skeleton.cpp`. Ne touche pas au `.hpp`.

## Contraintes

- Aucune bibliothèque hors standard. `<string>` est déjà inclus par le `.hpp`.
- Tu dois fournir les **quatre** surcharges. Pour la version `double`, seul le
  **préfixe** `"flottant "` est testé : le formatage exact du nombre est libre.

## Le piège de la résolution de surcharge

Considère cet appel :

```cpp
describe("x");   // "x" est un littéral de type const char[2]
```

Intuitivement, on s'attend à ce que ça appelle la surcharge `const std::string&`.
**Mais ce n'est pas le cas.** Un littéral comme `"x"` est un tableau de
caractères (`const char[]`) qui se convertit en `const char*`. Or, pour le
compilateur :

- aller de `const char*` vers `std::string` demande une **conversion définie
  par l'utilisateur** (le constructeur de `std::string`) ;
- aller de `const char*` vers `bool` est une **conversion standard** (un
  pointeur non nul devient `true`).

Les conversions standard sont **prioritaires** sur les conversions définies par
l'utilisateur. Résultat : `describe("x")` appelle la surcharge **`bool`**, pas
celle qui prend une chaine ! C'est un classique qui surprend tout le monde.

C'est pour cette raison que le fichier de test écrit explicitement :

```cpp
describe(std::string("bonjour"));   // type std::string => surcharge string, sans ambiguite
```

Retiens l'idée : quand tu veux vraiment cibler la surcharge `std::string`,
passe un objet **déjà** de type `std::string` (par exemple avec le suffixe `s`
de `std::string_literals`, ou en construisant un `std::string` explicitement).

## Cas de test (dans `describe_test.cpp`)

| Appel | Résultat attendu |
|-------|------------------|
| `describe(42)` | `"entier 42"` |
| `describe(std::string("bonjour"))` | `"texte: bonjour"` |
| `describe(true)` | `"booleen vrai"` |
| `describe(false)` | `"booleen faux"` |
| `describe(3.5)` | une chaine commençant par `"flottant "` |

## Compiler & tester

```bash
g++ -std=c++20 -Wall -Wextra -Wpedantic -I ../.. describe_skeleton.cpp describe_test.cpp -o test && ./test
```
