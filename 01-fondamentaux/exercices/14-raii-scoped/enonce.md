# RAII `ScopedAppender` ★★★★★

**Difficulté :** 5/5

**Sections du cours visées :** 15 (RAII — *Resource Acquisition Is Initialization*)

## Objectif

Découvrir le pattern **RAII** en implémentant un objet dont le
**destructeur** garantit une action de fin de vie. C'est le mécanisme
fondamental du C++ pour gérer fichiers, verrous, mémoire, connexions :
on attache une action à la **destruction**, et le langage garantit
qu'elle s'exécutera **automatiquement** à la sortie de portée.

`ScopedAppender` mémorise une référence vers une `std::string` et une
chaîne `on_exit`. À sa **destruction**, il doit ajouter `on_exit` à la
fin de la chaîne référencée.

Deux idées clés à observer :

- **Ordre de destruction inverse.** Dans une même portée, les objets
  sont détruits dans l'ordre **inverse** de leur construction. Si tu
  construis `a` puis `b`, c'est `b` qui meurt en premier.
- **Classe non copiable.** L'objet possède une action de sortie : on
  interdit explicitement la copie (`= delete`) pour qu'il n'y ait
  aucune ambiguïté sur « qui exécute l'action ».

Le header `scoped.hpp` te donne la classe complète (membres +
signatures) : **tu n'y touches pas**. Le constructeur t'est déjà
fourni dans `scoped_skeleton.cpp` (il *doit* utiliser la liste
d'initialisation car `target_` est une référence — sinon ça ne
compile pas). **À toi d'écrire le corps du destructeur.**

## Signatures imposées (dans `scoped.hpp`)

```cpp
class ScopedAppender {
public:
    ScopedAppender(std::string& target, std::string on_exit);
    ~ScopedAppender();   // doit ajouter on_exit_ à target_
    ScopedAppender(const ScopedAppender&) = delete;
    ScopedAppender& operator=(const ScopedAppender&) = delete;
private:
    std::string& target_;
    std::string on_exit_;
};
```

## Contraintes

- Tu **n'as pas le droit de modifier** `scoped.hpp` ni `scoped_test.cpp`.
- Tu écris ta solution dans `scoped_skeleton.cpp`. **Seul le corps du
  destructeur** est à compléter (le constructeur t'est donné).
- Bibliothèque imposée : `<string>` (déjà inclus via le header).
  Aucune autre n'est nécessaire ; ni `std::unique_ptr`, ni `goto`, ni
  `atexit` : la seule mécanique attendue est celle du **destructeur**.
- La classe doit rester **non copiable** : ne retire pas les `= delete`
  (de toute façon `scoped.hpp` ne se modifie pas).

## Cas de test

| Scénario                                                     | Résultat attendu              |
|--------------------------------------------------------------|-------------------------------|
| `{ ScopedAppender a(log, "A"); ScopedAppender b(log, "B"); }` | `log == "BA"` (B détruit avant A) |
| Copie d'un `ScopedAppender` (en commentaire dans le test)    | ne **compilerait pas** (copie supprimée) |

## Compiler & tester

```sh
g++ -std=c++20 -Wall -Wextra -Wpedantic -I /home/valentin/Documents/project\ euler/01-fondamentaux scoped_skeleton.cpp scoped_test.cpp -o test && ./test
```

Tant que le destructeur est un bouchon, le test échoue (code retour 1) :
c'est attendu. Quand le destructeur est correct, `./test` affiche
`TOUS LES TESTS PASSENT.` et renvoie 0.
