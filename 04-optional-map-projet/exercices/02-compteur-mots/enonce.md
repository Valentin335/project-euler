# 02 — Compteur de mots (tu écris tout le programme) ★★★

Deuxième exercice **100 % autonome** : tu écris le programme complet, `main`
compris. Pas de squelette ni de tests fournis.

## But

Lire tout le texte fourni sur l'entrée standard (plusieurs lignes, jusqu'à
Ctrl-D), puis afficher :

1. le **nombre total de mots**,
2. le **nombre de mots distincts**,
3. pour chaque mot distinct, **combien de fois** il apparaît, **trié par ordre
   alphabétique**.

Un « mot » = une suite de caractères séparés par des espaces (on ne gère pas la
ponctuation : `chat,` et `chat` comptent comme différents, c'est accepté).

## Exemple

Entrée :
```
le chat dort le chien dort
```

Sortie (l'ordre exact des lignes d'en-tête est libre, mais le décompte trié
doit y être) :
```
Total : 6 mots
Distincts : 4
chat : 1
chien : 1
dort : 2
le : 2
```

## Outils utiles

- `std::getline` en boucle pour lire toutes les lignes, ou lire directement les
  mots avec `std::cin >> mot` (l'opérateur `>>` saute les espaces ET les sauts
  de ligne — pratique ici).
- **`std::map<std::string, int>`** (`<map>`) : un dictionnaire trié. `++compte[mot]`
  crée l'entrée à 0 puis l'incrémente. Parcourir une `map` la donne **déjà triée
  par clé** :
  ```cpp
  std::map<std::string, int> compte;
  std::string mot;
  while (std::cin >> mot) {
      ++compte[mot];
  }
  for (const auto& [m, n] : compte) {   // structured bindings : m=clé, n=valeur
      std::cout << m << " : " << n << "\n";
  }
  ```

## Conseils

- Le nombre total de mots = la somme des compteurs (ou un compteur à part).
- Le nombre de mots distincts = `compte.size()`.
- La `map` te donne le tri alphabétique gratuitement (c'est tout son intérêt ici).

## Compiler

```bash
g++ -std=c++20 -Wall -Wextra -Wpedantic compteur.cpp -o compteur && ./compteur
# puis tape du texte, et Ctrl-D pour terminer l'entrée
```

Crée `compteur.cpp` dans ce dossier. Quand il marche, compare avec le corrigé.
