# Conventions du cours à vérifier lors d'une revue

Liste de contrôle pour le skill `/review-exo`. **Tout n'est pas pertinent pour
chaque exercice** — fais la part des choses selon ce que l'énoncé veut
enseigner.

## Principe directeur : adapter la sévérité à l'objectif de l'exercice

Chaque exercice a **une vocation pédagogique** précise (apprendre les
références, le `const`, la surcharge, RAII…). La revue doit cibler **cette**
notion, pas tout marteler.

- Un exercice qui enseigne une **notion** (la majorité du chapitre 1) : on
  vérifie que la notion est bien employée, que les tests passent, que le style
  est correct. **On NE met PAS de contrainte de performance** (chrono / nombre
  d'opérations) — ce serait hors sujet et décourageant.
- Un exercice qui enseigne un **algorithme** ou dont l'énoncé **mentionne
  explicitement** une complexité / un temps / un nombre d'opérations : là, et
  là seulement, on valide la contrainte de perf (via `CHECK_UNDER_MS` ou
  `CHECK_OPS_UNDER`).

Règle simple : **si l'énoncé ne parle pas de performance, n'en parle pas non
plus.** Pas de bazooka contre une mouche.

## 1. Bibliothèques interdites / imposées

L'énoncé peut interdire une bibliothèque pour forcer l'apprentissage d'un
fondamental. Exemples vus au chapitre 1 :
- `05-stats-vector` : `<algorithm>` interdit (on muscle la boucle range-for).
- `04-echange-rotation` : `std::swap` / `std::exchange` interdits (on
  réimplémente l'échange).

→ Grep la solution pour l'`#include` ou l'appel interdit. Si présent, c'est un
écart à signaler.

## 2. Signatures imposées

- Le `.hpp` ne doit pas avoir été modifié.
- Les fonctions ont exactement la signature demandée (types, `const`,
  références). Pas de signature contournée (ex. paramètre changé en valeur alors
  que `const&` était imposé).

## 3. Idiomes C++ modernes

- **`const`-correctness** : `const T&` pour les gros objets lus, `const` sur les
  variables qui ne changent pas.
- **Pas de `using namespace std;`** (surtout pas en header).
- **`std::optional`** plutôt qu'une valeur-sentinelle (-1, nullptr…) quand
  l'énoncé modélise « valeur ou rien ».
- **Exceptions** quand l'énoncé exige de lever (`throw std::domain_error`, etc.)
  sur les cas invalides.
- **`at()` vs `[]`** selon ce que l'énoncé demande (accès vérifié ou non).
- **Range-based for** quand c'est l'idiome attendu.
- Affectation simultanée / `std::tie` / structured bindings là où c'est plus sûr
  (vu au chapitre des fondamentaux).

## 4. Robustesse de la solution (cas limites)

Les tests fournis couvrent déjà les cas méchants pertinents (vide, négatifs,
doublons, taille 1, limites). Si tu repères un cas limite **non couvert** que la
solution gère mal, signale-le par une question — sans donner le correctif.

## 5. Lisibilité et style

- Noms parlants (`prev`/`current` plutôt que `cpt1`/`cpt2`).
- Scope minimal des variables (déclaration au plus près de l'usage).
- Indentation 4 espaces, cohérence des accolades.
- Pas de code mort, pas de commentaire qui répète le code.

## 6. Performance — UNIQUEMENT si l'énoncé le justifie

Ne déclenche cette section que si l'énoncé impose une borne explicite (temps,
nombre d'opérations, complexité). Outils disponibles dans `check.hpp` :
- `CHECK_UNDER_MS(expr, limite_ms)` : garde-fou temps (limite généreuse).
- `CHECK_OPS_UNDER(expr, max_ops)` avec `check::Counted<T>` : compte les
  comparaisons — robuste, indépendant de la machine.

Si l'énoncé est muet sur la performance : **ne pas en faire un critère**.
